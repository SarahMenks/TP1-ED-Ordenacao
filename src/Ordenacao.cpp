#include "Ordenacao.hpp"

using namespace std;

Ordenacao::Ordenacao(ifstream &arquivo){
        //lê a primeira linha do arquivo que contem o tamanho do vetor de pessoas
        string tamanho_str;

        getline(arquivo, tamanho_str);
        this->tamanho_lista = stoi(tamanho_str, nullptr, 10);

        this->p = new Pessoa[this->tamanho_lista];
        CriaPessoas(arquivo);
}

Ordenacao::~Ordenacao(){
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

    ImprimeTudo();
}

void Ordenacao::OrdenaNome(){
    //implementação do insertionsort
    int indice;
    string nome_aux;
    Pessoa aux;

    for(int i = 1 ; i < this->tamanho_lista ; i++){
        //considera o elemento anterior como ordenado
        aux = this->p[i];
        nome_aux = this->p[i].nome;
        indice = (i-1);

        //se o elemento i for menor que um elemento anterior, troca os dois
        while(indice >= 0 && nome_aux < this->p[indice].nome){
            this->p[indice+1] = this->p[indice];
            
            indice--;
        }

        //o loop acima sobrescreve a variavel p[indice+1]. É necessário reatribuir o valor
        this->p[indice+1] = aux;
    }
}

void Ordenacao::OrdenaCPF(int inicio, int fim){
    if(inicio >= fim)
        return;

    //implementação do quick sort com mediana de 3
    
    int esquerda = inicio, direita = fim;

    int pivo = media3(p[inicio].cpf, p[(inicio+fim)/2].cpf, p[fim].cpf);

    while(esquerda <= direita){
        while(p[esquerda].cpf < pivo)
            (esquerda)++;
        
        while(p[direita].cpf > pivo)
            (direita)--;

        if(esquerda <= direita){
            Pessoa temp = p[esquerda];
            p[esquerda] = p[direita];
            p[direita] = temp;
            
            (esquerda)++;
            (direita)--;
        }
    }

    if(inicio < direita)
        OrdenaCPF(inicio, direita);
    
    if(esquerda < fim)
        OrdenaCPF(esquerda, fim);

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

void Ordenacao::OrdenaEndereco(){

    //implementação do selection sort
    for(int i = 0 ; i < (this->tamanho_lista - 1) ; i++){
        int indice_menor_num = i;

        //busca a posicao do menor numero
        for(int j = (i+1) ; j < this->tamanho_lista ; j++){
            if(p[j].endereco < p[indice_menor_num].endereco)
                indice_menor_num = j;
        }

        //troca os valores
        if(indice_menor_num != i){
            Pessoa temp = p[i];
            p[i] = p[indice_menor_num];
            p[indice_menor_num] = temp;
        }
    }
}

void Ordenacao::ImprimeTudo(){
    cout << "====================" << endl;
    for (int j = 0; j < this->tamanho_lista; j++) {
        this->p[j].imprimePessoa();
    }
}
