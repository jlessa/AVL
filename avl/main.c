#include <stdio.h>
#include <stdlib.h>
#include "avl.h"

int main(void)
{
    AVL *a;
    a = cria();
    a = insere(a,5);
    a = insere(a,7);	
    imprimeSemVazios(a);
	system("pause");

    return 0;
}
