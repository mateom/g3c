typedef struct G3cPluginHookList
{
	int              hook_id;
	G3cHookCallback  callback;
} G3cPluginHookList;

/**
 * Las macros que van a continuacion sirven para exportar los hooks en
 * los que está interesado el plugin. Estos hooks serán conectados 
 * automaticamente cuando el plugin sea cargado.
 *
 * Ejemplo de uso de las macros:
 *
 * G3C_PLUGIN_EXPORT_HOOKS_BEGIN(foo)
 *		G3C_EXPORT_HOOK(G3C_HOOK_INPKG,dummy_callback)
 *      // No olvides nunca el siguiente hook si el plugin tiene que
 *      // inicializar alguno de sus valores 
 *		G3C_EXPORT_HOOK(G3C_HOOK_START,foo_g3c_start) 
 * G3C_PLUGIN_EXPORT_HOOKS_END(foo)
 *
 * ATENCION: Las macros no llevan ningun signo de puntacion al terminar 
 * la linea. El signo de puntacion es puesto automáticamente en la 
 * expansión de la macro. 
 */

#define G3C_PLUGIN_EXPORT_HOOKS_BEGIN(p_name) \
G3cPluginHookList   p_name##_hook_list[] {

#define G3C_EXPORT_HOOK(id,callback) {id, callback},

#define G3C_PLUGIN_EXPORT_HOOKS_END(p_name) {0,NULL}};

#define G3C_PLUGIN_HOOKSLIST_P(p_name)  p_name##_hook_list

typedef struct G3cPluginInfo
{
	char*                plugin_name;
	char*                plugin_authors;
	char*                plugin_license;
	G3cPluginHookList*   plugin_hooks;
} G3cPluginInfo;

#define G3C_PLUGIN_EXPORT_INFO_INIT(p_name) \
G3cPluginInfo   p_name##_info

#define G3C_PLUGIN_EXPORT_INFO(p_name,key,value) \
p_name##_info.##key = value
