#include "Usuario.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <ctime>

Usuario::Usuario(string nome, string senha, vector<Figurinha *> &todasFigurinhas)
    : nome(nome), senha(senha), album(todasFigurinhas)
{
}

Usuario::~Usuario() {}

string Usuario::getNome() const
{
    return nome;
}

string Usuario::getSenha() const
{
    return senha;
}

Album &Usuario::getAlbum()
{
    return album;
}

void Usuario::salvarEmCsv(const string &arquivo)
{
    ofstream fsOf(arquivo, ios::app);

    fsOf << '\n'
         << nome << ',' << senha;
    fsOf.close();

    cout << "---------------------" << endl;
    cout << "Usuário salvo no CSV!" << endl;
}

vector<Usuario> Usuario::CarregarDeCsv(const string &arquivo, vector<Figurinha *> &todasFigurinhas)
{
    ifstream fsIn;
    fsIn.open(arquivo);

    string linha;

    getline(fsIn, linha);
    vector<Usuario> usuarios;

    while (getline(fsIn, linha))
    {
        stringstream ss(linha);
        string nome, senha;

        getline(ss, nome, ',');
        getline(ss, senha, ',');

        Usuario temp(nome, senha, todasFigurinhas);
        usuarios.push_back(temp);
    }

    return usuarios;
}

void Usuario::proporTroca(vector<Usuario *> &listaUsuarios)
{
    for (Usuario *u : listaUsuarios)
    {
        cout << "-- Figurinhas de " << u->getNome() << ":" << endl;
        u->getAlbum().mostrarFigurinhasDisponiveisParaTroca();
    }

    string escolha;
    cout << "Digite o nome do usuário que você deseja trocar (Digite:'sair' para sair desse menu): ";
    cin >> escolha;

    Usuario *destino = nullptr;

    while (true)
    {
        bool usuarioValido = false;

        if (escolha == "sair")
        {
            cout << "Saindo do menu de trocas...\n";
            return;
        }

        for (Usuario *u : listaUsuarios)
        {
            if (u->getNome() == escolha)
            {
                usuarioValido = true;
                destino = u;
                break;
            }
        }

        if (!usuarioValido)
        {
            cout << "Usuário não encontrado. Digite novamente: ";
            cin >> escolha;
            continue;
        }

        cout << "Lista de figurinhas disponíveis para troca de " << destino->getNome() << ":" << endl;

        if (!destino->getAlbum().mostrarFigurinhasDisponiveisParaTroca())
        {
            cout << "Lista vazia! Escolha outro usuário: ";
            cin >> escolha;
            continue;
        }

        break;
    }

    int numFigurinhaRequerida;
    cout << "Digite o número da figurinha que você deseja receber: ";
    cin >> numFigurinhaRequerida;

    Figurinha *figurinhaRequerida = destino->getAlbum().obterFigurinhaPeloNumParaTroca(numFigurinhaRequerida);

    cout << "Suas figurinhas disponíveis para troca:" << endl;
    album.mostrarFigurinhasDisponiveisParaTroca();

    int numFigurinhaOferecida;
    cout << "Digite o número da figurinha que você deseja oferecer: ";
    cin >> numFigurinhaOferecida;

    Figurinha *figurinhaOferecida = getAlbum().obterFigurinhaPeloNumParaTroca(numFigurinhaOferecida);

    Troca troca(nome, *figurinhaRequerida, *figurinhaOferecida);
    destino->getAlbum().adicionarRequisicao(troca);

    cout << "Requisição de troca enviada com sucesso para " << destino->getNome() << endl;
};
