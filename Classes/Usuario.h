#pragma once

#include "Album.h"
#include <vector>

class Usuario
{
private:
    string nome, senha;
    Album album;

public:
    Usuario();
    Usuario(string nome, string senha);
    ~Usuario();

    string getNome() const;
    string getSenha() const;

    static vector<Usuario> CarregarDeCsv(const string &arquivo);
    void salvarEmCsv(const string &arquivo);
    void abrirPacotinho(vector<Figurinha> &figurinhas);
};