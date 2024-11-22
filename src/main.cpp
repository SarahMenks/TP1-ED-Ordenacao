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
                case 0:
                    break;
                break;

                case 1:
                    ord.InsertionSort();
                    cout << "Ordenado por nome:" << endl;
                    ord.ImprimeOrdenado();
                break;

                case 2:
                    ord.QuickSort(0, (ord.tamanho_lista-1));
                    cout << "Ordenado por CPF:" << endl;
                    ord.ImprimeOrdenado();
                break;

                case 3:
                    ord.SelectionSort();
                    cout << "Ordenado por endereco:" << endl;
                    ord.ImprimeOrdenado();
                break;

                case 4:
                    ord.ImprimeArquivo();
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