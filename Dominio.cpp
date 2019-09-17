/** \file Dominio.cpp
 *\brief Documento com todas as implementacoes das classes de dominios
 * \author Alexandre Mitsuru Kaihara e Lucas silva
 * \since 29/03/19
 * \version 1.0
 */
//Histórico de alterações:
    //29-Mar-19 Alexandre, inclusão dos 9 primeiros domínios com algumas implementações descrito no PDF
    //30-Mar-19 Alexandre, finalização de 10 domínios com implementação das funções. Falta incluir o tratamento de exceções e corrigir o problema da classe código de não herança do valor dos limites dos códigos
    //01-Abr-19 Alexandre, Correção do problema do inteiro LIMITE_CODIGO da classe base Codigo
    //02-Abr-19 Alexandre, Correção de convenção de alguns parâmetros. Adição do tratamento de exceções.
    //16-Abr-19 Alexandre, Retirou a herança das classes tempo e nome
#include "Dominio.h"
#include <iostream>
#include <string.h>



void Codigo::validaCodigo (unsigned int acodigo) throw (std::invalid_argument)
{

    if (acodigo >= LIMITE_CODIGO)
    {
        throw std::invalid_argument ("Argumento inválido.\n");
    }

}



/** \brief Valida o parametro e em caso afirmativo, armazena o valor e em caso invalido gera uma excecao
 *
 * \param unsigned int acodigo Valor passado por parametro de um codigo
 * \return Sem retorno
 *
 */
void Codigo::setCodigo (unsigned int acodigo) throw (std::invalid_argument)
{

    validaCodigo (acodigo);
    this->codigo = acodigo;

}



CodigoSeguranca::CodigoSeguranca()
{
    LIMITE_CODIGO = 1000;
}



CodigoEvento::CodigoEvento()
{
    LIMITE_CODIGO = 1000;
}



CodigoApresentacao::CodigoApresentacao()
{
    LIMITE_CODIGO = 10000;
}



CodigoIngresso::CodigoIngresso()
{
    LIMITE_CODIGO = 100000;
}



void NomeEvento::validaNomeEvento (char anomeEvento[21]) throw (std::invalid_argument)
{

    int letras = 0;
    int espacosConsecutivos = 0;

    for (int i = 0; i < 21 && anomeEvento[i] != 0; i++)
    {

        if (anomeEvento[i] == '\0')
        {
            return;
        }

        //Verifica letras, a-z e A-Z
        if ((anomeEvento[i] > 96 && anomeEvento[i] < 123) || (anomeEvento[i] > 64 && anomeEvento[i] < 91))
        {
            letras++;
            espacosConsecutivos = 0;
        }

        //Verifica números
        else if (anomeEvento[i] > 47 && anomeEvento[i] < 58)
        {
            espacosConsecutivos = 0;
        }

        //Verifica espaços consecutivos
        else if (anomeEvento[i] == ' ')
        {
            espacosConsecutivos++;

            //Se houver dois espaços consecutivos encerra
            if (espacosConsecutivos >= 2)
            {
                throw std::invalid_argument ("Argumento inválido.\n");
            }
        }

        else if(anomeEvento[i] != '\0')
        {
            throw std::invalid_argument ("Argumento inválido.\n");
        }
    }

    //Se a quantidade de letras for 0 retorna 0
    if(letras == 0){
        throw std::invalid_argument ("Argumento inválido.\n");
    }

}



/** \brief Valida o parametro e em caso afirmativo, armazena o valor e em caso invalido gera uma excecao
 *
 * \param char anomeEvento[21] String contendo o nome de um evento a ser validado
 * \return Sem retorno
 *
 */
void NomeEvento::setNomeEvento (char anomeEvento[21]) throw (std::invalid_argument)
{

    validaNomeEvento (anomeEvento);
    strcpy(nomeEvento, anomeEvento);

}



