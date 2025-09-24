#pragma once

#include "Figurinha.h"
#include "Pagina.h"
#include "Troca.h"

class Album
{
private:
    vector<Figurinha> figurinhas;
    Troca requisicoesTroca;
    Pagina paginas;

public:
    Album();
    ~Album();
};
