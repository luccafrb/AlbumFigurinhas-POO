#ifndef FIGURINHA_JOGADOR_H
#define FIGURINHA_JOGADOR_H

#include "Figurinha.h"

class FigurinhaJogador : public Figurinha
{
private:
    string posicao;
    int nivel;

public:
    FigurinhaJogador(int num, string nome, string cont, int status, int nivel);
    ~FigurinhaJogador();

    void mostrarDetalhes();
};

#endif