void Cidade::validaCidade (char acidade[17]) throw (std::invalid_argument)
{

    int letras = 0;
    int espacosConsecutivos = 0;

    for (int i = 0; i < 17 && acidade[i] != 0; i++)
    {

        //Verifica letras, a-z e A-Z
        if ((acidade[i] > 96 && acidade[i] < 123) || (acidade[i] > 64 && acidade[i] < 91))
        {
            letras++;
            espacosConsecutivos = 0;
        }

        //Verifica números
        else if (acidade[i] > 47 && acidade[i] < 58)
        {
            espacosConsecutivos = 0;
        }

        //Verifica espaços consecutivos
        else if (acidade[i] == ' ')
        {
            espacosConsecutivos++;

            //Se houver dois espaços consecutivos encerra
            if (espacosConsecutivos >= 2)
            {
                throw std::invalid_argument ("Argumento inválido.\n");
            }
        }

        else if (acidade[i] == '.')
        {
            //Verifica se a próxima posição é letra, a-z e A-Z
            if ((acidade[i+1] <= 96 || acidade[i+1] >= 123) && (acidade[i+1] <= 64 || acidade[i+1] >= 91))
            {
                throw std::invalid_argument ("Argumento inválido.\n");
            }
        }

        //Se não for letra, número ou '.', encerra a execução
        else if(acidade[i] != '\0')
        {
            throw std::invalid_argument ("Argumento inválido.\n");
        }
    }

    //Se a quantidade de letras for 0 retorna 0
    if(letras == 0){
        throw std::invalid_argument ("Argumento inválido.\n");
    }

}



/** \brief Valida o parametro e em caso afirmativo, armazena o valor e em caso invalido gera uma excecao
 *
 * \param char acidade[17] String contendo o nome de uma cidade a ser validada
 * \return Sem retorno
 *
 */
void Cidade::setCidade (char acidade[17]) throw (std::invalid_argument)
{

    validaCidade (acidade);
    strcpy(cidade, acidade);

}



void Estado::validaEstado (char aestado[3]) throw (std::invalid_argument)
{

    //Procura as iniciais, depois analisa se a segunda letra corresponde a algum estado
    switch (aestado[0]){

        case 'A':
            if (aestado[1] != 'C' && aestado[1] != 'L' && aestado[1] != 'P' && aestado[1] != 'M')
            {
                 throw std::invalid_argument ("Argumento inválido.\n");
            }
            break;

        case 'B':
            if (aestado[1] != 'A')
            {
                 throw std::invalid_argument ("Argumento inválido.\n");
            }
            break;

        case 'C':
            if (aestado[1] != 'E')
            {
                throw std::invalid_argument ("Argumento inválido.\n");
            }
            break;

        case 'D':
            if (aestado[1] != 'F')
            {
                 throw std::invalid_argument ("Argumento inválido.\n");
            }
            break;

        case 'E':
            if (aestado[1] != 'S')
            {
                 throw std::invalid_argument ("Argumento inválido.\n");
            }
            break;

        case 'T':
            if (aestado[1] != 'O')
            {
                 throw std::invalid_argument ("Argumento inválido.\n");
            }
            break;

        case 'G':
            if (aestado[1] != 'O')
            {
                 throw std::invalid_argument ("Argumento inválido.\n");
            }
            break;

        case 'M':
            if (aestado[1] != 'T' && aestado[1] != 'S' && aestado[1] != 'G' && aestado[1] != 'A')
            {
                 throw std::invalid_argument ("Argumento inválido.\n");
            }
            break;

        case 'P':
            if (aestado[1] != 'A' && aestado[1] != 'B' && aestado[1] != 'R' && aestado[1] != 'E' && aestado[1] != 'I')
            {
                 throw std::invalid_argument ("Argumento inválido.\n");
            }
            break;

        case 'R':
            if (aestado[1] != 'J' && aestado[1] != 'N' && aestado[1] != 'S' && aestado[1] != 'O' && aestado[1] != 'R')
            {
                 throw std::invalid_argument ("Argumento inválido.\n");
            }
            break;

        case 'S':
            if (aestado[1] != 'C' && aestado[1] != 'P' && aestado[1] != 'E')
            {
                 throw std::invalid_argument ("Argumento inválido.\n");
            }
            break;

        default:
             throw std::invalid_argument ("Argumento inválido.\n");

    }
}




/** \brief Valida o parametro e em caso afirmativo, armazena o valor e em caso invalido gera uma excecao
 *
 * \param char aestado[3] String contendo o nome de um estado a ser validada
 * \return Sem retorno
 *
 */
void Estado::setEstado (char aestado[17]) throw (std::invalid_argument)
{

    validaEstado(aestado);
    strcpy(estado, aestado);

}



