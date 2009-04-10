#include "g3c_hooks.h"

typedef struct G3cCoreRegister
{
	G3cHookDescriptor*   hooks_registered;
	G3cHookDescriptor*   hooks_binded;
} G3cCoreRegister;


G3cCoreRegister*    __core_register__;

G3cBool     g3c_core_register_init();
void        g3c_core_register_destroy();
