#include "parsing.h"
#include "commentsMapping.h"
#include <fstream>
#include "classes.cpp"
#include <string>
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

void assignPaths(TreeNode *root, string parentPath = "/")
{

    if (root->isComment)
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

int main()
{
    ifstream MyReadFile("test.txt");

    string myText = "";
    string xmlText = "";
    // Use a while loop together with the getline() function to read the file line by line
    while (getline(MyReadFile, myText))
    {
        // Output the text from the file
        xmlText += myText;
    }

    // Close the file
    MyReadFile.close();

    ProcessedFile f = parseXml(xmlText);
    assignPaths(&f.tree.root);
    cout << "-------------------------------------\n";
    printPaths(&f.tree.root);
    mapComments(&f.tree.root);
    f.print();

    return 0;
}
