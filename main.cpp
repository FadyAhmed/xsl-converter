#include "parsing.h"
#include "commentsMapping.h"
#include <fstream>
#include "classes.cpp"
#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include "paths.h"

using namespace std;

 //Template for overloading insertion operator to print map
 template <typename key, typename value>
ostream &operator<<(ostream &stream, const map<key, value> &myMap)
{
    for(const pair<key, value> &t: myMap)
    {
        stream << t.first<<" "<<t.second[0] <<" "<<t.second[1] <<" "<<endl;
    }
    return stream;
}

/*
void xmlTestbench (string inputxmlfileName , string inputcsvpaths){
    ifstream MyReadFile(inputxmlfileName);
    string myText = "";
    string xmlText = "";

    while (getline(MyReadFile, myText))
    {
        xmlText += myText;
    }
    MyReadFile.close();

    vector<string> words= parsingCSV(inputcsvpaths);
    ProcessedFile f = parseXml(xmlText);
    assignPaths(&f.tree.root);
    cout << "---------------paths----------------------\n";
    printPaths(&f.tree.root);
    map<string,string> m;
    m= mappingPaths(words);
    cout<<"----------printing map------------\n";
    cout << m;
    cout<<"----------------------------------\n";
    mapComments(&f.tree.root,m);
    mapText(&f.tree.root,m);
    f.print();
}*/

void jsonTestbench (string inputxmlfileName , string inputcsvpaths){
    ifstream MyReadFile(inputxmlfileName);
    string myText = "";
    string xmlText = "";
    // Use a while loop together with the getline() function to read the file line by line
    while (getline(MyReadFile, myText))
    {// Output the text from the file
        xmlText += myText;
    }
    // Close the file
    MyReadFile.close();

    auto words= parsingCSV(inputcsvpaths);

    ProcessedFile f = parseXml(xmlText);
    assignPaths(&f.tree.root);
    cout << "-------------------------------------\n";
    printPaths(&f.tree.root);
    map<string, vector<string>> m;
    m= mappingPathsjson(words);
    cout<<"------------";
    cout << m;
    //mapComments(&f.tree.root,m);
    //mapText(&f.tree.root,m);
   // f.print();
}

int main()
{
    //xmlTestbench ("test.txt" , "sampleXml.csv");
    jsonTestbench ("test.txt" , "sampleJson.csv");

    return 0;
}
