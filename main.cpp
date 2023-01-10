#include "parsing.h"
#include <fstream>
#include "classes.cpp"
#include <string>
#include <map>
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;
/*
void mapComments(TreeNode* root) {
    // map each comment to node
    // delete isCommentFlag
    if (root->isComment) {
        root->value = "was Comment";
        root->isComment = false;
    }
    for (int i = 0; i < root->children.size(); i++)
    {
        mapComments(&(root->children[i]));
    }
}
*/
string commentNodeType(TreeNode* root)
{    string type ="";
    if (root->value == "Optional :")
    {
       type = "if";
       return type;
    }
    if (root->value == "One or more time :")// le7ad ma net2aked bas
    {
       type = "for-each";
       return type;
    }
}





string assignPath (TreeNode* root ,std:: map<string,string>paths)
{   TreeNode* child = &(root->children[0]);
    string key = child->value;//to
    string path = paths[key];
    return path;
}

void convertToIf(TreeNode* root)
{
    //for testing assignPath function only
    map<string,string>paths;
    paths["to"]="/Body/to";
    paths["from"]="/Body/from";

    string attribute = "test";
    root->value="xsl:if";
    root->keys.push_back(attribute);
    string path = assignPath(root ,paths);
    root->values.push_back(path);

}
void convertToForEach(TreeNode* root)
{   string attribute = "select";
    root->value ="xsl:for-each";
    root->keys.push_back(attribute);
    root->values.push_back("path");


}

void mapComments(TreeNode* root) {
    // map each comment to node
    // delete isCommentFlag

    if (root->isComment) {
       // root->value = "was Comment";
        string type =commentNodeType(root);
        if(type == "if")
        {convertToIf(root);}
        else if(type== "for-each")
        {convertToForEach(root);}
        root->isComment = false;
    }
    for (int i = 0; i < root->children.size(); i++)
    {
        mapComments(&(root->children[i]));
    }
}





int main()
{
    ifstream MyReadFile("test.txt");

    string myText = "";
    string xmlText = "";
    // Use a while loop together with the getline() function to read the file line by line
    while (getline(MyReadFile, myText)) {
        // Output the text from the file
        xmlText += myText;
    }

    // Close the file
    MyReadFile.close();


    ProcessedFile f = parseXml(xmlText);
    mapComments(&f.tree.root);
    f.print();

    return 0;
}
