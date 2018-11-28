#include "app.h"

typedef struct node 
{
  uint8_t value;
  struct node *next;
} linkedListNode_t;

linkedListNode_t* getNode(void);