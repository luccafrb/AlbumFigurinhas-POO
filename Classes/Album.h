#pragma once

#include "Figurinha.h"
#include "Pagina.h"
#include "Troca.h"

class Album
{
private:
    vector<Pagina> paginas;
    vector<Figurinha> figurinhas;
    vector<Troca> requisicoesTroca;

public:
    Album(vector<Figurinha> &todasFigurinhas);
    ~Album();

    bool colarFigurinha();
    bool mostrarFigurinhasDaColecao();
    void adicionarFigurinha(Figurinha figurinha);
    void verAlbum();
    void criarPaginas(vector<Figurinha> &todasFigurinhas);
    bool disponibilizarFigurinhaParaTroca();
    bool mostrarFigurinhasDisponiveisParaTroca();
    void abrirPacotinho(vector<Figurinha> &todasFigurinhas);

        // Métodos para gerenciamento de requisições de troca
    void adicionarRequisicao(Troca& requisicao);
    vector<Troca>& getRequisicoes();

    void adicionarFigurinha(Figurinha *figurinha);
    void removerFigurinha(Figurinha *figurinha);

    Figurinha *obterFigurinhaPeloNumParaTroca(int num);

    bool mostrarRequisicoes();
};