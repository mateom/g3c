#include "g3c_btypes.h"
#include "g3c_hooks.h"
#include "g3c_plugin.h"
#include "g3c_dlopen.h"
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


G3cBool g3c_core_loader_bind_all_hooks(G3cPluginHookList *first)
{
        G3cPluginHookList*   current;

        current = first;

        while( current->hook_id != 0 && current->callback != NULL )
        {
                if( g3c_hook_bind(current->hook_id,
                                        0,
                                        current->callback) == g3c_false )
                {
                        /* Si no se ha podido hacer bind al hook, posiblemente
                           sea porque el hook no existe (El plugin está 
                           tratando de hacer bind a un hook que no es del core).
                           Por ello, registramos ese hook. Se al intentar volver
                           a hacer bind, fallamos, implica que el hook está 
                           bloqueado, que el dispositivo se ha quedado sin 
                           memoria, etc. por lo que debemos detener la carga de
                           ese plugin. */

                        g3c_hook_register(current->hook_id);
                        if( g3c_hook_bind(current->hook_id,
                                                0,
                                                current->callback) == g3c_false)
                        {
                                return g3c_false;
                        }

                }
        }

        return g3c_true;
}


G3cPluginInfo* g3c_core_loader_load_plugin(char* plugin_name)
{
        G3cLib                   plugin_handle;
        G3cPluginInfoCallback    callback;
        G3cPluginInfo            info;

        plugin_handle = g3c_core_dlopen(plugin_name);

        callback = g3c_core_dlsym(plugin_handle,
                        "g3c_plugin_get_info",
                        G3cPluginInfoCallback);

        callback(&info);
        
        g3c_core_loader_bind_all_hooks(info.plugin_hooks);

        return &info;
}



G3cBool g3c_core_loader_start()
{
       G3cCoreHook       message = G3C_HOOK_MESSAGE;
       G3cHookContext    context;
       G3cBool           ret_value;

       context.data_0 = (void*) &ret_value;
       

       g3c_hook_register(message,"G3cCoreHookMessage");

       if( g3c_hook_bind(message, 0, g3c_basic_core_hook_message) != g3c_true )
       {
              printf("g3c_hook_bind failed: Unable to bind basic hooks.\n");
              return g3c_false;
       }

       g3c_core_plugin_register(g3c_core_loader_load_plugin(p_name));

       g3c_hoook_send(G3C_HOOK_START,&context);

       return ret_value;
}
