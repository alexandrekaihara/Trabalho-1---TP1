#ifndef VALIDADORES_H_INCLUDED
#define VALIDADORES_H_INCLUDED

#include <iostream>
#include "Dominio.h"
#include "Entidades.h"



class Validadores
{
public:


    int validador_cpf (CPF *cpf);


    int validador_senha (Senha *senha);


    int validador_numeroCartaoCredito (NumeroCartaoCredito *numeroCartaoCredito);


    int validador_codigoSeguranca (CodigoSeguranca *codigoSeguranca);


    int validador_codigoEvento (CodigoEvento *codigoEvento);


    int validador_codigoApresentacao (CodigoApresentacao *codigoApresentacao);


    int validador_nomeEvento (NomeEvento *nomeEvento);


    int validador_cidade (Cidade *cidade);


    int validador_estado (Estado *estado);


    int validador_data (Data *data);


    int validador_dataValidade (DataValidade *dataValidade);


    int validador_horario (Horario *horario);


    int validador_classeEvento (ClasseEvento *classeEvento);


    int validador_faixaEtaria (FaixaEtaria *faixaEtaria);


    int validador_preco (Preco *preco);


    int validador_numeroSala (NumeroSala *numeroSala);


    int validador_disponibilidade (Disponibilidade *disponibilidade);


};




#endif
