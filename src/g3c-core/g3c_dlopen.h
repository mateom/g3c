#ifndef _G3C_DLOPEN_
#define _G3C_DLOPEN_

typedef void* G3cLib;


G3cLib         g3c_core_dlopen(char*);
void*          _g3c_core_dlsym_(G3cLib,char*);
#define        g3c_core_dlsym(lib,chr,ret) \
        ((ret*) _g3c_core_dlsym_(lib,chr)
void           g3c_core_dlclose(G3cLib);

#endif /* _G3C_DLOPEN_ */
