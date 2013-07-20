#include "avl.h"


int maximo(int a, int b){
    if(a>b) return a;
    return b;
};

int calc_alt(AVL *t){
    if(!t) return -1;
    return t->alt;
};

int vazia(AVL *t){
    return t==NULL;
}

void imprime(AVL *t){
    if(vazia(t)) printf("<>");
    else
}

AVL* RSE(AVL *t){
    AVL *novo =t->dir;
    t->dir = novo->esq;
    novo->esq = t;
    t->alt = 1 + maximo(calc_alt(novo->esq),calc_alt(novo->dir));
    novo->alt = maximo(calc_alt(novo->dir),t->alt)+1;
    return novo;
};

AVL* RSD(AVL *t){
    AVL *novo =t->esq;
    t->esq = novo->dir;
    novo->dir = t;
    t->alt = 1 + maximo(calc_alt(novo->esq),calc_alt(novo->dir));
    novo->alt = maximo(calc_alt(novo->esq),t->alt)+1;
    return novo;
};

AVL* RDE(AVL* t){
     t->dir = RSD(t->dir);
     t = RSE(t);
     return t;
};

AVL* RED(AVL* t){
     t->esq = RSD(t->esq);
     t = RSD(t);
     return t;
};
