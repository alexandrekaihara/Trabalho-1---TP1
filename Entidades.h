/** \file Entidades.h
 *\brief Documento com todas as classes de entidades
 * \author Alexandre Mitsuru Kaihara e Lucas silva
 * \since 04/04/19
 * \version 1.0
 */
//Histórico de alterações:
    //09-Abr-19 Alexandre, Inclusão dos atributos das entidades.
    //26-Abr-19 Lucas    , Criacao das entidades Ingresso, Cartao de Credito e Apresentacao.
#ifndef ENTIDADES_H_INCLUDED
#define ENTIDADES_H_INCLUDED

#include "Dominio.h"
#include "string.h"



/** \class Usuario
 * \brief Permite armazenar CPF e senha
 *
 * \param void setCPF (CPF &objetoCPF) Armazena o valor do cpf do objeto passado já validado
 * \param void setSenha (Senha objetoSenha) Armazena o valor do cpf do objeto passado já validado
 * \param getCPF () Retorna o valor de CPF armazenado
 * \param getSenha () Retorna o valor de senha armazenado
 *
 */
class Usuario
{
private:

    std::string cpf;

    std::string senha;

public:


    void setCPF (CPF &objetoCPF)
    {
        this->cpf = objetoCPF.getCPF ();
    }


    void setSenha (Senha &objetoSenha)
    {
        this->senha = objetoSenha.getSenha ();
    }


    std::string getCPF()
    {
        return cpf;
    }


    std::string getSenha()
    {
        return senha;
    }


};



/** \class Evento
 * \brief Permite armazenar codigo de evento, nome de evento, cidade, estado, classe de evento e faixa etaria
 *
 * \param void setCodigoEvento (CodigoEvento &objetoCodigoEvento) Armazena o valor do codigo de evento do objeto passado já validado
 * \param void setNomeEvento (NomeEvento &objetoNomeEvento) Armazena o valor do nome do evento do objeto passado já validado
 * \param void setCidade (Cidade &objetoCidade) Armazena o valor da cidade do objeto passado já validado
 * \param void void setEstado (Estado &objetoEstado) Armazena o valor do estado do objeto passado já validado
 * \param void setClasseEvento (ClasseEvento &objetoClasseEvento) Armazena o valor da classe de evento do objeto passado já validado
 * \param void void setFaixaEtaria (FaixaEtaria &objetoFaixaEtaria) Armazena o valor da faixa etaria do objeto passado já validado
 * \param unsigned int getCodigoEvento () Retorna o valor do codigo de evento armazenado
 * \param char *getNomeEvento () Retorna o valor do nome de evento armazenado
 * \param void setCidade (Cidade &objetoCidade) Retorna o valor de cidade armazenado
 * \param char *getEstado () Retorna o valor de estado armazenado
 * \param int getClasseEvento () Retorna o valor de classe de evento armazenado
 * \param std::string getFaixaEtaria () Retorna o valor de faixa etaria armazenado
 *
 */
class Evento
{
private:

    unsigned int codigoEvento;

    char nomeEvento[21];

    char cidade[17];

    char estado[3];

    int classeEvento;

    std::string faixaEtaria;

public:


    void setCodigoEvento (Codigo &objetoCodigoEvento)
    {
        this->codigoEvento = objetoCodigoEvento.getCodigo ();
    }


    void setNomeEvento (NomeEvento &objetoNomeEvento)
    {
        strcpy (this->nomeEvento, objetoNomeEvento.getNomeEvento ());
    }


    void setCidade (Cidade &objetoCidade)
    {
        strcpy (this->cidade, objetoCidade.getCidade ());
    }


    void setEstado (Estado &objetoEstado)
    {
        strcpy (this->estado, objetoEstado.getEstado());
    }


    void setClasseEvento (ClasseEvento &objetoClasseEvento)
    {
        this->classeEvento = objetoClasseEvento.getClasseEvento ();
    }


    void setFaixaEtaria (FaixaEtaria &objetoFaixaEtaria)
    {
        this->faixaEtaria = objetoFaixaEtaria.getFaixaEtaria ();
    }


    unsigned int getCodigoEvento ()
    {
        return codigoEvento;
    }


    char *getNomeEvento ()
    {
        return nomeEvento;
    }


    char *getCidade ()
    {
        return cidade;
    }


    char *getEstado ()
    {
        return estado;
    }


    int getClasseEvento ()
    {
        return classeEvento;
    }


    std::string getFaixaEtaria ()
    {
        return faixaEtaria;
    }
};



