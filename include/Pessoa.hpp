#ifndef PESSOA_HPP
#define PESSOA_HPP
#include <iostream>

struct Pessoa{
    std::string nome, cpf, endereco;
    std::string outros;

    void imprimePessoa();
};
#endif