/** \file Teste.cpp
 *\brief Documento com todas as implementacoes das classes de testes de entidade e dominio
 * \author Alexandre Mitsuru Kaihara e Lucas silva
 * \since 29/03/19
 * \version 1.0
 */
#include "Teste.h"
#include "Entidades.h"
#include "Dominio.h"
#include <iostream>
#include <string.h>



int Teste::run(){

    setUp();

    testarCenarioSucesso();

    testarCenarioFalha();

    tearDown();

    return estado;

}



void TDCodigoSeguranca::testarCenarioSucesso()
{

    for(unsigned int i = 0; i <= VALOR_VALIDO; i++)
    {

        try
        {

            classeteste->setCodigo(i);

            if (classeteste->getCodigo() != i)
            {
                estado = FALHA;
            }

        }

        catch (std::invalid_argument excecao)
        {
            estado = FALHA;
        }

    }

}



void TDCodigoSeguranca::testarCenarioFalha()
{

    try
    {
        classeteste->setCodigo(VALOR_INVALIDO);
        estado = FALHA;
    }

    catch (std::invalid_argument excecao)
    {
        return;
    }

}



void TDCodigoSeguranca::setUp()
{

    classeteste = new CodigoSeguranca();
    estado = SUCESSO;

}



void TDCodigoSeguranca::tearDown()
{
    delete classeteste;
}



void TDCodigoEvento::testarCenarioSucesso()
{

    for(unsigned int i = 0; i <= VALOR_VALIDO; i++)
    {

        try
        {

            classeteste->setCodigo(i);

            if (classeteste->getCodigo() != i)
            {
                estado = FALHA;
            }

        }

        catch (std::invalid_argument excecao)
        {
            estado = FALHA;
        }

    }

}



void TDCodigoEvento::testarCenarioFalha()
{

    try
    {
        classeteste->setCodigo(VALOR_INVALIDO);
        estado = FALHA;
    }

    catch (std::invalid_argument excecao)
    {
        return;
    }

}



void TDCodigoEvento::setUp()
{

    classeteste = new CodigoEvento();
    estado = SUCESSO;

}



void TDCodigoEvento::tearDown()
{
    delete classeteste;
}



void TDCodigoIngresso::testarCenarioSucesso()
{

    for(unsigned int i = 0; i <= VALOR_VALIDO; i++)
    {

        try
        {

            classeteste->setCodigo(i);

            if (classeteste->getCodigo() != i)
            {
                estado = FALHA;
            }

        }
        catch (std::invalid_argument excecao)
        {
            estado = FALHA;
        }

    }

}



void TDCodigoIngresso::testarCenarioFalha()
{

    try
    {
        classeteste->setCodigo(VALOR_INVALIDO);
        estado = FALHA;
    }

    catch (std::invalid_argument excecao)
    {
        return;
    }

}



void TDCodigoIngresso::setUp()
{

    classeteste = new CodigoIngresso();
    estado = SUCESSO;

}



void TDCodigoIngresso::tearDown()
{
    delete classeteste;
}



void TDCodigoApresentacao::testarCenarioSucesso()
{

    for(unsigned int i = 0; i <= VALOR_VALIDO; i++)
    {

        try
        {

            classeteste->setCodigo(i);

            if (classeteste->getCodigo() != i)
            {
                estado = FALHA;
            }

        }

        catch (std::invalid_argument excecao)
        {
            estado = FALHA;
        }

    }

}



void TDCodigoApresentacao::testarCenarioFalha()
{

    try
    {
        classeteste->setCodigo(VALOR_INVALIDO);
        estado = FALHA;
    }

    catch (std::invalid_argument excecao)
    {
        return;
    }

}



void TDCodigoApresentacao::setUp()
{

    classeteste = new CodigoApresentacao();
    estado = SUCESSO;

}



void TDCodigoApresentacao::tearDown()
{
    delete classeteste;
}



void TDNomeEvento::testarCenarioSucesso()
{

    for(int i = 0; i < 5; i++)
    {

        try
        {

            classeteste->setNomeEvento (casosValidos[i]);

            if (strcmp(classeteste->getNomeEvento (), casosValidos[i]) != 0)
            {
                estado = FALHA;
            }

        }

        catch (std::invalid_argument excecao)
        {
            estado = FALHA;
        }

    }

}



