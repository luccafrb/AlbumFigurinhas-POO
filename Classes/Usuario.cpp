#include "Usuario.h"
#include <fstream>
#include <sstream>

Usuario::Usuario(string nome, string senha)
    : nome(nome), senha(senha)
{
}

Usuario::~Usuario()
{
}

string Usuario::getNome()
{
    return nome;
}

string Usuario::getSenha()
{
    return senha;
}

vector<Usuario> Usuario::CarregarDeCsv(const string &arquivo)
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

        Usuario temp(nome, senha);
        usuarios.push_back(temp);
    }

    return usuarios;
}
