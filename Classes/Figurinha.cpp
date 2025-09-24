#include "Figurinha.h"
#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>

using namespace std;

Figurinha::Figurinha(int num, string nome, string cont, int status, int numPag)
    : num(num), nome(nome), conteudo(cont), status(status), numPag(numPag)
{
}

Figurinha::~Figurinha()
{
}

vector<Figurinha> Figurinha::CarregarDeCsv(const string &arquivo)
{
    vector<Figurinha> figurinhas;

    ifstream fsIn;
    fsIn.open(arquivo);

    string linha;
    getline(fsIn, linha); // Pular cabeçalho do csv

    while (getline(fsIn, linha))
    {
        stringstream ss(linha);
        string numStr, nome, conteudo, status, numPag;
        getline(ss, numStr, ',');
        getline(ss, nome, ',');
        getline(ss, conteudo, ',');
        getline(ss, status, ',');
        getline(ss, numPag, ',');

        Figurinha temp(stoi(numStr), nome, conteudo, stoi(status), stoi(numPag));
        figurinhas.push_back(temp);
    }

    fsIn.close();

    return figurinhas;
}