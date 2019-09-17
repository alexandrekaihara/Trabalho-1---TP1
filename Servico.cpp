/** \file Servico.cpp
 * \brief Documento com todas as implementacoes das classes da camada de servicos
 * \author Alexandre Mitsuru Kaihara e Lucas silva
 * \since 02/05/19
 * \version 1.0
 */
#include <iostream>
#include <sstream>
#include <string>
#include "Servico.h"
#include "BancoDados.h"



int SAutenticar::autenticar (CPF acpf, Senha asenha, Database *database)
{
    std::string sql;
    sql = "SELECT Senha FROM Cliente WHERE CPF = '";
    sql += acpf.getCPF() + "';";

    const unsigned char* ret;

    if (database->prepare_v2_database (database->db, (char*)sql.c_str(), -1, &database->stmt, NULL) != SQLITE_OK) return -1;

    if ((database->rc = database->step_text_database(database->stmt, &ret)) == -1)                                return -1;


    // Converter a senha recebida em char para comparar
    char senha[asenha.getSenha ().length ()+1];
    strcpy(senha, asenha.getSenha ().c_str ());

    if (strcmp (senha, (const char*)ret) == 0)
    {
        sqlite3_finalize(database->stmt);
        return 0;
    }
    else
    {
        // CPF ou senha incorretos
        sqlite3_finalize(database->stmt);
        return -2;
    }
}



int SUsuario::cadastrar (CPF acpf, Senha asenha, NumeroCartaoCredito anumeroCartaoCredito, CodigoSeguranca acodigoSeguranca, DataValidade adataValidade) throw (std::invalid_argument)
{
    // Converte o numero em string para realizar comando no sqlite
    std::stringstream ss;
    ss << acodigoSeguranca.getCodigo();
    std::string sql1 = ss.str();

    // Assume-se que o cpf recebido ja foi autenticado e a senha também

    Database database;

    if (database.open_database(&database.db) != 0)
    {
        return -1;
    }

    std::string sql;
    sql = "INSERT INTO Cliente (CPF, Senha) VALUES ('";
    sql += acpf.getCPF() + "', '";
    sql += asenha.getSenha() + "')";

    database.rc = database.exec_database (database.db, (char*)sql.c_str(), database.callback, 0, &database.zErrMsg);

    sql = "INSERT INTO CartaoCredito (CPF, NumeroCartaoCredito, CodigoSeguranca, DataValidade) VALUES ('";
    sql += acpf.getCPF() + "', '";
    sql += anumeroCartaoCredito.getNumeroCartaoCredito() + "', ";
    sql += sql1 + ", '";
    sql += (std::string)adataValidade.getDataValidade() + "');";

    database.rc = database.exec_database (database.db, (char*)sql.c_str(), database.callback, 0, &database.zErrMsg);

    database.close_database(database.db);

    if (database.rc == 0)
    {
        std::cout << "Usuario cadastrado com sucesso!\n";
        setbuf(stdin, nullptr);
        getchar();
    }

    return database.rc;
}



int SUsuario::descadastrar (CPF acpf)
{
    Database database;

    if (database.open_database(&database.db) != 0) return -1;

    std::string sql;
    sql = "SELECT Responsavel FROM Evento WHERE Responsavel = '";
    sql += acpf.getCPF() + "'";

    const unsigned char* ret;

    if (database.prepare_v2_database (database.db, (char*)sql.c_str(), -1, &database.stmt, NULL) != SQLITE_OK) return -1;

    // Se o usuario for responsavel por um evento, devera estar em ret
    if((database.rc = database.step_text_database(database.stmt, &ret)) == -1) return -1;

    // Se o retorno do comando SQL for nulo, significa que o usuario não é responsavel por um evento
    if (strcmp((char*)acpf.getCPF().c_str(), (const char*)ret) != SQLITE_OK)
    {
        sqlite3_finalize(database.stmt);

        sql = "DELETE FROM Cliente WHERE CPF = '" + acpf.getCPF() + "'";

        if (database.exec_database (database.db, (char*)sql.c_str(), database.callback, 0, &database.zErrMsg) != SQLITE_OK) return -1;
        std::cout << acpf.getCPF() << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";

        sql = "DELETE FROM CartaoCredito WHERE CPF = '" + acpf.getCPF() + "'";

        if (database.exec_database (database.db, (char*)sql.c_str(), database.callback, 0, &database.zErrMsg) != SQLITE_OK) return -1;

        std::cout << "Descadastro com sucesso\n";
        setbuf(stdin, nullptr);
        getchar();
    }

    else
    {
        std::cout << "Erro no descadastro. " << acpf.getCPF() << " eh resposavel por um evento\n";
        setbuf(stdin, nullptr);
        getchar();

        sqlite3_finalize(database.stmt);

        database.close_database(database.db);

        return -1;
    }

    database.close_database(database.db);

    return 0;
}



