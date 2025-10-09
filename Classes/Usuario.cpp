#include "Usuario.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <ctime>

Usuario::Usuario(string nome, string senha, vector<Figurinha> &todasFigurinhas)
    : nome(nome), senha(senha), album(todasFigurinhas)
{
}

Usuario::~Usuario() {}

string Usuario::getNome() const
{
    return nome;
}

string Usuario::getSenha() const
{
    return senha;
}

vector<Usuario> Usuario::CarregarDeCsv(const string &arquivo, vector<Figurinha> &todasFigurinhas)
{
    ifstream fsIn;
    fsIn.open(arquivo);

    string linha;

    getline(fsIn, linha);
    vector<Usuario> usuarios;

    while (getline(fsIn, linha))
    {
        stringstream ss(linha);
        string nome, senha;

        getline(ss, nome, ',');
        getline(ss, senha, ',');

        Usuario temp(nome, senha, todasFigurinhas);
        usuarios.push_back(temp);
    }

    return usuarios;
}

void Usuario::abrirPacotinho(vector<Figurinha> &todasFigurinhas)
{
    album.abrirPacotinho(todasFigurinhas);
}

void Usuario::verAlbum()
{
    album.verAlbum();
}

void Usuario::colarFigurinha()
{
    album.colarFigurinha();
}

void Usuario::salvarEmCsv(const string &arquivo)
{
    ofstream fsOf(arquivo, ios::app);

    fsOf << '\n'
         << nome << ',' << senha;
    fsOf.close();

    cout << "---------------------" << endl;
    cout << "Usuário salvo no CSV!" << endl;
}