#pragma once

#include <string>

using namespace std;

class Troca
{
private:
    string nomeProponente;
    int figurinhaRequerida, figurinhaDisponivel, status;
    // status da troca pode ser: 0 (aguardando análise), 1 (aceita), 2 (recusada)

public:
    Troca(string proponente, int requerida, int disponivel);

    ~Troca();

    string getNomeProponente();
    int getFigurinhaRequerida();
    int getFigurinhaDisponivel();
    int getStatus();
    int setStatus(int status);

    void aceitar(bool decisao);
};