void TDNomeEvento::testarCenarioFalha()
{
    for(int i = 0; i < 5; i++)
    {
        try
        {

            classeteste->setNomeEvento (casosInvalidos[i]);

            estado = FALHA;

        }

        catch (std::invalid_argument excecao)
        {
            return;
        }

    }

}



void TDNomeEvento::setUp()
{

    //Inicializar todas as strings com '\0'
    for(int i = 0; i < 5; i++)
    {

        casosValidos[i] = new char[21];

        casosInvalidos[i] = new char[21];

        for(int j = 0; j < 21; j++)
        {

            casosValidos[i][j] = '\0';

            casosInvalidos[i][j] = '\0';

        }
    }

    strcpy(casosValidos[0], "Algebra 1 UNB 2018");

    strcpy(casosValidos[1], "A");

    strcpy(casosValidos[2], "alexandre");

    strcpy(casosValidos[3], "TP1 eh top");

    strcpy(casosValidos[4], "a p r e n d e r");

    strcpy(casosInvalidos[0], "Algebra  UNB 2018 ");

    strcpy(casosInvalidos[1], "A@");

    strcpy(casosInvalidos[2], "alexandrea!@##$$@");

    strcpy(casosInvalidos[3], "TP1 eh top$#@$#@%");

    strcpy(casosInvalidos[4], "a  2  f  d  s  e");

    classeteste = new NomeEvento();

    estado = SUCESSO;

}



void TDNomeEvento::tearDown()
{
    delete classeteste;

    for(int i = 0; i < 5; i++)
    {

        delete casosValidos[i];

        delete casosInvalidos[i];

    }
}



void TDCidade::testarCenarioSucesso()
{

    for(int i = 0; i < 5; i++)
    {

        try
        {

            classeteste->setCidade (casosValidos[i]);

            if (strcmp(classeteste->getCidade (), casosValidos[i]) != 0)
            {
                estado = FALHA;
            }

        }

        catch (std::invalid_argument excecao)
        {
            estado = FALHA;
        }

    }

}



void TDCidade::testarCenarioFalha()
{
    for(int i = 0; i < 5; i++)
    {
        try
        {

            classeteste->setCidade (casosInvalidos[i]);

            estado = FALHA;

        }

        catch (std::invalid_argument excecao)
        {
            return;
        }

    }

}



void TDCidade::setUp()
{

    //Inicializar todas as strings com '\0'
    for(int i = 0; i < 5; i++)
    {

        casosValidos[i] = new char[17];

        casosInvalidos[i] = new char[17];

        for(int j = 0; j < 17; j++)
        {

            casosValidos[i][j] = '\0';

            casosInvalidos[i][j] = '\0';

        }
    }

    strcpy(casosValidos[0], "Formosa.GO");

    strcpy(casosValidos[1], "Brasilia.DF");

    strcpy(casosValidos[2], "Goiania");

    strcpy(casosValidos[3], "Pato Branco");

    strcpy(casosValidos[4], "Sao Paulo");

    strcpy(casosInvalidos[0], "Formosa-GO");

    strcpy(casosInvalidos[1], "Brasilia. Df");

    strcpy(casosInvalidos[2], "$Sao !Paulo");

    strcpy(casosInvalidos[3], "Pato  Branco");

    strcpy(casosInvalidos[4], "!!@#");

    classeteste = new Cidade();

    estado = SUCESSO;

}



void TDCidade::tearDown()
{
    delete classeteste;

    for(int i = 0; i < 5; i++)
    {

        delete casosValidos[i];

        delete casosInvalidos[i];

    }
}



void TDEstado::testarCenarioSucesso()
{

    for(int i = 0; i < 5; i++)
    {

        try
        {

            classeteste->setEstado (casosValidos[i]);

            if (strcmp(classeteste->getEstado (), casosValidos[i]) != 0)
            {
                estado = FALHA;
            }

        }

        catch (std::invalid_argument excecao)
        {
            estado = FALHA;
        }

    }

}



