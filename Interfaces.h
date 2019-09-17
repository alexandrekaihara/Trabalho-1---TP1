/** \file Interfaces.h
 * \brief   Documento com todas as classes de interfaces
 * \author  Alexandre Mitsuru Kaihara e Lucas silva
 * \since   30/04/19
 * \version 1.0
 */
//Histórico de alterações:
#ifndef INTERFACES_H_INCLUDED
#define INTERFACES_H_INCLUDED

#include "Dominio.h"
#include "Entidades.h"
#include "BancoDados.h"



class IAAutenticacao
{
public:


    virtual Usuario* executarAutenticar () = 0;


};



class IAUsuario
{
public:


    virtual void executarUsuario (Usuario** ausuario) = 0;


};



class IAEvento
{
public:


    virtual void executarEvento (Usuario* ausuario) = 0;


    virtual void executarCriarEvento (Usuario* ausuario) = 0;


    virtual void executarConsultarEvento () = 0;


    virtual void executarEditarEvento (Usuario* ausuario) = 0;


    virtual void executarStatusEvento (Usuario* ausuario) = 0;


};



class IAVendas
{
public:


    virtual void executarVendas (Usuario* ausuario) = 0;


};



class ISAutenticacao
{
public:


    virtual int autenticar (CPF acpf, Senha asenha, Database* database) = 0;


};



class ISUsuario
{
public:


    virtual int cadastrar (CPF, Senha, NumeroCartaoCredito, CodigoSeguranca, DataValidade) throw (std::invalid_argument) = 0;


    virtual int descadastrar (CPF) = 0;


};



class ISEvento
{
public:


    virtual int criarEvento (Evento* aevento, Apresentacao** aapresentacao, Usuario* usuario) = 0;


    virtual int consultar (Data adataInicio, Data adataFim, Cidade, Estado) = 0;


    virtual int editarEvento (Evento* aevento,  int aparam, Usuario* ausuario, CodigoEvento acodigoevento) = 0;


    virtual int deletarEvento (CodigoEvento acodigoEvento, Usuario* ausuario) = 0;


    virtual int statusvenda (CodigoEvento acodigoEvento, Usuario* ausuario) = 0;


};



class ISVendas
{
public:


    virtual int comprar (CodigoApresentacao, int aquantidadeIngresso, Usuario* ausuario) = 0;


};



#endif
