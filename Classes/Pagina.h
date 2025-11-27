#pragma once
#include <string>
#include "Figurinha.h"

class Pagina
{
private:
    vector<Figurinha *> figurinhas;
    string titulo;
    int numMax, numMin;

public:
    Pagina(string titulo, int numMin, int numMax);
    ~Pagina();

    int getNumMin();
    int getNumMax();
    void mostrarFigurinhas();
    void adicionarFigurinha(Figurinha *figurinha);
    string getTitulo();
};