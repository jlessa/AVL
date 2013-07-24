#include <stdio.h>
#include <stdlib.h>
#include "avl.h"

int main(void)
{
    AVL *a,*b;
    a = cria();
	b = cria();
    a = insere(a,5);
    a = insere(a,7);	
    a = insere(a,4);	
	a = insere(a,8);
	b = busca(a,9);
	if(!vazia(b))
		printf("%d\n",b->matricula);
	else
		printf("erro");
	system("pause");

    return 0;
}
