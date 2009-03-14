#include "g3c_plugin.h"
#include "g3c_hooks.h"
#include "dummy.h"

#include <stdio.h>

G3cCoreHook interested[] = {G3C_HOOK_START,G3C_HOOK_HALT};

G3cPluginHookList dummy_hook_list[] = {
	G3C_EXPORT_HOOK(G3C_HOOK_START,dummy_plugin_start)
	G3C_EXPORT_HOOK(G3C_HOOK_HALT,dummy_plugin_halt)
        {0, NULL}
};


G3C_PLUGIN_EXPORT_INFO_BEGIN(dummy)
        G3C_PLUGIN_EXPORT_INFO(name,"Dummy plugin")
        G3C_PLUGIN_EXPORT_INFO(authors,"Mateo Matachana\nAndres Alonso")
        G3C_PLUGIN_EXPORT_INFO(license,"Licencia para probar")
        G3C_PLUGIN_EXPORT_INFO(hooks,G3C_PLUGIN_HOOKSLIST_P(dummy))
G3C_PLUGIN_EXPORT_INFO_END(dummy);

G3cBool dummy_plugin_start(G3cHook hook,
                G3cHookContext* context,
                void* raw_data)
{
	printf("Esto empieza");
	return g3c_true;
}

G3cBool dummy_plugin_halt(G3cHook hook,
                G3cHookContext* context, 
                void* raw_data)
{
	printf("Se acabo lo que se daba");
	return g3c_true;
}

G3C_PLUGIN_EXPORT_ALL(dummy);
