#include <Python.h>

#include "graph/node/node.h"
#include "graph/node/root.h"

#include "graph/node/nodes/csg.h"

#include "graph/datum/datums/name_datum.h"
#include "graph/datum/datums/float_datum.h"
#include "graph/datum/datums/shape_input_datum.h"
#include "graph/datum/datums/shape_function_datum.h"
#include "graph/datum/datums/string_datum.h"

////////////////////////////////////////////////////////////////////////////////

Node* DifferenceNode(float x, float y, float z, float scale, NodeRoot* parent)
{
    Q_UNUSED(x);
    Q_UNUSED(y);
    Q_UNUSED(z);
    Q_UNUSED(scale);

    Node* n = new Node(NodeType::DIFFERENCE, parent->getName("d"), parent);
    new ShapeInputDatum("a", n);
    new ShapeInputDatum("b", n);
    new ShapeFunctionDatum("shape", n, "difference", {"a", "b"});
    return n;
}

Node* IntersectionNode(float x, float y, float z, float scale, NodeRoot* parent)
{
    Q_UNUSED(x);
    Q_UNUSED(y);
    Q_UNUSED(z);
    Q_UNUSED(scale);

    Node* n = new Node(NodeType::INTERSECTION, parent->getName("d"), parent);
    new ShapeInputDatum("a", n);
    new ShapeInputDatum("b", n);
    new ShapeFunctionDatum("shape", n, "intersection", {"a", "b"});
    return n;
}

Node* UnionNode(float x, float y, float z, float scale, NodeRoot* parent)
{
    Q_UNUSED(x);
    Q_UNUSED(y);
    Q_UNUSED(z);
    Q_UNUSED(scale);

    Node* n = new Node(NodeType::UNION, parent->getName("d"), parent);
    new ShapeInputDatum("a", n);
    new ShapeInputDatum("b", n);
    new ShapeFunctionDatum("shape", n, "union", {"a", "b"});
    return n;
}

Node* BlendNode(float x, float y, float z, float scale, NodeRoot* parent)
{
    Q_UNUSED(x);
    Q_UNUSED(y);
    Q_UNUSED(z);
    Q_UNUSED(scale);

    Node* n = new Node(NodeType::BLEND, parent->getName("b"), parent);
    new ShapeInputDatum("a", n);
    new ShapeInputDatum("b", n);
    new FloatDatum("q", "0.1", n);
    new ShapeFunctionDatum("shape", n, "blend", {"a", "b", "q"});
    return n;
}

Node* OffsetNode(float x, float y, float z, float scale, NodeRoot* parent)
{
    Q_UNUSED(x);
    Q_UNUSED(y);
    Q_UNUSED(z);
    Q_UNUSED(scale);

    Node* n = new Node(NodeType::OFFSET, parent->getName("d"), parent);
    new ShapeInputDatum("a", n);
    new FloatDatum("o", "0.0", n);
    new ShapeFunctionDatum("shape", n, "offset", {"a", "o"});

    return n;
}

Node* ShellNode(float x, float y, float z, float scale, NodeRoot* parent)
{
    Q_UNUSED(x);
    Q_UNUSED(y);
    Q_UNUSED(z);
    Q_UNUSED(scale);

    Node* n = new Node(NodeType::SHELL, parent->getName("d"), parent);
    new ShapeInputDatum("a", n);
    new FloatDatum("s", "0.0", n);
    new ShapeFunctionDatum("shape", n, "shell", {"a", "s"});

    return n;
}



Node* ClearanceNode(float x, float y, float z, float scale, NodeRoot* parent)
{
    Q_UNUSED(x);
    Q_UNUSED(y);
    Q_UNUSED(z);
    Q_UNUSED(scale);

    Node* n = new Node(NodeType::CLEARANCE, parent->getName("d"), parent);
    new ShapeInputDatum("a", n);
    new ShapeInputDatum("b", n);
    new FloatDatum("o", "0.0", n);
    new ShapeFunctionDatum("shape", n, "clearance", {"a", "b", "o"});

    return n;
}
