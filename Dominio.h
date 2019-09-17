/** \file Dominio.h
 * \brief Documento com todas as classes de dominios
 * \author Alexandre Mitsuru Kaihara e Lucas silva
 * \since 29/03/19
 * \version 1.0
 */
//Histórico de alterações:
    //29-Mar-19 Alexandre, inclusão dos 9 primeiros domínios descrito no PDF
    //30-Mar-19 Alexandre, finalização de descrição de classes de 10 domínios
    //01-Abr-19 Alexandre, Correção do problema do inteiro LIMITE_CODIGO da classe base Codigo
    //02-Abr-19 Alexandre, Correção de convenção de alguns parâmetros. Adição do tratamento de exceções.
    //11-Abr-19 Alexandre, Correção das funções de todos os validaNome - retirei o criterio de '\0' -
    //16-Abr-19 Alexandre, Retirou a herança das classes tempo e nome
#ifndef DOMINIO_H_INCLUDED
#define DOMINIO_H_INCLUDED

#include <stdexcept>


/** \class Codigo
 * \brief Classe base para todos os dominios do tipo codigo. Presta o servico de set e get valores. O set de código pode gerar uma excecao
 *
 *  \param void setCodigo (unsigned int acodigo) Permite a escrita do valor de codigo segundo um criterio de validacao
 *  \param unsigned int getCodigo () Recebe o valor de um unsigned int armazenado
 *  \return Ao invocar get codigo, retorna o valor de unsigned int armazenado
 *
 */
class Codigo
{
protected:

    unsigned int LIMITE_CODIGO;

private:

    unsigned int codigo;


    //Valida o int codigo, tratando uma exceção caso codigo >= LIMITE_CODIGO
    virtual void validaCodigo(unsigned int acodigo) throw (std::invalid_argument);


public:


    void setCodigo (unsigned int acodigo) throw (std::invalid_argument);


    unsigned int getCodigo ()
    {
        return codigo;
    }


};



/** \class CodigoSeguranca
 * \brief Classe derivada de Codigo que tem um valor positivo limite de 1000
 *
 *  \param void setCodigo (unsigned int acodigo) Permite a escrita do valor de codigo segundo um criterio de validacao
 *  \param unsigned int getCodigo () Recebe o valor de um unsigned int armazenado
 *  \return Ao invocar get codigo, retorna o valor de unsigned int armazenado
 *
 */
class CodigoSeguranca : public Codigo
{
public:


    CodigoSeguranca();


};



/** \class CodigoEvento
 * \brief Classe derivada de Codigo que tem um valor positivo limite de 1000
 *
 *  \param void setCodigo (unsigned int acodigo) Permite a escrita do valor de codigo segundo um criterio de validacao
 *  \param unsigned int getCodigo () Recebe o valor de um unsigned int armazenado
 *  \return Ao invocar get codigo, retorna o valor de unsigned int armazenado
 *
 */
class CodigoEvento : public Codigo
{
public:


    CodigoEvento();


};



/** \class CodigoApresentacao
 * \brief Classe derivada de Codigo que tem um valor positivo limite de 10000
 *
 *  \param void setCodigo (unsigned int acodigo) Permite a escrita do valor de codigo segundo um criterio de validacao
 *  \param unsigned int getCodigo () Recebe o valor de um unsigned int armazenado
 *  \return Ao invocar get codigo, retorna o valor de unsigned int armazenado
 *
 */
class CodigoApresentacao : public Codigo
{
public:


    CodigoApresentacao();


};



/** \class CodigoIngresso
 * \brief Classe derivada de Codigo que tem um valor positivo limite de 100000
 *
 *  \param void setCodigo (unsigned int acodigo) Permite a escrita do valor de codigo segundo um criterio de validacao
 *  \param unsigned int getCodigo () Recebe o valor de um unsigned int armazenado
 *  \return Ao invocar get codigo, retorna o valor de unsigned int armazenado
 *
 */
class CodigoIngresso : public Codigo
{
public:


    CodigoIngresso();


};



/** \class NomeEvento
 * \brief Classe que presta o servico de set e get string de nome de um evento. O set de codigo pode gerar uma excecao
 *
 * \param void setNomeEvento (char anomeEvento[21]) Valida o parametro e em caso afirmativo, armazena o valor
 * \param char *getNomeEvento() Retorna o endereco da string que contem o nome armazenado
 *
 */
class NomeEvento
{
private:

    char nomeEvento[21];


    void validaNomeEvento (char anomeEvento[21]) throw (std::invalid_argument);


public:


    void setNomeEvento (char anomeEvento[21]) throw (std::invalid_argument);


     char *getNomeEvento ()
    {
        return nomeEvento;
    }


};



/** \class Cidade
 * \brief Classe que presta o servico de set e get string de nome de um evento. O set de codigo pode gerar uma excecao
 *
 * \param void setCidade (char acidade[21]) Valida o parametro e em caso afirmativo, armazena o valor
 * \param char *getCidade () Retorna o endereco da string que contem o nome armazenado
 *
 */
