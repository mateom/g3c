#include <stdlib.h>

typedef struct _G3cListInternals
{
	unsigned int      number_of_elements;
	unsigned int      size_of_element;
} G3cListInternals;

#define g3c_declare_list(t,n)           \
	G3cListInternals*     __##n##__; \
	t*                    n

#define GLS sizeof(G3cListInternals)

void __g3c_list_new__(G3cListInternals**,void**);
#define g3c_list_new(n) __g3c_list_new__(&__##n##__,(void**)&n)

G3cBool __g3c_list_init__(G3cListInternals**,void**, 
				unsigned int, unsigned int);
#define g3c_list_init(l,n,s) __g3c_list_init__(&__##l##__,(void**)&l,n,s)

G3cBool __g3c_list_alloc__(G3cListInternals**, void**);
#define g3c_list_alloc(l) __g3c_list_alloc__(&__##l##__,(void**)&l)

#define g3c_list_set_size(l,s) __##l##__->number_of_elements = s
#define g3c_list_get_size(l) __##l##__->number_of_elements
#define g3c_list_destroy(l) free(__##l##__)
