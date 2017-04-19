#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 4
typedef struct elementos {
    char nome[50];
} t_elemento;

typedef struct no {
    t_elemento dado;
    struct no * prox;
} t_no;

typedef struct fila {
    t_no* inicio;
    int quant_element;
    t_no* final;
} t_fila;

int isVazia (t_fila * fila)
{
    return (fila->quant_element == 0);
}


t_fila * criaCabeca(){
    t_fila * fila = (t_fila*) malloc(sizeof(t_fila));

    if (fila) {
        fila->inicio = fila->final = NULL;
        fila->quant_element=0;
    }

    return fila;
}

t_no * criaNo() {
    t_no * no = (t_no*) malloc(sizeof(t_no));

    // verifica se houve memoria suficiente para alocar
    if (no)
        no->prox = NULL;

    return no;
}
int inserir (t_fila *fila, t_elemento valor) {
    t_no *novo;
    novo = criaNo();
    if (novo == NULL)
        return 0; // Erro: memoria insuficiente
    novo->dado = valor;
    if (isVazia(fila))
        fila->inicio = novo;
    else
        (fila->final)->prox = novo;
    fila->final = novo;
    fila->quant_element++;
    return 1;
}

void entraPessoa(t_fila *fila){
	t_elemento dado;
	int i;
	
	for(i=0;i<4;i++){
		printf("Digite o nome:");
		scanf("%s", &dado.nome);
		inserir(fila, dado);
	}
}

void exibe(t_fila *fila){
	if(fila != NULL)
		printf ("%s\n", fila->inicio->dado.nome);
		printf ("%s\n", fila->inicio->prox->dado.nome);
		printf ("%s\n", fila->inicio->prox->prox->dado.nome);
		printf ("%s\n", fila->final->dado.nome);
}

int main(){
	t_fila f = *criaCabeca();
	int i;
	entraPessoa(&f);
	
	exibe(&f);
}
