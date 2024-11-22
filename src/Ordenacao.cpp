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
        p[numPessoa].cpf = stoi(caracteristica, nullptr, 10);

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
    int posicao;
    string nome_aux;
    int aux;

    for(int i = 1 ; i < this->tamanho_lista ; i++){
        //considera o elemento anterior como ordenado
        aux = this->indices[i];
        nome_aux = this->p[indices[i]].nome;
        posicao = (i-1);

        //se o elemento i for menor que um elemento anterior, troca os dois
        while(posicao >= 0 && nome_aux < this->p[indices[posicao]].nome){
            this->indices[posicao+1] = indices[posicao];
            
            posicao--;
        }

        //o loop acima sobrescreve a variavel indices[posicao+1]. É necessário reatribuir o valor
        this->indices[posicao+1] = aux;
    }
}

void Ordenacao::QuickSort(int inicio, int fim){
    if(inicio >= fim)
        return;

    //implementação do quick sort com mediana de 3    
    int esquerda = inicio, direita = fim;

    int pivo = media3(p[indices[inicio]].cpf, p[indices[(inicio+fim)/2]].cpf, p[indices[fim]].cpf);

    while(esquerda <= direita){
        while(p[indices[esquerda]].cpf < pivo)
            (esquerda)++;
        
        while(p[indices[direita]].cpf > pivo)
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

int Ordenacao::media3(int a, int b, int c){
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

void Ordenacao::SelectionSort(){
    for(int i = 0 ; i < (this->tamanho_lista - 1) ; i++){
        int indice_menor_num = i;

        //busca a posicao do menor numero
        for(int j = (i+1) ; j < this->tamanho_lista ; j++){
            if(p[indices[j]].endereco < p[indices[indice_menor_num]].endereco)
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