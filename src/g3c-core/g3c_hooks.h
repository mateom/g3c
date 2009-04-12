#ifndef _G3C_HOOKS_H_
#define _G3C_HOOKS_H_

#include "g3c_btypes.h"

typedef int G3cHook;
typedef struct _G3cHookContext G3cHookContext;

typedef G3cBool (*G3cHookCallback)(G3cHook, G3cHookContext*,void*);

struct 
{
        G3cHookCallback   reply_to;
        //G3cQueue*         message_queue;
        void*             data_0;
        void*             data_1;
        void*             data_2;
        void*             data_3;
        void*             data_4;
        void*             data_5;
        void*             data_6;
        void*             data_7;
} _G3cHookContext;

typedef struct _G3cHookDescriptor {
	G3cHook            hook_id;
	G3cHookCallback    hook_callback;
	G3cHookOptions     hook_options;
} G3cHookDescriptor;


typedef enum G3cHookOptions
{
        G3C_HOOK_OPT_ONLYONE = 1 << 1,
        G3C_HOOK_OPT_NOWAIT  = 1 << 2, 
} G3cHookOptions;

/**
 * Listado con todos los hooks básicos a los que se pueden conectar los plugins
 * para proveer funcionalidad. Estos tipos son básicos y pueden ser extendidos
 * por los plugins. Estos plugins no proporcionan funcionalidad, deben de ser 
 * extendidos por los plugins para crear algún tipo de funcionalidad, sea la
 * UI, el protocolo, etc.
 */

typedef enum G3cCoreHook
{
        G3C_HOOK_INPKG,   /* Ha llegado un nuevo paquete a la interfaz de red. 
                           Este hook es útil para programar plugins para 
                           añadir un nuevo protocolo a G3C.  */

        G3C_HOOK_OUTPKG,   /* Mandar un paquete de datos por la interfaz de red.
                           A este hook solo se puede conectar el core de g3c,
                           sirve para indicarle que envíe los datos, es una
                           abstracción de la función send/sendto de la API
                           de sockets del SO sobre el que corra G3C */

        G3C_HOOK_OUTDAT,  /* Un nuevo paquete de datos va a salir a la interfaz 
                           de red. Los datos del paquete corresponden a una 
                           copia del fichero solicitado, debe ser un plugin
                           que implemente un protocolo el que fije la 
                           codificación adecuada para los datos.  */

        G3C_HOOK_START,   /* G3C va a comenzar a cargarse. Este hook es llamado
                           después de cargar todos los plugins. Los plugins que
                           necesiten una inicializacion deberán usar este hook
                           para inicializarse y los que se encarguen de la UI
                           deberán usar este hook para empezar a mostar la UI.
                           A partir de la invocación de este hook, G3C 
                           considerará a todos los plugins listos para trabajar
                           y empezarán a recibir llamadas. */

         G3C_HOOK_HALT,   /* G3C va a ser cerrado. Los plugins deberá cerrar
                           todos los descriptores de ficheros abiertos, sus
                           conexiones con el cliente, etc. La UI deberá dejar de
                           ser mostrada. */

         G3C_HOOK_MESSAGE,/* El core G3C desea mostrar un mensaje. Este hook
                           puede ser util para un plugin que guarde un log o
                           para mostrar notificaciones al usuario. Normalmente
                           este hook va a contener demasiada informacion para
                           el usuario, por lo que la mejor idea es redirigirlo
                           a la salida estándar (stdout) a través de printf o
                           a un fichero. */

         G3C_HOOK_WARN,   /* Igual a G3C_HOOK_MESSAGE pero muestra una 
                           advertencia al usuario. Puede ser buena idea
                           mostrarlo, ya que indica problemas en el
                           funcionamiento de G3C. */

         G3C_HOOK_ERROR   /* Igual a G3C_HOOK_ERROR pero muestra un error al
                           usuario. Este hook se debería de mapear a un plugin
                           UI para G3C ya que indica un error como que la red
                           no está disponible, un fallo interno, etc. */
} G3cCoreHook;

G3cBool      g3c_hook_register( G3cHook hook_id );

G3cBool      g3c_hook_bind( 
                            G3cHook         hook_id, 
                            G3cHookOptions  opts, 
                            G3cHookCallback callback
                          );

G3cBool      g3c_hook_send(
                            G3cHook          hook_id,
                            G3cHookContext*  hook_context
                          );

#endif
