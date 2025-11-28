#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "program.h"
#include "Interface/Menus.h"
#include "Classes/Usuario.h"

using namespace std;

program::program()
{
}

program::~program()
{
    for (Figurinha *f : todasFigurinhas)
    {
        delete f;
    }
    todasFigurinhas.clear();
}

void program::adicionarUsuario()
{
    bool nomeUnico = false;
    string nome, senha;

    while (!nomeUnico)
    {
        cout << "Digite o nome do novo usuário: ";
        cin >> nome;

        nomeUnico = true;

        for (Usuario &u : usuarios)
        {
            if (u.getNome() == nome)
            {
                cout << "O nome de usuário \"" << u.getNome() << "\" já existe. Escolha outro, por favor." << endl;
                nomeUnico = false;
                break;
            }
        }
    }

    cout << "Digite a senha do novo usuário: ";
    cin >> senha;

    Usuario novoUsuario(nome, senha, todasFigurinhas);
    novoUsuario.salvarEmCsv("Dados\\usuarios.csv");
    usuarios.push_back(novoUsuario);
}

void program::inicializate()
{
    cout << "Bem vindo ao Álbum de figurinhas!" << endl;

    todasFigurinhas = Figurinha::CarregarDeCsv("Dados\\figurinhas.csv");
    usuarios = Usuario::CarregarDeCsv("Dados\\usuarios.csv", todasFigurinhas);
}

void program::run()
{
    menuInicial();
}

void program::menuGerenciarAlbum(Usuario &usuarioAtual, Menus &menus)
{
    int escolha = 0;

    while (true)
    {
        escolha = menus.mostrarMenuAlbum();

        switch (escolha)
        {
        case 1:
            usuarioAtual.getAlbum().verAlbum();
            break;

        case 2:
            menuGerenciarColecao(usuarioAtual, menus);
            break;

        case 3:
            usuarioAtual.getAlbum().abrirPacotinho(todasFigurinhas);
            cout << "Precione qualquer tela para continuar";
            getchar();
            getchar();
            break;

        case 4:
            return;

        default:
            cout << "Opção inválida!" << endl;
        }
    }
}

void program::menuGerenciarColecao(Usuario &usuarioAtual, Menus &menus)
{
    int escolha = 0;
    vector<Usuario *> listaUsuarios;

    for (Usuario &u : usuarios)
    {
        if (u.getNome() != usuarioAtual.getNome())
        {
            listaUsuarios.push_back(&u);
        }
    }

    while (true)
    {
        escolha = menus.mostrarMenuGerenciarColecao();

        switch (escolha)
        {
        case 1:
            usuarioAtual.getAlbum().mostrarFigurinhasDaColecao();
            cout << "Precione qualquer tela para continuar";
            getchar();
            getchar();
            break;

        case 2:
            usuarioAtual.getAlbum().mostrarFigurinhasDisponiveisParaTroca();
            cout << "Precione qualquer tela para continuar";
            getchar();
            getchar();
            break;

        case 3:
        {
            usuarioAtual.getAlbum().mostrarFigurinhasDaColecao();
            cout << "Digite os números das figurinhas que deseja colar (ex: 12,23,31): ";
            cin.ignore();
            string entrada;
            getline(cin, entrada);

            usuarioAtual.getAlbum().colarFigurinhas(entrada);

            cout << "Pressione ENTER para continuar";
            getchar();
            break;
        }

        case 4:
            usuarioAtual.getAlbum().disponibilizarFigurinhaParaTroca();
            break;

        case 5:
            gerenciarRequisicoes(usuarioAtual, listaUsuarios);
            break;

        case 6:
            usuarioAtual.proporTroca(listaUsuarios);
            cout << "Precione qualquer tela para continuar";
            getchar();
            getchar();
            break;

        case 7:
            return;

        default:
            cout << "Opção inválida!" << endl;
        }
    }
}

