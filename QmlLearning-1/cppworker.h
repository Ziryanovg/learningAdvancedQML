#ifndef CPPWORKER_H
#define CPPWORKER_H

#include <QObject>

class CppWorker : public QObject
{
    Q_OBJECT
public:
    explicit CppWorker(QObject *parent = nullptr);
    Q_INVOKABLE void defaultMethod();
    Q_INVOKABLE QString defaultMethodWithReturn(QString name);

signals:

public slots:
    void cppSlot();
};

#endif // CPPWORKER_H
