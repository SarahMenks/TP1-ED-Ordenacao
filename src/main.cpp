#include "Ordenacao.hpp"
#include <iostream>
#include <fstream>

using namespace std;

int main(){
    //abre o arquivo e cria uma "pessoa"
    ifstream arquivo("entrada.xcsv");

    if (!(arquivo.is_open())){
        cout << "Cannot open file" << endl;
        return 1;
    }
    else {        
        
        cout << "Arquivo normal:" << endl;
        Ordenacao ord(arquivo);

        int opcao;

        do{
            cin >> opcao;

            switch(opcao){
                case 1:
                    ord.OrdenaNome();
                    cout << "Ordenado por nome:" << endl;
                    ord.ImprimeTudo();
                break;

                case 2:
                    ord.OrdenaCPF(0, (ord.tamanho_lista-1));
                    cout << "Ordenado por CPF:" << endl;
                    ord.ImprimeTudo();
                break;

                case 3:
                    ord.OrdenaEndereco();
                    cout << "Ordenado por endereco:" << endl;
                    ord.ImprimeTudo();
                break;

                default:
                    cout << "Opcao invalida" << endl;
                break;
            }
            
        } while(opcao != 0);
        
        //fecha o arquivo
        arquivo.close();
    }
    return 0;
}