void TDEstado::testarCenarioFalha()
{
    for(int i = 0; i < 5; i++)
    {
        try
        {

            classeteste->setEstado (casosInvalidos[i]);

            estado = FALHA;

        }

        catch (std::invalid_argument excecao)
        {
            return;
        }

    }

}



void TDEstado::setUp()
{

    //Inicializar todas as strings com '\0'
    for(int i = 0; i < 5; i++)
    {

        casosValidos[i] = new char[3];

        casosInvalidos[i] = new char[3];

        for(int j = 0; j < 3; j++)
        {

            casosValidos[i][j] = '\0';

            casosInvalidos[i][j] = '\0';

        }
    }

    strcpy(casosValidos[0], "GO");

    strcpy(casosValidos[1], "DF");

    strcpy(casosValidos[2], "MA");

    strcpy(casosValidos[3], "PR");

    strcpy(casosValidos[4], "RJ");

    strcpy(casosInvalidos[0], "Go");

    strcpy(casosInvalidos[1], "ME");

    strcpy(casosInvalidos[2], "QW");

    strcpy(casosInvalidos[3], "Q!");

    strcpy(casosInvalidos[4], "!@");

    classeteste = new Estado();

    estado = SUCESSO;

}



void TDEstado::tearDown()
{
    delete classeteste;

    for(int i = 0; i < 5; i++)
    {

        delete casosValidos[i];

        delete casosInvalidos[i];

    }
}



void TDData::testarCenarioSucesso()
{

    for (int i = 0; i < 5; i++)
    {

        try
        {

            classeteste->setData (casosValidos[i]);

            if (strcmp (classeteste->getData (), casosValidos[i]) != 0)
            {
                estado = FALHA;
            }

        }

        catch (std::invalid_argument excecao)
        {
            estado = FALHA;
        }

    }

}



void TDData::testarCenarioFalha()
{
    for (int i = 0; i < 5; i++)
    {
        try
        {

            classeteste->setData (casosInvalidos[i]);

            estado = FALHA;

        }

        catch (std::invalid_argument excecao)
        {
            return;
        }

    }

}



void TDData::setUp()
{

    //Inicializar todas as strings com '\0'
    for(int i = 0; i < 5; i++)
    {

        casosValidos[i] = new char[9];

        casosInvalidos[i] = new char[9];

        for(int j = 0; j < 9; j++)
        {

            casosValidos[i][j] = '\0';

            casosInvalidos[i][j] = '\0';

        }
    }

    strcpy(casosValidos[0], "29/02/16");

    strcpy(casosValidos[1], "29/02/00");

    strcpy(casosValidos[2], "31/12/99");

    strcpy(casosValidos[3], "30/11/12");

    strcpy(casosValidos[4], "31/01/01");

    strcpy(casosInvalidos[0], "13/00/15");

    strcpy(casosInvalidos[1], "30/99/00");

    strcpy(casosInvalidos[2], "00/12/12");

    strcpy(casosInvalidos[3], "99/03\19");

    strcpy(casosInvalidos[4], "12/AS/12");

    classeteste = new Data();

    estado = SUCESSO;

}



void TDData::tearDown()
{
    delete classeteste;

    for(int i = 0; i < 5; i++)
    {

        delete casosValidos[i];

        delete casosInvalidos[i];

    }
}



void TDDataValidade::testarCenarioSucesso()
{

    for (int i = 0; i < 5; i++)
    {

        try
        {

            classeteste->setDataValidade (casosValidos[i]);

            if (strcmp(classeteste->getDataValidade (), casosValidos[i]) != 0)
            {
                estado = FALHA;
            }

        }

        catch (std::invalid_argument excecao)
        {
            estado = FALHA;
        }

    }

}



void TDDataValidade::testarCenarioFalha()
{
    for (int i = 0; i < 5; i++)
    {
        try
        {

            classeteste->setDataValidade (casosInvalidos[i]);

            estado = FALHA;

        }

        catch (std::invalid_argument excecao)
        {
            return;
        }

    }

}



