#ifndef MOVIE_H
#define MOVIE_H

#include <QObject>

class Movie : public QObject
{
    Q_OBJECT


public:
    explicit Movie(QObject *parent = nullptr);

    Q_PROPERTY(QString title READ title WRITE setTitle NOTIFY titleChanged)

    QString title() const;

signals:
    void titleChanged(QString title);

public slots:
    void setTitle(QString title);

private:
    QString m_title;
};

#endif // MOVIE_H