int Tempo::charToInt(char acharToInt[3])
{

    int inteiro = 0;
    int potencia = 1;

    for(int i=0; i < 2; i++)
    {

        if(i > 0)
        {
            potencia *= 10;
        }

        switch (acharToInt[1-i])
        {
            case '1':
                inteiro += 1*(potencia);
                break;

            case '2':
                inteiro += 2*(potencia);
                break;

            case '3':
                inteiro += 3*(potencia);
                break;

            case '4':
                inteiro += 4*(potencia);
                break;

            case '5':
                inteiro += 5*(potencia);
                break;

            case '6':
                inteiro += 6*(potencia);
                break;

            case '7':
                inteiro += 7*(potencia);
                break;

            case '8':
                inteiro += 8*(potencia);
                break;

            case '9':
                inteiro += 9*(potencia);
                break;

            default:
                break;

        }
    }

    return inteiro;
}



int Tempo::ehNumero(char acaractere)
{
    //Verifica se as demais casas contém números
    if(acaractere >= '0' && acaractere <= '9'){
        return 1;
    }

    return 0;

}



void Data::validaData (char adata[9]) throw (std::invalid_argument)
{
    //Se não houver as barras no lugar correto, é inválido
    if (adata[2] != '/' || adata[5] != '/')
    {
        throw std::invalid_argument ("Argumento inválido.\n");
    }

    int dia = 0;
    int mes = 0;
    int ano = 0;
    int contador = 0;
    char charDiaMesAno[3];

    //Converte o dia, mes e ano em inteiros
    for (int i = 0; i < 9; i++)
    {
        //Quando encontrar uma barra deve analisar a string
        if (i == 2 || i == 5 || i == 8)
        {
            charDiaMesAno[2] = '\0';

            //A conversão é dia, mes ou ano
            switch (i)
            {
                case 2:
                    dia = charToInt (charDiaMesAno);
                    break;

                case 5:
                    mes = charToInt (charDiaMesAno);
                    break;

                case 8:
                    ano = charToInt (charDiaMesAno);
                    break;

                default:
                    break;
            }

            contador = 0;
        }

        else
        {
            //Garante que tudo que está sendo analisado são números
            if (ehNumero (adata[i]) == 0)
            {
                throw std::invalid_argument ("Argumento inválido.\n");
            }

            charDiaMesAno[contador] = adata[i];

            contador++;
        }
    }

    //Verifica se o mes está correto
    if (mes < 1 || mes > 12)
    {
        throw std::invalid_argument ("Argumento inválido.\n");
    }

    //Verifica meses com 31 dias
    if (mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes == 8 || mes == 10 || mes == 12)
    {
        if (dia < 1 || dia > 31){
            throw std::invalid_argument ("Argumento inválido.\n");
        }
    }

    //Verifica o ano bissexto
    else if (mes == 2)
    {
        //Ano bissexto
        if (ano % 4 == 0 && (dia < 1 || dia > 29))
        {
            throw std::invalid_argument ("Argumento inválido.\n");
        }

        //Ano não bissexto
        else if ((ano % 4 != 0) && (dia < 1 || dia > 28))
        {
            throw std::invalid_argument ("Argumento inválido.\n");
        }
    }

    //Verifica meses com 30 dias
    else if (dia < 1 || dia > 30)
    {
        throw std::invalid_argument ("Argumento inválido.\n");
    }

}




/** \brief Valida o parametro e em caso afirmativo, armazena o valor e em caso invalido gera uma excecao
 *
 * \param char adata[9] String contendo uma data a ser validada
 * \return Sem retorno
 *
 */
void Data::setData (char adata[9]) throw (std::invalid_argument)
{

    validaData (adata);
    strcpy(data, adata);

}



void DataValidade::validaDataValidade (char adatavalidade[6]) throw (std::invalid_argument)
{
    //Verifica se há '/'
    if (adatavalidade[2] != '/')
    {
        throw std::invalid_argument ("Argumento inválido.\n");
    }

    int mes = 0;
    int contador = 0;           //Serve para alinhar a atribuição do charMes com atempo
    char charMes[3];

    //Converte o mes em inteiro
    for (int i = 0; i < 6; i++)
    {
        //Quando encontrar uma barra deve analisar a string
        if (i == 2 || i == 5)
        {
            charMes[2] = '\0';

            //A conversão do mes em inteiro
            switch (i)
            {
                case 2:
                    mes = charToInt (charMes);
                    break;

                default:
                    break;
            }

            contador = 0;
        }

        else
        {
            //Garante que tudo que está sendo analisado são números
            if (ehNumero (adatavalidade[i]) == 0)
            {
                throw std::invalid_argument ("Argumento inválido.\n");
            }

            charMes[contador] = adatavalidade[i];

            contador++;
        }
    }

    if (mes < 1 || mes > 12)
    {
        throw std::invalid_argument ("Argumento inválido.\n");
    }

}




