#include "FigurinhaMegaEvolucao.h"

FigurinhaMegaEvolucao::FigurinhaMegaEvolucao(int num, string nome, string cont, int status, string estagio, string proximoPokemon, string pedraMega)
    : FigurinhaEvolucao(num, nome, cont, status, estagio, proximoPokemon), pedraMega(pedraMega)
{
}

FigurinhaMegaEvolucao::~FigurinhaMegaEvolucao()
{
}

void FigurinhaMegaEvolucao::mostrarDetalhes()
{
}
