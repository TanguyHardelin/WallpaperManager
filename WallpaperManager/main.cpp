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
void downloadImages(QStringList all_argv){
    ImageDownloader ddl_image("https://wallpaperscraft.com/all/3840x2160");
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
        downloadImages(all_argv);
    }
    else if(all_argv.contains("--help")){
        displayHelp();
    }
    else{
        //On montre la fenetre:
        w.show();
    }


    return application.exec();
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
