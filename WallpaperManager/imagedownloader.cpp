#include <cstdlib>
#include <sstream>
#include <string>
#include <iostream>

#include <QFile>
#include <QStringList>
#include <QTextStream>
#include <QDebug>
#include <QMessageBox>

#include "imagedownloader.h"

using namespace std;

ImageDownloader::ImageDownloader(QString current_site,QObject *parent) : QObject(parent), _current_site(current_site)
{
    getAllBackground();
}
QStringList ImageDownloader::getListOfPictureExisting(){
    //On charge le fichier qui contient le nom de toute les images:
    QFile all_pictures_ddl(".all_picture_ddl.txt");
    if(!all_pictures_ddl.open(QIODevice::ReadOnly)){
        if(0!=system("touch .all_picture_ddl.txt"))
            qDebug()<<"Erreur lors de l'ouverture en lecture du fichier .all_picture_ddl.txt ";
    }
    QTextStream all_pictures_ddl_stream(&all_pictures_ddl);
    QStringList all_pictures_ddl_list=all_pictures_ddl_stream.readAll().split("\n");
    all_pictures_ddl.close();
    return all_pictures_ddl_list;

}

void ImageDownloader::getAllBackground(){
    QStringList list_of_all_pictures_ddl=getListOfPictureExisting();

    QFile all_pictures_ddl(".all_picture_ddl.txt");
    if(!all_pictures_ddl.open(QIODevice::Append)){
        if(0!=system("touch .all_picture_ddl.txt"))
            qDebug()<<"Erreur lors de l'ouverture du fichier .all_picture_ddl.txt quand on veut ajouter";
    }
    QTextStream all_pictures_ddl_stream(&all_pictures_ddl);




    //On fait la recherche sur 10 pages
    for(int i=0;i<2;i++){
        stringstream tmp;
        tmp << i;
        system(("wget -O tmp_"+QString(tmp.str().c_str())+".html "+_current_site+"/page2"+QString(tmp.str().c_str())).toStdString().c_str());
        //On recupere les images
        QFile file("tmp_"+QString(tmp.str().c_str())+".html");
        if(!file.open(QIODevice::ReadOnly)) {
            QMessageBox::information(0, "Connexion internet manquante !", file.errorString());
        }
        else{
            QTextStream in(&file);
            QString text=in.readAll();
            file.close();

            //On split avec les balises images:
            QStringList address_list=text.split("<div class=\"wallpaper_pre\"");
            for(int j=1;j<address_list.length();j++){
                qDebug()<<"Va à l'adresse: "+address_list[j].split("href=\"")[1].split("\"")[0];
                //On va à l'adresse pointé par l'adresse
                QString tmp_command=("wget -O tmp.html "+address_list[j].split("href=\"")[1].split("\"")[0]);
                tmp_command=tmp_command.replace("//","https://");
                system(tmp_command.toStdString().c_str());


                QFile tmp_file("tmp.html");
                if(!tmp_file.open(QIODevice::ReadOnly)) {
                    QMessageBox::information(0, "Connexion internet manquante !", tmp_file.errorString());
                }
                QString tmp_text=tmp_file.readAll();
                tmp_text=tmp_text.split("<img")[2];


                QString url=tmp_text.split("src=\"")[1].split("\"")[0];
                //En cas où l'attribut alt est absent
                QStringList filename_list=tmp_text.split("alt=\"");
                QString filename="";
                if(filename_list.size()>1)
                    filename=tmp_text.split("alt=\"")[1].split("\"")[0];
                filename=filename.replace(" ","_")+".jpeg";
                qDebug()<<"Name: "+filename+" url: "+url.replace("//","https://");
                last_background=filename;
                if(url.contains("http")){
                    if(!list_of_all_pictures_ddl.contains(filename)){
                        //On n'a pas encore téléchargé l'image:
                        qDebug()<<"Command "+("wget -O "+filename+" "+url);
                        system(("wget -O Images/"+filename+" "+url).toStdString().c_str());
                        system(("convert Images/"+filename+" -resize 20% Icons/"+filename).toStdString().c_str());
                        all_pictures_ddl_stream<<filename+"\n";
                        all_pictures_ddl_stream.flush();
                    }


                }

            }

        }
    }

}
