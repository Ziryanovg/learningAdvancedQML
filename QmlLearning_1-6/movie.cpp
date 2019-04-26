#include "movie.h"

Movie::Movie(QObject *parent) : QObject(parent),m_title("Titanic")
{

}

QString Movie::title() const
{
    return m_title;
}

void Movie::setTitle(QString title)
{
    if (m_title == title)
        return;

    m_title = title;
    emit titleChanged(m_title);
}
