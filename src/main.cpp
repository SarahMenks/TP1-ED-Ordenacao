#include <iostream>
#include <fstream>
#include "Pessoa.hpp"

using namespace std;

int main(){
    //abre o arquivo e cria uma "pessoa"
    ifstream arquivo("entrada.xcsv");

    if (!(arquivo.is_open())){
        cout << "Cannot open file" << endl;
        return 1;
    }
    else {
        cout << "Abriu" << endl;
        int tamanho;

        getline(arquivo, tamanho);

        Pessoa p[5];

        //inicializa variaveis aleatorias que vao ajudar na leitura do arquivo
        string str_temp, nome_temp;
        int int_temp, cpf_temp;
        int i, int_temp, cpf_temp;
    
        
        while(getline(arquivo, nome_temp)) {
            str_temp = "";
            int_temp = 0; 
            
            for(i=0 ; i < nome_temp.size() ; i++){
                if(nome_temp[i] != ',')
                    str_temp += nome_temp[i];
                else
                    break;
            }
            p->nome = str_temp;
            cout << p->nome << endl;

            for( ; i < cpf_temp.size() ; i++){
                if(cpf_temp[i] != ',')
                    int_temp += cpf_temp[i];
                else
                    break;
            }
            p->cpf = int_temp;
            cout << p->cpf << endl;

        }
    }
    return 0;
}