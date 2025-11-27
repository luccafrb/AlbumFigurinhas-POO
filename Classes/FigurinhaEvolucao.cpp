#include "FigurinhaEvolucao.h"

#include <iostream>

FigurinhaEvolucao::FigurinhaEvolucao(int num, string nome, string cont, int status, string estagio, string proximoPokemon)
    : Figurinha(num, nome, cont, status), estagio(estagio), proximoPokemon(proximoPokemon) {}

FigurinhaEvolucao::~FigurinhaEvolucao() {}

void FigurinhaEvolucao::mostrarDetalhes()
{
    cout << "Detalhes Figurinha " << nome << ":" << endl;

    cout << "Número da página: " << numPag << endl;

    cout << "Status: " << status << endl;

    cout << "Conteudo: " << conteudo;

    cout << "Estagio: " << estagio << endl;

    cout << "Próximo pokemon: " << proximoPokemon << endl;
}

Figurinha *FigurinhaEvolucao::clone()
{
    return new FigurinhaEvolucao(*this);
}
