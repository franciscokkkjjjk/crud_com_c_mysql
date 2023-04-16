void excluirUsuario(MYSQL* connect, int id);

void cadastrarUsuario(MYSQL* connect, const char* nome, int idade);

void mostrarUsuario(MYSQL* connect, int id);

void editarUsuario(MYSQL* connect, const char* nome, int idade, int id);

void mostrarTodosUsuarios(MYSQL* connect, int numeroDaPagina);

int procurarUsuario(MYSQL* connect, int id);