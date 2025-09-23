#pragma once

#include <string>

using namespace std;

class Figurinha
{
private:
    string nome, conteudo;
    int num, status, numPag;
    // status da figurinha pode ser:  0 (na coleção), 1 (colada no álbum), 2 (disponível para troca)

public:
    Figurinha(/* args */);
    ~Figurinha();
};