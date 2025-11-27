#ifndef FIGURINHA_MEGA_EVOLUCAO_H
#define FIGURINHA_MEGA_EVOLUCAO_H

#include "FigurinhaEvolucao.h"

class FigurinhaMegaEvolucao : public FigurinhaEvolucao
{
private:
    string pedraMega;

public:
    FigurinhaMegaEvolucao(int num, string nome, string cont, int status, string estagio, string proximoPokemon, string pedraMega);
    ~FigurinhaMegaEvolucao();

    void mostrarDetalhes();
    Figurinha *clone();
};

#endif