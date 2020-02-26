/*
  The KaiLanguage
  Programming language
  by Kai Lyons
  Under the Apache 2.0 license
*/
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

bool fileExt(string const &filename){
    string ext = ".kai";
    if(filename.length() > ext.length()){
        return (0 == filename.compare (filename.length() - ext.length(), ext.length(), ext));
    } else {
        return false;
    }
}

int main(){
    // Variables are set here:
    string file;
    string filename;

    // This part is temporary (for testing purposes)
    cout << "Enter file name: ";
    cin >> filename;

    // Check File Type
    cout << fileExt(filename) << endl;
    
    // Come back to later:
    /*
    if (){
        cout << "Wrong file type" << endl;
        return 1;
    }
    */

    // Open file
    ifstream kaicode (filename);
    if (kaicode.is_open()){
        while (getline (kaicode, file)){
            cout << file << endl;
        }
    }
}
