#include "acutest.h"
#include "../src/dotGraph.h"

void test_createGraphInstance(void)
{
  dotGraph_handle_t graph;
  TEST_CHECK(graph.nodes != NULL);
  TEST_CHECK(graph.edges != NULL);
}

void test_initGraph(void)
{
  // set-up
  dotGraph_handle_t graph;
  
  // act
  bool result = dotGraph_initGraph( &graph);

  // validate
  TEST_CHECK(result);
  TEST_CHECK_(graph.iNode == 0, 
             "Unexpected node count = %d",
             graph.iNode);
  TEST_CHECK_(graph.iEdge == 0, 
             "Unexpected edge count = %d",
             graph.iNode);
}

void test_initGraph_allNodesUninitialized(void)
{
  // set-up
  dotGraph_handle_t graph;
  
  // act
  bool result = dotGraph_initGraph( &graph);
  bool nodeInitialized = false;

  for (int i = 0; i < MAX_NODES; i++)
  {
    nodeInitialized = nodeInitialized || graph.nodes[i].initialized;
  }

  // validate
  TEST_CHECK(!nodeInitialized);
}

void test_addNewNode(void)
{
  // set-up
  dotGraph_handle_t graph;
  dotGraph_node_t *pNode;
  int16_t id = 27;
  // act
  bool result = dotGraph_initGraph( &graph);
  result = result && dotGraph_initNode(&graph,
                                       &pNode, 
                                       id,
                                       NULL);

  // validate we have graph with 1 node and no edges
  TEST_CHECK(result);
  TEST_CHECK(pNode->id == id);
  TEST_CHECK(pNode->initialized);
  TEST_CHECK(graph.iEdge == 0);
  TEST_CHECK_(graph.iNode == 1, 
             "Unexpected node count = %d",
             graph.iNode);
}


TEST_LIST = {
   { "create dotGraph instance", test_createGraphInstance},
   { "initialize dotGraph", test_initGraph},
   { "nodes shall be un-initialized after initGraph", test_initGraph_allNodesUninitialized},
   { "add new node", test_addNewNode}
};