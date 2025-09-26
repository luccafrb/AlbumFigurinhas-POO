#include "Usuario.h"
#include <fstream>
#include <sstream>
#include <iostream>

Usuario::Usuario()
    : nome(""), senha("") {}

Usuario::Usuario(string nome, string senha)
    : nome(nome), senha(senha) {}

Usuario::~Usuario() {}

string Usuario::getNome() const
{
    return nome;
}

string Usuario::getSenha() const
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

void Usuario::salvarEmCsv(const string &arquivo)
{
    ofstream fsOf;
    fsOf.open(arquivo, ios::app);

    if (fsOf.tellp() != 0)
    {
        cout << '\n';
    }

    fsOf.close();
    cout << "---------------------" << endl;
    cout << "Usuário salvo no CSV!" << endl;
}