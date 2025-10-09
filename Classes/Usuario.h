#pragma once

#include "Album.h"
#include <vector>

class Usuario
{
private:
    string nome, senha;
    Album album;

public:
    Usuario(string nome, string senha, vector<Figurinha> &todasFigurinhas);
    ~Usuario();

    string getNome() const;
    string getSenha() const;

    static vector<Usuario> CarregarDeCsv(const string &arquivo, vector<Figurinha> &todasFigurinhas);
    void salvarEmCsv(const string &arquivo);
    void colarFigurinha();
    void abrirPacotinho(vector<Figurinha> &todasFigurinhas);
    void verAlbum();
};