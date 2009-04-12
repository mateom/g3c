#include <stdlib.h>
#include "g3c_lib.h"

void __g3c_list_new__(G3cListInternals** li, void** l)
{
	*li = (G3cListInternals*) malloc(sizeof(G3cListInternals)+4);
	*l  = *li + sizeof(G3cListInternals);

	(*li)->number_of_elements = 0;
	(*li)->size_of_element    = 0;
}

G3cBool __g3c_list_init__(G3cListInternals** li, 
			void** l,
			unsigned int number_of_elements,
			unsigned int size_of_element)
{
	if( (*li)->number_of_elements != 0 )
	{
		
		free(*li);
		__g3c_list_new__(li,l);
	}

	(*li)->number_of_elements = number_of_elements;
	(*li)->size_of_element    = size_of_element;

	return __g3c_list_alloc__(li,l);
}

G3cBool __g3c_list_alloc__(G3cListInternals** li, void** l)
{
	G3cListInternals* list;

	list = (G3cListInternals*) realloc(*li, 
		((*li)->number_of_elements+1)*((*li)->size_of_element)+GLS);

	if( list == NULL )
	{
		return g3c_false;
	}

	*li = list;
	*l  = list + GLS;

	return g3c_true;
}

	
