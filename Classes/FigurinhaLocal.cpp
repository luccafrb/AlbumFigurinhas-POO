#include "FigurinhaLocal.h"

#include <iostream>

FigurinhaLocal::FigurinhaLocal(int num, string nome, string cont, int status, string tipo, string regiao, string liderGinasio)
    : Figurinha(num, nome, cont, status), regiao(regiao), liderGinasio(liderGinasio) {}

FigurinhaLocal::~FigurinhaLocal() {}

void FigurinhaLocal::mostrarDetalhes()
{
    cout << "Detalhes Figurinha " << nome << ":" << endl;

    cout << "Número da página: " << numPag << endl;

    cout << "Status: " << status << endl;

    cout << "Conteudo: " << conteudo;

    cout << "Regiao: " << regiao << endl;

    cout << "Lider do ginasio: " << liderGinasio << endl;
}

Figurinha *FigurinhaLocal::clone()
{
    return new FigurinhaLocal(*this);
}
