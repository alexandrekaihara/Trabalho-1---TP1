/** \file Servico.h
 * \brief Documento com todas as classes da camada de servicos
 * \author Alexandre Mitsuru Kaihara e Lucas silva
 * \since 02/05/19
 * \version 1.0
 */
//Histórico de alterações:
#ifndef SERVICO_H_INCLUDED
#define SERVICO_H_INCLUDED

#include "Entidades.h"
#include "Dominio.h"
#include "Interfaces.h"
#include "Apresentacao.h"
#include "sqlite3.h"



/** \class
 * \brief
 *
 * \param
 * \param
 * \return
 *
 */
class SAutenticar : public ISAutenticacao
{
public:


    int autenticar (CPF acpf, Senha asenha, Database* database);


};



/** \class
 * \brief
 *
 * \param
 * \param
 * \return
 *
 */
class SUsuario : public ISUsuario
{
public:


    int cadastrar (CPF, Senha, NumeroCartaoCredito, CodigoSeguranca, DataValidade) throw (std::invalid_argument);


    int descadastrar (CPF acpf);


};



/** \class
 * \brief
 *
 * \param
 * \param
 * \return
 *
 */
class SEvento: public ISEvento
{
public:


    int criarEvento (Evento* aevento, Apresentacao** aapresentacao, Usuario* usuario);


    int consultar (Data adataInicio, Data adataFim, Cidade, Estado);


    int editarEvento (Evento* aevento, int aparam, Usuario* ausuario, CodigoEvento acodigoevento);


    int deletarEvento (CodigoEvento acodigoEvento, Usuario* ausuario);


    int statusvenda (CodigoEvento acodigoEvento, Usuario* ausuario);


};



/** \class
 * \brief
 *
 * \param
 * \param
 * \return
 *
 */
class SVendas : public ISVendas
{
public:


    int comprar (CodigoApresentacao, int aquantidadeIngresso, Usuario* ausuario);


};



#endif
