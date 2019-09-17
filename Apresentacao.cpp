/** \file Apresentacao.cpp
 * \brief Documento com todas as implementacoes das classes da camada de apresentacao
 * \author Alexandre Mitsuru Kaihara e Lucas silva
 * \since 02/05/19
 * \version 1.0
 */
#include <iostream>
#include "Apresentacao.h"
#include "BancoDados.h"



void AControle::executar (AControle* acontrole)
{
    // Ponteiro para o login de usuário
    Usuario* usuario = 0;
    int sair = 0;
    int opcao;

    while (sair ==0)
    {
        if(usuario != 0)
        {
            std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
            std::cout << "Sistema de venda de Ingressos:              Usuario:";
            std::cout << usuario->getCPF() << + "\n\n";
            std::cout << "[0] Autenticar usuario\n[1] Usuario\n[2] Eventos\n[3] Compra/Venda\n[4] Sair\n";
        }
        else
        {
            std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
            std::cout << "Sistema de venda de Ingressos:              Usuario:\n\n";
            std::cout << "[0] Autenticar usuario\n[1] Usuario\n[2] Eventos\n[3] Compra/Venda\n[4] Sair\n";
        }


        // Usou-se scanf pois assim quando o buffer recebe mais de um caractere, ele não buga
        setbuf(stdin, nullptr);
        scanf("%d", &opcao);

        if      (opcao == 0)
        {
            usuario = acontrole->objetoIAAutenticacao->executarAutenticar ();
        }
        else if (opcao == 1)
        {
            acontrole->objetoIAUsuario->executarUsuario (&usuario);
        }
        else if (opcao == 2)
        {
            acontrole->objetoIAEvento->executarEvento (usuario);
        }
        else if (opcao == 3)
        {
            if (usuario != nullptr)
            {
                acontrole->objetoIAVEndas->executarVendas (usuario);
            }
            else
            {
                std::cout << "Necessario Login (Autenticacao)\n";
                setbuf(stdin, nullptr);
                getchar();
            }
        }
        else if (opcao == 4)
        {
            sair = 1;
        }
    }
}



Usuario* AAutenticar::executarAutenticar ()
{
    int sair = 0;
    int option;
    while (sair == 0)
    {
        std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
        std::cout << "[0] Autenticar usuario\n[1] Sair\n";

        // Usou-se scanf pois assim quando o buffer recebe mais de um caractere, ele não buga
        setbuf(stdin, nullptr);
        scanf("%d", &option);

        if (option == 0)
        {
            Validadores v;

            CPF cpf;
            if (v.validador_cpf (&cpf)     == -1) break;

            Senha senha;
            if (v.validador_senha (&senha) == -1) break;

            Database database;
            Usuario* usuario;
            if (database.open_database(&database.db) != SQLITE_OK)
            {
                database.print_error (&database);
            }

            int retorno;
            retorno = this->objetoISAutenticacao->autenticar (cpf, senha, &database);
            if (retorno == 0)
            {
                usuario = new Usuario ();

                usuario->setCPF (cpf);

                usuario->setSenha (senha);

                printf("Autenticado com sucesso!\n");
                setbuf(stdin, nullptr);
                getchar();
            }
            else if (retorno == -1)
            {
                database.print_error (&database);
                usuario = 0;
            }
            else if (retorno == -2)
            {
                printf("CPF ou Senha incorretos!\n");
                setbuf(stdin, nullptr);
                getchar();
                usuario = 0;
            }

            database.close_database(database.db);
            return usuario;
        }
        else if (option == 1)
        {
            sair = 1;
        }
    }
    return 0;
}