int SEvento::criarEvento (Evento* aevento, Apresentacao** aapresentacao, Usuario* usuario)
{
    Database database;

    if (database.open_database(&database.db) != 0)
    {
        return -1;
    }

    std::string sql;
    sql = "SELECT COUNT(Responsavel) FROM Evento WHERE Responsavel = '";
    sql += usuario->getCPF() + "';";

    if (database.prepare_v2_database (database.db, (char*)sql.c_str(), -1, &database.stmt, NULL) != 0)
    {
        return -1;
    }

    const unsigned char* ret;
    int ret_code;

    // Le todos os cpf dos responsaveis de evento, se for maior que 5, não pode criar evento no cpf cadastrado
    if ((ret_code = database.step_text_database(database.stmt, &ret)) == -1)
    {
        return -1;
    }

    int retorno;
    std::stringstream ss5 ((const char*)ret);
    ss5 >> retorno;

    sqlite3_finalize(database.stmt);


    if (retorno >= 5)
    {
        std::cout << "Usuario responsavel por mais de 5 eventos!\n";
        setbuf(stdin, nullptr);
        getchar();
        return -1;
    }

    std::stringstream ss;
    ss << aevento->getCodigoEvento();
    std::string codigoevento = ss.str();

    std::string nomeevento (aevento->getNomeEvento());

    std::string cidade     (aevento->getCidade());

    std::string estado     (aevento->getEstado());

    std::stringstream ss6;
    ss6 << aevento->getClasseEvento();
    std::string classeevento = ss6.str();

    sql = "INSERT INTO Evento (Responsavel, CodigoEvento, NomeEvento, Cidade, Estado, ClasseEvento, FaixaEtaria) VALUES ('";
    sql += usuario->getCPF()         + "', ";
    sql += codigoevento              + ", '";
    sql += nomeevento                + "', '";
    sql += cidade                    + "', '";
    sql += estado                    + "', ";
    sql += classeevento              + ", '";
    sql += aevento->getFaixaEtaria() + "');";

    database.exec_database (database.db, (char*)sql.c_str(), database.callback, 0, &database.zErrMsg);

    for (int i = 0; i < 10 && aapresentacao[i] != nullptr; i++)
    {
        std::stringstream ss1;
        ss1 << aapresentacao[i]->getCodigoApresentacao();
        std::string codigoapresentacao = ss1.str();

        std::string data = (std::string)aapresentacao[i]->getData();

        std::string horario = (std::string)aapresentacao[i]->getHorario();

        std::stringstream ss2;
        ss2 << aapresentacao[i]->getPreco();
        std::string preco (ss2.str());

        std::stringstream ss3;
        ss3 << aapresentacao[i]->getNumeroSala();
        std::string numerosala = ss3.str();

        std::stringstream ss4;
        ss4 << aapresentacao[i]->getDisponibilidade();
        std::string disponibilidade = ss4.str();

        sql = "INSERT INTO Apresentacao (Evento, CodigoApresentacao, Data, Horario, Preco, NumeroSala, Disponibilidade) VALUES (";
        sql += codigoevento       + ", ";
        sql += codigoapresentacao + ", '";
        sql += data               + "', '";
        sql += horario            + "', '";
        sql += preco              + "', '";
        sql += numerosala         + "', '";
        sql += disponibilidade    + "');";

        database.rc = database.exec_database (database.db, (char*)sql.c_str(), database.callback, 0, &database.zErrMsg);
    }

    if (database.rc == 0)
    {
        std::cout << "Cadastro de evento e apresentacoes com sucesso!\n";
        setbuf(stdin, nullptr);
        getchar();
    }

    database.close_database(database.db);

    return 0;
}



