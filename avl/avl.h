#include <stdio.h>
#include <stdlib.h>

typedef struct TAVL{
    int matricula;
    char nome[78];
    double cr;
    double cargaCursada;
    int nSemestre;
    int alt;
    struct TAVL *esq, *dir;
}AVL;

void alteraCR(AVL *a , double c);
void alteraSemestre(AVL *a ,int n);
void imprime(AVL* t,int m);

int calc_alt(AVL *t);
int maximo(int a,int b);
int vazia(AVL *t);

AVL* RSE (AVL *t);
AVL* RSD (AVL *t);
AVL* RDE (AVL* t);
AVL* RED (AVL* t);
AVL* insere(AVL *t,int m,char n[78],double c,double carga, int sem);

AVL* busca (AVL* t,int m);
AVL* destroi(AVL *t);
AVL* removeAluno(AVL* t,int m);
