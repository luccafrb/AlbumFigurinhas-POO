#ifndef FIGURINHA_ESTADIO_H
#define FIGURINHA_ESTADIO_H

#include "Figurinha.h"

class FigurinhaEstadio : public Figurinha
{
private:
    string cidade;
    int capacidade;

public:
    FigurinhaEstadio(/* args */);
    ~FigurinhaEstadio();

    void mostrarDetalhes();
};

#endif