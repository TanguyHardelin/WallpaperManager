#include <cstdlib>
#include <sstream>
#include <string>
#include <iostream>

#include <QFile>
#include <QMessageBox>
#include <QTextStream>
#include <QDebug>
#include <QHBoxLayout>
#include <QPushButton>
#include <QTextStream>
#include <QLabel>
#include <QDir>

#include "home.h"
#include "ui_home.h"
#include "button_other_background.h"
#include "all_other_background.h"
#include "xml.h"

using namespace std;

Home::Home(QWidget *parent):
    QWidget(parent),
    ui(new Ui::Home),
    _current_background("")
{
    ui->setupUi(this);
   // getAllBackground();
    //On va chercher les parametres:
    _param_file=new XML(".param.xml");
    if(!_param_file->tagExist("current_background")){
       _param_file->addTag("current_background");
       _param_file->writeXML();
    }

    _current_background=_param_file->parseXMLByTag("current_background");
    ui->actual_background->setPixmap(QPixmap("Images/"+_current_background));


/*
    //On rajoute tout les autres backgrounds existant:
    getOtherBackground();
    QHBoxLayout *layout_other_background=new QHBoxLayout;
    ui->widget_other_background->setLayout(layout_other_background);
    for(int i=0;i<_other_background.size();i++){
        Button_other_background *button=new Button_other_background(_other_background[i]);
        layout_other_background->addWidget(button);
        _all_other_background.push_back(button);

        QObject::connect(_all_other_background[i],SIGNAL(background_changed(QString)),this,SLOT(changeBackground(QString)));

        if(i>=_maximum_index_other_background){
            _current_index_other_background=_maximum_index_other_background;
            break;
        }

    }
    */



  //  QObject::connect(ui->button_all_other_background,SIGNAL(clicked()),this,SLOT(openOtherBackgroundWindow()));
}
void Home::changeBackground(QString background_name){
    _current_background=background_name;
    _param_file->editTag("current_background",_current_background);
    system(("feh --bg-scale Images/"+_current_background).toStdString().c_str());

    QFileInfo fichier_image("Images/"+_current_background);
    system(("gsettings set org.gnome.desktop.background picture-uri file:"+fichier_image.absoluteFilePath()).toStdString().c_str());
    _param_file->writeXML();
    ui->actual_background->setPixmap(QPixmap("Images/"+_current_background));

}

void Home::getOtherBackground(){
    QDir picture_repository("Images/");
    _other_background=picture_repository.entryList(QDir::Files);
}
void Home::openOtherBackgroundWindow(){
    _all_other_background_window=new All_Other_Background;
    QObject::connect(_all_other_background_window,SIGNAL(background_changed(QString)),this,SLOT(changeBackground(QString)));
    _all_other_background_window->show();
}

Home::~Home()
{
    delete ui;
    delete _param_file;
    for(int i=0;i<_all_other_background.size();i++){
        delete _all_other_background[i];
    }
    if(_all_other_background_window!=0)
        delete _all_other_background_window;
}
