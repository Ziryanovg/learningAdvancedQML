#ifndef CPPSENDER_H
#define CPPSENDER_H

#include <QObject>
#include <QTimer>

class cppSender : public QObject
{
    Q_OBJECT
public:
    explicit cppSender(QObject *parent = nullptr);

private:
    QTimer* timer;
    int count;

signals:
    void callToQml(QString param);
    void sendToQmlCount(int value);


public slots:
    void cppSlot();
};

#endif // CPPSENDER_H
