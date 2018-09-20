#ifndef BLOCKNODE_H
#define BLOCKNODE_H

#include <iostream>
#include <vector>
#include "A_asterisco.h"

using namespace std;

typedef int BlockId;

class BlockNode{
    public:
        class Block{
            Block(BlockId id){
                this->id = id;
            }
            public:
                BlockId id;
            
                bool operator ==(Block other){
                    return id == other.id;
                }
                bool operator !=(Block other){
                    return id != other.id;
                }
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

        void deleteBlockNode();
        void changeBlock(int sourceTorre, int destTorre);

        HeuristicValue heuristicValue;
        vector<vector<Block>> torres;
};


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

#endif