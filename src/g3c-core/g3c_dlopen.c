#include "g3c_dlopen.h"
#include <dlfcn.h>

G3cLib  g3c_core_dlopen(char* libName)
{
        return dlopen(libName, RTLD_LAZY);
}

void* _g3c_core_dlsym_(G3cLib libHandle, char* symname)
{
        return dlsym(libHandle,symname);
}

void g3c_core_dlclose(G3cLib libHandle)
{
        dlclose(libHandle);
}

