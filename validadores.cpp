#include "validadores.h"



int Validadores::validador_cpf (CPF *cpf)
{
    std::string acpf;

    try
    {
        std::cout << "Digite um CPF valido:\n";
        std::cin >> acpf;
        cpf->setCPF(acpf);
        return 0;
    }
    catch (std::invalid_argument excecao)
    {
        std::cout << "CPF Invalido!\n";
        setbuf(stdin, nullptr);
        getchar();
        return -1;
    }
}



int Validadores::validador_senha (Senha *senha)
{
    std::string asenha;

    try
    {
        std::cout << "Digite uma senha valida:\n";
        std::cin >> asenha;
        senha->setSenha(asenha);
        return 0;
    }
    catch (std::invalid_argument excecao)
    {
        std::cout << "Senha Invalida\n";
        setbuf(stdin, nullptr);
        getchar();
        return -1;
    }
}



int Validadores::validador_numeroCartaoCredito (NumeroCartaoCredito *numeroCartaoCredito)
{
    std::string anumeroCartaoCredito;

    try
    {
        std::cout << "Digite um numero de cartao de credito valido:\n";
        std::cin  >> anumeroCartaoCredito;
        numeroCartaoCredito->setNumeroCartaoCredito (anumeroCartaoCredito);
        return 0;
    }
    catch (std::invalid_argument excecao)
    {
        std::cout << "Numero de cartao de credito invalido!\n";
        setbuf(stdin, nullptr);
        getchar();
        return -1;
    }
}



int Validadores::validador_codigoSeguranca (CodigoSeguranca *codigoSeguranca)
{
    int acodigoSeguranca;

    try
    {
        std::cout << "Digite um codigo de seguranca valido:\n";
        std::cin  >> acodigoSeguranca;
        codigoSeguranca->setCodigo (acodigoSeguranca);
        return 0;
    }
    catch (std::invalid_argument excecao)
    {
        std::cout << "Codigo de seguranca invalido!\n";
        setbuf(stdin, nullptr);
        getchar();
        return -1;
    }
}



int Validadores::validador_codigoEvento (CodigoEvento *codigoEvento)
{
    int acodigoevento;

    try
    {
        std::cout << "Digite um codigo de evento valido\n";
        std::cin >> acodigoevento;
        codigoEvento->setCodigo (acodigoevento);
        return 0;
    }
    catch (std::invalid_argument excecao)
    {
        std::cout << "Codigo de evento invalido!\n";
        setbuf(stdin, nullptr);
        getchar();
        return -1;
    }
}



int Validadores::validador_codigoApresentacao (CodigoApresentacao *codigoApresentacao)
{
    int acodigoapresentacao;

    try
    {
        std::cout << "Digite um codigo de apresentacao valido\n";
        std::cin >> acodigoapresentacao;
        codigoApresentacao->setCodigo (acodigoapresentacao);
        return 0;
    }
    catch (std::invalid_argument excecao)
    {
        std::cout << "Codigo de apresentacao invalida!\n";
        setbuf (stdin, nullptr);
        getchar ();
        return -1;
    }
}



int Validadores::validador_nomeEvento (NomeEvento *nomeEvento)
{
    std::string anomeevento;

    try
    {
        std::cout << "Digite um nome de evento valido\n";
        setbuf(stdin, nullptr);
        std::getline(std::cin, anomeevento, '\n');
        nomeEvento->setNomeEvento ((char*)anomeevento.c_str());
        return 0;
    }
    catch (std::invalid_argument excecao)
    {
        std::cout << "Nome de evento invalido!\n";
        setbuf(stdin, nullptr);
        getchar();
        return -1;
    }


}



int Validadores::validador_cidade (Cidade *cidade)
{
    std::string acidade1;

    try
    {
        std::cout << "Digite um nome de cidade valido\n";
        setbuf(stdin, nullptr);
        std::getline(std::cin, acidade1, '\n');
        cidade->setCidade ((char*)acidade1.c_str());
        return 0;
    }
    catch (std::invalid_argument excecao)
    {
        std::cout << "Nome de cidade invalido!\n";
        setbuf(stdin, nullptr);
        getchar();
        return -1;
    }
}



