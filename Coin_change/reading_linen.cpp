#include <iostream>
#include <fstream>
#include <limits>
#include <string>
#include <vector>

using namespace std;

fstream& GotoLine(fstream& file, unsigned int num){
    file.seekg(ios::beg);
    for(int i=0; i < num - 1; ++i){
        file.ignore(numeric_limits<streamsize>::max(),'\n');
    }
    return file;
}

int main(){
    vector<string> STR;
    fstream file("input1.txt");
    GotoLine(file, 4);
    string st;
    getline(file, st);
    STR.push_back(st);
    cout << STR[0] << endl;
    return 0;
}