#include <Python.h>

#include "graph/node/node.h"
#include "graph/node/root.h"

#include "graph/node/nodes/deform.h"

#include "graph/datum/datums/name_datum.h"
#include "graph/datum/datums/float_datum.h"
#include "graph/datum/datums/shape_input_datum.h"
#include "graph/datum/datums/shape_function_datum.h"
#include "graph/datum/datums/string_datum.h"

////////////////////////////////////////////////////////////////////////////////

Node* AttractNode(float x, float y, float z, float scale, NodeRoot* parent)
{
    Node* n = new Node(NodeType::ATTRACT, parent->getName("a"), parent);
    new FloatDatum("x", QString::number(x), n);
    new FloatDatum("y", QString::number(y), n);
    new FloatDatum("z", QString::number(z), n);
    new FloatDatum("r", QString::number(scale), n);
    new ShapeInputDatum("input", n);
    new ShapeFunctionDatum("shape", n, "attract",
            {"input", "x", "y", "z", "r"});
    return n;
}

Node* RepelNode(float x, float y, float z, float scale, NodeRoot* parent)
{
    Node* n = new Node(NodeType::REPEL, parent->getName("a"), parent);
    new FloatDatum("x", QString::number(x), n);
    new FloatDatum("y", QString::number(y), n);
    new FloatDatum("z", QString::number(z), n);
    new FloatDatum("r", QString::number(scale), n);
    new ShapeInputDatum("input", n);
    new ShapeFunctionDatum("shape", n, "repel",
            {"input", "x", "y", "z", "r"});
    return n;
}

Node* ScaleXNode(float x, float y, float z, float scale, NodeRoot* parent)
{
    Node* n = new Node(NodeType::SCALEX, parent->getName("a"), parent);
    new FloatDatum("x", QString::number(x), n);
    new FloatDatum("_y", QString::number(y), n);
    new FloatDatum("_z", QString::number(z), n);
    new FloatDatum("s", QString::number(scale), n);
    new ShapeInputDatum("input", n);
    new ShapeFunctionDatum("shape", n, "scale_x",
            {"input", "x", "s"});
    return n;
}

Node* ScaleYNode(float x, float y, float z, float scale, NodeRoot* parent)
{
    Node* n = new Node(NodeType::SCALEY, parent->getName("a"), parent);
    new FloatDatum("_x", QString::number(x), n);
    new FloatDatum("y", QString::number(y), n);
    new FloatDatum("_z", QString::number(z), n);
    new FloatDatum("s", QString::number(scale), n);
    new ShapeInputDatum("input", n);
    new ShapeFunctionDatum("shape", n, "scale_y",
            {"input", "y", "s"});
    return n;
}

Node* ScaleZNode(float x, float y, float z, float scale, NodeRoot* parent)
{
    Node* n = new Node(NodeType::SCALEZ, parent->getName("a"), parent);
    new FloatDatum("_x", QString::number(x), n);
    new FloatDatum("_y", QString::number(y), n);
    new FloatDatum("z", QString::number(z), n);
    new FloatDatum("s", QString::number(scale), n);
    new ShapeInputDatum("input", n);
    new ShapeFunctionDatum("shape", n, "scale_z",
            {"input", "z", "s"});
    return n;
}

