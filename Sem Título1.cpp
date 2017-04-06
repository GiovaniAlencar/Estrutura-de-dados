#include <stdio.h>
#include <stdlib.h>

typedef struct elemento{
	char placa[24];
} t_elemento;

typedef struct pilha{
	t_elemento vetor[3];
	int topo;
}t_pilha;

int push(t_pilha * pilha, t_elemento valor){
	pilha->vetor[++pilha->topo] = valor;
		return 1;
}

entraCarros(t_pilha * plh){
	t_elemento dado;
	for(int i = 0; i<3; i++){
		printf("Placa: ");
		scanf("%d", &dado.placa);
	    push(plh, dado);
	}
}

int main(){
	t_pilha pilha;
	pilha.topo = -1;
	int i;
	
	entraCarros(&pilha);
	i = pilha.topo;
	printf("%s", pilha.vetor[i].placa);
}
