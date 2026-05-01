#include <stdlib.h>
#include <stdio.h>

#include "node.h"
#include "config.h"
#include "graph-cycles.h"

void printGraph(Node* nodeArr, int n){
    for(int i = 1; i <= n; i++){
        for(int j = 0; j < nodeArr[i].numTo; j++){
            printf("%d -> %d\n", i, nodeArr[i].nodesTo[j]);
        }
    }
}

int main(int argc, char *argv[]) {
    int n, c;
    Node* nodeArr = readCFG(findCFG(argc, argv), &n, &c);

    printf("\n=== PRADINIAI DUOMENYS ===\n");
    printf("n = %d, c = %d\n", n, c);
    printf("Grafas:\n");
    printGraph(nodeArr, n);

    printf("\n=== REZULTATAI ===\n");
    for(int i = 1; i <= n; i++){
        int cycle = isCycle(nodeArr, &i, i);
        if(cycle){
            printf("Grafas turi ciklą (-ų).\n");
            return 0;
        }
    }

    printf("Grafas neturi ciklų.\n");
    return 0;
}