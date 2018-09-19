#ifndef BLOCKNODE_H
#define BLOCKNODE_H

#include <iostream>
#include <vector>

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
            
            bool operator(Block other){
                return id == other.id;
            }
        };

        bool operator ==(BlockNode other){
            for(int i = 0; i < torres.size(); i++){
                
            }
        }

    private:
        vector<vector<Block>> torres;
};

#endif