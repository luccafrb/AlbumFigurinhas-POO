#include "Album.h"

#include <iostream>
#include <ctime>

using namespace std;

Album::Album(vector<Figurinha> &todasFigurinhas)
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

        Figurinha &f = figurinhas[escolha - 1];
        f.colar();

        for (Pagina &p : paginas)
        {
            if (p.getTitulo() == f.getConteudo())
            {
                p.adicionarFigurinha(&f);
                cout << "Figurinha " << f.getNome() << " colada na página " << p.getTitulo() << "!" << endl;
                break;
            }
        }
    }

    return true;
}

void Album::adicionarFigurinha(Figurinha &figurinha)
{
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

void Album::mostrarFigurinhasColadas()
{
    if (figurinhas.size() == 0)
    {
        cout << "Sem figurinhas." << endl;
        return;
    }

    for (Figurinha &f : figurinhas)
    {
        if (f.getStatus() == 1)
        {
            cout << f.getNome() << endl;
        }
    }
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
}

void Album::criarPaginas(vector<Figurinha> &todasFigurinhas)
{
    vector<string> conteudosUnicos;
    vector<int> numDeFigurinhasPorConteudo;

    for (Figurinha &f : todasFigurinhas)
    {
        bool encontrado = false;

        for (int i = 0; i < conteudosUnicos.size(); i++)
        {
            if (f.getConteudo() == conteudosUnicos[i])
            {
                numDeFigurinhasPorConteudo[i]++;
                encontrado = true;
                break;
            }
        }

        if (!encontrado)
        {
            conteudosUnicos.push_back(f.getConteudo());
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

void Album::abrirPacotinho(vector<Figurinha> &todasFigurinhas)
{
    vector<Figurinha> pacotinho;
    int quantidade = 3;

    if (todasFigurinhas.empty())
        return;

    srand(time(nullptr));

    vector<int> indices;
    for (size_t i = 0; i < todasFigurinhas.size(); ++i)
        indices.push_back(i);

    for (int i = 0; i < quantidade; ++i)
    {
        int randPos = rand() % indices.size();
        int idx = indices[randPos];

        pacotinho.push_back(todasFigurinhas[idx]);

        indices[randPos] = indices.back();
        indices.pop_back();
    }

    cout << "-- Novas figurinhas --" << endl;
    for (Figurinha f : pacotinho)
    {
        cout << f.getNome() << endl;
        adicionarFigurinha(f);
    }

    cout << "---------------------" << endl;
    cout << "Pressione ENTER para continuar..." << endl;
    getchar();
    getchar();
}
