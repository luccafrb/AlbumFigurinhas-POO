#include "Album.h"

#include <iostream>
#include <ctime>
#include <algorithm>

using namespace std;

Album::Album(vector<Figurinha *> todasFigurinhas)
{
    criarPaginas(todasFigurinhas);
}

Album::~Album()
{
}

bool Album::colarFigurinha()
{
    int escolha = -1;

    while (true)
    {
        if (mostrarFigurinhasDaColecao() == false)
        {
            cout << "Sem figurinhas na coleção." << endl;
            return false;
        }

        cout << "Digite o número da figurinha que você deseja colar (0 para sair): ";
        cin >> escolha;

        if (escolha == 0)
            break;

        bool figurinhaValida = false;

        for (Figurinha *f : figurinhas)
        {
            if (f->getNum() == escolha)
            {
                if (f->getStatus() == 2)
                {
                    cout << "Não é possível colar uma figurinha disponível para troca." << endl;
                    break;
                }

                f->colar();

                for (Pagina &p : paginas)
                {
                    if (p.getTitulo() == f->getConteudo())
                    {
                        p.adicionarFigurinha(f);
                        cout << "Colada na página " << p.getTitulo() << endl;
                        break;
                    }
                }

                figurinhaValida = true;
                break;
            }
        }

        if (!figurinhaValida)
        {
            return false;
        }
    }

    return true;
}

void Album::adicionarFigurinha(Figurinha *figurinha)
{
    figurinha->indisponibilizarParaTroca();
    figurinhas.push_back(figurinha);
}

void Album::verAlbum()
{
    if (paginas.empty())
    {
        cout << "O álbum está vazio." << endl;
        return;
    }

    int paginaAtual = 0;

    while (true)
    {
        cout << "-- Página " << paginaAtual + 1 << " do Álbum --" << endl;
        paginas[paginaAtual].mostrarFigurinhas();

        cout << "---------------------" << endl;
        if (paginaAtual < paginas.size() - 1)
            cout << "1 - Próxima página" << endl;
        if (paginaAtual > 0)
            cout << "2 - Página anterior" << endl;
        cout << "0 - Sair" << endl;

        int escolha;
        cin >> escolha;

        if (escolha == 1 && paginaAtual < paginas.size() - 1)
            paginaAtual++;
        else if (escolha == 2 && paginaAtual > 0)
            paginaAtual--;
        else if (escolha == 0)
            return;
        else
            cout << "Opção inválida! Tente novamente." << endl;
    }
}

bool Album::mostrarFigurinhasDaColecao()
{
    bool temFigurinha1 = false;

    for (Figurinha *f : figurinhas)
    {
        if (f->getStatus() == 0)
        {
            temFigurinha1 = true;
            break;
        }
    }
    if (temFigurinha1)
    {
        cout << "Figurinhas na coleção:" << endl;
        for (Figurinha *f : figurinhas)
        {
            if (f->getStatus() == 0)
            {
                cout << f->getNum() << " - " << f->getNome() << endl;
            }
        }
    }

    bool temFigurinha2 = false;

    for (Figurinha *f : figurinhas)
    {
        if (f->getStatus() == 2)
        {
            temFigurinha2 = true;
        }
    }

    if (temFigurinha2)
    {
        cout << "Figurinhas disponíveis para troca:" << endl;
        for (Figurinha *f : figurinhas)
        {
            if (f->getStatus() == 2)
            {
                cout << f->getNum() << " - " << f->getNome() << endl;
            }
        }
    }

    if (!temFigurinha1 && !temFigurinha2)
    {
        cout << "Nenhuma figurinha na coleção" << endl;
        return false;
    }

    return true;
}

