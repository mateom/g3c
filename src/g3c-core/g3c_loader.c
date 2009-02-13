#include "g3c_btypes.h"
#include "g3c_hook.h"
#include <stdio.h>

G3cBool g3c_core_basic_hook_message( G3cHook          hook_id,
                                     G3cHookContext*  context,
                                     void*            message )
{
	G3cCoreHook  id = hook_id;
        char*        cadena;

        if( id != G3C_HOOK_MESSAGE )
                return g3c_false;

	cadena = (char*) message;

        printf("%s\n",cadena);

        return g3c_true;	
}

G3cBool g3c_core_loader_start()
{
       G3cCoreHook message = G3C_HOOK_MESSAGE;

       g3c_hook_register(message,"G3cCoreHookMessage");

       if( g3c_hook_bind(message, 0, g3c_basic_core_hook_message) != g3c_true )
       {
              printf("g3c_hook_bind failed: Unable to bind basic hooks.\n");
              return g3c_false;
       }

       return g3c_true;
}
