
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
    sprintf(attributes.customAttibutes, "ca=\"cv-%d\"", id);

    success = success &&
              dotGraph_getNewNodeInstance( &graph, &currentNode);
    

    success = success &&
              dotGraph_initNode(currentNode, 
                                i+10,
                                &attributes);
  }

  success = success &&
            dotGraph_writeToLogs(&graph);

  return 0;
}