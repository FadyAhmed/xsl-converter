#ifndef PATHS_H
#define PATHS_H
#include "classes.cpp"
#include <string>
#include <map>

using namespace std;

void assignPaths(TreeNode *root, string parentPath = "/");
void printPaths(TreeNode *root);
map<string, string> mappingPaths (vector<string> paths);
map<string, vector<string>> mappingPathsjson (vector<string> paths);
#endif // PATHS_H
