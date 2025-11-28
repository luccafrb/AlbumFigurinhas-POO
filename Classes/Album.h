#pragma once

#include "Figurinha.h"
#include "Pagina.h"
#include "Troca.h"

class Album
{
private:
    vector<Pagina> paginas;
    vector<Figurinha *> figurinhas;
    vector<Troca> requisicoesTroca;

public:
    Album(vector<Figurinha *> todasFigurinhas);
    ~Album();

    bool colarFigurinhas(const string &entrada);    
    bool mostrarFigurinhasDaColecao();
    void adicionarFigurinha(Figurinha *figurinha);
    void verAlbum();
    void criarPaginas(vector<Figurinha *> todasFigurinhas);
    bool disponibilizarFigurinhaParaTroca();
    bool mostrarFigurinhasDisponiveisParaTroca();
    void abrirPacotinho(vector<Figurinha *> todasFigurinhas);

    void adicionarRequisicao(Troca &requisicao);
    vector<Troca> &getRequisicoes();

    void removerFigurinha(Figurinha *figurinha);

    Figurinha *obterFigurinhaPeloNumParaTroca(int num);

    bool mostrarRequisicoes();
};
