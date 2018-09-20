#ifndef BLOCK_NODE_FUNCTIONS_H
#define BLOCK_NODE_FUNCTIONS_H

#include <iostream>
#include <vector>
#include "BlockNode.h"

using namespace std;

BlockNode goalNode;

// Heuristic idea from http://www.d.umn.edu/~kvanhorn/cs2511/discussions/heuristics.html
HeuristicValue heuristic(BlockNode & node){
    HeuristicValue res = 0;
    bool casesFlag = false;
    for(int i = 0; i < node.torres.size(); i++){
        //Case 1: Current state has a blank and goal state has a block. 
        if(node.torres[i].empty() and !goalNode.torres[i].empty()){
            res += goalNode.torres[i].size();
        } 
        //Case 2:  Current state has a block and goal state has a blank. 
        else if(!node.torres[i].empty() and goalNode.torres[i].empty()){
            res += node.torres[i].size();
        }        
        else{
            casesFlag = false;
            for(int j = 0; j < node.torres[i].size(); j++){
                // Case 3: The incorrect block must be moved out and the correct blocks must be moved in. Increment the heuristic value by the number of these blocks. 
                if(j == goalNode.torres[i].size() or node.torres[i][j] != goalNode.torres[i][j]){
                    res += node.torres[i].size() - j;
                    res += goalNode.torres[i].size() - j;
                    casesFlag = true;
                    break;
                }
            }
            // Case 4: Increment the heuristic value by the number of incorrect positions above the correct block. 
            if(!casesFlag and node.torres[i].size() < goalNode.torres[i].size()){
                res += goalNode.torres[i].size() - node.torres[i].size();
            }
        }
    }
    node.heuristicValue = res;
    return res;
}

vector<BlockNode> createSons(BlockNode & father){
    father.print();
    vector<BlockNode> res;
    BlockNode tempBlockNode;
    for(int i = 0; i < father.torres.size(); ++i){
        for(int j = 0; j < father.torres.size(); ++j){
            if(i == j) continue;    
            if(father.torres[i].size() == 0) continue;
            tempBlockNode.deleteBlockNode();
            tempBlockNode = father;
            tempBlockNode.changeBlock(i, j);
            res.push_back(tempBlockNode);
            //Here we can write the restrictions too

        }
    }
    tempBlockNode.deleteBlockNode();
    return res;
}

bool heapCompare(A_Asterisco<BlockNode>::Node * a, A_Asterisco<BlockNode>::Node * b){
    return a->heuristicValue > b->heuristicValue;
}

HashKey hashFun(BlockNode * node){
    return node->heuristicValue;
}

bool hashCompare(BlockNode * a, BlockNode * b){
    return (*a) == (*b);
}


#endif