class Cidade
{

private:

    char cidade[17];


    void validaCidade (char acidade[17]) throw (std::invalid_argument);


public:


    void setCidade (char acidade[17]) throw (std::invalid_argument);


     char* getCidade()
    {
        return cidade;
    }


};



/** \class Estado
 * \brief Classe que presta o servico de set e get string de nome de um evento. O set de codigo pode gerar uma excecao
 *
 * \param void setEstado (char aestado[21]) Valida o parametro e em caso afirmativo, armazena o valor
 * \param char *getEstado () Retorna o endereco da string que contem o nome armazenado
 *
 */
class Estado
{
private:

    char estado[3];


    void validaEstado(char aestado[3]) throw (std::invalid_argument);


public:


    void setEstado(char aestado[3]) throw (std::invalid_argument);


     char* getEstado()
    {
        return estado;
    }


};



/** \class Tempo
 * \brief Classe base para todos os dominios do tipo tempo. Presta o servico de verificacao se eh caractere e conversao de uma string de duas posicoes para inteiro
 *
 *  \param void ehNumero (char acaractere) Retorna 1 se o caractere for numero e 0 caso contrario
 *  \param int charToInt (char acharToInt[3]) Converte a string para inteiro
 *
 */
class Tempo
{
public:


    int ehNumero (char acaractere);


    int charToInt (char acharToInt[3]);


};



/** \class DataValidade
 * \brief Classe derivada de tempo que presta o servico de set e get string de uma data de validade. O set da string pode gerar uma excecao
 *
 * \param void setDataValidade (char adataValidade[6]) Valida o parametro e em caso afirmativo, armazena o valor, caso contrário gera uma excecao
 * \param char *getDataValidade () Retorna o endereço da string que contem a data armazenada
 *
 */
class DataValidade: public Tempo
{
private:

    char dataValidade[6];


    void validaDataValidade (char adataValidade[6]) throw (std::invalid_argument);

public:

    void setDataValidade(char adataValidade[6]) throw (std::invalid_argument);


    char *getDataValidade()
    {
        return dataValidade;
    }
};



/** \class Data
 * \brief Classe derivada de tempo que presta o servico de set e get string de uma data. O set da string pode gerar uma excecao
 *
 * \param void setData (char adata[6]) Valida o parametro e em caso afirmativo, armazena o valor, caso contrário gera uma excecao
 * \param char *getData () Retorna o endereço da string que contem a data armazenada
 *
 */
class Data: public Tempo
{
private:

    char data[9];


    void validaData(char adata[9]) throw (std::invalid_argument);


public:

    void setData (char adata[6]) throw (std::invalid_argument);


    char *getData()
    {
        return data;
    }


};



/** \class Horario
 * \brief Classe derivada de tempo que presta o serviço de set e get string de um horário. O set de código pode gerar uma exceção
 *
 * \param void setHorario (char ahorario[6]) Valida o parâmetro e em caso afirmativo, armazena o valor
 * \param char *getHorario () Retorna o endereço da string que contém a data armazenada
 *
 */
class Horario: public Tempo
{
private:

    char horario[6];


    void validaHorario (char ahorario[6]) throw (std::invalid_argument);


public:

    void setHorario (char ahorario[6]) throw (std::invalid_argument);


    char *getHorario ()
    {
        return horario;
    }


};



/** \class Preco
 * \brief Classe relativa ao preco do ingresso
 *
 *  \param void setPreco (float apreco) Permite a escrita do valor do preco segundo um criterio de validacao
 *  \param float getPreco () Recebe o valor de float armazenado
 *  \return Ao invocar getPreco, retorna o valor de float armazenado
 *
 */
class Preco
{
private:

    float preco;

    const float MAX = 1000;

    const float MIN = 0;

    void validarPreco (float) throw (std::invalid_argument);

public:


    float getPreco ()
    {
        return preco;
    }


    void setPreco (float) throw (std::invalid_argument);


};



/** \class NumeroSala
 * \brief Classe relativa ao numero de sala de cada apresentação
 *
 *  \param void setNumeroSala (int anumeroSala) Permite a escrita do valor do preco segundo um criterio de validacao. Gera execao caso o argumento seja inválido
 *  \param int getNumeroSala () Recebe o valor de int armazenado
 *  \return Ao invocar getNumeroSala, retorna o valor de int armazenado
 *
 */
class NumeroSala
{
private:
    int numeroSala;

    const static int MAX = 10;

    const static int MIN = 1;


    void validarNumeroSala (int) throw (std::invalid_argument);


public:


    int getNumeroSala ()
    {
        return numeroSala;
    }


    void setNumeroSala (int) throw (std::invalid_argument);


};



