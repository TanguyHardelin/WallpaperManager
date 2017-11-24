#include <iostream>


#include <QApplication>
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QStringList>
#include <QString>

#include "home.h"
#include "imagedownloader.h"
#include "xml.h"

using namespace std;

void displayHelp(){
    cout<<"AIDE"<<endl;
}
QString downloadImages(QStringList all_argv){
    ImageDownloader ddl_image("https://wallpaperscraft.com/all/3840x2160");
    return ddl_image.getLastBackground();
}

int main(int argc, char *argv[])
{
    QApplication application(argc, argv);
    Home w;

    //On rentre tout les arguments donnés en paramètres dans une list (permet d'utiliser la méthode contains)
    QStringList all_argv;
    for(int i=0;i<argc;i++){
        all_argv.append(QString(argv[i]));
    }
    //On execute les actions en fonctions de ce que on veut:
    if(all_argv.contains("--download_images") || all_argv.contains("-D")){
        QString last_background=downloadImages(all_argv);
        //On set l'image:
        if(last_background=="")
            last_background="3840x2160_Wallpaper_night_city,_skyscrapers,_night,_bridge.jpeg";
        qDebug()<<"Background changed: "+last_background;
        w.changeBackground(last_background);

    }
    else if(all_argv.contains("--help")){
        displayHelp();
    }
    else{
        //On montre la fenetre:
        w.show();
        return application.exec();
    }



}





/*
//Test unitaire de la class XML:
int main(int argc,char **argv){
    QApplication app(argc,argv);

    XML xml("param.xml");

    xml.editTag("info","toto");
    xml.addTag("lol");
    xml.editTag("lol","bonjour!");
    qDebug()<<xml.parseXMLByTag("info");
    xml.writeXML();



    return 0;
}
*/
