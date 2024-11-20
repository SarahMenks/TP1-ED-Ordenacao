#ifndef ORD_IND_HPP
#define ORD_IND_HPP

#include "Pessoa.hpp"
#include <iostream>
#include <fstream>

struct Ordenacao{

    int tamanho_lista;
    Pessoa *p;

    Ordenacao(std::ifstream &arquivo);
    ~Ordenacao();
    void CriaPessoas(std::ifstream &arquivo);

    void OrdenaNome(); //Insertion
    
    void OrdenaCPF(int inicio, int fim); //Quick
    int media3(int a, int b, int c);
    
    void OrdenaEndereco(); //Selection

    void ImprimeTudo();
};

#endif