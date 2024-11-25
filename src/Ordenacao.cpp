#include "Ordenacao.hpp"

using namespace std;

Ordenacao::Ordenacao(ifstream &arquivo){
        //lê a primeira linha do arquivo que contem o tamanho do vetor de pessoas
        string tamanho_str;

        getline(arquivo, tamanho_str);
        this->tamanho_lista = stoi(tamanho_str, nullptr, 10);
        
        this->indices = new int[this->tamanho_lista];
        ResetIndices();
        
        this->p = new Pessoa[this->tamanho_lista];
        CriaPessoas(arquivo);
}

Ordenacao::~Ordenacao(){
    delete[] indices;
    
    delete[] p;
}

void Ordenacao::CriaPessoas(ifstream &arquivo){
    //inicializa variaveis aleatorias que vao ajudar na leitura do arquivo
    int numPessoa = 0;
    string linha, caracteristica;
    long unsigned int i;

    //lê cada linha do arquivo e separa as caracteristicas de cada pessoa
    while(getline(arquivo, linha)) {            
        caracteristica = "";
        for(i=0 ; i < linha.size() ; i++){
            if(linha[i] != ',')
                caracteristica += linha[i];
            else
                break;
        }
        p[numPessoa].nome = caracteristica;

        caracteristica = "";
        for(i+=1 ; i < linha.size() ; i++){
            if(linha[i] != ','){
                caracteristica += linha[i];
            }
            else
                break;
        }
        p[numPessoa].cpf = caracteristica;

        caracteristica = "";
        for(i+=1 ; i < linha.size() ; i++){
            if(linha[i] != ','){
                caracteristica += linha[i];
            }
            else
                break;
        }
        p[numPessoa].endereco = caracteristica;

        caracteristica = "";
        for(i+=1 ; i < linha.size() ; i++){
            if(linha[i] != ','){
                caracteristica += linha[i];
            }
            else
                break;
        }
        p[numPessoa].outros = caracteristica;

        numPessoa++;
    }

    ImprimeArquivo();
}

void Ordenacao::InsertionSort(){
    int posicao = 0;
    int indice_aux = 0;
    string aux = "";

    for(int i = 1 ; i < this->tamanho_lista ; i++){
        //considera o elemento anterior como ordenado
        indice_aux = indices[i];
        aux = RetornaChave(indice_aux);

        posicao = (i-1);

        //se o elemento i for menor que um elemento anterior, troca os dois
        while(posicao >= 0 && aux < RetornaChave(indices[posicao])){
            this->indices[posicao+1] = indices[posicao];
            posicao--;
        }

        //o loop acima sobrescreve a variavel indices[posicao+1]. É necessário reatribuir o valor
        this->indices[posicao+1] = indice_aux;
    }
}

string media3(string a, string b, string c){
    //media de 3 strings, para o pivo do quicksort
    if(a < b){
        if(b < c) //a b c
            return b;

        else if(a < c) //a c b
            return c;

        else // c a b
            return a; 
    }
    else{
        if(a < c) //b a c
            return a;

        else if(b < c) //b c a
            return c;

        else // c b a
            return b;
    }
}

void Ordenacao::QuickSort(int inicio, int fim){
    if(inicio >= fim)
        return;

    //implementação do quick sort com mediana de 3    
    int esquerda = inicio, direita = fim;

    string pivo = media3(RetornaChave(indices[inicio]), RetornaChave(indices[(inicio+fim)/2]), RetornaChave(indices[fim]));

    while(esquerda <= direita){
        while(RetornaChave(indices[esquerda]) < pivo)
            (esquerda)++;
        
        while(RetornaChave(indices[direita]) > pivo)
            (direita)--;

        if(esquerda <= direita){
            int temp = indices[esquerda];
            indices[esquerda] = indices[direita];
            indices[direita] = temp;
            
            (esquerda)++;
            (direita)--;
        }
    }

    if(inicio < direita)
        QuickSort(inicio, direita);
    
    if(esquerda < fim)
        QuickSort(esquerda, fim);

}

void Ordenacao::SelectionSort(){
    for(int i = 0 ; i < (this->tamanho_lista - 1) ; i++){
        int indice_menor_num = i;

        //busca a posicao do menor numero
        for(int j = (i+1) ; j < this->tamanho_lista ; j++){
            if(RetornaChave(this->indices[j]) < RetornaChave(this->indices[indice_menor_num]))
                indice_menor_num = j;
        }

        //se o menor numero nao for o atual, troca
        if(indice_menor_num != i){
            int temp = indices[i];
            indices[i] = indices[indice_menor_num];
            indices[indice_menor_num] = temp;
        }
    }
}

void Ordenacao::ImprimeArquivo(){
    cout << "Lista de pessoas:" << endl;
    cout << "====================" << endl;
    for(int i = 0 ; i < this->tamanho_lista ; i++){
        this->p[i].imprimePessoa();
    }
}

void Ordenacao::ImprimeOrdenado(){
    cout << "Lista de pessoas ordenada:" << endl;
    cout << "====================" << endl;
    for (int i = 0 ; i < this->tamanho_lista ; i++){
        this->p[indices[i]].imprimePessoa();
    }
}

void Ordenacao::ResetIndices(){
    for(int i = 0 ; i < this->tamanho_lista ; i++)
        this->indices[i] = i;
}

void Ordenacao::EscolheAtributo(int opcao){
    //se o atributo escolhido for invalido, encerra o programa
    try{
        if(opcao < 1 || opcao > 3)
            throw "Atributo invalido";
    }
    catch(const char* msg){
        cerr << msg << endl;
        exit(1);
    }
    
    this->atributo = opcao;
}

string Ordenacao::RetornaChave(int posicao){
    switch(this->atributo){
        case 1:
            return this->p[posicao].nome;
        break;

        case 2:
            return this->p[posicao].cpf;
        break;

        case 3:
            return this->p[posicao].endereco;
        break;
    }

}