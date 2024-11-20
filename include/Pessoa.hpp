#ifndef PESSOA_HPP
#define PESSOA_HPP
#include <iostream>

struct Pessoa{
    std::string nome;
    int cpf;
    std::string endereco;
    std::string outros;
    Pessoa();
};
#endif