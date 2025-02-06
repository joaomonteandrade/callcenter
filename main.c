#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>

struct Chamada {
	char tel[9];
	time_t entrada;
	double espera;
};

struct Fila {
    int quantAguard;
    int quantFeita;
    struct Chamada aguard[255];
    struct Chamada feita[255];
};

struct Fila createFila();
void addChamada(struct Fila *fila);
void finalizaChamada(struct Fila *fila);

//m�todo para inicializar uma fila
struct Fila createFila(){
    struct Fila fila;
    fila.quantAguard = 0;
    fila.quantFeita = 0;
    return fila;
}

void addChamada(struct Fila *fila){
    struct Chamada chamada; //cria uma chamada

    srand(time(NULL)+fila->quantAguard); //coloca a seed da randomiza��o
    for(int i = 0; i < 8; i++)chamada.tel[i] = (rand() % 10) + '0'; //cria um telefone aleat�rio
    time(&chamada.entrada); //armazena o hor�rio que a chamada foi adicionada

    fila->aguard[fila->quantAguard] = chamada; //coloca a chamda no �ltimo lugar da lista
    fila->quantAguard++; //atualiza a quantidade de pessoas aguardando
    printf("foi a adicionado � lista de espera o cliente n�mero %d, telefone +55 (69)9%s\n", fila->quantAguard, fila->aguard[fila->quantAguard-1].tel);

}

void finalizaChamada(struct Fila *fila){
    if(fila->quantAguard < 1){printf("N�o H� nenhuma chamada para ser finalizada"); return;}
    fila->feita[fila->quantFeita] = fila->aguard[0]; //coloca a primeira pessoa da fila na lista de atendidas
    fila->feita[fila->quantFeita].espera = difftime(time(NULL), fila->feita[fila->quantFeita].entrada); //armazena o hor�rio que a chamada foi finalizada
    fila->quantFeita++; //atualiza a quantidade de pessoas que foram atendidas

    //o segundo vira o primeiro, o terceiro vira o segundo e assim por diante
    for(int i = 0; i < fila->quantAguard; i++) fila->aguard[i] = fila->aguard[i+1];

    fila->quantAguard--; //tem menos pessoas aguardando agora
    printf("A chamada referente ao telefone +55 (69)9%s foi finalizada ap�s aguardar %.2f segundos\n", fila->feita[fila->quantFeita-1].tel, fila->feita[fila->quantFeita-1].espera);
};

double esperaMedia(struct Fila *fila){
    if(fila->quantFeita < 1){
        printf("Ningu�m foi atendido ainda");
        return 0;
    }
    double total;
    for(int i = 0; i < fila->quantFeita; i++){
        total += fila->feita[i].espera;
    }
    return total/fila->quantFeita;
}

void printTable(struct Fila *fila){
    printf("\nChamadas na fila de espera: \n");
    for(int i = 0; i < fila->quantAguard; i++){
        printf("n %d - telefone: +55 (69)9%s, entrada: %s", i+1, fila->aguard[i].tel, ctime(&fila->aguard[i].entrada));
    }
    printf("Chamadas finalizadas: \n");
    for(int i = 0; i < fila->quantFeita; i++){
        printf("n %d - telefone: +55 (69)9%s, entrada: %s, espera: %f\n", i+1, fila->feita[i].tel, ctime(&fila->feita[i].entrada), fila->feita[i].espera);
    }
    printf("\n");
};

int main()
{

    struct Fila fila = createFila();
	addChamada(&fila);
	addChamada(&fila);
	addChamada(&fila);
	addChamada(&fila);
	addChamada(&fila);

	sleep(1);
	finalizaChamada(&fila);
	sleep(1);
	finalizaChamada(&fila);

	printTable(&fila);

	printf("Tempo m�dio de espera: %.2f segundos", esperaMedia(&fila));

	return 0;
}
