#include "button_other_background.h"
#include <QIcon>

Button_other_background::Button_other_background(QString background_name):_background_name(background_name)
{
    QIcon icon("Icons/"+background_name);
    this->setIcon(icon);
    this->setIconSize(QSize(115,65));

    QObject::connect(this,SIGNAL(clicked(bool)),this,SLOT(emit_change_background()));
}
void Button_other_background::emit_change_background(){
    emit background_changed(_background_name);
}
