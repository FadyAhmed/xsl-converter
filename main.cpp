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
    while (getline(MyReadFile, myText))
    {
        // Output the text from the file
        xmlText += myText;
    }

    // Close the file
    MyReadFile.close();

    auto words= parsingCSV("sample.csv");
    cout<< words[0];

    ProcessedFile f = parseXml(xmlText);
    assignPaths(&f.tree.root);
    cout << "-------------------------------------\n";
    printPaths(&f.tree.root);
    mapComments(&f.tree.root);
    f.print();

    return 0;
}
