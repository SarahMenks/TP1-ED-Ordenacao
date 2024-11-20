#include "Pessoa.hpp"
#include <iostream>
#include <fstream>
using namespace std;

void Pessoa::imprimePessoa(){
    cout << "Nome: " << this->nome << endl;
    cout << "CPF: " << this->cpf << endl;
    cout << "Endereco: " << this->endereco << endl;
    cout << "Outros: " << this->outros << endl;
    cout << "====================" << endl;
}