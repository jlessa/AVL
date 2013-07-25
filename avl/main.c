#include <stdio.h>
#include <stdlib.h>
#include "avl.h"

int main(void)
{
    AVL *a,*b;
    a = cria();
	b = cria();



	a = insere(a,4);
	a = insere(a,8);
	a = insere(a,9);
	a = retira(a,5);
	a = retira(a,4);	
	a = retira(a,9);
	a = insere(a,7);
	a = insere(a,12);
	a = insere(a,66);
	a = insere(a,43);
	a = insere(a,22);
	a = insere(a,65);
	a = insere(a,3);
	a = insere(a,1);
	imprime(a);

	system("pause");
    return 0;
}
