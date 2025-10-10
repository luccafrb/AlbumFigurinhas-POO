#ifndef COLAR_FIGURINHAS_H
#define COLAR_FIGURINHAS_H

#include <iostream>
#include <vector>
#include <string>

class ColarFigurinhas {
private:
    std::vector<int> coladas;
    std::vector<int> repetidas;

public:
    ColarFigurinhas();               // Construtor
    void carregarCSV();              // Lê os CSVs
    void salvarCSV();                // Salva os CSVs
    void colarFigurinha(int numero); // Cola uma figurinha
    void mostrarFigurinhas();        // Mostra as listas
};

#endif
