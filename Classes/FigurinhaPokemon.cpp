#include "FigurinhaPokemon.h"

FigurinhaPokemon::FigurinhaPokemon(int num, string nome, string cont, int status, int nivel)
    : Figurinha(num, nome, cont, status), nivel(nivel) {}

FigurinhaPokemon::~FigurinhaPokemon()
{
}

void FigurinhaPokemon::mostrarDetalhes()
{
}
