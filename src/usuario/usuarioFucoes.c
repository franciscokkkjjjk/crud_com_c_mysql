#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mariadb/mysql.h>

void cadastrarUsuario(MYSQL* connect, const char* nome, int idade) {
    char query[1024];
    sprintf(query, "INSERT INTO usuarios(nome, idade) VALUES ('%s', %d)", nome, idade);
    if(mysql_query(connect, query)) {
        printf("Erro ao cadastrar usuário: %s\n", mysql_error(connect));
        return;
    }
}

void mostrarUsuario(MYSQL* connect, int id) {
    char query[1024];
    sprintf(query, "SELECT * FROM usuarios WHERE id=%d", id);
    if(mysql_query(connect, query)) {
        printf("Erro ao procurar usuário: %s\n", mysql_error(connect));
        return;
    }
    MYSQL_RES* resultado = mysql_store_result(connect);
    if(resultado == NULL) {
        printf("Erro ao armazenar resultado: %s\n", mysql_error(connect));
        return ;
    }
    MYSQL_ROW linha = mysql_fetch_row(resultado);
    if(linha == NULL) {
        printf("Pessoa não encotrada.\n");
        return;
    }
    printf("ID: %s\n", linha[0]);
    printf("NOME: %s\n", linha[1]);
    printf("IDADE: %s\n", linha[2]);

    mysql_free_result(resultado);
}

void excluirUsuario(MYSQL* connect, int id) {
   char query[1024];

   sprintf(query, "DELETE FROM usuarios WHERE id=%d", id);

   if(mysql_query(connect, query)) {
    printf("Erro ao deletar o usuario: %s\n", mysql_error(connect));
    
   }
}


void editarUsuario(MYSQL* connect, const char* nome, int idade, int id) {
    char query[2048];

    sprintf(query, "UPDATE usuarios SET nome='%s', idade=%d WHERE id=%d", nome, idade, id);

    if(mysql_query(connect, query)) {
        printf("Não foi possivel editar o usuario: %s\n", mysql_error(connect));
        return;
    }
}

void mostrarTodosUsuarios(MYSQL* connect, int numeroDaPagina) {
    const int limiteDoSalto = 2;
    int numeroDeSaltos = numeroDaPagina*limiteDoSalto;
    char query[1024];
        sprintf(query, "SELECT * FROM usuarios LIMIT %d OFFSET %d", limiteDoSalto, numeroDeSaltos);
        
          if(mysql_query(connect, query)){ 
            printf("Não foi possivel puxar a lista de usuarios: %s\n", mysql_error(connect));
            return;
        }

        MYSQL_RES* result = mysql_store_result(connect);

        if(result == NULL) {
            printf("Erro ao armazenar resultado: %s\n", mysql_error(connect));
            return;
        }

        MYSQL_ROW linha;
        while((linha = mysql_fetch_row(result)) != NULL) {        
            printf("ID: %s\n", linha[0]);
            printf("NOME: %s\n", linha[1]);
            printf("IDADE: %s\n", linha[2]);
        }
        mysql_free_result(result);
    return;
}
