#include "cppworker.h"
#include <QDebug>

CppWorker::CppWorker(QObject *parent) : QObject(parent)
{

}

void CppWorker::defaultMethod()
{
    qDebug() << "Call Default Method";
}

QString CppWorker::defaultMethodWithReturn(QString name)
{
    return "Name is " + name;
}

void CppWorker::cppSlot()
{
    qDebug() << "Call cppSlot";
}
