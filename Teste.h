/** \file Teste.h
 *\brief Documento com todas as classes de testes de entidade e dominio
 * \author Alexandre Mitsuru Kaihara e Lucas silva
 * \since 29/03/19
 * \version 1.0
 */
#ifndef TESTE_H_INCLUDED
#define TESTE_H_INCLUDED

#include "Dominio.h"
#include "Entidades.h"


//Classe base que possui os atributos comuns a todos os Testes
class Teste
{
protected:

    int estado;

public:

    const static int SUCESSO =  0;

    const static int FALHA = -1;


    virtual void setUp() = 0;


    virtual void tearDown() = 0;


    virtual void testarCenarioFalha() = 0;


    virtual void testarCenarioSucesso() = 0;


    int run();


};



class TDCodigoSeguranca : public Teste
{
private:

    CodigoSeguranca *classeteste;

    const static int VALOR_VALIDO = 999;

    const static int VALOR_INVALIDO = 1000;


    void testarCenarioSucesso();


    void testarCenarioFalha();


    void setUp();


    void tearDown();


};



class TDCodigoEvento : public Teste
{
private:

    CodigoEvento *classeteste;

    const static int VALOR_VALIDO = 999;

    const static int VALOR_INVALIDO = 1000;


    void testarCenarioSucesso();


    void testarCenarioFalha();


    void setUp();


    void tearDown();


};



class TDCodigoApresentacao: public Teste
{
private:

    CodigoApresentacao *classeteste;

    const static int VALOR_VALIDO = 9999;

    const static int VALOR_INVALIDO = 10000;


    void testarCenarioSucesso();


    void testarCenarioFalha();


    void setUp();


    void tearDown();


};



class TDCodigoIngresso: public Teste
{
private:

    CodigoIngresso *classeteste;

    const static int VALOR_VALIDO = 99999;

    const static int VALOR_INVALIDO = 100000;


    void testarCenarioSucesso();


    void testarCenarioFalha();


    void setUp();


    void tearDown();


};



class TDNomeEvento : public Teste
{
private:

    char *casosValidos[5];

    char *casosInvalidos[5];

    NomeEvento *classeteste;


    void testarCenarioSucesso();


    void testarCenarioFalha();


    void setUp();


    void tearDown();


};



class TDCidade : public Teste
{
private:

    char *casosValidos[5];

    char *casosInvalidos[5];

    Cidade *classeteste;


    void testarCenarioSucesso();


    void testarCenarioFalha();


    void setUp();


    void tearDown();


};



class TDEstado : public Teste
{
private:

    char *casosValidos[5];

    char *casosInvalidos[5];

    Estado *classeteste;


    void testarCenarioSucesso();


    void testarCenarioFalha();


    void setUp();


    void tearDown();


};



class TDData : public Teste
{
private:

    char *casosValidos[5];

    char *casosInvalidos[5];

    Data *classeteste;


    void testarCenarioSucesso();


    void testarCenarioFalha();


    void setUp();


    void tearDown();


};



class TDDataValidade : public Teste
{
private:

    char *casosValidos[5];

    char *casosInvalidos[5];

    DataValidade *classeteste;


    void testarCenarioSucesso();


    void testarCenarioFalha();


    void setUp();


    void tearDown();


};



class TDHorario : public Teste
{
private:

    char *casosValidos[5];

    char *casosInvalidos[5];

    Horario *classeteste;


    void testarCenarioSucesso();


    void testarCenarioFalha();


    void setUp();


    void tearDown();


};



class TUPreco
{
private:

    Preco *preco;

    int estado;

    const float VALOR_VALIDO = 100;

    const float VALOR_INVALIDO = -1;

    void setUp ();

    void tearDown ();

    void testarCenarioSucesso ();

    void testarCenarioFalha ();

public:

    const static int SUCESSO =  0;

    const static int FALHA   = -1;


    int run();


};



class TUNumeroSala
{
private:

    NumeroSala *numeroSala;

