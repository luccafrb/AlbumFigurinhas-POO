#include "FigurinhaPokemon.h"

FigurinhaPokemon::FigurinhaPokemon(int num, string nome, string cont, int status, int nivel, string tipoPrincipal)
    : Figurinha(num, nome, cont, status), nivel(nivel), tipoPrincipal(tipoPrincipal) {}

FigurinhaPokemon::~FigurinhaPokemon()
{
}

Figurinha *FigurinhaPokemon::clone()
{
    return new FigurinhaPokemon(*this);
}

void FigurinhaPokemon::mostrarDetalhes()
{
}
