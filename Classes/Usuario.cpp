#include "Usuario.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <ctime>

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

void Usuario::abrirPacotinho(vector<Figurinha> &todasFigurinhas)
{
    vector<Figurinha> pacotinho;
    int quantidade = 3;

    if (todasFigurinhas.empty())
        return;

    srand(time(nullptr));

    // Copia os índices de todas as figurinhas
    vector<int> indices;
    for (size_t i = 0; i < todasFigurinhas.size(); ++i)
        indices.push_back(i);

    // Garante que não vai tentar pegar mais do que existe
    quantidade = min(quantidade, (int)todasFigurinhas.size());

    // Seleciona 'quantidade' figurinhas aleatoriamente sem repetição
    for (int i = 0; i < quantidade; ++i)
    {
        int randPos = rand() % indices.size();
        int idx = indices[randPos];

        pacotinho.push_back(todasFigurinhas[idx]);

        // Remove o índice usado
        indices[randPos] = indices.back();
        indices.pop_back();
    }

    for (Figurinha &f : pacotinho)
    {
        album.adicionarFigurinha(f);
    }

    cout << "-- Novas figurinhas --" << endl;

    for (int i = 0; i < pacotinho.size(); i++)
    {
        cout << pacotinho[i].getNome() << endl;
    }

    cout << "---------------------" << endl;
    cout << "Pressione ENTER para continuar..." << endl;
    getchar();
    getchar();
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