void program::menuInicial()
{
    int escolha;
    Menus menus;

    do
    {
        escolha = menus.mostrarMenuInicial();

        switch (escolha)
        {
        case 1:
            adicionarUsuario();
            break;

        case 2:
        {
            Usuario &usuarioAtual = login();
            menuGerenciarAlbum(usuarioAtual, menus);
            break;
        }

        case 3:
            cout << "Saindo.." << endl;
            break;

        case 4:
        {
            cout << "Lista de usuários:" << endl;
            for (const Usuario &u : usuarios)
            {
                cout << u.getNome() << endl;
            }

            cout << endl;
            cout << "Lista de Figurinhas:" << endl;
            for (Figurinha *f : todasFigurinhas)
            {
                cout << f->getNome() << endl;
            }
            break;
        }

        default:
            break;
        }
    } while (escolha != 3);
}

Usuario &program::login()
{
    string senha, nome;
    cout << "Lista de Usuários:" << endl;

    for (Usuario &u : usuarios)
    {
        cout << "- " << u.getNome() << endl;
    }

    while (true)
    {
        cout << "Digite o nome do seu usuário: ";
        cin >> nome;

        for (Usuario &u : usuarios)
        {
            if (u.getNome() == nome)
            {
                bool senhaCorreta = false;

                while (!senhaCorreta)
                {
                    cout << "Digite a senha do seu usuário: ";
                    cin >> senha;

                    if (u.getSenha() == senha)
                    {
                        senhaCorreta = true;
                        return u;
                    }

                    cout << "Senha de usuário incorreta! Tente novamente." << endl;
                }
            }
        }

        cout << "Nome de usuário não encontrado. Tente novamente." << endl;
    }
}

void program::gerenciarRequisicoes(Usuario &usuarioAtual, vector<Usuario *> listaUsuarios)
{
    if (!usuarioAtual.getAlbum().mostrarRequisicoes())
    {
        return;
    }

    int opcao = -1;

    while (true)
    {
        cout << "Digite o número da requisição que você deseja gerenciar (0 - Voltar): ";
        cin >> opcao;

        if (opcao == 0)
        {
            return;
        }

        vector<Troca> *trocas = &usuarioAtual.getAlbum().getRequisicoes();

        if (opcao < 1 || opcao > trocas->size())
        {
            cout << "Opção de requisição inválida. Tente novamente." << endl;
            continue;
        }

        Troca *trocaEscolhida = &(*trocas)[opcao - 1];

        Usuario *usuarioProponente = nullptr;
        for (Usuario *u : listaUsuarios)
        {
            if (trocaEscolhida->getNomeProponente() == u->getNome())
            {
                usuarioProponente = u;
                break;
            }
        }

        int decisao;

        trocaEscolhida->mostrar();

        switch (trocaEscolhida->getStatus())
        {
        case 1:
            cout << "Requisição já aceita!" << endl;
            continue;

        case 2:
            cout << "Requisição já recusada!" << endl;
            continue;

        default:
            cout << "O que você deseja fazer com essa requisição? 1 - Aceitar / 2 - Recusar / 0 - voltar: ";
            cin >> decisao;

            if (decisao == 0)
            {
                continue;
            }

            break;
        }

        if (decisao == 1)
        {
            trocaEscolhida->aceitar(true);

            Figurinha *figOferecida = trocaEscolhida->getFigurinhaOferecida();
            Figurinha *figRequerida = trocaEscolhida->getFigurinhaRequerida();

            usuarioAtual.getAlbum().adicionarFigurinha(figOferecida);
            usuarioAtual.getAlbum().removerFigurinha(figRequerida);

            usuarioProponente->getAlbum().adicionarFigurinha(figRequerida);
            usuarioProponente->getAlbum().removerFigurinha(figOferecida);

            cout << "Troca realizada!" << endl;
        }
        else if (decisao == 2)
        {
            trocaEscolhida->aceitar(false);
            cout << "Requisição recusada!" << endl;
        }
    }
}