int Validadores::validador_estado (Estado *estado)
{

    std::string aestado;

    try
    {
        std::cout << "Digite um nome de estado valido:\n";
        std::cin >> aestado;
        estado->setEstado ((char*)aestado.c_str());
        return 0;
    }
    catch (std::invalid_argument excecao)
    {
        std::cout << "Nome de evento invalido!\n";
        setbuf(stdin, nullptr);
        getchar();
        return -1;
    }
}


int Validadores::validador_data (Data *data)
{
    std::string adata;

    try
    {
        std::cout << "Digite uma data valida\n";
        std::cin >> adata;
        data->setData ((char*)adata.c_str());
        return 0;
    }
    catch (std::invalid_argument excecao)
    {
        std::cout << "Data invalida!\n";
        setbuf (stdin, nullptr);
        getchar ();
        return -1;
    }
}



int Validadores::validador_dataValidade (DataValidade *dataValidade)
{
    std::string adataValidade;

    try
    {
        std::cout << "Digite uma data de validade valido:\n";
        std::cin >> adataValidade;
        dataValidade->setDataValidade ((char*)adataValidade.c_str());
        return 0;
    }
    catch (std::invalid_argument excecao)
    {
        std::cout << "Numero de data de validade invalido!\n";
        setbuf(stdin, nullptr);
        getchar();
        return -1;
    }
}



int Validadores::validador_horario (Horario *horario)
{
    std::string ahorario;

    try
    {
        std::cout << "Digite um horario valido\n";
        std::cin >> ahorario;
        horario->setHorario ((char*)ahorario.c_str());
        return 0;
    }
    catch (std::invalid_argument excecao)
    {
        std::cout << "Horario invalido!\n";
        setbuf (stdin, nullptr);
        getchar ();
        return -1;
    }

}



int Validadores::validador_classeEvento (ClasseEvento *classeEvento)
{
    int aclasseevento;

    try
    {
        std::cout << "Digite uma classe de evento valido\n";
        std::cin >> aclasseevento;
        classeEvento->setClasseEvento (aclasseevento);
        return 0;
    }
    catch (std::invalid_argument excecao)
    {
        std::cout << "Classe de evento invalido!\n";
        setbuf(stdin, nullptr);
        getchar();
        return -1;
    }
}



int Validadores::validador_faixaEtaria (FaixaEtaria *faixaEtaria)
{
    std::string afaixaetaria;

    try
    {
        std::cout << "Digite uma faixa etaria valida\n";
        std::cin  >> afaixaetaria;
        faixaEtaria->setFaixaEtaria ((char*)afaixaetaria.c_str());
        return 0;
    }
    catch (std::invalid_argument excecao)
    {
        std::cout << "Faixa etaria invalido!\n";
        setbuf(stdin, nullptr);
        getchar();
        return -1;
    }
}



int Validadores::validador_preco (Preco *preco)
{
    float apreco;

    try
    {
        std::cout << "Digite um preco valido\n";
        std::cin >> apreco;
        preco->setPreco (apreco);
        return 0;
    }
    catch (std::invalid_argument excecao)
    {
        std::cout << "Preco invalido!\n";
        setbuf (stdin, nullptr);
        getchar ();
        return -1;
    }
}



int Validadores::validador_numeroSala (NumeroSala *numeroSala)
{
    int anumerosala;

    try
    {
        std::cout << "Digite um numero de sala valido\n";
        std::cin >> anumerosala;
        numeroSala->setNumeroSala (anumerosala);
        return 0;
    }
    catch (std::invalid_argument excecao)
    {
        std::cout << "Numero sala invalida!\n";
        setbuf (stdin, nullptr);
        getchar ();
        return -1;
    }
}



int Validadores::validador_disponibilidade (Disponibilidade *disponibilidade)
{
    int adisponibilidade;

    try
    {
        std::cout << "Digite um valor de disponibilidade valido\n";
        std::cin >> adisponibilidade;
        disponibilidade->setDisponibilidade (adisponibilidade);
        return 0;
    }
    catch (std::invalid_argument excecao)
    {
        std::cout << "Valor de disponibilidade invalido!\n";
        setbuf (stdin, nullptr);
        getchar ();
        return -1;
    }
}
