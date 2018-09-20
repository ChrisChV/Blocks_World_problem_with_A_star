#ifndef A_ASTERISCO_H
#define A_ASTERISCO_H

#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
#include "HashTable.h"

using namespace std;

typedef float HeuristicValue;

template <typename NodeObject>
class A_Asterisco{
    public:
        class Node{
            public:
                Node(){
                    this->heuristicValue = 0;
                };
                Node(Node * father){
                    this->heuristicValue = 0;
                    this->father = father;
                }
                Node(NodeObject nodeObject, Node * father){
                    this->nodeObject = nodeObject;
                    this->heuristicValue = 0;
                    this->father = father;
                };
                
                void createSons(function<vector<NodeObject>(NodeObject &)> createSonsFunction,
                                    function<HeuristicValue(NodeObject &)> heuristicFunction);
                void setHeuristicValue(function<HeuristicValue(NodeObject &)> heuristicFunction);
                void deleteNode();

                vector<Node *> sons;
                NodeObject nodeObject;
                Node * father;
                HeuristicValue heuristicValue;                

        };


        A_Asterisco(function<HeuristicValue(NodeObject &)> heuristicFunction,
                 function<vector<NodeObject>(NodeObject &)> createSonsFunction, 
                 function<bool(Node *, Node *)> heapCompareFunction,
                 function<HashKey(NodeObject *)> hashFunction,
                 function<bool(NodeObject *, NodeObject *)> compareFunction){
                     this->heuristicFunction = heuristicFunction;
                     this->createSonsFunction = createSonsFunction;
                     this->heapCompareFunction = heapCompareFunction;
                     visited = HashTable<NodeObject *>(hashFunction, compareFunction);
                 };

        vector<NodeObject> start(NodeObject initObject, HeuristicValue metaValue);


    private:
        void addSonsToHeap(Node * node);
        void deleteAll();

        Node * root;
        vector<Node *> heapOfNodes;
        HashTable<NodeObject *> visited; 
        function<HeuristicValue(NodeObject &)> heuristicFunction;
        function<vector<NodeObject>(NodeObject &)> createSonsFunction;
        function<bool(Node *, Node *)> heapCompareFunction;

};

template <typename NodeObject>
vector<NodeObject> A_Asterisco<NodeObject>::start(NodeObject initObject, HeuristicValue metaValue){
    root = new Node(initObject, nullptr);
    root->setHeuristicValue(heuristicFunction);
    Node * actualNode = root;
    while(actualNode->heuristicValue != metaValue){
        cout<<"Nodo actual ("<<actualNode->heuristicValue<<"):"<<endl<<endl;
        actualNode->createSons(createSonsFunction, heuristicFunction);
        cout<<endl;
        addSonsToHeap(actualNode);
        pop_heap(heapOfNodes.begin(), heapOfNodes.end(), heapCompareFunction);
        actualNode = heapOfNodes.back();
        heapOfNodes.pop_back();
        visited.insert(&actualNode->nodeObject);
    }
    vector<NodeObject> res;
    while(actualNode != nullptr){
        res.push_back(actualNode->nodeObject);
        actualNode = actualNode->father;
    }
    reverse(res.begin(), res.end());
    deleteAll();
    return res;
}

template <typename NodeObject>
void A_Asterisco<NodeObject>::addSonsToHeap(Node * node){
    for(auto iter = node->sons.begin(); iter != node->sons.end(); ++iter){
        if(!visited.exist(&( (*iter)->nodeObject))){
            heapOfNodes.push_back(*iter);
            push_heap(heapOfNodes.begin(), heapOfNodes.end(), heapCompareFunction);
        }
    }
}

template <typename NodeObject>
void A_Asterisco<NodeObject>::Node::createSons(function<vector<NodeObject>(NodeObject &)> createSonsFunction,
                                                function<HeuristicValue(NodeObject &)> heuristicFunction){
    vector<NodeObject> nodeSons = createSonsFunction(this->nodeObject);
    for(auto iter = nodeSons.begin(); iter != nodeSons.end(); ++iter){
        this->sons.push_back(new Node((*iter), this));
        this->sons.back()->setHeuristicValue(heuristicFunction);
    }
    nodeSons.clear();
    nodeSons.shrink_to_fit();
}

template <typename NodeObject>
void A_Asterisco<NodeObject>::Node::setHeuristicValue(function<HeuristicValue(NodeObject &)> heuristicFunction){
    this->heuristicValue = heuristicFunction(this->nodeObject);
}

template <typename NodeObject>
void A_Asterisco<NodeObject>::Node::deleteNode(){
    for(auto iter = sons.begin(); iter != sons.end(); ++iter){
        (*iter)->deleteNode();
    }
    sons.clear();
    sons.shrink_to_fit();
    delete this;
}

template <typename NodeObject>
void A_Asterisco<NodeObject>::deleteAll(){
    root->deleteNode();
    heapOfNodes.clear();
    heapOfNodes.shrink_to_fit();
    visited.clear();
}




#endif