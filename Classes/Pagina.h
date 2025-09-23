#pragma once
#include <string>
#include "Figurinha.h"

#define MAX_FIGURINHAS 30

class Pagina
{
private:
    Figurinha figurinhas[MAX_FIGURINHAS];
    string titulo;
    int numMin, numMax;

public:
    Pagina(/* args */);
    ~Pagina();
};
