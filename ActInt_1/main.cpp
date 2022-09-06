// =========================================================
// Archivo: main.cpp
// Autores:
//      Aldo Tena García - A01275222
//      Renato Sebastían Ramirez Calva - A01275401
// Fecha: 01/09/2022
// =========================================================

#include <bits/stdc++.h>
#include <iostream>
#include <fstream>

using namespace std;

// Parte 1 - Determinar si existen algunos de los códigos maliciosos en ambos archivos de transmisión
// Complejidad: O(n)
void CodigosMaliciosos(string t1,string t2,string mc1,string mc2,string mc3){

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

// Parte 2 - Códigos maliciosos nuevos en formato "espejeado" (o palídromos)
// Complejidad: O(n)

string x(string text){
    string z;
    for(int i = 0; i < text.size(); i++){
        if(text[i] != ' '){
            z += "#";  
            z += text[i];
        }
    }
    z += "#";
    return z;
}

void Encontrar(string text){
    string k = x(text);
    int a, b, c, d, e, f, p[k.length()];
    b = c = 0;
    for(a = 0; a < k.length(); a++) {
        d = b - (a - b);
        if(c > a){
            p[a] = min(c - a, p[d]);
        }
        else{ 
            p[a] = 0;
        }
        while(k[a + 1 + p[a]] == k[a - 1 - p[a]]){
            p[a]++;
        }
        if(a + p[a] > c){
            b = a; 
            c = a + p[a];
        }
    }
    e = f = 0;
    for(a = 1; a < k.length(); a++){
        if(p[a] > e){
            e = p[a]; 
            f = a;
        }
    }
    int sum = (f - e)/2;
    cout << "mirrored code found, start at " << sum << ", ended at " << e + sum << endl;
}

void Desconocidos(string t1,string t2){
    cout << "\ntransmission1.txt:" << endl;
    Encontrar(t1);
    cout << "\ntransmission2.txt:" << endl;
    Encontrar(t2);
}


// Parte 3 - Subcadena común más larga entre ambos archivos
// Complejidad: O(nlogn)

void Subcadena(string t1,string t2){
    int x = t1.size(), y = t2.size(), z[x + 1][y + 1];
    for(int i = 0; i <= x; i++) {
        for(int j = 0; j <= y; j++) {
            if(i == 0 || j == 0) {
                z[i][j] = 0;
            }
            else if(t1[i - 1] == t2[j -1]) {
                z[i][j] = z[i -1][j -1] + 1;
            }
            else {
                z[i][j] = max(z[i - 1][j], z[i][j - 1]);
            }
        }
    }
    cout << "\nthe longest common substring between transmission1.txt and transmission2.txt is " << z[x][y] << " characters long" << endl;
}

int main(){

    // Función Main
    // Complejidad: O(n)

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

    //Llamado a funciones
    //Parte 1
    CodigosMaliciosos(t1,t2,mc1,mc2,mc3);
    //Parte 2
    Desconocidos(t1,t2);
    //Parte 3
    Subcadena(t1,t2);

    return 0;
}