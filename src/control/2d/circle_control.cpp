#include "control/2d/circle_control.h"

_RadiusControl::_RadiusControl(Node *node, QObject* parent)
    : WireframeControl(node, parent)
{
    watchDatums({"x","y","r"});
}

QVector<QVector<QVector3D>> _RadiusControl::lines() const
{
    QVector3D c = center();
    float r = getValue("r");
    int n = 64;

    QVector<QVector3D> circle;
    for (int i=0; i <= n; ++i)
    {
        circle << c + r*QVector3D(cos(i*2*M_PI/n), sin(i*2*M_PI/n), 0);
    }

    return {circle};
}

QVector3D _RadiusControl::center() const
{
    return QVector3D(getValue("x"), getValue("y"), 0);
}

void _RadiusControl::drag(QVector3D c, QVector3D d)
{
    dragValue("r", QVector3D::dotProduct((c - center()).normalized(), d));
}

////////////////////////////////////////////////////////////////////////////////

CircleControl::CircleControl(Node *node, QObject* parent)
    : DummyControl(node, parent),
      radius(new _RadiusControl(node, this)),
      center(new Point2DControl(node, this))
{
    watchDatums({"x","y","r"});
}

void CircleControl::drag(QVector3D c, QVector3D delta)
{
    center->drag(c, delta);
}

QRectF CircleControl::bounds(QMatrix4x4 m, QMatrix4x4 t) const
{
    return radius->bounds(m, t);
}
