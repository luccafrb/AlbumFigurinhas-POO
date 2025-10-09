#pragma once

#include <string>
#include <vector>

using namespace std;

class Figurinha
{
private:
    string nome, conteudo;
    int num, status, numPag;
    // status da figurinha pode ser:  0 (na coleção), 1 (colada no álbum), 2 (disponível para troca)

public:
    // construtor e destrutor
    Figurinha(int num, string nome, string cont, int status);
    ~Figurinha();

    // getters
    string getNome()
    {
        return nome;
    }

    string getConteudo()
    {
        return conteudo;
    }

    int getStatus()
    {
        return status;
    }

    int getNumPag()
    {
        return numPag;
    }

    int getNum()
    {
        return num;
    }

    bool colar();

    // vetor de figurinhas
    static vector<Figurinha> CarregarDeCsv(const string &arquivo);
};