#include "Troca.h"

Troca::Troca(string proponente, int requerida, int disponivel)
    : nomeProponente(proponente), figurinhaRequerida(requerida), figurinhaDisponivel(disponivel), status(0) {}

Troca::~Troca()
{}

void Troca::aceitar(bool decisao)
{
    if (decisao == 1)
    {
        status = 1;
    }
    else if(decisao == 2)
    {
        status = 2;
    }   
}
