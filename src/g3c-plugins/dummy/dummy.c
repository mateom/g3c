#include "g3c_plugin.h"
#include "g3c_hooks.h"
#include "dummy.h"

G3cBool dummy_plugin_start(G3cHook hook,G3cHookContext* context, void* raw_data)
{
	printf("Esto empieza");
	return g3c_true;
}

G3cBool dummy_plugin_halt(G3cHook hook,G3cHookContext* context, void* raw_data)
{
	printf("Se acabo lo que se daba");
	return g3c_true;
}

G3C_PLUGIN_EXPORT_ALL(dummy);