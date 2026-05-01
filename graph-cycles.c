#ifndef GRAPH_CYCLE_H
#define GRAPH_CYCLE_H

#include "node.h"

int isCycle(Node* nodeArr, int *startNode, int currentNode){
    for(int i = 0; i < nodeArr[currentNode].numTo; i++){
        if(nodeArr[currentNode].nodesTo[i] == *startNode) return 1;
        return isCycle(nodeArr, startNode, nodeArr[currentNode].nodesTo[i]);
    }
    return 0;
}

#endif