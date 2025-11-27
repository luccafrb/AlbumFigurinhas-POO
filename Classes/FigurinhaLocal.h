#ifndef FIGURINHA_LOCAL_H
#define FIGURINHA_LOCAL_H

#include "Figurinha.h"

class FigurinhaLocal : public Figurinha
{
private:
    string regiao;
    string liderGinasio;

public:
    FigurinhaLocal(int num, string nome, string cont, int status, string tipo, string regiao, string liderGinasio);
    ~FigurinhaLocal();

    void mostrarDetalhes();
    Figurinha *clone();
};

#endif