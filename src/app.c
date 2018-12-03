
#include "app.h"
#include "dotGraph.h"

// public 
int runApp(void)
{
  //instansiate graph handle
  dotGraph_handle_t graph;


  dotGraph_node_t *currentNode;

  bool success = true;

  success = success && 
            dotGraph_initGraph(&graph);

  for (uint16_t i = 0; i < 2; i++)
  {
    uint8_t id = i+10;

    dotGraph_nodeAttributes_t attributes;
    sprintf(attributes.label, "id:%d", id);
    attributes.shape = DOT_GRAPH_NODE_PENTAGON;
    attributes.color = i<7 ? i+1 : 7;

    // can add node custom attribute
    sprintf(attributes.customAttibutes, "ca=\"cv-%d\"", id);

    

    // well return existing node with ID or create new one
    success = success &&
              dotGraph_initNode(&graph,
                                &currentNode, 
                                i+10,
                                &attributes);
  }
  
  printf("******************************************\n");
  printf("Can get existing node by ID.\n");
  // get node by id

  uint8_t nodeNum1 = graph.iNode;

  success = success && dotGraph_initNode(&graph,
                    &currentNode, 
                    10,
                    NULL);

  uint8_t nodeNum2 = graph.iNode;

  if (success && nodeNum2 == nodeNum1)
  {
   printf("SUCCESS. \n");
  }
  else
  {
    printf("FAIL. \n");
  }
  printf("\n");


  printf("******************************************\n");
  printf("print graph.\n");
  printf("\n");
  success = success &&
            dotGraph_writeToLogs(&graph);
  printf("\n");

  return 0;
}