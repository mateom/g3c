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


	/* Asignamos valores a la lista */

	for(i = 0; i < 10; i++)
	{
		list[i] = i;
	}

	/* Mostramos los valores de la lista */

	for(i = 0; i < 10; i++)
	{
		printf("list[%d] = %d\n",i,list[i]);
	}
#if 0
	/* TODO Investigar porque hace fallar al destroy esto */
	/* Cambiamos el tamaño de la lista a 20 elementos */

	g3c_list_set_size(list, 20);

	/* Y nos aseguramos de que se le reserve memoria */
	g3c_list_alloc(list);

	/* Asignamos algunos valores: */

	for( i = 0;i < 20;i++)
	{
		if( (i % 2) == 0 )
		{
			list[i] = 2^(i/2);
		} else
		{
			list[i] = -2^(i/2);
		}
	}

	printf("Lista de 20 elementos:\n\n");

	/* Y los imprimimos */

	for( i = 0;i < 20;i++)
	{
		printf("list[%d] = %d\n",i,list[i]);
	}
#endif
	/* Liberamos los recursos utilizados por la lista */

	g3c_list_destroy(list);

	return 0;
}
