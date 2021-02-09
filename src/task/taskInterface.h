#include <stdio.h>
#include <stdint.h>

typedef   void (*execute_fn_t)(void *context);

typedef struct taskInterface_s
{
    void *context;
    execute_fn_t execute_fn;
} taskInterface_t;

void taskInterface_execute ( taskInterface_t* interface);

typedef struct taskInstance_s
{
    uint8_t result;
} taskInstance_t;

void taskInstance_getInterface( void* instance, taskInterface_t* interface);

