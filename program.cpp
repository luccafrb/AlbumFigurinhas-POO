#include <iostream>
#include "program.h"
#include "Interface/Menus.h"
#include "Classes/Usuario.h"

using namespace std;

program::program()
{
}

program::~program()
{
}

Usuario criarUsuario()
{
    string nome, senha;
    cout << "Digite o nome do novo usuário: ";
    cin >> nome;

    cout << "Digite a senha do novo usuário: ";
    cin >> senha;

    Usuario novoUsuario(nome, senha);
    return novoUsuario;
}

void program::adicionarUsuario(Usuario usuario)
{
    usuarios.push_back(usuario);
}

void program::inicializate()
{
    cout << "Bem vindo ao Álbum de figurinhas!" << endl;

    usuarios = Usuario::CarregarDeCsv("Dados\\usuarios.csv");
    figurinhas = Figurinha::CarregarDeCsv("Dados\\figurinhas.csv");
}

void program::run()
{
    char escolha;

    Menus menus;

    do
    {
        escolha = menus.mostrarMenuInicial();

        switch (escolha)
        {
        case 1:
        {
            bool nomeUnico = true;
            Usuario novoUsuario;

            do
            {
                novoUsuario = criarUsuario();
                nomeUnico = true;

                for (Usuario &u : usuarios)
                {
                    if (u.getNome() == novoUsuario.getNome())
                    {
                        cout << "O nome de usuário \"" << u.getNome() << "\" já existe. Escolha outro, por favor." << endl;
                        nomeUnico = false;
                        break;
                    };
                }

            } while (nomeUnico == false);

            novoUsuario.salvarEmCsv("Dados\\usuarios.csv");
            adicionarUsuario(novoUsuario);
            break;
        }

        case 2:
            cout << "Solicita usuario e senha, e próximo menu" << endl;
            break;

        case 3:
            cout << "Saindo.." << endl;
            break;

        case 4:
            cout << "Lista de usuários:" << endl;

            for (const Usuario &u : usuarios)
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