/** \brief Valida o parametro e em caso afirmativo, armazena o valor e em caso invalido gera uma excecao
 *
 * \param char adataValidade[6] String contendo uma data de validade a ser validada
 * \return Sem retorno
 *
 */
void DataValidade::setDataValidade (char adataValidade[6]) throw (std::invalid_argument)
{

    validaDataValidade (adataValidade);
    strcpy(dataValidade, adataValidade);

}



void Horario::validaHorario (char ahorario[9]) throw (std::invalid_argument)
{
    //Verifica se há '/'
    if (ahorario[2] != ':')
    {
        throw std::invalid_argument ("Argumento inválido.\n");
    }

    int hora = 0;
    int minuto = 0;
    int contador = 0;           //Serve para alinhar a atribuição do charMes com atempo
    char charHoraMinuto[3];

    //Converte o mes em inteiro
    for (int i = 0; i < 6; i++)
    {
        //Quando encontrar uma barra deve analisar a string
        if (i == 2 || i == 5)
        {
            charHoraMinuto[2] = '\0';

            //A conversão do mes em inteiro
            switch (i)
            {
                case 2:
                    hora = charToInt (charHoraMinuto);
                    break;

                case 5:
                    minuto = charToInt (charHoraMinuto);

                default:
                    break;
            }

            contador = 0;
        }

        else
        {
            //Garante que tudo que está sendo analisado são números
            if (ehNumero (ahorario[i]) == 0)
            {
                throw std::invalid_argument ("Argumento inválido.\n");
            }

            charHoraMinuto[contador] = ahorario[i];

            contador++;
        }
    }

    if (hora < 7 || hora > 22)
    {
        throw std::invalid_argument ("Argumento inválido.\n");
    }

    if (minuto != 0 && minuto != 15 && minuto != 30 && minuto != 45)
    {
        throw std::invalid_argument ("Argumento inválido.\n");
    }

}



/** \brief Valida o parametro e em caso afirmativo, armazena o valor e em caso invalido gera uma excecao
 *
 * \param char ahorario[6] String contendo um horario a ser validado
 * \return Sem retorno
 *
 */
void Horario::setHorario (char ahorario[6]) throw (std::invalid_argument)
{

    validaHorario (ahorario);
    strcpy(horario, ahorario);

}



void Preco::validarPreco (float apreco) throw (std::invalid_argument)
{
    if(apreco > MAX || apreco < MIN)
    {
        throw std::invalid_argument("Argumento inválido.\n");
    }
}



/** \brief Valida o parametro e em caso afirmativo, armazena o valor e em caso invalido gera uma excecao
 *
 * \param float apreco Float contendo um preco a ser validado
 * \return Sem retorno
 *
 */
void Preco::setPreco (float apreco) throw (std::invalid_argument)
{
    validarPreco (apreco);
    this->preco = apreco;
}



void NumeroSala::validarNumeroSala (int anumeroSala) throw (std::invalid_argument)
{
    if (anumeroSala < MIN || anumeroSala > MAX){
        throw std::invalid_argument ("Argumento inválido.\n");
    }
}



/** \brief Valida o parametro e em caso afirmativo, armazena o valor e em caso invalido gera uma excecao
 *
 * \param int anumeroSala Int contendo um numero de sala a ser validado
 * \return Sem retorno
 *
 */
void NumeroSala::setNumeroSala (int anumeroSala) throw (std::invalid_argument)
{
    validarNumeroSala (anumeroSala);
    this->numeroSala = anumeroSala;
}



void Disponibilidade::validarDisponibilidade (int adisponibilidade) throw (std::invalid_argument)
{
    if (adisponibilidade < MIN || adisponibilidade > MAX){
        throw std::invalid_argument ("Argumento inválido.\n");
    }
}



