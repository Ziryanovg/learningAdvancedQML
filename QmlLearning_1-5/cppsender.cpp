#include "cppsender.h"

cppSender::cppSender(QObject *parent) : QObject(parent),timer(new QTimer),count(0)
{
    connect(timer,&QTimer::timeout,[=](){
       ++count;
       emit sendToQmlCount(count);
    });

    timer->start(1000);
}

void cppSender::cppSlot()
{
    emit callToQml("param from cpp");
}
