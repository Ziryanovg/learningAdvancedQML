#include "mainmodel.h"
#include <QXmlStreamWriter>
#include <QXmlStreamReader>
#include <QFile>
#include <QDebug>

MainModel::MainModel(QObject *parent):
    QAbstractListModel(parent)
{
    readModelFromXml();
    //m_data.append("first");
    //m_data.append("second");

    //writeToXml();
}

int MainModel::rowCount(const QModelIndex &parent) const
{
    if (parent.isValid()) {
        return 0;
    }

    return m_data.size();
}

QVariant MainModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid()) {
        return QVariant();
    }

    switch (role) {
    case TextRole:
        return m_data.at(index.row());
    default:
        return QVariant();
    }
}

QHash<int, QByteArray> MainModel::roleNames() const
{
    QHash<int, QByteArray> roles = QAbstractListModel::roleNames();
    roles[TextRole] = "name";

    return roles;
}

void MainModel::add()
{
    beginInsertRows(QModelIndex(), m_data.size(), m_data.size());
    m_data.append("new");
    endInsertRows();

    m_data[0] = QString("Size: %1").arg(m_data.size());
    QModelIndex index = createIndex(0, 0, static_cast<void *>(0));
    emit dataChanged(index, index);
}

void MainModel::writeToXml()
{
    QFile file("D:/1.xml");
    file.open(QIODevice::WriteOnly);
    QXmlStreamWriter xmlWriter(&file);

    xmlWriter.setAutoFormatting(true);
    xmlWriter.writeStartDocument();

    xmlWriter.writeStartElement("items");

    for (auto i=0;i<m_data.size();i++) {
        xmlWriter.writeStartElement("item");
        xmlWriter.writeCharacters(m_data.at(i));
        xmlWriter.writeEndElement();
    }


    xmlWriter.writeEndElement();
    xmlWriter.writeEndDocument();
    file.close();

}

void MainModel::readModelFromXml()
{
    QFile file("D:/1.xml");
    if(!file.open(QFile::ReadOnly | QFile::Text)){
        qDebug() << "Cannot read file" << file.errorString();
        exit(0);
    }

    QXmlStreamReader xml(&file);

    while (!xml.atEnd() && !xml.hasError())
    {

        QXmlStreamReader::TokenType token = xml.readNext();
        if (token == QXmlStreamReader::StartDocument)
            continue;
        if (token == QXmlStreamReader::StartElement)
        {
            if (xml.name() == "items")
                continue;
            if (xml.name() == "item")
                m_data.append(xml.readElementText());
        }
    }

    file.close();
}


