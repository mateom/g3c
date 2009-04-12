#include <stdio.h>
#include <g3c_lib.h>

int main(int argc, char** argv)
{
	int i;
	
	/* Declaramos la lista. Esto va a crear una variable de tipo lista
	   de enteros y de nombre "list" */

	g3c_declare_list(int,list);

	/* Preparamos los campos internos de la lista */
	g3c_list_new(list);
	
	/* Creamos espacio para 10 elementos en esa lista. El tamaños de cada 
	   elemento será el de un entero, dado que es una lista de enteros.
	   */

	g3c_list_init(list,10,sizeof(int));


	/* Asginamos valores a la lista */

	for(i = 0; i < 10; i++)
	{
		list[i] = i;
	}

	/* Mostramos los valores de la lista */

	for(i = 0; i < 10; i++)
	{
		printf("list[%d] = %d\n",i,list[i]);
	}

	/* Liberamos los recursos utilizados por la lista */

	g3c_list_destroy(list);

	return 0;
}
