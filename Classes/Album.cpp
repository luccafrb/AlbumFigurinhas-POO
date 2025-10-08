#include "Album.h"

#include <iostream>

using namespace std;

Album::Album(/* args */)
{
}

Album::~Album()
{
}

bool Album::colarFigurinha()
{
    int escolha = -1;

    while (escolha != 0)
    {
        mostrarFigurinhasDaColecao();

        cout << "Digite o número da figurinha que você deseja colar (0 para sair): ";
        cin >> escolha;

        if (escolha == 0)
            break;

        if (escolha < 1 || escolha > figurinhas.size())
        {
            cout << "Número inválido! Tente novamente." << endl;
            continue;
        }

        figurinhas[escolha - 1].colar();
    }

    return true;
}

void Album::adicionarFigurinha(Figurinha &figurinha)
{
    figurinhas.push_back(figurinha);
}

void Album::mostrarFigurinhasDaColecao()
{
    if (figurinhas.size() == 0)
    {
        cout << "Sem figurinhas na coleção." << endl;
        return;
    }

    cout << "-- Figurinhas na coleção --" << endl;

    for (int i = 0; i < figurinhas.size(); i++)
    {
        if (figurinhas[i].getStatus() == 0)
        {
            cout << i + 1 << " - " << figurinhas[i].getNome() << endl;
        }
    }

    cout << "-- Figurinhas coladas no álbum --" << endl;

    for (int i = 0; i < figurinhas.size(); i++)
    {
        if (figurinhas[i].getStatus() == 1)
        {
            cout << i + 1 << " - " << figurinhas[i].getNome();
        }
    }
}
