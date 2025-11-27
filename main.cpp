#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

#include "Classes/Usuario.h"
#include "Classes/Figurinha.h"
#include "program.h"

using namespace std;

int main()
{
    try
    {
        program p;
        p.inicializate();
        p.run();
    }
    catch (const exception &e)
    {
        cerr << "Erro: " << e.what() << endl;
        return 1;
    }

    return 0;
}