void AUsuario::executarUsuario (Usuario** ausuario)
{
    int sair = 0, opcao;
    while (sair == 0)
    {
        std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
        std::cout <<"[0] Cadastrar usuario\n[1] Descadastrar usuario\n[2] Sair\n";

        setbuf (stdin, nullptr);
        scanf ("%d", &opcao);

        switch (opcao)
        {
            case 0:
            {
                Validadores v;

                CPF cpf;
                if (v.validador_cpf (&cpf) == -1) break;

                Senha senha;
                if (v.validador_senha (&senha) == -1) break;

                NumeroCartaoCredito numeroCartaoCredito;
                if (v.validador_numeroCartaoCredito (&numeroCartaoCredito) == -1) break;

                CodigoSeguranca codigoSeguranca;
                if (v.validador_codigoSeguranca(&codigoSeguranca) == -1) break;

                DataValidade dataValidade;
                if (v.validador_dataValidade(&dataValidade) == -1) break;

                this->objetoISUsuario->cadastrar(cpf, senha, numeroCartaoCredito, codigoSeguranca, dataValidade);
                break;
            }

            case 1:
            {
                // Se o usuario nao tiver sido logado ele não pode descadastrar a si mesmo
                if (*ausuario == nullptr)
                {
                    std::cout << "Necessario Login (Autenticacao)\n";
                    setbuf(stdin, nullptr);
                    getchar();
                }
                else
                {
                    CPF cpf;
                    cpf.setCPF ((*ausuario)->getCPF());
                    //Sucesso na autenticacao
                    if (this->objetoISUsuario->descadastrar(cpf) == 0)
                    {
                        // Deletado o usuario, deve deslogar o usuario
                        delete (*ausuario);
                        *ausuario = 0;
                    }
                }
                break;
            }

            case 2:
            {
                sair = 1;
                break;
            }
            default:
            {
                break;
            }
        }
    }
}



void AEvento::executarEvento (Usuario* ausuario)
{
    int sair = 0, opcao;

    while (sair == 0)
    {
        std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
        std::cout << "[0] Criar evento\n[1] Consultar evento\n[2] Editar evento\n[3] Status de vendas\n[4] Sair\n";

        setbuf (stdin, nullptr);
        scanf ("%d", &opcao);
        switch (opcao)
        {
            case 0:
            {
                executarCriarEvento(ausuario);
                break;
            }

            case 1:
            {
                executarConsultarEvento();
                break;
            }

            case 2:
            {
                executarEditarEvento (ausuario);
                break;
            }

            case 3:
            {
                executarStatusEvento(ausuario);
                break;
            }

            case 4:
            {
                sair = 1;
                break;
            }

            default:
            {
                break;
            }
        }
    }
}



