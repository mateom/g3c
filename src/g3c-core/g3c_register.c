#include "g3c_register.h"


G3cBool  g3c_core_register_init()
{
	__core_register__ = (G3cCoreRegister*) malloc(sizeof(G3cCoreRegister));

	return __core_register__ == NULL ? g3c_false : g3c_true;
}

void  g3c_core_register_destroy()
{
	free(__core_register__);

	__core_register__ = NULL;

}

