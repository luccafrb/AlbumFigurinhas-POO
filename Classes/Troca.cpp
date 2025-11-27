#include "Troca.h"

#include <iostream>

using namespace std;

Troca::Troca(string proponente, Figurinha &requerida, Figurinha &oferecida)
    : nomeProponente(proponente), figurinhaRequerida(requerida), figurinhaOferecida(oferecida), status(0) {}

Troca::~Troca()
{
}

string Troca::getNomeProponente()
{
    return nomeProponente;
}

Figurinha *Troca::getFigurinhaRequerida()
{
    return &figurinhaRequerida;
}

Figurinha *Troca::getFigurinhaOferecida()
{
    return &figurinhaOferecida;
}

int Troca::getStatus()
{
    return status;
}

void Troca::aceitar(bool decisao)
{
    if (decisao)
    {
        status = 1;
    }
    else if (!decisao)
    {
        status = 2;
    }
}

void Troca::mostrar()
{
    cout << "Requisicao de " << nomeProponente << ":" << endl;

    cout << "Figurinha requerida: " << figurinhaRequerida.getNome() << endl;
    cout << "Figurinha oferecida: " << figurinhaOferecida.getNome() << endl;
    cout << "Status: ";

    string statusStr;
    switch (status)
    {
    case 0:
        statusStr = "Aguardando análise";
        break;

    case 1:
        statusStr = "Aceita";
        break;
    case 2:
        statusStr = "Recusada";
        break;
    }

    cout << status << endl;
};