void Album::criarPaginas(vector<Figurinha *> todasFigurinhas)
{
    vector<string> conteudosUnicos;
    vector<int> numDeFigurinhasPorConteudo;

    for (Figurinha *f : todasFigurinhas)
    {
        bool encontrado = false;

        for (int i = 0; i < conteudosUnicos.size(); i++)
        {
            if (f->getConteudo() == conteudosUnicos[i])
            {
                numDeFigurinhasPorConteudo[i]++;
                encontrado = true;
                break;
            }
        }

        if (!encontrado)
        {
            conteudosUnicos.push_back(f->getConteudo());
            numDeFigurinhasPorConteudo.push_back(1);
        }
    }

    int contador = 1;
    for (int i = 0; i < conteudosUnicos.size(); i++)
    {
        string conteudo = conteudosUnicos[i];
        int numFigurinhas = numDeFigurinhasPorConteudo[i];

        int numMin = contador;
        int numMax = contador + numFigurinhas - 1;
        contador = numMax + 1;

        Pagina novaPagina(conteudo, numMin, numMax);
        paginas.push_back(novaPagina);
    }
}

bool Album::disponibilizarFigurinhaParaTroca()
{
    if (mostrarFigurinhasDaColecao() == false)
    {
        return false;
    }

    while (true)
    {
        int escolha;
        cout << "Digite o número da figurinha que você deseja liberar para troca (0 - Voltar): ";
        cin >> escolha;

        if (escolha == 0)
        {
            return true;
        }

        for (Figurinha *f : figurinhas)
        {
            if (f->getNum() == escolha && f->getStatus() == 0)
            {
                f->disponibilizarParaTroca();
                cout << "Figurinha \'" << f->getNome() << "\' disponibilizada para troca!" << endl;
                break;
            }
        }
        mostrarFigurinhasDaColecao();
    }
}

bool Album::mostrarFigurinhasDisponiveisParaTroca()
{
    bool temDisponivel = false;

    for (Figurinha *f : figurinhas)
    {
        if (f->getStatus() == 2)
        {
            temDisponivel = true;
        }
    }

    if (temDisponivel)
    {
        cout << "Figurinhas disponíveis para troca:" << endl;

        for (Figurinha *f : figurinhas)
        {
            if (f->getStatus() == 2)
            {
                cout << f->getNum() << " - " << f->getNome() << endl;
            }
        }
    }

    if (!temDisponivel)
    {
        cout << "Nenhuma figurinha na coleção" << endl;
        return false;
    }

    return true;
}

void Album::abrirPacotinho(vector<Figurinha *> todasFigurinhas)
{
    vector<Figurinha *> pacotinho;
    int quantidade = 3;

    if (todasFigurinhas.empty())
        return;

    srand(time(nullptr));

    vector<int> indices;
    for (size_t i = 0; i < todasFigurinhas.size(); ++i)
        indices.push_back(i);

    cout << "Novas figurinhas:" << endl;

    for (int i = 0; i < quantidade; ++i)
    {
        int randPos = rand() % indices.size();
        int idx = indices[randPos];

        Figurinha *figurinhaMolde = todasFigurinhas[idx];

        Figurinha *novaFigurinha = figurinhaMolde->clone();

        figurinhas.push_back(novaFigurinha);

        cout << novaFigurinha->getNum() << " - " << novaFigurinha->getNome() << endl;

        indices[randPos] = indices.back();
        indices.pop_back();
    }
}

void Album::adicionarRequisicao(Troca &requisicao)
{
    requisicoesTroca.push_back(requisicao);
}

vector<Troca> &Album::getRequisicoes()
{
    return requisicoesTroca; // Retorna o vetor de requisições
}

void Album::removerFigurinha(Figurinha *figurinha)
{
    auto var = figurinhas.begin();
    while (var != figurinhas.end())
    {
        if (*var == figurinha)
        {
            figurinhas.erase(var);
            return;
        }

        var++;
    }
}

Figurinha *Album::obterFigurinhaPeloNumParaTroca(int num)
{
    for (Figurinha *f : figurinhas)
    {
        if (f->getNum() == num && f->getStatus() == 2)
        {
            return f;
        }
    }

    return nullptr;
}

bool Album::mostrarRequisicoes()
{
    if (requisicoesTroca.empty())
    {
        cout << "Sem requisições de troca no momento." << endl;
        return false;
    }

    cout << "Lista de requisições:" << endl;

    for (int i = 0; i < requisicoesTroca.size(); i++)
    {
        cout << i + 1 << " - ";
        requisicoesTroca[i].mostrar();
    }

    return true;
}