void TDDataValidade::setUp()
{

    //Inicializar todas as strings com '\0'
    for(int i = 0; i < 5; i++)
    {

        casosValidos[i] = new char[6];

        casosInvalidos[i] = new char[6];

        for(int j = 0; j < 6; j++)
        {

            casosValidos[i][j] = '\0';

            casosInvalidos[i][j] = '\0';

        }
    }

    strcpy(casosValidos[0], "02/16");

    strcpy(casosValidos[1], "02/00");

    strcpy(casosValidos[2], "12/99");

    strcpy(casosValidos[3], "11/12");

    strcpy(casosValidos[4], "01/01");

    strcpy(casosInvalidos[0], "00/15");

    strcpy(casosInvalidos[1], "99/00");

    strcpy(casosInvalidos[2], "00/12");

    strcpy(casosInvalidos[3], "03\19");

    strcpy(casosInvalidos[4], "AS/12");

    classeteste = new DataValidade();

    estado = SUCESSO;

}



void TDDataValidade::tearDown()
{
    delete classeteste;

    for(int i = 0; i < 5; i++)
    {

        delete casosValidos[i];

        delete casosInvalidos[i];

    }
}



void TDHorario::testarCenarioSucesso()
{

    for (int i = 0; i < 5; i++)
    {

        try
        {

            classeteste->setHorario (casosValidos[i]);

            if (strcmp(classeteste->getHorario (), casosValidos[i]) != 0)
            {
                estado = FALHA;
            }

        }

        catch (std::invalid_argument excecao)
        {
            estado = FALHA;
        }

    }

}



void TDHorario::testarCenarioFalha()
{
    for (int i = 0; i < 5; i++)
    {
        try
        {

            classeteste->setHorario (casosInvalidos[i]);

            estado = FALHA;

        }

        catch (std::invalid_argument excecao)
        {
            return;
        }

    }

}



void TDHorario::setUp()
{

    //Inicializar todas as strings com '\0'
    for(int i = 0; i < 5; i++)
    {

        casosValidos[i] = new char[6];

        casosInvalidos[i] = new char[6];

        for(int j = 0; j < 6; j++)
        {

            casosValidos[i][j] = '\0';

            casosInvalidos[i][j] = '\0';

        }
    }

    strcpy(casosValidos[0], "07:00");

    strcpy(casosValidos[1], "22:45");

    strcpy(casosValidos[2], "12:15");

    strcpy(casosValidos[3], "13:30");

    strcpy(casosValidos[4], "21:00");

    strcpy(casosInvalidos[0], "07/15");

    strcpy(casosInvalidos[1], "06:00");

    strcpy(casosInvalidos[2], "00:00");

    strcpy(casosInvalidos[3], "12:03");

    strcpy(casosInvalidos[4], "23:00");

    classeteste = new Horario();

    estado = SUCESSO;

}



void TDHorario::tearDown()
{
    delete classeteste;

    for(int i = 0; i < 5; i++)
    {

        delete casosValidos[i];

        delete casosInvalidos[i];

    }
}



void TUPreco::setUp ()
{
    preco = new Preco ();

    estado = SUCESSO;
}


void TUPreco::tearDown ()
{
    delete preco;
}



void TUPreco::testarCenarioSucesso ()
{
    try
    {
        preco->setPreco (VALOR_VALIDO);

        if(preco->getPreco () != VALOR_VALIDO){

            estado = FALHA;

        }
    }

    catch (std::invalid_argument excecao)
    {
        estado = FALHA;
    }
}



void TUPreco::testarCenarioFalha()
{
    try
    {
        preco->setPreco (VALOR_INVALIDO);

        estado = FALHA;

    }

    catch (std::invalid_argument excecao)
    {
        return;
    }
}



int TUPreco::run ()
{
    setUp ();

    testarCenarioSucesso ();

    testarCenarioFalha ();

    tearDown ();

    return estado;
}



void TUNumeroSala::setUp ()
{
    numeroSala = new NumeroSala ();

    estado = SUCESSO;

}



void TUNumeroSala::tearDown ()
{
    delete numeroSala;
}



void TUNumeroSala::testarCenarioSucesso ()
{
    try
    {
        numeroSala->setNumeroSala (VALOR_VALIDO);

        if(numeroSala->getNumeroSala () != VALOR_VALIDO){
            estado = FALHA;
        }
    }

    catch (std::invalid_argument excecao)
    {
        estado = FALHA;
    }
}



