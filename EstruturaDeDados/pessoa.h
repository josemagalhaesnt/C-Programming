typedef struct pessoa Pessoa;

//criar agenda telefonica
Pessoa* criarAgenda();

//inserir Pessoa na agenda
Pessoa* cadastrarPessoa(Pessoa* p, char n[80], char t[20]);

//mostrar a lista
void mostrarAgenda(Pessoa* p);