/** \brief Valida o parametro e em caso afirmativo, armazena o valor e em caso invalido gera uma excecao
 *
 * \param int adisponibilidade[6] Int contendo um valor de disponibilidade de ingressos a ser validado
 * \return Sem retorno
 *
 */
void Disponibilidade::setDisponibilidade (int adisponibilidade) throw (std::invalid_argument)
{
    validarDisponibilidade (adisponibilidade);
    this->disponibilidade = adisponibilidade;
}



void FaixaEtaria::validarFaixaEtaria (std::string afaixaEtaria) throw (std::invalid_argument)
{
    if (afaixaEtaria != LIVRE
       && afaixaEtaria != DOZE_ANOS
       && afaixaEtaria != QUATORZE_ANOS
       && afaixaEtaria != DEZESEIS_ANOS
       && afaixaEtaria != DEZOITO_ANOS)
    {
        throw std::invalid_argument ("Argumento inválido.\n");
    }
}



/** \brief Valida o parametro e em caso afirmativo, armazena o valor e em caso invalido gera uma excecao
 *
 * \param std::string asetfaixaEtaria String contendo uma faixa etaria de evento a ser validado
 * \return Sem retorno
 *
 */
void FaixaEtaria::setFaixaEtaria (std::string afaixaEtaria) throw (std::invalid_argument)
{
    validarFaixaEtaria (afaixaEtaria);
    this->faixaEtaria = afaixaEtaria;
}



void ClasseEvento::validarClasseEvento (int aclasseEvento) throw (std::invalid_argument)
{
    if (aclasseEvento != TEATRO
       && aclasseEvento != ESPORTE
       && aclasseEvento != SHOW_NACIONAL
       && aclasseEvento != SHOW_INTERNACIONAL )
    {
        throw std::invalid_argument ("Argumento inválido.\n");
    }
}



/** \brief Valida o parametro e em caso afirmativo, armazena o valor e em caso invalido gera uma excecao
 *
 * \param int aclasseEvento Int contendo uma classe de evento a ser validado
 * \return Sem retorno
 *
 */
void ClasseEvento::setClasseEvento (int aclasseEvento) throw (std::invalid_argument)
{
    validarClasseEvento (aclasseEvento);
    this->classeEvento = aclasseEvento;
}



int Senha::isDigito (char acaractere)
{
    return (acaractere >= '0' && acaractere <= '9') ? 1 : 0;
}



int Senha::isMaiusculo (char acaractere)
{
    return (acaractere >= ASCII_A && acaractere <= ASCII_Z) ? 1 : 0;
}



int Senha::isMinusculo (char acaractere)
{
    return (acaractere >= ASCII_a && acaractere <= ASCII_z) ? 1 : 0;
}



int Senha::isRepetido (char acaractere, std::string asenha)
{
    std::size_t found = asenha.find (acaractere);
    return (found != std::string::npos && asenha.find(acaractere, found+1) != std::string::npos) ? 1 : 0 ;
}



int Senha::isCaractereValido(char acaractere)
{
    return (isDigito (acaractere) || isMaiusculo (acaractere) || isMinusculo (acaractere)) ? 1 : 0 ;
}



void Senha::validarSenha (std::string asenha) throw (std::invalid_argument)
{
    bool temDigito = false;

    bool temMaiusculo = false;

    bool temMinusculo = false;

    bool temRepetido = false;

    bool temCaractereInvalido = false;

    for(unsigned int i = 0; i < asenha.size (); i++){
        if(isDigito (asenha[i])){
            temDigito = true;
        }
        if(isMaiusculo (asenha[i])){
            temMaiusculo = true;
        }
        if(isMinusculo (asenha[i])){
            temMinusculo = true;
        }
        if(isRepetido (asenha[i], asenha)){
            temRepetido = true;
        }
        if(!isCaractereValido (asenha[i])){
            temCaractereInvalido = true;
        }
    }
    if ((!temDigito || !temMaiusculo || !temMinusculo || temRepetido) || asenha.size () != LIMITE_CARACTERE || temCaractereInvalido ){
        throw std::invalid_argument ("Argumento inválido.\n");
    }
}



/** \brief Valida o parametro e em caso afirmativo, armazena o valor e em caso invalido gera uma excecao
 *
 * \param std::string asenha String contendo uma senha a ser validado
 * \return Sem retorno
 *
 */
