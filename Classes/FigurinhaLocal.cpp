#include "FigurinhaLocal.h"

FigurinhaLocal::FigurinhaLocal(int num, string nome, string cont, int status, string tipo, string regiao, string liderGinasio)
    : Figurinha(num, nome, cont, status), regiao(regiao), liderGinasio(liderGinasio) {}

FigurinhaLocal::~FigurinhaLocal()
{
}

void FigurinhaLocal::mostrarDetalhes()
{
}