int SEvento::consultar (Data adataInicio, Data adataFim, Cidade acidade, Estado aestado)
{
    std::string datainicio (adataInicio.getData ());
    std::string datafim    (adataFim.getData ());
    std::string cidade     (acidade.getCidade ());
    std::string estado     (aestado.getEstado ());

    Database database;

    if (database.open_database (&database.db) != 0)
    {
        return -1;
    }

    std::string sql;
    sql = "SELECT CodigoEvento as CODEV, NomeEvento as Evento, ClasseEvento as Classe, FaixaEtaria FROM Evento, Apresentacao WHERE";
    sql += " Evento.Cidade = '"           + cidade;
    sql += "' AND Evento.Estado = '"      + estado;
    sql += "' AND Apresentacao.Data >= '" + datainicio;
    sql += "' AND Apresentacao.Data <= '" + datafim;
    sql += "' AND Apresentacao.Evento = Evento.CodigoEvento";
    sql += " GROUP BY CodigoEvento ;";

    database.exec_database (database.db, (char*)sql.c_str(), database.callback, (void*)"Callback function called", &database.zErrMsg);

    std::cout << "\n";

    sql = "SELECT CodigoEvento as CODEV, CodigoApresentacao as CODAP, Data, Horario as 'as', Preco, NumeroSala as Sala, Disponibilidade as Disp FROM Evento, Apresentacao WHERE";
    sql += " Evento.Cidade = '"            + cidade;
    sql += "' AND Evento.Estado = '"      + estado;
    sql += "' AND Apresentacao.Data >= '" + datainicio;
    sql += "' AND Apresentacao.Data <= '" + datafim;
    sql += "' AND Apresentacao.Evento = Evento.CodigoEvento;";

    database.exec_database (database.db, (char*)sql.c_str(), database.callback, (void*)"Callback function called", &database.zErrMsg);

    setbuf(stdin, nullptr);
    getchar();

    database.close_database(database.db);

    return 0;
}



int SEvento::editarEvento (Evento* aevento, int aparam, Usuario* ausuario, CodigoEvento acodigoevento)
{
    std::stringstream ss2;
    ss2 << acodigoevento.getCodigo ();
    std::string codigoevento = ss2.str ();

    std::string sql1;
    sql1 =  "SELECT COUNT(Ingresso.CodigoIngresso) ";
    sql1 += "FROM Ingresso ";
    sql1 += "WHERE Ingresso.Apresentacao IN (SELECT Apresentacao.CodigoApresentacao FROM Apresentacao WHERE ";
    sql1 += "Apresentacao.Evento = " + codigoevento + ");";

    const unsigned char* ret;

    Database database;

    if (database.open_database(&database.db) != 0)
    {
        return -1;
    }

    if (database.prepare_v2_database (database.db, (char*)sql1.c_str(), -1, &database.stmt, NULL) != 0)
    {
        return -1;
    }

    // Le a quantidade de ingressos vendidos do evento dado
    if ((database.rc = database.step_text_database(database.stmt, &ret)) == -1)
    {
        return -1;
    }

    int retorno;
    std::stringstream ss5 ((const char*)ret);
    ss5 >> retorno;

    sqlite3_finalize (database.stmt);

    if (retorno > 0)
    {
        std::cout << "Alteracao nao permitida. Ingressos ja vendidos!\n";
        setbuf(stdin, nullptr);
        getchar();
        return -1;
    }


    std::string str;
    std::string atributo;

    switch (aparam)
    {
        case 0:
        {
            std::stringstream ss;
            ss << aevento->getCodigoEvento ();
            str = ss.str ();

            atributo = "CodigoEvento";
            break;
        }

        case 1:
        {
            str = "'" + (std::string)aevento->getNomeEvento () + "'";
            atributo = "NomeEvento";
            break;
        }

        case 2:
        {
            str = "'" + (std::string)aevento->getCidade () + "'";
            atributo = "Cidade";
            break;
        }

        case 3:
        {
            str = "'" + (std::string)aevento->getEstado () + "'";
            atributo = "Estado";
            break;
        }

        case 4:
        {
            std::stringstream ss1;
            ss1 << aevento->getClasseEvento ();
            atributo = "ClasseEvento";
            str = ss1.str();
            break;
        }

        case 5:
        {
            str = "'" + (std::string)aevento->getFaixaEtaria () + "'";
            atributo = "FaixaEtaria";
            break;
        }

        default:
        {
            return -1;
        }
    }

    std::string sql;
    sql =  "UPDATE Evento SET " + atributo + " = " + str;
    sql += " WHERE Responsavel = '" + ausuario->getCPF();
    sql += "' AND CodigoEvento = "  + codigoevento + ";";

    database.rc = database.exec_database (database.db, (char*)sql.c_str(), database.callback, 0, &database.zErrMsg);

    if (database.rc == 0)
    {
        std::cout << "Dados atualizados com sucesso\n";
        setbuf(stdin, nullptr);
        getchar();
    }

    database.close_database(database.db);

    return database.rc;

}



