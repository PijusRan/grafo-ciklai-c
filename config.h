#ifndef CONFIG_H
#define CONFIG_H

#include "node.h"

Node* readCFG(const char *filename, int *n_ptr, int *c_ptr);
void printHelp(const char *command);
const char *findCFG(int argc, char *argv[]);

#endif