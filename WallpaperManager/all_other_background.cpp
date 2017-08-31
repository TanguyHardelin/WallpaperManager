#include "all_other_background.h"
#include "ui_all_other_background.h"

All_Other_Background::All_Other_Background(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::All_Other_Background)
{
    ui->setupUi(this);
}

All_Other_Background::~All_Other_Background()
{
    delete ui;
}
