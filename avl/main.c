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
	a = insere(a,9);
	a = retira(a,5);
	//a = retira(a,4);
	imprimeSemVazios(a);
	printf("\n");
	imprimeComVazios(a);

	system("pause");

    return 0;
}
