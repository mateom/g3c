#include "g3c_plugins.h"

G3cCoreHooks interested[] = {G3C_HOOK_START,G3C_HOOK_HALT};

G3C_PLUGIN_EXPORT_HOOKS_BEGIN(dummy)
	G3C_EXPORT_HOOK(interested[0],dummy_plugin_start)
	G3C_EXPORT_HOOK(interested[1],dummy_plugin_halt)
G3C_PLUGIN_EXPORT_HOOKS_END(dummy)

G3C_PLUGIN_EXPORT_INFO_INIT(dummy);
G3C_PLUGIN_EXPORT_INFO(dummy,plugin_name,"Dummy plugin");
G3C_PLUGIN_EXPORT_INFO(dummy,plugin_authors,"Mateo Matachana\nAndres Alonso");
G3C_PLUGIN_EXPORT_INFO(dummy,plugin_license,"Licencia para probar");
G3C_PLUGIN_EXPORT_INFO(dummy,plugin_hooks,G3C_PLUGIN_HOOKSLIST(dummy));

