#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

#include "Classes/Usuario.h"
#include "Classes/Figurinha.h"

using namespace std;

int main()
{
    vector<Usuario> usuarios = Usuario::CarregarDeCsv("Dados\\usuarios.csv");
    vector<Figurinha> figurinhas = Figurinha::CarregarDeCsv("Dados\\figurinhas.csv");

    cout << "Lista de usuários:" << endl;

    for (Usuario u : usuarios)
    {
        cout << u.getNome() << endl;
    }

    cout << "Lista de Figurinhas:" << endl;

    for (Figurinha f : figurinhas)
    {
        cout << f.getNome() << endl;
    }

    return 0;
}
