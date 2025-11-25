#ifndef FIGURINHA_ESPECIAL_H
#define FIGURINHA_ESPECIAL_H

#include "Figurinha.h"

class FigurinhaEspecial : public Figurinha
{
private:
    string tipo;

public:
    FigurinhaEspecial(int num, string nome, string cont, int status, string tipo);
    ~FigurinhaEspecial();

    void mostrarDetalhes();
};

#endif