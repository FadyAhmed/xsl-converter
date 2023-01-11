#include "classes.cpp"
#include <iostream>
#include <map>

string assignPath(TreeNode *root, std::map<string, string> paths)
{
    TreeNode *child = &(root->children[0]);
    string key = child->value; // to
    string path = paths[key];
    return path;
}

string commentNodeType(TreeNode *root)
{
    string type = "";
    if (root->value == "Optional :")
    {
        type = "if";
        return type;
    }
    if (root->value == "One or more time :") // le7ad ma net2aked bas
    {
        type = "for-each";
        return type;
    }
}

void convertToIf(TreeNode *root)
{
    map<string, string> paths;
    paths["to"] = "/Body/to";
    paths["from"] = "/Body/from";

    string attribute = "test";
    root->value = "xsl:if";
    root->keys.push_back(attribute);
    string path = assignPath(root, paths);
    root->values.push_back(path);
}

void convertToForEach(TreeNode *root)
{
    string attribute = "select";
    root->value = "xsl:for-each";
    root->keys.push_back(attribute);
    root->values.push_back("path");
}

void mapComments(TreeNode *root)
{
    // map each comment to node
    // delete isCommentFlag

    if (root->isComment)
    {
        // root->value = "was Comment";
        string type = commentNodeType(root);
        if (type == "if")
        {
            convertToIf(root);
        }
        else if (type == "for-each")
        {
            convertToForEach(root);
        }
        root->isComment = false;
    }

    for (int i = 0; i < root->children.size(); i++)
    {
        mapComments(&(root->children[i]));
    }
}
