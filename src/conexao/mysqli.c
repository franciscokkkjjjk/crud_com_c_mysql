#include <stdio.h>
#include <mariadb/mysql.h>

MYSQL* inicializar_conecao(void) {
    MYSQL* connect = mysql_init(NULL);
    if(connect == NULL) {
        printf("Erro ao inicializar no banco %s\n", mysql_error(connect));
        return NULL;
    }
    if(mysql_real_connect(connect, "127.0.0.1", "root", "", "crud_c", 0, NULL, 0) == NULL){
        printf("Erro ao conectar no banco de dados: %s\n", mysql_error(connect) );
        return NULL;
    }
    return connect;
}

void fechar_conexao(MYSQL* connect) {
    mysql_close(connect);
}