void AEvento::executarCriarEvento (Usuario* ausuario)
{
    if (ausuario == nullptr)
    {
        std::cout << "Necessario autenticacao!\n";
        setbuf(stdin, nullptr);
        getchar();
    }
    else
    {
        Validadores v;

        CodigoEvento codigoEvento;
        if (v.validador_codigoEvento(&codigoEvento)  == -1)     return;

        NomeEvento nomeEvento;
        if (v.validador_nomeEvento (&nomeEvento)     == -1)     return;

        Cidade cidade;
        if (v.validador_cidade (&cidade)             == -1)     return;

        Estado estado;
        if (v.validador_estado (&estado)             == -1)     return;

        ClasseEvento classeEvento;
        if (v.validador_classeEvento (&classeEvento) == -1)     return;

        FaixaEtaria faixaEtaria;
        if (v.validador_faixaEtaria (&faixaEtaria)   == -1)     return;

        Evento evento;

        evento.setCodigoEvento  (codigoEvento);
        evento.setNomeEvento    (nomeEvento);
        evento.setCidade        (cidade);
        evento.setEstado        (estado);
        evento.setClasseEvento  (classeEvento);
        evento.setFaixaEtaria   (faixaEtaria);

        Apresentacao*apresentacao[10];

        for(int i = 0; i<10; i++)
        {
            apresentacao[i] = nullptr;
        }

        CodigoApresentacao codigoApresentacao;

        Data data;

        Horario horario;

        Preco preco;

        NumeroSala numeroSala;

        Disponibilidade disponibilidade;

        int opcao1, sair1=0;
        int contadorApresentacao = 0;
        for (int i = 0; sair1 == 0; i++)
        {
            std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
            std::cout << "[0] Criar apresentacao       Criados: ";
            std::cout << contadorApresentacao << "\n";
            std::cout << "[1] Finalizar\n";
            std::cin  >> opcao1;

            if (contadorApresentacao >= 10 && opcao1 != 1)
            {
                std::cout << "Possivel criar apenas 10 apresentacoes por evento\n";
                setbuf (stdin,nullptr);
                getchar();
            }
            else
            {
                switch (opcao1)
                {
                    case 0:
                    {
                        if (v.validador_codigoApresentacao (&codigoApresentacao) == -1) break;

                        if (v.validador_data (&data)                             == -1) break;

                        if (v.validador_horario (&horario)                       == -1) break;

                        if (v.validador_preco (&preco)                           == -1) break;

                        if (v.validador_numeroSala (&numeroSala)                 == -1) break;

                        if (v.validador_disponibilidade(&disponibilidade)        == -1) break;

                        apresentacao[i] = new Apresentacao();
                        contadorApresentacao++;

                        apresentacao[i]->setCodigoApresentacao (codigoApresentacao);
                        apresentacao[i]->setData               (data);
                        apresentacao[i]->setHorario            (horario);
                        apresentacao[i]->setPreco              (preco);
                        apresentacao[i]->setNumeroSala         (numeroSala);
                        apresentacao[i]->setDisponibilidade    (disponibilidade);

                        break;
                    }

                    case 1:
                    {
                        opcao1 = -1;

                        if (contadorApresentacao == 0)
                        {
                            std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
                            std::cout << "Crie no mínimo uma apresentacao para o evento\n[0] Continuar a criar apresentacoes\n[1] Sair (O evento sera excluido)\n";
                            std::cin  >> opcao1;
                        }

                        if (opcao1 == 1)
                        {
                            sair1 = 1;
                            break;
                        }
                        else if (opcao1 == 0)
                        {
                            break;
                        }

                        sair1 = 1;
                        break;
                    }

                    default:
                    {
                        break;
                    }
                }
            }
        }

        if (contadorApresentacao != 0)
        {
            //Cria no banco de dados os dados recebidos
            objetoISEvento->criarEvento(&evento, apresentacao, ausuario);
        }
    }
}



void AEvento::executarConsultarEvento ()
{
    Validadores v;

    std::cout << "(Data inicio)";
    Data datainicio;
    if (v.validador_data (&datainicio) == -1) return;

    std::cout << "(Data fim)";
    Data datafim;
    if (v.validador_data (&datafim)    == -1) return;

    Cidade cidade;
    if (v.validador_cidade (&cidade)   == -1) return;

    Estado estado;
    if (v.validador_estado (&estado)   == -1) return;

    std::cout  << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";

    objetoISEvento->consultar (datainicio, datafim, cidade, estado);
}



