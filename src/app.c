
#include "app.h"
#include "dotGraph.h"

// public 
int runApp(void)
{
  //instansiate graph handle
  dotGraph_handle_t graph;
  dotGraph_node_t nodes[2];
  dotGraph_edge_t edges[2];

  dotGraph_node_t *currentNode;

  bool success = true;

  success = success && 
            dotGraph_initGraph(&graph, nodes, 2, edges, 2);

  for (uint16_t i = 0; i < graph.numNodes; i++)
  {
    success = success &&
              dotGraph_getNewNodeInstance( &graph, &currentNode);
    
    uint16_t id = i+10;
    char attr[20];
    sprintf(attr, "[label=\"%d\"]", id);

    success = success &&
              dotGraph_initNode(currentNode, 
                                id);
  }

  success = success &&
            dotGraph_writeToLogs(&graph);

  return 0;
}