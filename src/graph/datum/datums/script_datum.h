#ifndef SCRIPT_DATUM_H
#define SCRIPT_DATUM_H

#include <Python.h>

#include <QSet>
#include <QString>

#include "graph/datum/types/eval_datum.h"

class ScriptDatum : public EvalDatum
{
public:
    explicit ScriptDatum(QString name, Node* parent);
    explicit ScriptDatum(QString name, QString expr, Node* parent);
    virtual ~ScriptDatum();

    PyObject* makeInput(QString name, PyTypeObject* type);
    PyObject* makeOutput(QString name, PyObject* out);

    PyTypeObject* getType() const override { return Py_None->ob_type; }
    bool hasOutput() const override { return false; }

    DatumType::DatumType getDatumType() const override
        { return DatumType::SCRIPT; }

protected:

    /** Returns true if we are already evaluating this datum.
     */
    bool isRecursing() const override { return globals; }

    /** Returns True if we can make an input or output datum with this name.
     */
    bool isValidName(QString name) const;

    /** Evaluates the script (getting back None) and causing datum creation.
     */
    PyObject* getCurrentValue() override;

    /** Function that returns the desired start token for PyRun_String
     */
    int getStartToken() const override;

    /** Function that modifies the globals dict before eval is called.
     */
    void modifyGlobalsDict(PyObject* g) override;

    PyObject* globals;
    PyObject* input_func;
    PyObject* output_func;

    QSet<QString> touched;
    bool datums_changed;
};

#endif // SCRIPT_DATUM_H
