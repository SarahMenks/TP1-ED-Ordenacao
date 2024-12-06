#include "Ordenacao.hpp"
#include <iostream>
#include <fstream>
#include <chrono>

using namespace std;

void parse_args(int argc,char *argv[]){
    //argc deve receber o nome do arquivo xcvs
    if(argc < 2){
        cout << "Faltam argumentos" << endl;
        exit(1);
    }
    if(argc > 2){
        cout << "Argumentos a mais" << endl;
        exit(1);
    }
}

int main(int argc, char *argv[]){

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

        // for(int i = 0 ; i < 3 ; i++){
            ord.EscolheAtributo(1);
            // ord.InsertionSort();
             
        //}

        // for(int i = 0 ; i < 3 ; i++){
        //     ord.EscolheAtributo(i);
            auto start = std::chrono::steady_clock::now();
             ord.QuickSort(0, (ord.tamanho_lista-1),start);
            auto end = std::chrono::steady_clock::now();  
            auto time = (end - start);
            cout << time.count() << endl; 
        // }
        // for(int i = 0 ; i < 3 ; i++){
        //     ord.EscolheAtributo(i);
                //ord.SelectionSort();
        // }

        // ord.ImprimeArquivo();
    }
                
    //fecha o arquivo
    arquivo.close();
    return 0;
}