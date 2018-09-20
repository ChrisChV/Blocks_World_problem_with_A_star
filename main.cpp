#include <iostream>
#include "A_asterisco.h"
#include "BlockNodeFunctions.h"

using namespace std;


int main(int argc, char ** argv){
    if(argc != 3){
        cout<<"Faltan argumentos <fileOfInitBlock> <fileOfGoalBlock>"<<endl;
        return 1;
    }
    string fileOfInitBlockName(argv[1]);
    string fileOfGoalBlockName(argv[2]);
    BlockNode initBlock(fileOfInitBlockName);
    BlockNode goalBlock(fileOfGoalBlockName);
    if(initBlock.numOfBlocks != goalBlock.numOfBlocks){
        cout<<"El número de bloques entre el inicial y el final no coincide"<<endl;
        return 2;
    }
    if(initBlock.torres.size() != goalBlock.torres.size()){
        cout<<"El número de torres entre el inicial y el final no coincide"<<endl;
        return 3;
    }
    goalNode = goalBlock;
    A_Asterisco<BlockNode> Aa(heuristic, createSons, heapCompare, hashFun, hashCompare);
    vector<BlockNode> res = Aa.start(initBlock, 0);

    cout<<endl<<endl;
    cout<<"--------Solución-------"<<endl;
    for(BlockNode node : res){
        cout<<endl;
        node.print();
        cout<<endl;
    }
    
    return 0;
}
