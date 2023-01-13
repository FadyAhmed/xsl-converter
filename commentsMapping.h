#ifndef COMMENTSMAPPING_H
#define COMMENTSMAPPING_H
#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <map>
#include "classes.cpp"

using namespace std;

void mapComments(TreeNode *root, map<string,string> paths);
// TODO: should return enum (if, for-each)
// TODO: add pool of comments that indicate to something
string commentNodeType(TreeNode *root);
void convertToIf(TreeNode *root,map<string, string> paths);
void convertToForEach(TreeNode *root);
void convertToSelect(TreeNode *root,map<string,string> paths);
void mapText(TreeNode *root, map<string,string>paths);
#endif // COMMENTSMAPPING_H
