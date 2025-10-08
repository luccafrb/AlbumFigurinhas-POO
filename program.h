#pragma once

#include "Classes/Figurinha.h"
#include "Classes/Usuario.h"
#include "Interface/Menus.h"

class program
{
private:
    vector<Usuario> usuarios;
    vector<Figurinha> figurinhas;

public:
    program();
    ~program();

    void inicializate();
    void run();

    void adicionarUsuario();
    void menuGerenciarAlbum(Usuario *usuarioAtual, Menus &menu);
    void menuInicial();
    Usuario *login();
};