void TUNumeroSala::testarCenarioFalha ()
{
    try
    {
        numeroSala->setNumeroSala (VALOR_INVALIDO);

        estado = FALHA;
    }

    catch (std::invalid_argument excecao)
    {
        return;
    }
}



int TUNumeroSala::run ()
{
    setUp ();

    testarCenarioSucesso ();

    testarCenarioFalha ();

    tearDown ();

    return estado;
}



void TUDisponibilidade::setUp ()
{
    disponibilidade = new Disponibilidade ();

    estado = SUCESSO;
}



void TUDisponibilidade::tearDown ()
{
    delete disponibilidade;
}



void TUDisponibilidade::testarCenarioSucesso ()
{
    try
    {
        disponibilidade->setDisponibilidade (VALOR_VALIDO);

        if (disponibilidade->getDisponibilidade () != VALOR_VALIDO){
            estado = FALHA;
        }
    }

    catch (std::invalid_argument excecao)
    {
        estado = FALHA;
    }
}



void TUDisponibilidade::testarCenarioFalha ()
{
    try
    {
        disponibilidade->setDisponibilidade (VALOR_INVALIDO);

        estado = FALHA;
    }

    catch (std::invalid_argument excecao)
    {
        return;
    }
}



int TUDisponibilidade::run ()
{
    setUp ();

    testarCenarioSucesso ();

    testarCenarioFalha ();

    tearDown ();

    return estado;
}



void TUFaixaEtaria::setUp ()
{
    faixaEtaria = new FaixaEtaria ();

    estado = SUCESSO;
}



void TUFaixaEtaria::tearDown ()
{
    delete faixaEtaria;
}



void TUFaixaEtaria::testarCenarioSucesso ()
{
    try
    {
        faixaEtaria->setFaixaEtaria(VALOR_VALIDO);

        if(faixaEtaria->getFaixaEtaria() != VALOR_VALIDO){
            estado = FALHA;
        }
    }

    catch (std::invalid_argument excecao)
    {
        estado = FALHA;
    }
}



void TUFaixaEtaria::testarCenarioFalha ()
{
    try
    {
        faixaEtaria->setFaixaEtaria (VALOR_INVALIDO);

        estado = FALHA;
    }

    catch (std::invalid_argument excecao)
    {
        return;
    }
}



int TUFaixaEtaria::run ()
{
    setUp ();

    testarCenarioSucesso ();

    testarCenarioFalha ();

    tearDown ();

    return estado;
}



void TUClasseEvento::setUp ()
{
    classeEvento = new ClasseEvento ();

    estado = SUCESSO;
}



void TUClasseEvento::tearDown ()
{
    delete classeEvento;
}



void TUClasseEvento::testarCenarioSucesso ()
{
    try
    {
        classeEvento->setClasseEvento (VALOR_VALIDO);

        if(classeEvento->getClasseEvento () != VALOR_VALIDO){
            estado = FALHA;
        }
    }
    catch(std::invalid_argument excecao)
    {
        estado = FALHA;
    }
}



void TUClasseEvento::testarCenarioFalha ()
{
    try
    {
        classeEvento->setClasseEvento (VALOR_INVALIDO);

        estado = FALHA;
    }

    catch(std::invalid_argument excecao)
    {
        return;
    }
}



int TUClasseEvento::run ()
{
    setUp ();

    testarCenarioSucesso ();

    testarCenarioFalha ();

    tearDown ();

    return estado;

}



void TUSenha::setUp ()
{
    senha = new Senha ();

    estado = SUCESSO;
}



void TUSenha::tearDown ()
{
    delete senha;
}



void TUSenha::testarCenarioSucesso ()
{
    try
    {
        senha->setSenha (VALOR_VALIDO);

        if(senha->getSenha () != VALOR_VALIDO)
        {
            estado = FALHA;
        }
    }

    catch (std::invalid_argument excecao)
    {
        estado = FALHA;
    }
}



void TUSenha::testarCenarioFalha ()
{
    try
    {
        senha->setSenha (VALOR_INVALIDO);

        estado = FALHA;

    }

    catch (std::invalid_argument excecao)
    {
        return;
    }
}



int TUSenha::run ()
{
    setUp ();

    testarCenarioSucesso ();

    testarCenarioFalha ();

    tearDown ();

    return estado;
}



