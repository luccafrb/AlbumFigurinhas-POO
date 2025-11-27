#pragma once

#include <string>
#include "Figurinha.h"

using namespace std;

class Troca
{
private:
    string nomeProponente;
    Figurinha &figurinhaRequerida;
    Figurinha &figurinhaOferecida;
    int status;

public:
    Troca(string proponente, Figurinha &requerida, Figurinha &disponivel);

    ~Troca();

    string getNomeProponente();
    Figurinha *getFigurinhaRequerida();
    Figurinha *getFigurinhaOferecida();
    int getStatus();

    void aceitar(bool decisao);
    void mostrar();
};
