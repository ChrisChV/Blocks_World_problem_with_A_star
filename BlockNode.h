#ifndef BLOCKNODE_H
#define BLOCKNODE_H

#include <iostream>
#include <vector>
#include <fstream>
#include "A_asterisco.h"

using namespace std;

typedef int BlockId;

const string END_OF_TOWER = "x";

class BlockNode{
    public:
        class Block{
            public:
                Block(BlockId id){
                   this->id = id;
                }
                bool operator ==(Block other){
                    return id == other.id;
                }
                bool operator !=(Block other){
                    return id != other.id;
                }

                BlockId id;
        };

        bool operator ==(BlockNode other){
            for(int i = 0; i < torres.size(); i++){
                if(torres[i].size() != other.torres[i].size()) return false;
                for(int j = 0; j < torres[i].size(); j++){
                    if(torres[i][j] != other.torres[i][j]) return false;
                }
            }
            return true;
        }

        BlockNode(){heuristicValue = 0; numOfBlocks = 0;};
        BlockNode(string fileName);

        void deleteBlockNode();
        void changeBlock(int sourceTorre, int destTorre);
        void print();

        HeuristicValue heuristicValue;
        vector<vector<Block>> torres;
        int numOfBlocks;
};


BlockNode::BlockNode(string fileName){
    ifstream file(fileName);
    numOfBlocks = 0;
    string temp = "";
    vector<Block> tempTower;
    while(file >> temp){
        if(temp == END_OF_TOWER){
            torres.push_back(tempTower);
            tempTower.clear();
            tempTower.shrink_to_fit();
            continue;
        }
        tempTower.push_back(Block(stoi(temp)));
        numOfBlocks++;
    }
    file.close();
}

void BlockNode::deleteBlockNode(){
    for(auto iter = torres.begin(); iter != torres.end(); ++iter){
        iter->clear();
        iter->shrink_to_fit();
    }
    torres.clear();
    torres.shrink_to_fit();
}

void BlockNode::changeBlock(int sourceTorre, int destTorre){
    Block tempBlock = torres[sourceTorre].back();
    torres[sourceTorre].pop_back();
    torres[destTorre].push_back(tempBlock);
}

void BlockNode::print(){
    for(auto iter = torres.begin(); iter != torres.end(); ++iter){
        for(auto iter2 = iter->begin(); iter2 != iter->end(); ++iter2){
            cout<<iter2->id<<" ";
        }
        cout<<endl;
    }
}

#endif