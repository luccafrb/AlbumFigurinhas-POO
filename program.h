#pragma once

#include "Classes/Figurinha.h" // Garante que a definição de Figurinha está disponível
#include "Classes/Usuario.h"
#include "Interface/Menus.h"
#include <vector> // Incluir vector, caso não esteja nos includes anteriores

using namespace std;

class program
{
private:
    vector<Usuario> usuarios;

    // MUDANÇA ESSENCIAL: O vetor agora armazena PONTEIROS para Figurinha
    // Isso é necessário para alocação dinâmica e polimorfismo (Requisito 8)
    vector<Figurinha *> todasFigurinhas;

public:
    program();
    ~program();

    void inicializate();
    void run();

    void adicionarUsuario();
    void menuGerenciarAlbum(Usuario &usuarioAtual, Menus &menu);
    void menuGerenciarColecao(Usuario &usuarioAtual, Menus &menus);
    void menuInicial();
    Usuario &login();
    void gerenciarRequisicoes(Usuario &usuarioAtual, vector<Usuario *> listaUsuarios);
};