#ifndef XML_H
#define XML_H

#include <QString>

class XML
{
public:
    XML(QString filename);
    QString parseXMLByTag(QString tag);
    void addTag(QString tag);
    void editTag(QString tag,QString content);
    bool tagExist(QString tag);
    bool fileExist();
    bool writeXML();




protected:
    //Attributs:
    QString _filename;
    QString _content;
};

#endif // XML_H
