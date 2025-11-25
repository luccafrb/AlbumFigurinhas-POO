#include "FigurinhaEspecial.h"

FigurinhaEspecial::FigurinhaEspecial(int num, string nome, string cont, int status, string tipo)
    : Figurinha(num, nome, cont, status), tipo(tipo) {}

FigurinhaEspecial::~FigurinhaEspecial()
{
}

void FigurinhaEspecial::mostrarDetalhes()
{
}
