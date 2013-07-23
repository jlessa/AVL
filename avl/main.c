#include <stdio.h>
#include <stdlib.h>
#include "avl.h"

int main(void)
{
    AVL *a;
    a = cria();
    a = insere(a,5);
    a = insere(a,7);
    a = insere(a,3);
    a = insere(a,8);
    a = insere(a,9);
    a = insere(a,15);
    a = insere(a,2);
    a = insere(a,1);
    imprime(a);
    return 0;
}
