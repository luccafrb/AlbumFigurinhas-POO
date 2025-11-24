#ifndef FIGURINHA_ESPECIAL_H
#define FIGURINHA_ESPECIAL_H

#include "Figurinha.h"

class FigurinhaEspecial : public Figurinha
{
private:
    string tipo;

public:
    FigurinhaEspecial(/* args */);
    ~FigurinhaEspecial();

    void mostrarDetalhes();
};

#endif