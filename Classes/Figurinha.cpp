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

vector<Figurinha> Figurinha::CarregarDeCsv(const string &arquivo)
{
    vector<Figurinha> figurinhas;

    ifstream fsIn(arquivo);
    if (!fsIn.is_open()) {
        cout << "Erro ao abrir arquivo: " << arquivo << endl;
        return figurinhas;
    }

    string linha;
    getline(fsIn, linha); // pula cabeçalho
    while (getline(fsIn, linha)) {
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

// ====================
// NOVA FUNÇÃO ALEATÓRIA
// ====================
vector<pair<int, string>> Figurinha::GerarPacotinho(const string &arquivo)
{
    vector<pair<int, string>> pacotinho;
    vector<pair<int, string>> todas;

    ifstream fsIn(arquivo);
    if (!fsIn.is_open()) {
        cout << "Erro ao abrir " << arquivo << endl;
        return pacotinho;
    }

    string linha;
    getline(fsIn, linha); // pula cabeçalho

    while (getline(fsIn, linha)) {
        stringstream ss(linha);
        string numStr, nome;
        getline(ss, numStr, ',');
        getline(ss, nome, ',');
        todas.push_back({stoi(numStr), nome});
    }
    fsIn.close();

    if (todas.size() < 3) {
        cout << "Erro: menos de 3 figurinhas no arquivo." << endl;
        return pacotinho;
    }

    srand(time(nullptr));
    vector<int> indices;

    while (indices.size() < 3) {
        int idx = rand() % todas.size();
        if (find(indices.begin(), indices.end(), idx) == indices.end())
            indices.push_back(idx);
    }

    for (int i : indices)
        pacotinho.push_back(todas[i]);

    return pacotinho;
}
