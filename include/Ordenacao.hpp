#ifndef ORD_IND_HPP
#define ORD_IND_HPP

#include "Pessoa.hpp"
#include <iostream>
#include <fstream>

struct Ordenacao{

    int tamanho_lista;
    Pessoa *p; 
    int *indices; //indice ordenado das pessoas

    Ordenacao(std::ifstream &arquivo);
    ~Ordenacao();
    void CriaPessoas(std::ifstream &arquivo);

    void InsertionSort(); 
    
    void QuickSort(int inicio, int fim);
    int media3(int a, int b, int c);
    
    void SelectionSort(); 

    void ImprimeArquivo();
    void ImprimeOrdenado();
    void ResetIndices();
};

#endif