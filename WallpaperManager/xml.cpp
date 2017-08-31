#include <QFile>
#include <QTextStream>
#include <QFileInfo>
#include <QDebug>


#include "xml.h"

XML::XML(QString filename):_filename(filename)
{
    //Si le fichier n'existe pas on le creer:
    if(!fileExist()){
        _content="<xml>";
    }
    else{
        //On ouvre le fichier et on lit tout le contenu:
        QFile xml_file(_filename);
        xml_file.open(QIODevice::ReadOnly | QIODevice::Text);
        QTextStream stream_xml_file(&xml_file);
        QString text_from_xml_file=stream_xml_file.readAll();
        //On enleve la balise </xml>
        text_from_xml_file=text_from_xml_file.split("</xml>")[0];
        _content=text_from_xml_file;
        xml_file.close();
    }

}
QString XML::parseXMLByTag(QString tag){
    if(tagExist(tag)){
        return _content.split("<"+tag+">")[1].split("</"+tag+">")[0];
    }
    return "";
}
bool XML::fileExist(){
    QFileInfo check_file(_filename);
        // check if file exists and if yes: Is it really a file and no directory?
        if (check_file.exists() && check_file.isFile()) {
            return true;
        } else {
            return false;
        }
}
bool XML::writeXML(){
    QFile xml_file_out(_filename);
    if(!xml_file_out.open(QIODevice::WriteOnly)){
        return false;
    }
    QTextStream stream_xml_file_out(&xml_file_out);
    stream_xml_file_out<<_content+"</xml>";
    xml_file_out.close();
    return true;
}
void XML::addTag(QString tag){
    if(!tagExist(tag)){
        _content+="<"+tag+"></"+tag+">";
    }
}
void XML::editTag(QString tag,QString content){
    if(!tagExist(tag)){
        addTag(tag);
    }
    //On ajoute le contenu:
    _content=_content.split("<"+tag+">")[0]+"<"+tag+">"+content+"</"+tag+">"+_content.split("</"+tag+">")[1];

}
bool XML::tagExist(QString tag){
    return _content.contains("<"+tag+">")&&_content.contains("</"+tag+">");
}

