/* Copyright (c) 2018 SmartThings. All Rights Reserved. */

#include "dotGraph.h"
#include <stdint.h>
#include <string.h>

static dotGraph_graphSettings_t _defaultGraphSettings = {
  .colorScheme = "/dark28/",
  .graphName = "MeshNetworkGraph"
};

static dotGraph_nodeAttributes_t _defaultNodeSettings = {
  .shape = DOT_GRAPH_NODE_CIRCLE,
  .label = "unknown"
};

#define LOG_MODULE LOG_HUB

// Forward declarations
static const char* _getNodeTypeStr(dotGraph_nodeShape_e nodeType);
static const char* _getArrowTypeStr(dotGraph_arrowTypes_e arrowType);
static const char* _getLineTypeStr(dotGraph_lineTypes_e lineType);

bool dotGraph_initGraph(dotGraph_handle_t* self,
                        dotGraph_node_t* nodes,
                        uint16_t nNodes,
                        dotGraph_edge_t *edges,
                        uint16_t nEdges)
{
  self->nodes = nodes;
  self->numNodes = nNodes;

  for (uint16_t i; i<nNodes; i++)
  {
    self->nodes[i].initialized = false;
  }
  self->iNode = 0;
  self->initialized = true;

  return self->initialized;
  //memcpy(&self->settings, &_defaultGraphSettings, sizeof(dotGraph_graphSettings_t));
}


bool dotGraph_getNewNodeInstance(dotGraph_handle_t *self,
                                 dotGraph_node_t **node)
{
  if (self->initialized && self->iNode < self->numNodes)
  {
    *node = &(self->nodes[self->iNode]);
    self->iNode++;
    return true;
  }
  else
  {
    *node = NULL;
    return false;
  }

  //self->dni = dni;
  //self->parentDni = parentDni;
  //memcpy(&self->settings, &_defaultNodeSettings, sizeof(dotGraph_nodeSettings_t));
}

bool dotGraph_initNode(dotGraph_node_t *self,
                       uint16_t id)
{
  self->id = id;
  sprintf(self->attributes.label, "id=%d", id);
  self->initialized = true;
  return self->initialized;
}

bool dotGraph_writeToFile(dotGraph_handle_t* self)
{
  return true;
}

bool dotGraph_writeToLogs(dotGraph_handle_t* self)
{
  for(uint16_t i = 0; i < self->numNodes; i++)
  {
    if (self->nodes[i].initialized)
    {
      printf(" %d %s", self->nodes[i].id, self->nodes[i].attributes.label);
    }
  }

  return true;
}

