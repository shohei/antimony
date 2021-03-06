#include <Python.h>
#include "graph/datum/datums/int_datum.h"
#include "graph/datum/input.h"

IntDatum::IntDatum(QString name, Node* parent)
    : EvalDatum(name, parent)
{
    input_handler = new SingleInputHandler(this);
}

IntDatum::IntDatum(QString name, QString expr, Node *parent)
    : IntDatum(name, parent)
{
    setExpr(expr);
}
