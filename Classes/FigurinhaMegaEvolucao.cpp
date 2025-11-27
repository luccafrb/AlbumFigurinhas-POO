#include "FigurinhaMegaEvolucao.h"

#include <iostream>

FigurinhaMegaEvolucao::FigurinhaMegaEvolucao(int num, string nome, string cont, int status, string estagio, string proximoPokemon, string pedraMega)
    : FigurinhaEvolucao(num, nome, cont, status, estagio, proximoPokemon), pedraMega(pedraMega) {}

FigurinhaMegaEvolucao::~FigurinhaMegaEvolucao() {}

void FigurinhaMegaEvolucao::mostrarDetalhes()
{
    cout << "Detalhes Figurinha " << nome << ":" << endl;

    cout << "Número da página: " << numPag << endl;

    cout << "Status: " << status << endl;

    cout << "Conteudo: " << conteudo;

    cout << "Pedra Mega: " << pedraMega << endl;
}

Figurinha *FigurinhaMegaEvolucao::clone()
{
    return new FigurinhaMegaEvolucao(*this);
}
