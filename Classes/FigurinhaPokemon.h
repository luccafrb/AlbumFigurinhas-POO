#ifndef FIGURINHA_POKEMON_H
#define FIGURINHA_POKEMON_H

#include "Figurinha.h"

class FigurinhaPokemon : public Figurinha
{
private:
    string tipoPrincipal;
    int nivel;

public:
    FigurinhaPokemon(int num, string nome, string cont, int status, int nivel);
    ~FigurinhaPokemon();

    void mostrarDetalhes();
};

#endif