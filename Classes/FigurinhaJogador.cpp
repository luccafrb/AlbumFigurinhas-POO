#include "FigurinhaJogador.h"

FigurinhaJogador::FigurinhaJogador(int num, string nome, string cont, int status, int nivel)
    : Figurinha(num, nome, cont, status), nivel(nivel) {}

FigurinhaJogador::~FigurinhaJogador()
{
}

void FigurinhaJogador::mostrarDetalhes()
{
}