/** \class Apresentacao
 * \brief Permite armazenar codigo de apresentacao, data, horario, preco, numero da sala e disponibilidade
 *
 * \param void setCodigoApresentacao (Codigo &objetoCodigoApresentacao) Armazena o valor do codigo de apresentacao do objeto passado já validado
 * \param void setData (Data &objetoData) Armazena o valor da data do objeto passado já validado
 * \param void setHorario (Horario &objetoHorario) Armazena o valor do horario do objeto passado já validado
 * \param void setPreco (Preco &objetoPreco) Armazena o valor do preco do objeto passado já validado
 * \param void setNumeroSala (NumeroSala &objetoNumeroSala) Armazena o valor do numero da sala do objeto passado já validado
 * \param void setDisponibilidade (Disponibilidade &objetoDisponibilidade) Armazena o valor da disponibilidade do objeto passado já validado
 * \param unsigned int getCodigoApresentacao () Retorna o valor de  codigo de apresentacao armazenado
 * \param char *getData() Retorna o valor de data armazenado
 * \param void setHorario (Horario &objetoHorario) Retorna o valor de horario armazenado
 * \param float getPreco () Retorna o valor de preco armazenado
 * \param int getNumeroSala () Retorna o valor de numero da sala armazenado
 * \param int getDisponibilidade () Retorna o valor de disponivilidade armazenado
 *
 */
class Apresentacao
{
private:

    unsigned int codigoApresentacao;

    char data[9];

    char horario[6];

    float preco;

    int numeroSala;

    int disponibilidade;

public:


    void setCodigoApresentacao (Codigo &objetoCodigoApresentacao)
    {
        this->codigoApresentacao = objetoCodigoApresentacao.getCodigo ();
    }


    void setData (Data &objetoData)
    {
        strcpy (this->data, objetoData.getData ());
    }


    void setHorario (Horario &objetoHorario)
    {
        strcpy (this->horario, objetoHorario.getHorario ());
    }


    void setPreco (Preco &objetoPreco)
    {
        this->preco = objetoPreco.getPreco ();
    }


    void setNumeroSala (NumeroSala &objetoNumeroSala)
    {
        this->numeroSala = objetoNumeroSala.getNumeroSala ();
    }


    void setDisponibilidade (Disponibilidade &objetoDisponibilidade)
    {
        this->disponibilidade = objetoDisponibilidade.getDisponibilidade ();
    }


    int getDisponibilidade ()
    {
        return disponibilidade;
    }


    int getNumeroSala ()
    {
        return numeroSala;
    }


    float getPreco ()
    {
        return preco;
    }


    char *getHorario ()
    {
        return horario;
    }


    char *getData()
    {
        return data;
    }


    unsigned int getCodigoApresentacao ()
    {
        return codigoApresentacao;
    }

};



/** \class Ingresso
 * \brief Permite armazenar codigo de ingresso
 *
 * \param void setCodigoIngresso (Codigo &objetoCodigoIngresso) Armazena o valor do codigo de ingresso do objeto passado já validado
 * \param unsigned int getCodigoIngresso () Retorna o valor de codigo de ingresso armazenado
 *
 */
class Ingresso
{
private:

    unsigned int codigoIngresso;

public:

    void setCodigoIngresso (Codigo &objetoCodigoIngresso)
    {
        this->codigoIngresso = objetoCodigoIngresso.getCodigo ();
    }


    unsigned int getCodigoIngresso ()
    {
        return codigoIngresso;
    }
};



/** \class CartaoCredito
 * \brief Permite armazenar numero de cartao de credito, codigo de seguranca e data de validade
 *
 * \param void setNumeroCartaoCredito (NumeroCartaoCredito &objetoNumeroCartaoCredito) Armazena o valor do numero de cartao de credito do objeto passado já validado
 * \param void setCodigoSeguranca (Codigo &objetoCodigoSeguranca) Armazena o valor do codigo de seguranca do objeto passado já validado
 * \param void setDataValidade (DataValidade &objetoDataValidade) Armazena o valor do data de validade do objeto passado já validado
 * \param std::string getNumeroCartaoCredito () Retorna o valor de numero de cartao de credito armazenado
 * \param unsigned int getCodigoSeguranca () Retorna o valor de codigo de seguranca armazenado
 * \param char *getDataValidade () Retorna o valor de data de validade armazenado
 *
 */
class CartaoCredito
{
private:

    std::string numeroCartaoCredito;

    unsigned int codigoSeguranca;

    char dataValidade[6];

public:

    void setNumeroCartaoCredito (NumeroCartaoCredito &objetoNumeroCartaoCredito)
    {
        this->numeroCartaoCredito = objetoNumeroCartaoCredito.getNumeroCartaoCredito ();
    }


    void setCodigoSeguranca (Codigo &objetoCodigoSeguranca)
    {
        this->codigoSeguranca = objetoCodigoSeguranca.getCodigo ();
    }


    void setDataValidade (DataValidade &objetoDataValidade)
    {
        strcpy (this->dataValidade, objetoDataValidade.getDataValidade ());
    }


    std::string getNumeroCartaoCredito ()
    {
        return numeroCartaoCredito;
    }


    unsigned int getCodigoSeguranca ()
    {
        return codigoSeguranca;
    }


    char *getDataValidade ()
    {
        return dataValidade;
    }
};



#endif
