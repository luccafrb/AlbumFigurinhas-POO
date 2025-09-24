#pragma once

#include "Album.h"
#include <vector>

class Usuario
{
private:
    string nome, senha;
    Album album;

public:
    Usuario(string nome, string senha);
    ~Usuario();

    string getNome();
    string getSenha();

    static vector<Usuario> CarregarDeCsv(const string &arquivo);
};