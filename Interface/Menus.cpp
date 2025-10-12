#include "Menus.h"
#include <iostream>

using namespace std;

Menus::Menus()
{
}

Menus::~Menus()
{
}

int Menus::mostrarMenuInicial()
{
    cout << "Escolha uma das opções:" << endl;
    cout << "1 - Novo Álbum" << endl;
    cout << "2 - Acessar Álbum" << endl;
    cout << "3 - Sair" << endl;
    cout << "4 - Mostrar dados dos CSV's (Para teste)" << endl;
    cout << "-> ";

    int escolha;
    cin >> escolha;

    return escolha;
}

int Menus::mostrarMenuAlbum()
{
    cout << "Escolha uma das opções:" << endl;
    cout << "1 - Ver Álbum" << endl;
    cout << "2 - Gerenciar a Coleção" << endl;
    cout << "3 - Abrir Pacote de Figurinhas" << endl;
    cout << "4 - Voltar ao Menu Anterior" << endl;
    cout << "-> ";

    int escolha;
    cin >> escolha;

    return escolha;
}

int Menus::mostrarMenuGerenciarColecao()
{
    cout << "Escolha uma das opções:" << endl;
    cout << "1 - Mostrar figurinhas da coleção" << endl;
    cout << "2 - Mostrar figurinhas disponíveis para troca" << endl;
    cout << "3 - Colar Figurinha" << endl;
    cout << "4 - Disponibilizar para Troca" << endl;
    cout << "5 - Revisar solicitações de Troca" << endl;
    cout << "6 - Propor Troca de Figurinhas" << endl;
    cout << "7 - Voltar ao Menu Anterior" << endl;
    cout << "-> ";

    int escolha;
    cin >> escolha;

    return escolha;
}
