// =========================================================
// Archivo: main.cpp
// Autores:
//      Aldo Tena García - A01275222
// Fecha: 01/09/2022
// =========================================================

#include <bits/stdc++.h>
#include <iostream>
#include <fstream>

using namespace std;

// Parte 1 - Determinar si existen algunos de los códigos maliciosos en ambos archivos de transmisión
// Complejidad: O(n)
void CodigosMaliciosos(string t1,string t2,string mc1,string mc2,string mc3) {

    //Archivo 1 - transmission1.txt
    cout << "transmission1.txt: " << endl;
    size_t pos = t1.find(mc1);
    if(pos != string::npos){
        cout << "mcode1.txt - true, start at position " << pos << endl;
    }
    else{ 
        cout << "mcode1.txt - false" << endl;
    }
    pos = t1.find(mc2);
    if(pos != string::npos){
        cout << "mcode2.txt - true, start at position " << pos << endl;
    }
    else{
        cout << "mcode2.txt - false" << endl;
    }
    pos = t1.find(mc3);
    if(pos != string::npos){
        cout << "mcode3.txt - true, start at position "<< pos << endl;
    }
    else{
        cout << "mcode3.txt - false" << endl;
    }

    //Archivo 2 - transmission2.txt
    cout << "\ntransmission2.txt: " << endl;
    pos = t2.find(mc1);
    if(pos != string::npos){
        cout << "mcode1.txt - true, start at position " << pos << endl;
    }
    else{ 
        cout << "mcode1.txt - false" << endl;
    }
    pos = t2.find(mc2);
    if(pos != string::npos){
        cout << "mcode2.txt - true, start at position " << pos << endl;
    }
    else{
        cout << "mcode2.txt - false" << endl;
    }
    pos = t2.find(mc3);
    if(pos != string::npos){
        cout << "mcode3.txt - true, start at position "<< pos << endl;
    }
    else{
        cout << "mcode3.txt - false" << endl;
    }
}

int main() {
    //Declaracion de variables de tipo string
    string t1 = "", t2 = "", mc1 = "", mc2 = "", mc3 = "";
    string l1,l2,l3,l4,l5;
    ifstream txt1("transmission1.txt"), txt2("transmission2.txt"), txt3("mcode1.txt"), txt4("mcode2.txt"), txt5("mcode3.txt");
    //Lectura de archivos txt y almacenamiento de información
    while(getline(txt1, l1)){
        t1 = t1 + l1;
    }
    while(getline(txt2, l2)){
        t2 = t2 + l2;
    }
    while(getline(txt3, l3)){
        mc1 = mc1 + l3;
    }
    while(getline(txt4, l4)){
        mc2 = mc2 + l4;
    }
    while(getline(txt5, l5)){
        mc3 = mc3 + l5;
    }

    CodigosMaliciosos(t1,t2,mc1,mc2,mc3);
}