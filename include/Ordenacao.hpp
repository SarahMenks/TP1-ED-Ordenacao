#ifndef ORD_IND_HPP
#define ORD_IND_HPP

#include "Pessoa.hpp"
#include <iostream>
#include <fstream>

struct Ordenacao{

    int tamanho_lista;
    Pessoa *p; 
    int *indices; //indice ordenado das pessoas
    int atributo; //atributo a ser ordenado (nome, cpf ou endereco)

    Ordenacao(std::ifstream &arquivo);
    ~Ordenacao();
    void CriaPessoas(std::ifstream &arquivo);

    void InsertionSort(); 
    
    void QuickSort(int inicio, int fim);
    
    void SelectionSort(); 

    void ImprimeArquivo();
    void ImprimeOrdenado();
    void ResetIndices();
    void EscolheAtributo(int opcao);
    std::string RetornaChave(int posicao); //retorna qual chave sera ordenada
};

#endif