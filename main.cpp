#include <iostream>
#include <fstream>
#include "Pessoa.hpp"
using namespace std;
int main(){
    ifstream arquivo("entrada.xcsv");
    string teste;
    int teste2;
    Pessoa p;
    if (!(arquivo.is_open())) {
        cout << "Cannot open file" << endl;
    }
    else {
        cout << "Abriu" << endl;
        while(getline(arquivo, teste)) {
            // cout << p.nome << endl;
            // cout << p.cpf << endl;
            // cout << p.endereco << endl;
            // cout << p.outros << endl;
            cout << teste << endl;
            //cout << teste2 << endl;
        }
    }
    return 0;
}