void AEvento::executarEditarEvento (Usuario* ausuario)
{
    // Se nao tiver autenticado um usuario, nao pode editar evento
    if (ausuario == nullptr)
    {
        std::cout << "Necessario autenticacao!\n";
        setbuf(stdin, nullptr);
        getchar();
        return;
    }

    Validadores v;
    int sair = 0, opcao;
    while (sair == 0)
    {
        std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
        std::cout << "[0] Alterar dados\n[1] Descadastrar\n[2] Sair\n";
        setbuf(stdin, nullptr);
        scanf("%d", &opcao);

        switch (opcao)
        {
            // Alterar dados
            case 0:
            {
                CodigoEvento codigoEvento;
                if (v.validador_codigoEvento (&codigoEvento)  == -1) break;


                std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
                std::cout << "Alterar:\n[0] CodigoEvento\n[1] Nome do evento:\n[2] Cidade\n[3] Estado\n[4] Classe de evento\n[5] Faixa etaria\n";
                setbuf(stdin, nullptr);
                scanf("%d", &opcao);

                Evento evento;

                switch (opcao)
                {
                    case 0:
                    {
                        CodigoEvento codigoEvento1;
                        if (v.validador_codigoEvento (&codigoEvento1)  == -1) break;

                        evento.setCodigoEvento(codigoEvento1);

                        break;
                    }

                    case 1:
                    {
                        NomeEvento nomeEvento;
                        if (v.validador_nomeEvento (&nomeEvento)  == -1) break;

                        evento.setNomeEvento (nomeEvento);

                        break;
                    }

                    case 2:
                    {
                        Cidade cidade;
                        if (v.validador_cidade (&cidade)  == -1) break;

                        evento.setCidade (cidade);

                        break;
                    }

                    case 3:
                    {
                        Estado estado;
                        if (v.validador_estado (&estado)  == -1) break;

                        evento.setEstado (estado);

                        break;
                    }

                    case 4:
                    {
                        ClasseEvento classeEvento;
                        if (v.validador_classeEvento (&classeEvento)  == -1) break;

                        evento.setClasseEvento (classeEvento);

                        break;
                    }

                    case 5:
                    {
                        FaixaEtaria faixaEtaria;
                        if (v.validador_faixaEtaria (&faixaEtaria)  == -1) break;

                        evento.setFaixaEtaria (faixaEtaria);

                        break;
                    }

                    default:
                    {
                        break;
                    }
                }
                objetoISEvento->editarEvento(&evento, opcao, ausuario, codigoEvento);

                break;
            }
            // Descadastrar
            case 1:
            {
                CodigoEvento codigoEvento;
                if (v.validador_codigoEvento (&codigoEvento)  == -1) break;

                objetoISEvento->deletarEvento(codigoEvento, ausuario);

                break;
            }

            case 2:
            {
                sair = 1;
                break;
            }

            default:
            {
                break;
            }
        }
    }
}



void AEvento::executarStatusEvento (Usuario* ausuario)
{
    int sair3 = 0, opcao3;
    while(sair3 == 0)
    {
        std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
        std::cout << "Status de vendas\n[0] Consultar status\n[1] Sair\n";
        scanf("%d", &opcao3);

        switch (opcao3)
        {
            case 0:
            {
                Validadores v;

                CodigoEvento codigoEvento;
                if (v.validador_codigoEvento (&codigoEvento)  == -1) break;

                objetoISEvento->statusvenda (codigoEvento, ausuario);
                break;
            }

            case 1:
            {
                sair3 = 1;
                break;
            }

            default:
            {
                break;
            }
        }
    }
}



void AVendas::executarVendas (Usuario* ausuario)
{
    int sair = 0, opcao, quantidade;
    while (sair == 0)
    {
        std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
        std::cout << "Compra de ingressos:\n[0] Comprar um ingresso\n[1] Sair\n";
        setbuf(stdin, nullptr);
        scanf("%d", &opcao);

        switch (opcao)
        {
            case 0:
            {
                Validadores v;

                CodigoApresentacao codigoApresentacao;
                if (v.validador_codigoApresentacao(&codigoApresentacao)  == -1) break;

                std::cout << "Digite a quantidade de ingressos desejados\n";
                std::cin >> quantidade;

                if (quantidade > 250 || quantidade <= 0)
                {
                    std::cout << "Quantidade de ingressos invalido!\n";
                    setbuf(stdin, nullptr);
                    getchar();
                    break;
                }

                objetoISVendas->comprar(codigoApresentacao, quantidade, ausuario);

                break;
            }

            case 1:
            {
                sair = 1;
                break;
            }

            default:
            {
                break;
            }
        }
    }
}
