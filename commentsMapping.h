#ifndef COMMENTSMAPPING_H
#define COMMENTSMAPPING_H
#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include "classes.cpp"

using namespace std;

void mapComments(TreeNode* root);
// TODO: should return enum (if, for-each)
// TODO: add pool of comments that indicate to something
string commentNodeType(TreeNode* root);
void convertToIf(TreeNode* root);
void convertToForEach(TreeNode* root);

#endif // COMMENTSMAPPING_H