int SEvento::deletarEvento (CodigoEvento acodigoEvento, Usuario* ausuario)
{
    std::stringstream ss;
    ss << acodigoEvento.getCodigo ();
    std::string codigoevento (ss.str ());

    std::string sql1 = "SELECT COUNT(Ingresso.CodigoIngresso) FROM Ingresso WHERE Ingresso.Apresentacao IN (SELECT Apresentacao.CodigoApresentacao FROM Apresentacao WHERE Apresentacao.Evento = " + codigoevento + ");";

    const unsigned char* ret;

    Database database;

    if (database.open_database(&database.db) != 0)
    {
        return -1;
    }

    if (database.prepare_v2_database (database.db, (char*)sql1.c_str(), -1, &database.stmt, NULL) != 0)
    {
        return -1;
    }

    // Le a quantidade de ingressos vendidos do evento dado
    if ((database.rc = database.step_text_database(database.stmt, &ret)) == -1)
    {
        return -1;
    }

    int retorno;
    std::stringstream ss5 ((const char*)ret);
    ss5 >> retorno;

    sqlite3_finalize (database.stmt);

    if (retorno > 0)
    {
        std::cout << "Descadastro nao permitido. Ingressos ja vendidos!\n";
        setbuf(stdin, nullptr);
        getchar();
        return -1;
    }


    std::string sql = "SELECT Responsavel FROM Evento WHERE CodigoEvento = " + codigoevento + ";";

    if (database.prepare_v2_database (database.db, (char*)sql.c_str(), -1, &database.stmt, NULL) != 0)
    {
        return -1;
    }

    // Le o responsavel pelo codigo de evento recebido
    if ((database.rc = database.step_text_database(database.stmt, &ret)) == -1)
    {
        sqlite3_finalize(database.stmt);
        database.close_database(database.db);
        return -1;
    }

    if (strcmp((const char*)ret, (const char*)ausuario->getCPF ().c_str()) == 0)
    {
        sqlite3_finalize(database.stmt);

        sql = "DELETE FROM Evento WHERE CodigoEvento = " + codigoevento + ";";

        database.rc = database.exec_database (database.db, (char*)sql.c_str(), database.callback, 0, &database.zErrMsg);

        sql = "DELETE FROM Apresentacao WHERE Evento = " + codigoevento + ";";

        database.rc = database.exec_database (database.db, (char*)sql.c_str(), database.callback, 0, &database.zErrMsg);

        if (database.rc == 0)
        {
            std::cout << "Evento deletado com sucesso!\n";
            setbuf(stdin, nullptr);
            getchar();
        }
    }

    else
    {
        sqlite3_finalize(database.stmt);

        std::cout << "Usuario nao responsavel pelo codigo do evento digitado ou evento nao existente!\n";
        setbuf(stdin, nullptr);
        getchar();
    }

    database.close_database(database.db);

    return database.rc;
}



int SEvento::statusvenda (CodigoEvento acodigoEvento, Usuario* ausuario)
{
    std::stringstream ss;
    ss << acodigoEvento.getCodigo ();
    std::string codigoevento (ss.str ());

    std::string sql = "SELECT Responsavel FROM Evento WHERE CodigoEvento = " + codigoevento + ";";

    Database database;

    if (database.open_database(&database.db) != 0)
    {
        return -1;
    }

    if (database.prepare_v2_database (database.db, (char*)sql.c_str(), -1, &database.stmt, NULL) != 0)
    {
        database.close_database(database.db);
        return -1;
    }

    const unsigned char* ret;

    // Le o responsavel pelo codigo de evento recebido
    if ((database.rc = database.step_text_database(database.stmt, &ret)) == -1)
    {
        sqlite3_finalize(database.stmt);
        database.close_database(database.db);
        return -1;
    }

    if (strcmp((const char*)ret, (const char*)ausuario->getCPF ().c_str()) == 0)
    {
        sqlite3_finalize(database.stmt);

        std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";

        sql = "SELECT SUM(Ingresso.Quantidade) AS 'Quantidade Total' FROM Ingresso WHERE Ingresso.Apresentacao IN (SELECT Apresentacao.CodigoApresentacao FROM Apresentacao WHERE Evento = " + codigoevento + " );";

        database.exec_database (database.db, (char*)sql.c_str(), database.callback, (void*)"Callback function called", &database.zErrMsg);

        sql = "SELECT CPF FROM Ingresso WHERE Ingresso.Apresentacao IN (SELECT Apresentacao.CodigoApresentacao FROM Apresentacao WHERE Evento = " + codigoevento + ");";

        database.exec_database (database.db, (char*)sql.c_str(), database.callback, (void*)"Callback function called", &database.zErrMsg);

        setbuf(stdin, nullptr);
        getchar();
    }
    else
    {
        sqlite3_finalize(database.stmt);

        std::cout << "Usuario nao responsavel pelo codigo do evento digitado ou evento nao existente!\n";
        setbuf(stdin, nullptr);
        getchar();
    }

    database.close_database(database.db);

    return database.rc;
}



