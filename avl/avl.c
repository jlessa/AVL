#include "avl.h"

int vazia(AVL *t){
    return t == NULL;
};

void imprime(AVL *t){
	if(vazia(t))
        printf("<>");
    else
        if(vazia(t->esq) && (vazia(t->dir)))
            printf("<%d>",t->matricula);
        else{
            printf("<%d>",t->matricula);
			if(t->esq)
				imprime(t->esq);
			if(t->dir)
				imprime(t->dir);

        }
};

AVL* cria(){
    return NULL;
};

AVL* RSE(AVL *t){
    AVL *novo = t->dir;
    t->dir = novo->esq;
    novo->esq = t;
    t->alt = 1 + maximo(calc_alt(t->esq),calc_alt(t->dir));
    novo->alt = maximo(calc_alt(novo->dir),t->alt)+1;
    return novo;
};

AVL* RSD(AVL *t){
    AVL *novo =t->esq;
    t->esq = novo->dir;
    novo->dir = t;
    t->alt = 1 + maximo(calc_alt(t->esq),calc_alt(t->dir));
    novo->alt = maximo(calc_alt(novo->esq),t->alt)+1;
    return novo;
};

AVL* RDE(AVL* t){
     t->dir = RSD(t->dir);
     t = RSE(t);
     return t;
};

AVL* RED(AVL* t){
     t->esq = RSE(t->esq);
     t = RSD(t);
     return t;
};

int maximo(int a, int b){
    if(a>b) return a;
    return b;
};

int calc_alt(AVL *t){
    if(!t) return -1;
    return t->alt;
};

AVL* insere(AVL *t, int mat){
    if(!t){
        t = (AVL*) malloc((sizeof(AVL)));
        t->matricula = mat;
        /*
        colocar os scanners aqui para preencher as outras informações
        */

        t->alt = 0;
        t->esq = NULL;
		t->dir = NULL;
    }
    else
        if(mat < t->matricula){
            t->esq = insere(t->esq,mat);
            if((calc_alt(t->esq) - calc_alt((t->dir))) == 2)
                if(mat < t->esq->matricula)
                    t = RSD(t);
                else
                    t = RED(t);
        }
        else
            if(mat > t->matricula){
                t->dir = insere(t->dir,mat);
                if((calc_alt(t->dir) - calc_alt((t->esq))) == 2)
                    if(mat > t->dir->matricula)
                        t = RSE(t);
                    else
                        t = RDE(t);
            }
         t ->alt = maximo(calc_alt(t->esq),calc_alt(t->dir)) + 1;
         return t;
};

AVL* busca(AVL *t , int m){	
	if(vazia(t))
		return NULL;
	if(t->matricula == m)
		return t;
	if(m < t->matricula)
		busca(t->esq,m);
	else
		busca(t->dir,m);
};

int fb(AVL* t){    
	int left,right;		
	if(!t)
		return 0;	    
    if(!(t->esq))
        left = 0;
    else
        left = 1 + (t->esq->alt);
    if(!(t->dir))
        right = 0;
    else
        right = 1 + (t->dir->alt);
    return (left - right);
}

AVL* retira(AVL *t,int m){
    if(!t)
        return t;
    if(m > t->matricula){
        t->dir = retira(t->dir,m);
        if(fb(t) == 2)
            if(fb(t->esq) >= 0)
                t = RSD(t);
            else
                t = RSE(t);
    }
    else
        if(m < t->matricula){
            t->esq = retira(t->esq,m);
            if(fb(t) == -2)
                if(fb(t->dir) <= 0)
                    t = RSE(t);
                else
                    t = RDE(t);
        }
    else{
        if(t->dir){
            AVL *p = t->dir;
            while(p->esq)
                p = p->esq;
            t->matricula = p->matricula;
            p->matricula = m;
            t->dir = retira(t->dir,m);
            if(fb(t) == 2)
                if(fb(t->esq) >= 0)
                    t = RSD(t);
                else
                    t = RED(t);
        }
        else{
            AVL *q = t;
            t = t->esq;			
            free(q);
            return t;
        }
        if(t){
            int lh,rh;
            if(!t->esq)
                lh = 0;
            else
                lh = 1 + t->esq->alt;
            if(!t->dir)
                rh = 0;
            else
                rh = 1 + t->dir->alt;
            if(lh > rh)
                t->alt = lh;
            else
                t->alt = rh;
        }        
    }
	return t;
};
