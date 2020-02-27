/*
  The KaiLanguage
  Programming language
  by Kai Lyons
  Under the Apache 2.0 license
*/
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
using namespace std;

// This section deals with string whitespace
// ---------------------------------------------------------
const string whiteSpace =" \n\r\t\f\v";

string itrim(string const &str){
    size_t start = str.find_first_not_of(whiteSpace);
    return (start == string::npos) ? "" : str.substr(start);
}

string ttrim(string const &str){
    size_t finish = str.find_last_not_of(whiteSpace);
    return (finish == string::npos) ? "" : str.substr(finish);
}

string trim(const string &str){
    return ttrim(itrim(str));
}
// ---------------------------------------------------------

// Find the extention of the file
bool fileExt(string const &filename){
    string ext = ".kai";
    if(filename.length() > ext.length()){
        return (0 == filename.compare(filename.length() - ext.length(), ext.length(), ext));
    } else {
        return false;
    }
}

int main(){
    // Variables are set here:
    string line;
    string filename;
    // This part is temporary (for testing purposes)
    cout << "Enter file name: ";
    cin >> filename;

    // Check File Type
    if (!fileExt(filename)){
        cout << "Wrong file type" << endl;
        return 1;
    } else {
        cout << "Correct File : " << fileExt(filename) << endl;
    }

    // Open file
    ifstream kaicode (filename);
    if (kaicode.is_open()){
        while (getline (kaicode, line)){
            trim(line);
            // line.erase(remove(line.begin(), line.begin(), ' '), line.begin());
            // Check to find a "p" keyword (the keyword for print)
            if(line.rfind("p", 0) == 0){
                if(line.find("\"")){
                    line.erase(remove(line.begin(), line.end(), 'p'), line.end());
                    trim(line);
                    line.erase(remove(line.begin(), line.end(), '\"'), line.end());
                    trim(line);
                    cout << line << endl;
                }
            } else {
                cout << "";
            }
            // Check to find a "f" keyword (the keyword for for loops)
            if(line.rfind("f", 0) == 0){ 
                cout << "found \"f\" keyword" << endl;
            } else {
                cout << "";
            }
        }
    }
    return 0;
}
