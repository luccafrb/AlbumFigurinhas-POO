#ifndef FIGURINHA_ESTADIO_H
#define FIGURINHA_ESTADIO_H

#include "Figurinha.h"

class FigurinhaEstadio : public Figurinha
{
private:
    string cidade;
    int capacidade;

public:
    FigurinhaEstadio(int num, string nome, string cont, int status, string tipo, string cidade, int capacidade);
    ~FigurinhaEstadio();

    void mostrarDetalhes();
};

#endif