void TUCPF::setUp ()
{
    cpf = new CPF ();

    estado = SUCESSO;
}



void TUCPF::tearDown ()
{
    delete cpf;
}



void TUCPF::testarCenarioSucesso ()
{
    try
    {
        cpf->setCPF (VALOR_VALIDO);

        if (cpf->getCPF () != VALOR_VALIDO){
            estado = FALHA;
        }
    }

    catch (std::invalid_argument excecao)
    {
        estado = FALHA;
    }
}



void TUCPF::testarCenarioFalha ()
{
    try
    {
        cpf->setCPF (VALOR_INVALIDO);

        estado = FALHA;

    }

    catch (std::invalid_argument excecao)
    {
        return;
    }
}



int TUCPF::run ()
{
    setUp ();

    testarCenarioSucesso ();

    testarCenarioFalha ();

    tearDown ();

    return estado;
}



void TUNumeroCartaoCredito::setUp ()
{
    numeroCartaoCredito = new NumeroCartaoCredito ();

    estado = SUCESSO;
}



void TUNumeroCartaoCredito::tearDown ()
{
    delete numeroCartaoCredito;
}



void TUNumeroCartaoCredito::testarCenarioSucesso ()
{
    try
    {
        numeroCartaoCredito->setNumeroCartaoCredito (VALOR_VALIDO);

        if (numeroCartaoCredito->getNumeroCartaoCredito () != VALOR_VALIDO){
            estado = FALHA;
        }
    }

    catch (std::invalid_argument excecao)
    {
        estado = FALHA;
    }
}



void TUNumeroCartaoCredito::testarCenarioFalha ()
{
    try
    {
        numeroCartaoCredito->setNumeroCartaoCredito (VALOR_INVALIDO);

        estado = FALHA;

    }

    catch (std::invalid_argument excecao)
    {
        return;
    }
}



int TUNumeroCartaoCredito::run()
{
    setUp();

    testarCenarioSucesso();

    testarCenarioFalha();

    tearDown();

    return estado;

}



void TEUsuario::testarCenarioFalha(){}
void TEUsuario::testarCenarioSucesso()
{
    CPF cpf;

    Senha senha;

    cpf.setCPF ("529.982.247-25");

    senha.setSenha ("Lucas1");

    classeteste->setCPF (cpf);

    classeteste->setSenha (senha);

    if (classeteste->getCPF () != cpf.getCPF () && classeteste->getSenha() != senha.getSenha ())
    {
        estado = FALHA;
    }

}



void TEUsuario::setUp()
{

    classeteste = new Usuario();
    estado = SUCESSO;

}



void TEUsuario::tearDown()
{
    delete classeteste;
}



void TEEvento::testarCenarioFalha(){}
void TEEvento::testarCenarioSucesso()
{

    CodigoEvento codigoEvento;

    NomeEvento nomeEvento;

    Cidade cidade;

    Estado state;

    ClasseEvento classeEvento;

    FaixaEtaria faixaEtaria;

    codigoEvento.setCodigo(999);

    char testenomeEvento[21];

    strcpy (testenomeEvento, "Rock in rio");

    nomeEvento.setNomeEvento (testenomeEvento);

    char testenomeCidade[17];

    strcpy (testenomeCidade, "Rio de Janeiro");

    cidade.setCidade (testenomeCidade);

    char testenomeEstado[3];

    strcpy (testenomeEstado, "RJ");

    state.setEstado(testenomeEstado);

    classeEvento.setClasseEvento(4);

    std::string testefaixaEtaria = "L";

    faixaEtaria.setFaixaEtaria(testefaixaEtaria);

    classeteste->setCodigoEvento (codigoEvento);

    classeteste->setNomeEvento (nomeEvento);

    classeteste->setCidade (cidade);

    classeteste->setEstado (state);

    classeteste->setClasseEvento (classeEvento);

    classeteste->setFaixaEtaria (faixaEtaria);

    if (classeteste->getCodigoEvento () != codigoEvento.getCodigo ()
        && classeteste->getNomeEvento () != nomeEvento.getNomeEvento ()
        && classeteste->getCidade () != cidade.getCidade ()
        && classeteste->getEstado () != state.getEstado ()
        && classeteste->getClasseEvento () != classeEvento.getClasseEvento ()
        && classeteste->getFaixaEtaria () != faixaEtaria.getFaixaEtaria ())
    {
        estado = FALHA;
    }

}



