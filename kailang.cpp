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
            line.erase(remove(line.begin(), line.end(), ' '), line.end());
            // Check to find a "p" keyword (the keyword for print)
            if(line.rfind("p", 0) == 0){
                if(line.find("\"")){
                    line.erase(remove(line.begin(), line.end(), 'p'), line.end());
                    line.erase(remove(line.begin(), line.end(), '\"'), line.end());
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
