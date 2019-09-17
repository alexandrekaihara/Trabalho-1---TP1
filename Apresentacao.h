/** \file Apresentacao.h
 *\brief Documento com todas as classes da camada de apresentacao
 * \author Alexandre Mitsuru Kaihara e Lucas silva
 * \since 02/05/19
 * \version 1.0
 */
//Histórico de alterações:
#ifndef APRESENTACAO_H_INCLUDED
#define APRESENTACAO_H_INCLUDED

#include "Dominio.h"
#include "Entidades.h"
#include "Interfaces.h"
#include "Servico.h"
#include "validadores.h"



/** \class
 * \brief
 *
 * \param
 * \param
 * \return
 *
 */
class AControle
{
private:

    IAAutenticacao  *objetoIAAutenticacao;

    IAUsuario       *objetoIAUsuario;

    IAEvento        *objetoIAEvento;

    IAVendas        *objetoIAVEndas;

public:


    void setIAAutenticacao (IAAutenticacao *aIAAutenticacao)
    {
        this->objetoIAAutenticacao = aIAAutenticacao;
    }


    void setIAUsuario (IAUsuario *aIAUsuario)
    {
        this->objetoIAUsuario = aIAUsuario;
    }


    void setIAEvento (IAEvento *aIAEvento)
    {
        this->objetoIAEvento= aIAEvento;
    }


    void setIAVendas (IAVendas *aIAVendas)
    {
        this->objetoIAVEndas = aIAVendas;
    }


    void executar (AControle* acontrole);


};



/** \class
 * \brief
 *
 * \param
 * \param
 * \return
 *
 */
class AAutenticar : public IAAutenticacao
{
private:

    ISAutenticacao *objetoISAutenticacao;

public:


    void setISAutenticacao (ISAutenticacao *aISAutenticacao)
    {
        this->objetoISAutenticacao = aISAutenticacao;
    }


    Usuario* executarAutenticar ();


};



/** \class
 * \brief
 *
 * \param
 * \param
 * \return
 *
 */
class AUsuario : public IAUsuario
{
private:

    ISUsuario *objetoISUsuario;

public:


    void setISUsuario (ISUsuario *aISUsuario)
    {
        this->objetoISUsuario = aISUsuario;
    }


    void executarUsuario (Usuario** ausuario);


};



/** \class
 * \brief
 *
 * \param
 * \param
 * \return
 *
 */
class AEvento: public IAEvento
{
private:

    ISEvento *objetoISEvento;

public:


    void setISEvento (ISEvento *aISEvento)
    {
        this->objetoISEvento = aISEvento;
    }


    void executarEvento (Usuario* ausuario);


    void executarCriarEvento (Usuario* ausuario);


    void executarConsultarEvento ();


    void executarEditarEvento (Usuario* ausuario);


    void executarStatusEvento (Usuario* ausuario);


};



/** \class
 * \brief
 *
 * \param
 * \param
 * \return
 *
 */
class AVendas : public IAVendas
{
private:

    ISVendas *objetoISVendas;

public:


    void setISVendas (ISVendas *aISVendas)
    {
        this->objetoISVendas = aISVendas;
    }


    void executarVendas (Usuario* ausuario);


};



#endif
