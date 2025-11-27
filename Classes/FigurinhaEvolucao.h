#ifndef FIGURINHA_ECOLUCAO_H
#define FIGURINHA_ECOLUCAO_H

#include "Figurinha.h"

class FigurinhaEvolucao : public Figurinha
{
private:
    string estagio;
    string proximoPokemon;

public:
    FigurinhaEvolucao(int num, string nome, string cont, int status, string estagio, string proximoPokemon);
    ~FigurinhaEvolucao();

    void mostrarDetalhes();
    Figurinha *clone();
};

#endif