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

// Global Variables
string tokens[] = {"f", "p", "fn", "v"};

// Variable Variables
string strVariables[] = {};
string strVarValues[] = {};
int intVariables[] = {};
int intVarValues[] = {};
bool boolVariables[] = {};
bool voolVarValues[] = {};

/********************
 Variable Management
********************/
void createVar(string &line){
    cout << line << endl;
}

/***********************
 Functions for Keywords
***********************/
// Print Token
void pToken(string &line){
    if(line.find("\"")){
        line.erase(remove(line.begin(), line.end(), 'p'), line.end());
        if (line.rfind(" ", 0) == 0){
            line.erase(0,1);
        }
        line.erase(remove(line.begin(), line.end(), '\"'), line.end());
        cout << line << endl;
    }
}

// For Loop Token
void fToken(string &line){
    cout << line << endl;
}

// Variable Token
void vToken(string &line){
    cout << line << endl;
}

/* The Upcoming Function Token
void fnToken(){

}
*/

/***************************************
 Functions that control everything else
***************************************/
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
            // Remove whitespace - Might cause issues
            while (line.rfind(" ", 0) == 0){
                line.erase(0,1);
            }
            // Check to find a "p" keyword (the keyword for print)
            if(line.rfind("p", 0) == 0){
                pToken(line);
            }
            // Check to find a "f" keyword (the keyword for for loops)
            if(line.rfind("f", 0) == 0){ 
                fToken(line);
            }
            // Check to find a "v" keyword (the keyword for variables)
            if(line.rfind("v", 0) == 0){
                vToken(line);
            }
        }
    }
    return 0;
}
