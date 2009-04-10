#include "g3c_btypes.h"

#include "g3c_register.h"

int main(int argc, char* argv[])
{
	/* Antes de actuar, creamos el registro de la aplicación */

	if( g3c_core_register_init() != g3c_true )
	{
		printf("NO SE HA PODIDO INICIALIZAR EL REGISTRO:\n"
				"No se ha podido asignar memoria suficiente "
				"para el registro.\n"
				"Abortando!!!!");
		exit(-1);
	}


	g3c_core_register_destroy();
}
