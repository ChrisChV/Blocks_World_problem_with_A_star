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


        HeuristicValue heuristicValue;

    private:
        vector<vector<Block>> torres;
};

#endif