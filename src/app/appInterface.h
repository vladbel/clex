#include <stdio.h>
#include <stdint.h>

typedef   void (*execute_fn_t)(void *context);

typedef struct appInterface_s
{
    void *context;
    execute_fn_t execute_fn;
} appInterface_t;
void appInterface_execute ( appInterface_t* interface);

typedef struct appInstance_s
{
    uint8_t result;
} appInstance_t;
void appInstance_getInterface( void* instance, appInterface_t* interface);

