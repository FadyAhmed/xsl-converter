#ifndef PATHS_H
#define PATHS_H
#include "classes.cpp"
#include <string>

using namespace std;

void assignPaths(TreeNode *root, string parentPath = "/");
void printPaths(TreeNode *root);

#endif // PATHS_H
