#ifndef FIGURINHA_JOGADOR_H
#define FIGURINHA_JOGADOR_H

#include "Figurinha.h"

class FigurinhaJogador : public Figurinha
{
private:
    string posicao;
    int nivel;

public:
    FigurinhaJogador(/* args */);
    ~FigurinhaJogador();

    void mostrarDetalhes();
};

#endif