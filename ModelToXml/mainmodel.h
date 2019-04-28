#ifndef MAINMODEL_H
#define MAINMODEL_H

#include <QAbstractListModel>
#include <QObject>
#include <QStringList>

class MainModel : public QAbstractListModel
{
    Q_OBJECT

public:
    enum Roles {
        TextRole = Qt::UserRole + 1
    };

    MainModel(QObject *parent = nullptr);

    virtual int rowCount(const QModelIndex &parent) const;
    virtual QVariant data(const QModelIndex &index, int role) const;
    virtual QHash<int, QByteArray> roleNames() const;

    Q_INVOKABLE void add();

    Q_INVOKABLE void writeToXml();

    void readModelFromXml();

private:
    QStringList m_data;
};

#endif // MAINMODEL_H
