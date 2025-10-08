#pragma once

#include "Figurinha.h"
#include "Pagina.h"
#include "Troca.h"

class Album
{
private:
    vector<Figurinha> figurinhas;
    Troca requisicoesTroca;
    vector<Pagina> paginas;

public:
    Album();
    ~Album();

    bool colarFigurinha();
    void mostrarFigurinhasDaColecao();
    void adicionarFigurinha(Figurinha &figurinha);
};