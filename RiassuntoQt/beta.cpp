#include "beta.h"
#include <QDebug>

Beta::Beta(QObject *parent)
    : QObject{parent}
{

}

Beta::~Beta() noexcept
{
    qDebug() << "Distruggo " << objectName();
}

void Beta::riceviAllarme(QString m)
{
    qDebug() << "Allarme ricevuto " << m;
}
