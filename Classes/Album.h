#pragma once

#include "Figurinha.h"
#include "Pagina.h"
#include "Troca.h"

class Album
{
private:
    vector<Pagina> paginas;
    vector<Figurinha> figurinhas;
    Troca requisicoesTroca;

public:
    Album(vector<Figurinha> &todasFigurinhas);
    ~Album();

    bool colarFigurinha();
    void mostrarFigurinhasDaColecao();
    void mostrarFigurinhasColadas();
    void adicionarFigurinha(Figurinha &figurinha);
    void verAlbum();
    void criarPaginas(vector<Figurinha> &todasFigurinhas);
    void abrirPacotinho(vector<Figurinha> &todasFigurinhas);
};