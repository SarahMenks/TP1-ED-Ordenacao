#include <iostream>
#include <fstream>
#include "Pessoa.hpp"

using namespace std;

int main(){
    ifstream arquivo("entrada.xcsv");
    Pessoa p;
    string temp;
    int i;
    
    if (!(arquivo.is_open())) {
        cout << "Cannot open file" << endl;
        return 1;
    }
    else {
        cout << "Abriu" << endl;
        
        while(getline(arquivo, p.nome)) {
            temp = "";
            for(i=0 ; i < p.nome.size() ; i++){
                if(p.nome[i] != ',')
                    temp += p.nome[i];
                else
                    break;
            }
            
            p.nome = temp;

            for( ; i < p.cpf.size() ; i++){
                if(p.nome[i] != ',')
                    temp += p.nome[i];
                else
                    break;
            }
        }
    }
    return 0;
}