#include "FigurinhaEvolucao.h"

FigurinhaEvolucao::FigurinhaEvolucao(int num, string nome, string cont, int status, string estagio, string proximoPokemon)
    : Figurinha(num, nome, cont, status), estagio(estagio), proximoPokemon(proximoPokemon) {}

FigurinhaEvolucao::~FigurinhaEvolucao()
{
}

void FigurinhaEvolucao::mostrarDetalhes()
{
}

Figurinha *FigurinhaEvolucao::clone()
{
    return new FigurinhaEvolucao(*this);
}
