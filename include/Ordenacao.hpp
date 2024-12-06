#ifndef ORD_IND_HPP
#define ORD_IND_HPP

#include "Pessoa.hpp"
#include <iostream>
#include <fstream>
#include <chrono>

struct Ordenacao{

    int tamanho_lista;
    Pessoa *p; 
    int *indices; //indice ordenado das pessoas
    char atributo; //atributo a ser ordenado (nome, cpf ou endereco)

    Ordenacao(std::ifstream &arquivo);
    ~Ordenacao();
    void CriaPessoas(std::ifstream &arquivo);

    void InsertionSort(); 
    
    void QuickSort(int inicio, int fim, std::chrono::steady_clock::time_point start);
    
    void SelectionSort(); 

    void ImprimeArquivo();
    void LocalidadeReferencia();
    void ResetIndices();
    void EscolheAtributo(int atr);
    std::string RetornaChave(int posicao); //retorna qual chave sera ordenada
};

#endif