void Senha::setSenha (std::string asenha) throw (std::invalid_argument)
{
    validarSenha (asenha);
    this->senha = asenha;
}



int CPF::isDigito (char acaractere)
{
    return (acaractere >= '0' && acaractere <= '9') ? 1 : 0;
}



int CPF::isValidoPrimeiroDigito (std::string acpf)
{
    int soma = 0;

    int contador = 10;

    int aux;

    int primeiroDigito = acpf[9] - '0';

    for (int i = 0; i < 9; i++)
    {
        aux = acpf[i] - '0';
        soma = soma + (aux * contador);
        contador--;
    }

    soma *= 10;

    soma = soma%11;

    return (soma==primeiroDigito) ? 1 : 0;
}



int CPF::isValidoSegundoDigito (std::string acpf)
{
    int soma = 0;

    int contador = 11;

    int aux;

    int segundoDigito = acpf[10] - '0';

    for (int i = 0; i < 10; i++)
    {
        aux = acpf[i] - '0';
        soma = soma + (aux * contador);
        contador--;
    }

    soma *= 10;
    soma = soma%11;

    return (soma == segundoDigito) ? 1 : 0;
}



int CPF::isCPFInvalido (std::string acpf)
{
    char aux = acpf[0];

    for (int i = 1; i < 11; i++)
    {
        if (acpf[i] != aux){
            return 0;
        }
    }

    return 1;
}



int CPF::isFormatoValido (std::string acpf)
{
    if (acpf.size() != 14)
    {

    }

    else if (isDigito(acpf[0]) && isDigito(acpf[1]) && isDigito(acpf[2]) && acpf[3]=='.'
          && isDigito(acpf[4]) && isDigito(acpf[5]) && isDigito(acpf[6]) && acpf[7]=='.'
          && isDigito(acpf[8]) && isDigito(acpf[9]) && isDigito(acpf[10]) && acpf[11]=='-'
          && isDigito(acpf[12]) && isDigito(acpf[13]))
    {
        return 1;
    }

    return 0;
}



void CPF::validarCPF (std::string acpf) throw (std::invalid_argument)
{
    std::string aux = "";

    for (unsigned int i = 0; i < 14; i++)
    {
        if (isDigito (acpf[i]))
        {
            aux = aux + acpf[i];
        }
    }

    if (!isValidoPrimeiroDigito (aux) || !isValidoSegundoDigito (aux) || isCPFInvalido (aux) || !isFormatoValido (acpf))
    {
        throw std::invalid_argument ("Argumento inválido.\n");
    }

}



/** \brief Valida o parametro e em caso afirmativo, armazena o valor e em caso invalido gera uma excecao
 *
 * \param std::string acpf String contendo um CPF a ser validado
 * \return Sem retorno
 *
 */
void CPF::setCPF (std::string acpf) throw (std::invalid_argument)
{
    validarCPF (acpf);
    this->cpf = acpf;
}



int NumeroCartaoCredito::isValidoNumeroCartaoCredito (std::string anumeroCartaoCredito)
{
    int nSum       = 0;

    int nDigits    = anumeroCartaoCredito.size();

    int nParity    = (nDigits-1) % 2;

    char cDigit;

    for (int i = nDigits; i > 0 ; i--)
    {
        cDigit = anumeroCartaoCredito[i-1];
        int nDigit = cDigit - '0';

        if (nParity == i % 2)
            nDigit = nDigit * 2;

        nSum += nDigit/10;

        nSum += nDigit%10;
    }

    return (0 == nSum % 10) ? 1 : 0;
}



void NumeroCartaoCredito::validarNumeroCartaoCredito (std::string anumeroCartaoCredito) throw (std::invalid_argument)
{
    if (!isValidoNumeroCartaoCredito (anumeroCartaoCredito))
    {
        throw std::invalid_argument ("Argumento inválido.\n");
    }
}



/** \brief Valida o parametro e em caso afirmativo, armazena o valor e em caso invalido gera uma excecao
 *
 * \param std::string anumeroCartaoCredito String contendo um numero de cartao de credito a ser validado
 * \return Sem retorno
 *
 */
void NumeroCartaoCredito::setNumeroCartaoCredito (std::string anumeroCartaoCredito) throw (std::invalid_argument)
{
    validarNumeroCartaoCredito (anumeroCartaoCredito);
    this->numeroCartaoCredito = anumeroCartaoCredito;
}


