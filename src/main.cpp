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

        int opcao, atributo;

        do{
            cout << "Escolha uma opcao: (1 = Insertion / 2 = Quick / 3 = Selection)" << endl;
            cin >> opcao;

            if(opcao == 0)
                break;
            
            cout<< "Escolha o atributo: (1 = nome / 2 = cpf / 3 = endereco)" << endl;
            cin >> atributo;
            
            ord.EscolheAtributo(atributo);

            switch(opcao){
                case 1:
                    ord.InsertionSort();
                    cout << "Ordenado por nome:" << endl;
                    ord.ImprimeOrdenado();
                break;

                case 2:
                    ord.QuickSort(0, (ord.tamanho_lista-1));
                    cout << "Ordenado pelo Quick:" << endl;
                    ord.ImprimeOrdenado();
                break;

                case 3:
                    ord.SelectionSort();
                    cout << "Ordenado pelo Selection:" << endl;
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