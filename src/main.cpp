#include "Ordenacao.hpp"
#include <iostream>
#include <fstream>

using namespace std;

void parse_args(int argc,char *argv[]){
    //argc deve receber o nome do arquivo xcvs, a opcao de ordenacao e o atributo a ser ordenado
    if(argc < 4){
        cout << "Faltam argumentos" << endl;
        exit(1);
    }
    if(argc > 4){
        cout << "Argumentos a mais" << endl;
        exit(1);
    }

    //se o atributo escolhido for invalido, encerra o programa
    try{
        if(*argv[2] != 'n' && *argv[2] != 'c' && *argv[2] != 'e')
            throw "Atributo invalido";
    }
    catch(const char* msg){
        cerr << msg << endl;
        exit(1);
    }

    try{
        if(*argv[3] != 'q' && *argv[3] != 'i' && *argv[2] != 's' && *argv[2] != 'p')
            throw "Algoritmo de ordenação invalido";
    }
    catch(const char* msg){
        cerr << msg << endl;
        exit(1);
    }
}

int main(int argc, char *argv[]){
    //argv[1] é o nome do arquivo, argv[2] é o atributo a ser ordenado, argv[3] é a opção de ordenação

    //confere a entrada
    parse_args(argc, argv);

    //abre o arquivo e cria uma "pessoa"
    ifstream arquivo(argv[1]);

    if (!(arquivo.is_open())){
        cout << "Cannot open file" << endl;
        exit(1);
    }
    else {        
        
        Ordenacao ord(arquivo);
        //cout << "Arquivo normal:" << endl;
        //ord.ImprimeArquivo();
        
        ord.EscolheAtributo(*argv[2]);

        switch(*argv[3]){
            case 'i':
                ord.InsertionSort();
            break;

            case 'q':
                ord.QuickSort(0, (ord.tamanho_lista-1));
            break;

            case 's':
                ord.SelectionSort();
            break;

            case 'p':
                ord.ImprimeArquivo();
            break;

            default:
                cout << "Opcao invalida" << endl;
            break;
        }
                    
        //fecha o arquivo
        arquivo.close();
    }
    return 0;
}