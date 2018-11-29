/* Copyright (c) 2018 SmartThings. All Rights Reserved. */
#ifndef HUBCORE_DOTGRAPH_H
#define HUBCORE_DOTGRAPH_H

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

typedef enum {
  DOT_GRAPH_NODE_BOX,
  DOT_GRAPH_NODE_POLYGON,
  DOT_GRAPH_NODE_ELLIPSE,
  DOT_GRAPH_NODE_OVAL,
  DOT_GRAPH_NODE_CIRCLE,
  DOT_GRAPH_NODE_POINT,
  DOT_GRAPH_NODE_EGG,
  DOT_GRAPH_NODE_TRIANGLE,
  DOT_GRAPH_NODE_PLAINTEXT,
  DOT_GRAPH_NODE_PLAIN,
  DOT_GRAPH_NODE_DIAMOND,
  DOT_GRAPH_NODE_TRAPEZIUM,
  DOT_GRAPH_NODE_PARALLELOGRAM,
  DOT_GRAPH_NODE_HOUSE,
  DOT_GRAPH_NODE_PENTAGON,
  DOT_GRAPH_NODE_HEXAGON,
  DOT_GRAPH_NODE_SEPTAGON,
  DOT_GRAPH_NODE_OCTAGON,
  DOT_GRAPH_NODE_DOUBLECIRCLE,
  DOT_GRAPH_NODE_DOUBLEOCTAGON,
  DOT_GRAPH_NODE_TRIPLEOCTAGON,
  DOT_GRAPH_NODE_INVTRIANGLE,
  DOT_GRAPH_NODE_INVTRAPEZIUM,
  DOT_GRAPH_NODE_INVHOUSE,
  DOT_GRAPH_NODE_MDIAMOND,
  DOT_GRAPH_NODE_MSQUARE,
  DOT_GRAPH_NODE_MCIRCLE,
  DOT_GRAPH_NODE_RECT,
  DOT_GRAPH_NODE_RECTANGLE,
  DOT_GRAPH_NODE_SQUARE,
  DOT_GRAPH_NODE_STAR,
  DOT_GRAPH_NODE_NONE,
  DOT_GRAPH_NODE_UNDERLINE,
  DOT_GRAPH_NODE_CYLINDER,
  DOT_GRAPH_NODE_NOTE,
  DOT_GRAPH_NODE_TAB,
  DOT_GRAPH_NODE_FOLDER,
  DOT_GRAPH_NODE_BOX3D,
  DOT_GRAPH_NODE_COMPONENT,
  DOT_GRAPH_NODE_PROMOTER,
  DOT_GRAPH_NODE_CDS,
  DOT_GRAPH_NODE_TERMINATOR,
  DOT_GRAPH_NODE_UTR,
  DOT_GRAPH_NODE_PRIMERSITE,
  DOT_GRAPH_NODE_RESTRICTIONSITE,
  DOT_GRAPH_NODE_FIVEPOVERHANG,
  DOT_GRAPH_NODE_THREEPOVERHANG,
  DOT_GRAPH_NODE_NOVERHANG,
  DOT_GRAPH_NODE_ASSEMBLY,
  DOT_GRAPH_NODE_SIGNATURE,
  DOT_GRAPH_NODE_INSULATOR,
  DOT_GRAPH_NODE_RIBOSITE,
  DOT_GRAPH_NODE_RNASTAB,
  DOT_GRAPH_NODE_PROTEASESITE,
  DOT_GRAPH_NODE_PROTEINSTAB,
  DOT_GRAPH_NODE_RPROMOTER,
  DOT_GRAPH_NODE_RARROW,
  DOT_GRAPH_NODE_LARROW,
  DOT_GRAPH_NODE_LPROMOTER,
} dotGraph_nodeShape_e;

typedef enum {
  DOT_GRAPH_ARROW_BOX,
  DOT_GRAPH_ARROW_CROW,
  DOT_GRAPH_ARROW_CURVE,
  DOT_GRAPH_ARROW_ICURVE,
  DOT_GRAPH_ARROW_DIAMOND,
  DOT_GRAPH_ARROW_DOT,
  DOT_GRAPH_ARROW_INV,
  DOT_GRAPH_ARROW_NONE,
  DOT_GRAPH_ARROW_NORMAL,
  DOT_GRAPH_ARROW_TEE,
  DOT_GRAPH_ARROW_VEE,
} dotGraph_arrowTypes_e;

typedef enum {
  DOT_GRAPH_LINE_SOLID,
  DOT_GRAPH_LINE_DASHED,
  DOT_GRAPH_LINE_DOTTED,
  DOT_GRAPH_LINE_BOLD,
  DOT_GRAPH_LINE_ROUNDED,
  DOT_GRAPH_LINE_DIAGONALS,
  DOT_GRAPH_LINE_FILLED,
  DOT_GRAPH_LINE_STRIPED,
  DOT_GRAPH_LINE_WEDGED,
} dotGraph_lineTypes_e;

typedef enum
{
  DOT_GRAPH_DEVICE_TYPE_ROUTER,
  DOT_GRAPH_DEVICE_TYPE_END_DEVICE,
  DOT_GRAPH_DEVICE_TYPE_UNKNOWN,
} dotGraph_deviceTypes_e;

typedef struct
{
  char* colorScheme;
  char* graphName;
} dotGraph_graphSettings_t;

typedef struct
{
  dotGraph_nodeShape_e shape;
  char label[20];
} dotGraph_nodeAttributes_t;


typedef struct
{
  bool initialized;
  uint16_t id;
  dotGraph_nodeAttributes_t attributes;
} dotGraph_node_t;

typedef struct
{
  bool initialized;
  uint16_t id_1;
  uint16_t id_2;
} dotGraph_edge_t;

typedef struct
{
  bool initialized;
  dotGraph_node_t *nodes;
  uint16_t numNodes;
  uint16_t iNode; // node iterator
  dotGraph_edge_t *edges;
  dotGraph_graphSettings_t settings;
} dotGraph_handle_t;

bool dotGraph_initGraph(dotGraph_handle_t* self,
                        dotGraph_node_t* nodes,
                        uint16_t nNodes,
                        dotGraph_edge_t *edges,
                        uint16_t nEdges);

bool dotGraph_getNewNodeInstance(dotGraph_handle_t *self,
                              dotGraph_node_t **node);

bool dotGraph_initNode(dotGraph_node_t *self,
                       uint16_t id);

bool dotGraph_writeToFile(dotGraph_handle_t* self);
bool dotGraph_writeToLogs(dotGraph_handle_t* self);

#endif // HUBCORE_DOTGRAPH_H