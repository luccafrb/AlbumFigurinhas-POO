#include "Pagina.h"

#include <iostream>

using namespace std;

Pagina::Pagina(string titulo, int numMin, int numMax)
    : titulo(titulo), numMin(numMin), numMax(numMax)
{
    // Cria os espaços vazios para as figurinhas da página
    figurinhas.resize(numMax - numMin + 1, nullptr);
}

Pagina::~Pagina()
{
}

int Pagina::getNumMin()
{
    return numMin;
}

int Pagina::getNumMax()
{
    return numMax;
}

void Pagina::mostrarFigurinhas()
{
    cout << "Página: " << titulo << " (Figurinhas " << numMin << " a " << numMax << ")" << endl;
    int totalEspacos = numMax - numMin + 1;
    for (int i = 0; i < totalEspacos; i++)
    {
        cout << (numMin + i) << " - ";
        if (figurinhas[i] != nullptr)
            cout << figurinhas[i]->getNome() << endl;
        else
            cout << "[Vazio]" << endl;
    }
}

void Pagina::adicionarFigurinha(Figurinha *figurinha)
{
    int indice = figurinha->getNum() - numMin;
    if (indice < 0 || indice >= numMax - numMin + 1)
    {
        cout << "Número da figurinha fora do intervalo desta página." << endl;
        return;
    }

    figurinhas[indice] = figurinha;
}

string Pagina::getTitulo()
{
    return titulo;
}