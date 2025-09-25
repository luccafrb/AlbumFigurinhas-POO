#pragma once

#include "Classes/Figurinha.h"
#include "Classes/Usuario.h"

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
};
