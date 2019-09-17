/** \file Servico.cpp
 * \brief Documento com todas as implementacoes das classes dos builders
 * \author Alexandre Mitsuru Kaihara e Lucas silva
 * \since 21/05/19
 * \version 1.0
 */
#include "Builders.h"



AControle* SystemBuildApresentacao::build ()
{
    AControle* controle = new AControle ();

    // Cria Todos os módulos do sistema e interliga todas as interfaces de apresentacao e servico
    AAutenticar* aautenticar = new AAutenticar ();
    aautenticar->setISAutenticacao (new SAutenticar ());
    controle->setIAAutenticacao (aautenticar);

    AUsuario* ausuario = new AUsuario ();
    ausuario->setISUsuario (new SUsuario ());
    controle->setIAUsuario (ausuario);

    AEvento* aevento = new AEvento ();
    aevento->setISEvento (new SEvento ());
    controle->setIAEvento (aevento);

    AVendas* avendas = new AVendas ();
    avendas->setISVendas (new SVendas ());
    controle->setIAVendas (avendas);

    return controle;
}
