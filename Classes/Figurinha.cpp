#include "Figurinha.h"
#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>
#include <ctime>     // para time()
#include <cstdlib>   // para rand(), srand()
#include <algorithm> // para find()

using namespace std;

Figurinha::Figurinha(int num, string nome, string cont, int status, int numPag)
    : num(num), nome(nome), conteudo(cont), status(status), numPag(numPag)
{
}

Figurinha::~Figurinha() {}

bool Figurinha::colar()
{
    if (status == 0)
    {
        status = 1;
        cout << "Figurinha colada com sucesso!" << endl;
        return true;
    }
    else if (status == 1)
    {
        cout << "Figurinha já estava colada!" << endl;
        return true;
    }
    else
    {
        cout << "Falha em colar a figurinha!" << endl;
        return false;
    }
}

vector<Figurinha> Figurinha::CarregarDeCsv(const string &arquivo)
{
    vector<Figurinha> figurinhas;

    ifstream fsIn(arquivo);
    if (!fsIn.is_open())
    {
        cout << "Erro ao abrir arquivo: " << arquivo << endl;
        return figurinhas;
    }

    string linha;
    getline(fsIn, linha); // pula cabeçalho
    while (getline(fsIn, linha))
    {
        stringstream ss(linha);
        string numStr, nome, conteudo, status, numPag;
        getline(ss, numStr, ',');
        getline(ss, nome, ',');
        getline(ss, conteudo, ',');
        getline(ss, status, ',');
        getline(ss, numPag, ',');
        figurinhas.push_back(Figurinha(stoi(numStr), nome, conteudo, stoi(status), stoi(numPag)));
    }

    fsIn.close();
    return figurinhas;
}