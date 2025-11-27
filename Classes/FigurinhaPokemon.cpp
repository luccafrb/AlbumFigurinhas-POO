#include "FigurinhaPokemon.h"

#include <iostream>

FigurinhaPokemon::FigurinhaPokemon(int num, string nome, string cont, int status, int nivel, string tipoPrincipal)
    : Figurinha(num, nome, cont, status), nivel(nivel), tipoPrincipal(tipoPrincipal) {}

FigurinhaPokemon::~FigurinhaPokemon() {}

Figurinha *FigurinhaPokemon::clone()
{
    return new FigurinhaPokemon(*this);
}

void FigurinhaPokemon::mostrarDetalhes()
{
    cout << "Detalhes Figurinha " << nome << ":" << endl;

    cout << "Número da página: " << numPag << endl;

    cout << "Status: " << status << endl;

    cout << "Conteudo: " << conteudo;

    cout << "Tipo Principal: " << tipoPrincipal << endl;

    cout << "Nivel: " << nivel << endl;
}