    int estado;

    const static int VALOR_VALIDO = 10;

    const static int VALOR_INVALIDO = -1;

    void setUp ();

    void tearDown ();

    void testarCenarioSucesso ();

    void testarCenarioFalha ();

public:

    const static int SUCESSO =  0;

    const static int FALHA   = -1;


    int run();


};



class TUDisponibilidade
{
private:

    Disponibilidade *disponibilidade;

    int estado;

    const static int VALOR_VALIDO = 10;

    const static int VALOR_INVALIDO = -1;

    void setUp ();

    void tearDown ();

    void testarCenarioSucesso ();

    void testarCenarioFalha ();

public:

    const static int SUCESSO =  0;

    const static int FALHA   = -1;

    int run ();
};



class TUFaixaEtaria
{
private:

    FaixaEtaria *faixaEtaria;

    int estado;

    const std::string VALOR_VALIDO = "L";

    const std::string VALOR_INVALIDO = "11";


    void setUp ();

    void tearDown ();

    void testarCenarioSucesso ();

    void testarCenarioFalha ();

public:

    const static int SUCESSO =  0;

    const static int FALHA   = -1;

    int run ();
};



class TUClasseEvento
{
private:

    ClasseEvento *classeEvento;

    int estado;

    const static int VALOR_VALIDO = 1;

    const static int VALOR_INVALIDO = 5;

    void setUp ();

    void tearDown ();

    void testarCenarioSucesso ();

    void testarCenarioFalha ();

public:

    const static int SUCESSO =  0;

    const static int FALHA   = -1;

    int run ();
};



class TUSenha
{
private:

    Senha *senha;

    int estado;

    const std::string VALOR_VALIDO = "Lucas1";

    const std::string VALOR_INVALIDO = "Luc4s.";

    void setUp ();

    void tearDown ();

    void testarCenarioSucesso ();

    void testarCenarioFalha ();

public:

    const static int SUCESSO =  0;

    const static int FALHA   = -1;

    int run ();
};



class TUCPF
{
private:

    CPF *cpf;

    int estado;

    const std::string VALOR_VALIDO = "529.982.247-25";

    const std::string VALOR_INVALIDO = "111.111.111-11";

    void setUp ();

    void tearDown ();

    void testarCenarioSucesso ();

    void testarCenarioFalha ();

public:

    const static int SUCESSO =  0;

    const static int FALHA   = -1;

    int run ();
};



class TUNumeroCartaoCredito
{
private:

    NumeroCartaoCredito *numeroCartaoCredito;

    int estado;

    const std::string VALOR_VALIDO = "5373130930803211";

    const std::string VALOR_INVALIDO = "5373130930803212";

    void setUp ();

    void tearDown ();

    void testarCenarioSucesso ();

    void testarCenarioFalha ();

public:

    const static int SUCESSO =  0;

    const static int FALHA   = -1;

    int run ();
};



class TEUsuario: public Teste
{
private:

    Usuario *classeteste;


    void setUp ();


    void tearDown ();


    void testarCenarioSucesso ();


    void testarCenarioFalha();


public:
};



class TEEvento: public Teste
{
private:

    Evento *classeteste;


    void setUp ();


    void tearDown ();


    void testarCenarioSucesso ();


    void testarCenarioFalha();


public:
};



class TEApresentacao: public Teste
{
private:

    Apresentacao *classeteste;


    void setUp ();


    void tearDown ();


    void testarCenarioSucesso ();


    void testarCenarioFalha();


public:
};



class TEIngresso: public Teste
{
private:

    Ingresso *classeteste;


    void setUp ();


    void tearDown ();


    void testarCenarioSucesso ();


    void testarCenarioFalha();


public:
};



class TECartaoCredito: public Teste
{
private:

    CartaoCredito *classeteste;


    void setUp ();


    void tearDown ();


    void testarCenarioSucesso ();


    void testarCenarioFalha();


public:
};



#endif
