#pragma once

#include "Classes/Figurinha.h"
#include "Classes/Usuario.h"
#include "Interface/Menus.h"

class program
{
private:
    vector<Usuario> usuarios;
    vector<Figurinha> todasFigurinhas;

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
    void gerenciarRequisicoes(Usuario &usuarioAtual, vector<Usuario*> listaUsuarios);
};
