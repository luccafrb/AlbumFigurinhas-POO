#include <iostream>
#include "program.h"
#include "Interface/Menus.h"

using namespace std;

program::program()
{
}

program::~program()
{
}

void program::inicializate()
{
    cout << "Bem vindo ao Álbum de figurinhas!" << endl;

    usuarios = Usuario::CarregarDeCsv("Dados\\usuarios.csv");
    figurinhas = Figurinha::CarregarDeCsv("Dados\\figurinhas.csv");
}

void program::run()
{
    int escolha;

    Menus menus;

    do
    {
        escolha = menus.mostrarMenuInicial();

        switch (escolha)
        {
        case 1:
            cout << "Aqui, a gente cria um novo usuário" << endl;
            break;

        case 2:
            cout << "Solicita usuario e senha, e próximo menu" << endl;
            break;

        case 3:
            cout << "Saindo.." << endl;
            break;

        case 4:
            cout << "Lista de usuários:" << endl;

            for (Usuario u : usuarios)
            {
                cout << u.getNome() << endl;
            }

            cout << endl;
            cout << "Lista de Figurinhas:" << endl;

            for (Figurinha f : figurinhas)
            {
                cout << f.getNome() << endl;
            }
            break;

        default:
            break;
        }
    } while (escolha != 3);
}
