#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "node.h"
#include "config.h"

void clean(Node* nodeArr, int n){
    for(int i = 0; i < n; i++){
        free(nodeArr[i].nodesTo);
    }
    free(nodeArr);
    return;
}

Node* readCFG(const char *filename, int *n_ptr, int *c_ptr) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Nepavyko atidaryti failo");
        return NULL;
    }

    int n, c;
    if (fscanf(file, "%d %d", &n, &c) != 2) {
        fprintf(stderr, "Klaida: Nepavyko perskaityti n ir c.\n");
        fclose(file);
        return NULL;
    }

    /* Allocate and zero-initialise the node array */
    Node* nodeArr = malloc(sizeof(Node)*(n + 1));
    if (nodeArr == NULL) {
        fprintf(stderr, "Klaida: Nepakanka atminties.\n");
        fclose(file);
        return NULL;
    }

    /* Read c edges */
    for (int i = 0; i < c; i++) {
        int a, b;
        if (fscanf(file, "%d %d", &a, &b) != 2) {
            fprintf(stderr, "Klaida: Nepavyko perskaityti %d-osios jungties.\n", i + 1);
            clean(nodeArr, n);
            return NULL;
        }

        if (a < 0 || a > n || b < 0 || b > n) {
            fprintf(stderr, "Klaida: Mazgo indeksas uz intervalo [0, %d): %d %d\n", n, a, b);
            clean(nodeArr, n);
            return NULL;
        }
        
        //Sujungimai
        nodeArr[a].nodesTo[nodeArr[a].numTo] = b;
        nodeArr[a].numTo++;
    }

    fclose(file);

    if (n_ptr) *n_ptr = n;
    if (c_ptr) *c_ptr = c;
    return nodeArr;
}

void printHelp(const char *command) {
    printf("Naudojimas: %s <failas.cfg> [parinktys]\n\n", command);
    printf("Argumentai:\n");
    printf("  <failas.cfg>        Grafą aprašantis konfigūracijos failas (privaloma).\n");
    printf("Parinktys:\n");
    printf("  -h, --help          Rodo šį pagalbos pranešimą.\n\n");
    printf("Pavyzdys:\n");
    printf("  %s grafas.cfg\n", command);
}

const char *findCFG(int argc, char *argv[]) {
    for (int i = 1; i < argc; i++) {
        char *extension = strrchr(argv[i], '.');
        if (extension != NULL && strcmp(extension, ".cfg") == 0) {
            return argv[i];
        }
    }
    fprintf(stderr, "Klaida: Nepavyko rasti .cfg failo parametruose.\n");
    printHelp(argv[0]);
    exit(0);
}

