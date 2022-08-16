#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main ()
{
    vector<string> STR;
    ifstream infile;

    infile.open ("input1.txt");

    for(size_t i = 0; i < 4; i++){
        string st;
        getline (infile, st);
        STR.push_back(st);
        cout << STR[i] << endl;
    }

    infile.close();

    return 0;
}