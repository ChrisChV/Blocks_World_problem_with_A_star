#ifndef BLOCK_NODE_FUNCTIONS_H
#define BLOCK_NODE_FUNCTIONS_H

#include <iostream>
#include <vector>
#include "BlockNode.h"

using namespace std;

HeuristicValue heuristic(BlockNode & node){
    HeuristicValue res = 0;

    /*
    TODO
    */

   node.heuristicValue = res;
   return res;
}

vector<BlockNode> createSons(BlockNode & father){

}

bool heapCompare(A_Asterisco<BlockNode>::Node * a, A_Asterisco<BlockNode>::Node * b){
   
}

bool restrictions(BlockNode & node){
    return true;
}

HashKey hashFun(BlockNode * node){
    
}

bool hashCompare(BlockNode * a, BlockNode * b){
    return (*a) == (*b);
}


#endif