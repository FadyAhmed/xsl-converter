#include "parsing.h"
#include <fstream>
#include "classes.cpp"
#include <string>

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
