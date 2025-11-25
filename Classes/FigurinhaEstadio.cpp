#include "FigurinhaEstadio.h"

FigurinhaEstadio::FigurinhaEstadio(int num, string nome, string cont, int status, string tipo, string cidade, int capacidade)
    : Figurinha(num, nome, cont, status), cidade(cidade), capacidade(capacidade) {}

FigurinhaEstadio::~FigurinhaEstadio()
{
}

void FigurinhaEstadio::mostrarDetalhes()
{
}
