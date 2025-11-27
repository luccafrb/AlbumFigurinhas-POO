#include "FigurinhaPokemon.h"

FigurinhaPokemon::FigurinhaPokemon(int num, string nome, string cont, int status, int nivel, string tipoPrincipal)
    : Figurinha(num, nome, cont, status), nivel(nivel), tipoPrincipal(tipoPrincipal) {}

FigurinhaPokemon::~FigurinhaPokemon()
{
}

void FigurinhaPokemon::mostrarDetalhes()
{
}
