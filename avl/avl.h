#include <stdio.h>
#include <stdlib.h>
#include "string.h"

#define CARGA_MAX 3524.00;

typedef struct TAVL{
    int matricula;
    char nome[50];
    float cr;
    float cargaCursada;
    int nSemestre;
    int alt;
    struct TAVL *esq, *dir;
}AVL;



void alteraCR(AVL *a , double c);
void alteraSemestre(AVL *a ,int n);
void imprime(AVL* t);


int calc_alt(AVL *t);
int maximo(int a,int b);
int vazia(AVL *t);
int fb(AVL* t);


AVL* RSE (AVL *t);
AVL* RSD (AVL *t);
AVL* RDE (AVL* t);
AVL* RED (AVL* t);
AVL* insere(AVL *t, int mat , char nome[] , float c , float carga , int sem);
AVL* limpeza(AVL *t);

AVL* cria();
AVL* destroi(AVL *t);
AVL* retira(AVL* t,int m);
AVL* busca(AVL *t, int m);
