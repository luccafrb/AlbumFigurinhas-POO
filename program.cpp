#include <iostream>
#include <string>
#include <vector>
#include <algorithm> // Inclua se necessário
#include "program.h"
#include "Interface/Menus.h"
#include "Classes/Usuario.h"
// Assumindo que Figurinha e Troca estão incluídas via Usuario ou em outro lugar

using namespace std;

// Implementação do Construtor e Destrutor
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

// Implementação dos Métodos

/**
 * @brief Adiciona um novo usuário ao sistema, garantindo que o nome de usuário seja único.
 */
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

    // Assumindo que o construtor de Usuario recebe (nome, senha, todasFigurinhas)
    Usuario novoUsuario(nome, senha, todasFigurinhas);

    // Salva o novo usuário em CSV e o adiciona à lista em memória
    novoUsuario.salvarEmCsv("Dados\\usuarios.csv");
    usuarios.push_back(novoUsuario);
}

/**
 * @brief Carrega as figurinhas e os usuários a partir de arquivos CSV.
 */
void program::inicializate()
{
    cout << "Bem vindo ao Álbum de figurinhas!" << endl;

    // Carrega todas as figurinhas disponíveis
    todasFigurinhas = Figurinha::CarregarDeCsv("Dados\\figurinhas.csv");
    // Carrega os usuários existentes
    usuarios = Usuario::CarregarDeCsv("Dados\\usuarios.csv", todasFigurinhas);

    cout << "Figurinhas carregadas:" << endl;
    for (Figurinha *f : todasFigurinhas)
    {
        cout << f->getNome() << endl;
    }
}

/**
 * @brief Ponto de entrada principal da aplicação.
 */
void program::run()
{
    menuInicial();
}

/**
 * @brief Exibe o menu principal para gerenciar o álbum do usuário logado.
 */
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

/**
 * @brief Exibe o menu para gerenciar a coleção de figurinhas (trocas, colar, etc.).
 */
void program::menuGerenciarColecao(Usuario &usuarioAtual, Menus &menus)
{
    int escolha = 0;
    vector<Usuario *> listaUsuarios;

    // Preenche lista de outros usuários para trocas
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
            break;
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

/**
 * @brief Exibe o menu inicial (cadastro, login, sair).
 */
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
        {
            adicionarUsuario();
            break;
        }

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
            // Opção de debug/visualização
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

/**
 * @brief Realiza o processo de login do usuário.
 * @return Referência para o objeto Usuario logado.
 */
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

/**
 * @brief Permite ao usuário logado aceitar ou recusar requisições de troca.
 */
void program::gerenciarRequisicoes(Usuario &usuarioAtual, vector<Usuario *> listaUsuarios)
{
    // Assume que mostrarRequisicoes exibe a lista e retorna se há requisições pendentes
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

        // Encontra o ponteiro para o usuário proponente
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

        default: // Status pendente (0)
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

            // Troca de posse das figurinhas
            usuarioAtual.getAlbum().adicionarFigurinha(figOferecida);
            usuarioAtual.getAlbum().removerFigurinha(figRequerida); // Esta deve ser a figurinha que o proponente precisa (e o atual tem para troca)

            usuarioProponente->getAlbum().adicionarFigurinha(figRequerida);
            usuarioProponente->getAlbum().removerFigurinha(figOferecida); // Esta deve ser a figurinha que o proponente ofereceu

            cout << "Troca realizada!" << endl;
        }
        else if (decisao == 2)
        {
            trocaEscolhida->aceitar(false);
            cout << "Requisição recusada!" << endl;
        }
    }
}
