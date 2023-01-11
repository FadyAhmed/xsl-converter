#include "paths.h"

using namespace std;

void assignPaths(TreeNode *root, string parentPath)
{
    if (root->isComment || root->isText)
    {
        root->path = parentPath;
    }
    else
    {
        root->path = parentPath + root->value + "/";
    }
    for (int i = 0; i < root->children.size(); i++)
    {
        assignPaths(&(root->children[i]), root->path);
    }
}

void printPaths(TreeNode *root)
{
    cout << "tag: " << root->value << ", "
         << "Path: " << root->path << "\n";
    for (int i = 0; i < root->children.size(); i++)
    {
        printPaths(&(root->children[i]));
    }
}
