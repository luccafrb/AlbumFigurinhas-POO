#include "ColarFigurinhas.h"
#include <fstream>

ColarFigurinhas::ColarFigurinhas() {
    carregarCSV(); // Lê automaticamente ao criar o objeto
}

// Lê os CSVs e carrega para os vetores
void ColarFigurinhas::carregarCSV() {
    std::ifstream coladasFile("Dados/figurinhas_coladas.csv");
    std::ifstream repetidasFile("Dados/figurinhas_repetidas.csv");
    std::string linha;

    coladas.clear();
    repetidas.clear();

    if (coladasFile.is_open()) {
        getline(coladasFile, linha); // pula o cabeçalho
        while (getline(coladasFile, linha)) {
            if (!linha.empty())
                coladas.push_back(std::stoi(linha));
        }
        coladasFile.close();
    }

    if (repetidasFile.is_open()) {
        getline(repetidasFile, linha);
        while (getline(repetidasFile, linha)) {
            if (!linha.empty())
                repetidas.push_back(std::stoi(linha));
        }
        repetidasFile.close();
    }

    std::cout << "📂 CSVs carregados automaticamente (" 
              << coladas.size() << " coladas, " 
              << repetidas.size() << " repetidas).\n";
}

// Cola uma figurinha nova
void ColarFigurinhas::colarFigurinha(int numero) {
    for (int f : coladas) {
        if (f == numero) {
            repetidas.push_back(numero);
            std::cout << "⚠️ Figurinha " << numero << " já colada! Foi para repetidas.\n";
            return;
        }
    }

    coladas.push_back(numero);
    std::cout << "✅ Figurinha " << numero << " colada com sucesso!\n";
}

// Mostra figurinhas coladas e repetidas
void ColarFigurinhas::mostrarFigurinhas() {
    std::cout << "\n=== FIGURINHAS COLADAS ===\n";
    for (int f : coladas)
        std::cout << f << " ";
    std::cout << "\n\n=== FIGURINHAS REPETIDAS ===\n";
    for (int f : repetidas)
        std::cout << f << " ";
    std::cout << "\n";
}

// Salva os vetores nos arquivos CSV
void ColarFigurinhas::salvarCSV() {
    std::ofstream coladasFile("figurinhas_coladas.csv");
    coladasFile << "Figurinhas Coladas\n";
    for (int f : coladas)
        coladasFile << f << "\n";
    coladasFile.close();

    std::ofstream repetidasFile("figurinhas_repetidas.csv");
    repetidasFile << "Figurinhas Repetidas\n";
    for (int f : repetidas)
        repetidasFile << f << "\n";
    repetidasFile.close();

    std::cout << "Arquivos CSV salvos com sucesso!\n";
}
