#include "Troca.h"

Troca::Troca(/* args */)
{
}

Troca::~Troca()
{
}

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
