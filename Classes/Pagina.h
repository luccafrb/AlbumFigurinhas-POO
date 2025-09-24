#pragma once
#include <string>
#include "Figurinha.h"

class Pagina
{
private:
    vector<Figurinha> figurinhas;
    string titulo;
    int numMin, numMax;

public:
    Pagina(/* args */);
    ~Pagina();
};
