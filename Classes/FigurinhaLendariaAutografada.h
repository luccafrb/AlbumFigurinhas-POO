#ifndef FIGURINHA_LENDARIA_AUTOGRAFADA_H
#define FIGURINHA_LENDARIA_AUTOGRAFADA_H

#include "FigurinhaEspecial.h"

class FigurinhaLendariaAutografada : FigurinhaEspecial
{
private:
    string autografo;

public:
    FigurinhaLendariaAutografada(int num, string nome, string cont, int status, string tipo, string autografo);
    ~FigurinhaLendariaAutografada();

    void mostrarDetalhes();
};

#endif