void TEEvento::setUp()
{

    classeteste = new Evento();
    estado = SUCESSO;

}



void TEEvento::tearDown()
{
    delete classeteste;
}



void TEApresentacao::testarCenarioFalha(){}
void TEApresentacao::testarCenarioSucesso()
{

    CodigoApresentacao codigoApresentacao;

    Data data;

    Horario horario;

    Preco preco;

    NumeroSala numeroSala;

    Disponibilidade disponibilidade;


    //Set de valores válidos em cada domínio para armazenar nas entidades
    codigoApresentacao.setCodigo (123);

    char testeData[9];

    strcpy (testeData, "30/04/19");

    data.setData (testeData);

    char testeHorario[6];

    strcpy (testeHorario, "07:15");

    horario.setHorario (testeHorario);

    preco.setPreco (199.99);

    numeroSala.setNumeroSala (2);

    disponibilidade.setDisponibilidade (100);


    //Teste de set de valores nas entidades
    classeteste->setCodigoApresentacao (codigoApresentacao);

    classeteste->setData (data);

    classeteste->setHorario (horario);

    classeteste->setPreco (preco);

    classeteste->setNumeroSala (numeroSala);

    classeteste->setDisponibilidade (disponibilidade);

    if (classeteste->getCodigoApresentacao () != codigoApresentacao.getCodigo ()
        && classeteste->getData () != data.getData ()
        && classeteste->getHorario() != horario.getHorario ()
        && classeteste->getPreco() != preco.getPreco ()
        && classeteste->getNumeroSala () != numeroSala.getNumeroSala ()
        && classeteste->getDisponibilidade () != disponibilidade.getDisponibilidade ())
    {
        estado = FALHA;
    }

}



void TEApresentacao::setUp()
{

    classeteste = new Apresentacao();
    estado = SUCESSO;

}



void TEApresentacao::tearDown()
{
    delete classeteste;
}



void TEIngresso::testarCenarioFalha(){}
void TEIngresso::testarCenarioSucesso()
{

    CodigoIngresso CodigoIngresso;


    //Set de valores válidos em cada domínio para armazenar nas entidades
    CodigoIngresso.setCodigo (21839);


    //Teste de set de valores nas entidades
    classeteste->setCodigoIngresso (CodigoIngresso);

    if (classeteste->getCodigoIngresso () != CodigoIngresso.getCodigo ())
    {
        estado = FALHA;
    }

}



void TEIngresso::setUp()
{

    classeteste = new Ingresso();
    estado = SUCESSO;

}



void TEIngresso::tearDown()
{
    delete classeteste;
}




void TECartaoCredito::testarCenarioFalha(){}
void TECartaoCredito::testarCenarioSucesso()
{

    NumeroCartaoCredito numeroCartaoCredito;

    CodigoSeguranca codigoSeguranca;

    DataValidade dataValidade;


    //Set de valores válidos em cada domínio para armazenar nas entidades

    std::string testeNumeroCartaoCredito = "5373130930803211";

    numeroCartaoCredito.setNumeroCartaoCredito (testeNumeroCartaoCredito);

    codigoSeguranca.setCodigo (232);

    char testeDataValidade[6];

    strcpy (testeDataValidade, "04/19");

    dataValidade.setDataValidade (testeDataValidade);


    //Teste de set de valores nas entidades
    classeteste->setNumeroCartaoCredito (numeroCartaoCredito);

    classeteste->setCodigoSeguranca (codigoSeguranca);

    classeteste->setDataValidade (dataValidade);


    if (classeteste->getNumeroCartaoCredito () != numeroCartaoCredito.getNumeroCartaoCredito ()
        && classeteste->getCodigoSeguranca () != codigoSeguranca.getCodigo ()
        && classeteste->getDataValidade () != dataValidade.getDataValidade ())
    {
        estado = FALHA;
    }

}



void TECartaoCredito::setUp()
{

    classeteste = new CartaoCredito();
    estado = SUCESSO;

}



void TECartaoCredito::tearDown()
{
    delete classeteste;
}


