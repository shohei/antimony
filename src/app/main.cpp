#include <Python.h>

#include <QApplication>
#include <QDebug>
#include <QSurfaceFormat>

#include "app/app.h"
#include "fab/fab.h"

int main(int argc, char *argv[])
{
    // Set the default OpenGL version to be 2.1 with sample buffers
    QSurfaceFormat format;
    format.setVersion(2, 1);
    format.setSamples(2);
    QSurfaceFormat::setDefaultFormat(format);

    // Initialize the _fabtypes Python package and the Python interpreter
    fab::preInit();
    Py_Initialize();

    // Create the Application object
    App a(argc, argv);

    // Modify Python's default search path to include the application's
    // directory (as this doesn't happen on Linux by default)
    QString d = QCoreApplication::applicationDirPath();
#if defined Q_OS_MAC
    QStringList path = d.split("/");
    for (int i=0; i < 3; ++i)
        path.removeLast();
    d = path.join("/");
#endif
    fab::postInit(d.toStdString().c_str());

    return a.exec();
}
