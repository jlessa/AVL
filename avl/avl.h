#include <stdio.h>
#include <stdlib.h>
#include "string.h"

#define CARGA_MAX 3524.00;
#define NUM_SEM_MAX 12;

typedef struct TAVL{
    int matricula;
    char nome[50];    
    float cargaCursada;
    int nSemestre;
    int alt;
    struct TAVL *esq, *dir;
}AVL;



void alteraCH(AVL *a , int m , float c);
void alteraSemestre(AVL *a , int m, int sem);
void imprime(AVL* t);


int calc_alt(AVL *t);
int maximo(int a,int b);
int vazia(AVL *t);
int fb(AVL* t);


AVL* RSE (AVL *t);
AVL* RSD (AVL *t);
AVL* RDE (AVL* t);
AVL* RED (AVL* t);
AVL* insere(AVL *t, int mat , char nome[] , float carga , int sem);
AVL* limpeza(AVL *t);

AVL* cria();
AVL* destroi(AVL *t);
AVL* retira(AVL* t,int m);
AVL* busca(AVL *t, int m);
