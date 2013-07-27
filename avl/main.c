#include <stdio.h>
#include <stdlib.h>
#include "avl.h"

int main(void)
{
    AVL *a,*b;	    
	a = cria();
	b = cria();
    
    a = insere(a,4,"Jeff",3524,7);
	a = insere(a,2,"Tai",2000,13);
	a = insere(a,1,"Mateus",1300,9);
	a = insere(a,3,"Guilherme",2000,5);
	a = insere(a,5,"Gabriel",2000,3);
	a = insere(a,6,"Jesse",2000,4);		
	
	//a = limpeza(a);
	//alteraCH(a,4,2300);
	//alteraSemestre(a,2,12);

	printf("\nAlunos na Arvore: ");
	imprime(a);

	system("pause");
    return 0;
}