static const char* _getNodeTypeStr(dotGraph_nodeShape_e nodeType)
{
  switch(nodeType) {
    case DOT_GRAPH_NODE_BOX: return "box";
    case DOT_GRAPH_NODE_POLYGON: return "polygon";
    case DOT_GRAPH_NODE_ELLIPSE: return "ellipse";
    case DOT_GRAPH_NODE_OVAL: return "oval";
    case DOT_GRAPH_NODE_CIRCLE: return "circle";
    case DOT_GRAPH_NODE_POINT: return "point";
    case DOT_GRAPH_NODE_EGG: return "egg";
    case DOT_GRAPH_NODE_TRIANGLE: return "triangle";
    case DOT_GRAPH_NODE_PLAINTEXT: return "plaintext";
    case DOT_GRAPH_NODE_PLAIN: return "plain";
    case DOT_GRAPH_NODE_DIAMOND: return "diamond";
    case DOT_GRAPH_NODE_TRAPEZIUM: return "trapezium";
    case DOT_GRAPH_NODE_PARALLELOGRAM: return "parallelogram";
    case DOT_GRAPH_NODE_HOUSE: return "house";
    case DOT_GRAPH_NODE_PENTAGON: return "pentagon";
    case DOT_GRAPH_NODE_HEXAGON: return "hexagon";
    case DOT_GRAPH_NODE_SEPTAGON: return "septagon";
    case DOT_GRAPH_NODE_OCTAGON: return "octagon";
    case DOT_GRAPH_NODE_DOUBLECIRCLE: return "doublecircle";
    case DOT_GRAPH_NODE_DOUBLEOCTAGON: return "doubleoctagon";
    case DOT_GRAPH_NODE_TRIPLEOCTAGON: return "tripleoctagon";
    case DOT_GRAPH_NODE_INVTRIANGLE: return "invtriangle";
    case DOT_GRAPH_NODE_INVTRAPEZIUM: return "invtrapezium";
    case DOT_GRAPH_NODE_INVHOUSE: return "invhouse";
    case DOT_GRAPH_NODE_MDIAMOND: return "mdiamond";
    case DOT_GRAPH_NODE_MSQUARE: return "msquare";
    case DOT_GRAPH_NODE_MCIRCLE: return "mcircle";
    case DOT_GRAPH_NODE_RECT: return "rect";
    case DOT_GRAPH_NODE_RECTANGLE: return "rectangle";
    case DOT_GRAPH_NODE_SQUARE: return "square";
    case DOT_GRAPH_NODE_STAR: return "star";
    case DOT_GRAPH_NODE_NONE: return "none";
    case DOT_GRAPH_NODE_UNDERLINE: return "underline";
    case DOT_GRAPH_NODE_CYLINDER: return "cylinder";
    case DOT_GRAPH_NODE_NOTE: return "note";
    case DOT_GRAPH_NODE_TAB: return "tab";
    case DOT_GRAPH_NODE_FOLDER: return "folder";
    case DOT_GRAPH_NODE_BOX3D: return "box3d";
    case DOT_GRAPH_NODE_COMPONENT: return "component";
    case DOT_GRAPH_NODE_PROMOTER: return "promoter";
    case DOT_GRAPH_NODE_CDS: return "cds";
    case DOT_GRAPH_NODE_TERMINATOR: return "terminator";
    case DOT_GRAPH_NODE_UTR: return "utr";
    case DOT_GRAPH_NODE_PRIMERSITE: return "primersite";
    case DOT_GRAPH_NODE_RESTRICTIONSITE: return "restrictionsite";
    case DOT_GRAPH_NODE_FIVEPOVERHANG: return "fivepoverhang";
    case DOT_GRAPH_NODE_THREEPOVERHANG: return "threepoverhang";
    case DOT_GRAPH_NODE_NOVERHANG: return "noverhang";
    case DOT_GRAPH_NODE_ASSEMBLY: return "assembly";
    case DOT_GRAPH_NODE_SIGNATURE: return "signature";
    case DOT_GRAPH_NODE_INSULATOR: return "insulator";
    case DOT_GRAPH_NODE_RIBOSITE: return "ribosite";
    case DOT_GRAPH_NODE_RNASTAB: return "rnastab";
    case DOT_GRAPH_NODE_PROTEASESITE: return "proteasesite";
    case DOT_GRAPH_NODE_PROTEINSTAB: return "proteinstab";
    case DOT_GRAPH_NODE_RPROMOTER: return "rpromoter";
    case DOT_GRAPH_NODE_RARROW: return "rarrow";
    case DOT_GRAPH_NODE_LARROW: return "larrow";
    case DOT_GRAPH_NODE_LPROMOTER: return "lpromoter";
    default: return "none";
  }
}

static const char* _getArrowTypeStr(dotGraph_arrowTypes_e arrowType)
{
  switch(arrowType) {
    case DOT_GRAPH_ARROW_BOX: return "box";
    case DOT_GRAPH_ARROW_CROW: return "crow";
    case DOT_GRAPH_ARROW_CURVE: return "curve";
    case DOT_GRAPH_ARROW_ICURVE: return "icurve";
    case DOT_GRAPH_ARROW_DIAMOND: return "diamond";
    case DOT_GRAPH_ARROW_DOT: return "dot";
    case DOT_GRAPH_ARROW_INV: return "inv";
    case DOT_GRAPH_ARROW_NONE: return "none";
    case DOT_GRAPH_ARROW_NORMAL: return "normal";
    case DOT_GRAPH_ARROW_TEE: return "tee";
    case DOT_GRAPH_ARROW_VEE: return "vee";
    default: return "none";
  }
}

static const char* _getLineTypeStr(dotGraph_lineTypes_e lineType)
{
  switch(lineType)
  {
    case DOT_GRAPH_LINE_SOLID: return "solid";
    case DOT_GRAPH_LINE_DASHED: return "dashed";
    case DOT_GRAPH_LINE_DOTTED: return "dotted";
    case DOT_GRAPH_LINE_BOLD: return "bold";
    case DOT_GRAPH_LINE_ROUNDED: return "rounded";
    case DOT_GRAPH_LINE_DIAGONALS: return "diagonals";
    case DOT_GRAPH_LINE_FILLED: return "filled";
    case DOT_GRAPH_LINE_STRIPED: return "striped";
    case DOT_GRAPH_LINE_WEDGED: return "wedged";
    default: return "solid";
  }
}