/** \class Disponibilidade
 * \brief Classe relativa a disponibilidade da apresentacao
 *
 *  \param void setDisponibilidade (int) trow (std::invalid_argument) Permite a escrita do valor de disponibilidade segundo um criterio de validacao. Gera execao caso o argumento seja inválido
 *  \param int getDisponibilidade () Retorna o valor disponibilidade armazenado
 *
 */
class Disponibilidade
{
private:

    int disponibilidade;

    const static int MAX = 250;

    const static int MIN = 0;


    void validarDisponibilidade (int) throw (std::invalid_argument);


public:


    int getDisponibilidade ()
    {
        return disponibilidade;
    }


    void setDisponibilidade (int) throw (std::invalid_argument);


};



/** \class ClasseEvento
 * \brief Classe relativa ao tipo de classe de evento
 *
 *  \param void setClasseEvento (int) trow (std::invalid_argument) Permite a escrita do valor da classe de evento segundo um criterio de . Gera execao caso o argumento seja inválido
 *  \param int getClasseEvento () Retorna o valor da classe de evento armazenado
 *
 */
class ClasseEvento
{
private:

    int classeEvento;

    const static int TEATRO = 1;

    const static int ESPORTE = 2;

    const static int SHOW_NACIONAL = 3;

    const static int SHOW_INTERNACIONAL = 4;


    void validarClasseEvento (int) throw (std::invalid_argument);


public:


    int getClasseEvento ()
    {
        return classeEvento;
    }


    void setClasseEvento (int) throw (std::invalid_argument);


};



/** \class FaixaEtaria
 * \brief Classe relativa a faixa etaria
 *
 *  \param void setFaixaEtaria (std:string) trow (std::invalid_argument) Permite a escrita da faixa etaria segundo um criterio de . Gera execao caso o argumento seja inválido
 *  \param std::string getFaixaEtaria() Retorna o valor da faixa etaria armazenada
 *
 */
class FaixaEtaria
{
private:

    std::string faixaEtaria;

    const std::string LIVRE = "L";

    const std::string DOZE_ANOS = "12";

    const std::string QUATORZE_ANOS = "14";

    const std::string DEZESEIS_ANOS = "16";

    const std::string DEZOITO_ANOS = "18";


    void validarFaixaEtaria (std::string) throw (std::invalid_argument);


public:


    std::string getFaixaEtaria ()
    {
        return faixaEtaria;
    }


    void setFaixaEtaria (std::string) throw (std::invalid_argument);


};



/** \class Senha
 * \brief Classe relativa senha de usuario
 *
 *  \param void setSenha (std::string) trow (std::invalid_argument) Permite a escrita da senha de usuario segundo um criterio de . Gera execao caso o argumento seja inválido
 *  \param std::string getSenha () Retorna senha de usuario armazenado
 *
 */
class Senha
{
private:

    std::string senha;

    const static int ASCII_A = 65;

    const static int ASCII_Z = 90;

    const static int ASCII_a = 97;

    const static int ASCII_z = 122;

    const static int LIMITE_CARACTERE = 6;


    int isDigito (char);


    int isMaiusculo (char);


    int isMinusculo (char);


    int isRepetido (char, std::string);


    int isCaractereValido (char);


    void validarSenha (std::string) throw (std::invalid_argument);


public:


    std::string getSenha ()
    {
        return senha;
    }


    void setSenha (std::string) throw (std::invalid_argument);


};




/** \class CPF
 * \brief Classe relativa ao CPF de usuario
 *
 *  \param void setCPF (std::string) trow (std::invalid_argument) Permite a escrita do CPF de usuario segundo um criterio de . Gera execao caso o argumento seja inválido
 *  \param std::string getCPF () Retorna o valor CPF de usuario armazenado
 *
 */
class CPF
{
private:

    std::string cpf;

    int isDigito (char);


    int isValidoPrimeiroDigito (std::string);


    int isValidoSegundoDigito (std::string);


    int isCPFInvalido (std::string);


    int isFormatoValido (std::string);


    void validarCPF (std::string) throw (std::invalid_argument);


public:


    std::string getCPF () const
    {
        return cpf;
    }


    void setCPF (std::string) throw (std::invalid_argument);


};



/** \class NumeroCartaoCredito
 * \brief Classe relativa ao numero de cartao de credito
 *
 *  \param void setNumerocartaoCredito (std::string) trow (std::invalid_argument) Permite a escrita do numero de cartao de credito segundo um criterio de . Gera execao caso o argumento seja inválido
 *  \param std::string getNumeroCartaoCredito () Retorna o valor do numero de cartao de credito armazenado
 *
 */
class NumeroCartaoCredito
{
private:

    std::string numeroCartaoCredito;


    int isValidoNumeroCartaoCredito (std::string);


    void validarNumeroCartaoCredito (std::string) throw (std::invalid_argument);


public:


    std::string getNumeroCartaoCredito () const
    {
        return numeroCartaoCredito;
    }


    void setNumeroCartaoCredito (std::string) throw (std::invalid_argument);


};



#endif
