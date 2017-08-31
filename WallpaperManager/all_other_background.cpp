#include <QGridLayout>
#include <QDir>
#include <QDebug>



#include "all_other_background.h"
#include "ui_all_other_background.h"
#include "button_other_background.h"


#define HAUTEUR_MAX 560

All_Other_Background::All_Other_Background(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::All_Other_Background)
{
    ui->setupUi(this);

    _all_other_background_layout =new QGridLayout;
    ui->other_background_scroll_area_widget->setLayout(_all_other_background_layout);

    getOtherBackground();

    //Compteur servant à ajuster la taille:
    int compteur_lignes=0;

    for(int i=0;i<_other_background.size()/4;i++){
        for(int j=0;j<4;j++){
            Button_other_background *button_other_background=new Button_other_background(_other_background[i*4+j]);
            _buttons_all_other_background.push_back(button_other_background);
            _all_other_background_layout->addWidget(_buttons_all_other_background[_buttons_all_other_background.size()-1],i+1,j+1);
            QObject::connect(_buttons_all_other_background[_buttons_all_other_background.size()-1],SIGNAL(background_changed(QString)),this,SLOT(emit_background_changed(QString)));
        }
        compteur_lignes++;
    }
    int hauteur_final=(compteur_lignes)*(65+15);
    if(hauteur_final>HAUTEUR_MAX){
        hauteur_final=HAUTEUR_MAX;
    }

    this->resize((115+50)*4,hauteur_final);


}
void All_Other_Background::getOtherBackground(){
    QDir picture_repository("Images/");
    _other_background=picture_repository.entryList(QDir::Files);
}
void All_Other_Background::emit_background_changed(QString background_name){
    emit background_changed(background_name);
}

All_Other_Background::~All_Other_Background()
{
    delete ui;
    delete _all_other_background_layout;
    for(int i=0;i<_buttons_all_other_background.size();i++){
        delete _buttons_all_other_background[i];
    }
}
