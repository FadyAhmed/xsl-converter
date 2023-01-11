#include "parsing.h"
#include <fstream>
#include "classes.cpp"
#include <string>
#include <map>
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

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
{   map<string,string>paths;
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

void assignPaths(TreeNode* root, string parentPath = "/") {

    if(root->isComment){
        root->path = parentPath;
    }else{
            root->path = parentPath + root->value + "/";

    }
    for (int i = 0; i < root->children.size(); i++)
    {
        assignPaths(&(root->children[i]), root->path);
    }
}

void printPaths(TreeNode* root) {
    cout<<"tag: "<<root->value<<", "<<"Path: "<<root->path<<"\n";
    for (int i = 0; i < root->children.size(); i++)
    {
        printPaths(&(root->children[i]));
    }
}

vector<string> parsingCSV (string infile){
     //csv file parsing
  string Text="";
  string txt="";
  ifstream MyFile(infile);
  while (getline (MyFile, Text)) {
   txt += Text;}
   MyFile.close();
   std::stringstream str_strm(txt);
   string tmp;
   vector<string> words;
   char delim = ',';
   while (std::getline(str_strm, tmp, delim)) {
      words.push_back(tmp);
   }
  //
  // for(auto it = words.begin(); it != words.end(); it++) {
     // std::cout << *it << std::endl;
   //}

  return words;

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

    auto words= parsingCSV("sample.csv");
    cout<< words[0];

    ProcessedFile f = parseXml(xmlText);
    assignPaths(&f.tree.root);
    cout<<"-------------------------------------\n";
    printPaths(&f.tree.root);
    mapComments(&f.tree.root);
    f.print();

    return 0;
}
