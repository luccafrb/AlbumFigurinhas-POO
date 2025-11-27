#include "Figurinha.h"
#include "FigurinhaPokemon.h"
#include "FigurinhaEvolucao.h"
#include "FigurinhaLocal.h"
#include "FigurinhaMegaEvolucao.h"
#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>

using namespace std;

Figurinha::Figurinha(int num, string nome, string cont, int status)
    : num(num), nome(nome), conteudo(cont), status(status)
{
}

Figurinha::~Figurinha() {}

bool Figurinha::colar()
{
    if (status == 0)
    {
        status = 1;
        cout << "Figurinha colada com sucesso!" << endl;
        return true;
    }
    else if (status == 1)
    {
        cout << "Figurinha já estava colada!" << endl;
        return true;
    }
    else
    {
        cout << "Falha em colar a figurinha!" << endl;
        return false;
    }
}

void Figurinha::disponibilizarParaTroca()
{
    status = 2;
}

void Figurinha::indisponibilizarParaTroca()
{
    status = 0;
}

vector<Figurinha *> Figurinha::CarregarDeCsv(const string &arquivo)
{
    // A coleção agora armazena ponteiros, permitindo polimorfismo e herança.
    vector<Figurinha *> figurinhas;

    ifstream fsIn(arquivo);
    if (!fsIn.is_open())
    {
        cerr << "Erro ao abrir arquivo: " << arquivo << endl; // Usar cerr para erros
        return figurinhas;
    }

    string linha;
    getline(fsIn, linha); // Pula cabeçalho

    while (getline(fsIn, linha))
    {
        if (linha.empty())
            continue;

        stringstream ss(linha);
        string numStr, nome, conteudo, tipoFigurinha;
        string dado1, dado2, dado3, dado4; // Campos específicos
        Figurinha *novaFigurinha = nullptr;
        int statusInicial = 0; // Todas figurinhas começam na coleção

        // 1. LÊ OS CAMPOS BASE
        getline(ss, numStr, ',');
        getline(ss, nome, ',');
        getline(ss, conteudo, ',');
        getline(ss, tipoFigurinha, ','); // CAMPO CHAVE PARA DECISÃO (TIPO)

        // 2. LÊ TODOS OS DADOS ESPECÍFICOS (para simplificar a leitura da linha)
        getline(ss, dado1, ','); // dado_1
        getline(ss, dado2, ','); // dado_2
        getline(ss, dado3, ','); // dado_3
        getline(ss, dado4);      // dado_4 (lê até o final da linha)

        int num = stoi(numStr);

        // 3. DECIDE QUAL CLASSE CONCRETA INSTANCIAR DINAMICAMENTE
        if (tipoFigurinha == "POKEMON")
        {
            // FigurinhaPokemon(num, nome, cont, status, nivel, tipoPrincipal)
            int nivel = stoi(dado1);
            string tipoPrincipal = dado2;
            novaFigurinha = new FigurinhaPokemon(num, nome, conteudo, statusInicial, nivel, tipoPrincipal);
        }
        else if (tipoFigurinha == "LOCAL")
        {
            // FigurinhaLocal(num, nome, cont, status, tipo, regiao, lider)
            string regiao = dado1;
            string liderGinasio = dado2;
            novaFigurinha = new FigurinhaLocal(num, nome, conteudo, statusInicial, tipoFigurinha, regiao, liderGinasio);
        }
        else if (tipoFigurinha == "EVOLUCAO")
        {
            // FigurinhaEvolucao(num, nome, cont, status, estagio, proximoPokemon)
            string estagio = dado1;
            string proximoPokemon = dado2;
            novaFigurinha = new FigurinhaEvolucao(num, nome, conteudo, statusInicial, estagio, proximoPokemon);
        }
        else if (tipoFigurinha == "MEGA")
        {
            // FigurinhaMegaEvolucao(num, nome, cont, status, estagio, proximoPokemon, pedraMega)
            string estagio = dado1;
            string proximoPokemon = dado2;
            string pedraMega = dado3;
            novaFigurinha = new FigurinhaMegaEvolucao(num, nome, conteudo, statusInicial, estagio, proximoPokemon, pedraMega);
        }
        else
        {
            cerr << "AVISO: Linha ignorada devido a TIPO desconhecido: " << nome << endl;
        }

        // 4. ADICIONA O PONTEIRO À COLEÇÃO
        if (novaFigurinha != nullptr)
        {
            figurinhas.push_back(novaFigurinha);
        }
    }

    fsIn.close();
    return figurinhas;
}