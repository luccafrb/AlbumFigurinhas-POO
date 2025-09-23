#pragma once

#include "Figurinha.h"
#include "Pagina.h"
#include "Troca.h"

#define MAX_FIGURINHAS 30

class Album
{
private:
    Figurinha figurinhas[MAX_FIGURINHAS];
    Troca requisicoesTroca;
    Pagina paginas;

public:
    Album(/* args */);
    ~Album();
};
