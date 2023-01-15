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

map<string, string> mappingPaths (vector<string> paths){
    map<string,string> m;
     for(int i=0;i<paths.size();i+=2) {
            m[paths[i+1]]=paths[i];
    }
    return m;
}

map<string, vector<string>> mappingPathsjson (vector<string> paths){
    map<string,vector<string>>  m;
     for(int i=0;i<paths.size();i+=3) {
            m[paths[i+1]]={paths[i],paths[i+2]};
    }
    return m;
}

