#include <iostream>
#include "Dominio.h"
#include "Entidades.h"
#include "Interfaces.h"
#include "Apresentacao.h"
#include "Servico.h"
#include "Builders.h"
#include "BancoDados.h"



int main (int argc, char* argv[])
{
    AControle* controle;
    SystemBuildApresentacao init;

    controle = init.build ();

    controle->executar (controle);

    return 0;
}