int SVendas::comprar (CodigoApresentacao acodigoapresentacao, int aquantidade, Usuario* ausuario)
{
    Database database;

    if (database.open_database(&database.db) != 0)
    {
        return -1;
    }

    std::stringstream ss2;
    ss2 << acodigoapresentacao.getCodigo();
    std::string codigoapresentacao = ss2.str ();

    std::string sql = "SELECT Disponibilidade, CodigoApresentacao FROM Apresentacao WHERE CodigoApresentacao = " + codigoapresentacao + ";" ;

    if (database.prepare_v2_database (database.db, (char*)sql.c_str(), -1, &database.stmt, NULL) != 0)
    {
        sqlite3_finalize(database.stmt);
        database.close_database(database.db);
        return -1;
    }

    const unsigned char* ret;

    // Le se a disponibilidade é compativel com a quantidade de infressos desejada
    if ((database.rc = database.step_text_database(database.stmt, &ret)) == -1)
    {
        sqlite3_finalize(database.stmt);
        return -1;
    }

    // verifica se o codigo de apresentacao existe no banco de dados
    if (ret == nullptr)
    {
        std::cout << "Codigo de apresentacao inexistente!\n";
        setbuf(stdin, nullptr);
        getchar();
        sqlite3_finalize(database.stmt);
        return -1;
    }

    int retorno;
    std::stringstream ss1 ((const char*)ret);
    ss1 >> retorno;

    sqlite3_finalize(database.stmt);

    if (retorno < aquantidade)
    {
        std::cout << "Quantidade de ingressos desejada indisponivel ou codigo de apresentacao inexistente\n";
        setbuf(stdin, nullptr);
        getchar();
        return -1;
    }

    sql = "SELECT MAX(CodigoIngresso) FROM Ingresso" ;

    if (database.prepare_v2_database (database.db, (char*)sql.c_str(), -1, &database.stmt, NULL) != 0)
    {
        sqlite3_finalize(database.stmt);
        database.close_database(database.db);
        return -1;
    }

    // Le o maior codigo existente
    if ((database.rc = database.step_text_database(database.stmt, &ret)) == -1)
    {
        sqlite3_finalize(database.stmt);
        return database.rc;
    }

    const unsigned char* ret2 = ret;

    if (ret2 != nullptr)
    {
        std::stringstream ss6 ((const char*)ret2);
        ss6 >> retorno;
        retorno++;
    }
    else
    {
        retorno = 0;
    }

    sqlite3_finalize(database.stmt);

    CodigoIngresso acodigoingresso;
    acodigoingresso.setCodigo(retorno);

    std::stringstream ss3;
    ss3 << acodigoingresso.getCodigo();
    std::string codigoingresso = ss3.str ();

    std::stringstream ss4;
    ss4 << aquantidade;
    std::string quantidade = ss4.str ();

    sql = "INSERT INTO Ingresso (CPF, Apresentacao, CodigoIngresso, Quantidade) VALUES ('" + ausuario->getCPF() + "', " + codigoapresentacao + ", " + codigoingresso + ", " + quantidade + ");";

    database.rc = database.exec_database (database.db, (char*)sql.c_str(), database.callback, 0, &database.zErrMsg);

    sql = "SELECT CodigoIngresso FROM Ingresso WHERE Apresentacao = " + codigoapresentacao + ";";

    std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";

    database.exec_database (database.db, (char*)sql.c_str(), database.callback, (void*)"Callback function called", &database.zErrMsg);

    if (database.rc == 0)
    {
        std::cout << "Compra efetuada com sucesso!\n";
        setbuf(stdin, nullptr);
        getchar();
    }

    database.close_database(database.db);

    return database.rc;
}


