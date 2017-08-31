#ifndef HOME_H
#define HOME_H

#include <vector>

#include <QWidget>
#include <QStringList>
#include <QPushButton>

#include "button_other_background.h"
#include "all_other_background.h"
#include "xml.h"
namespace Ui {
class Home;
}

class Home : public QWidget
{
    Q_OBJECT

public:
    explicit Home(QWidget *parent = 0);
    void getOtherBackground();

    ~Home();

public slots:
    void changeBackground(QString background_name);
    void openOtherBackgroundWindow();

private:
    //Attribut:
    Ui::Home *ui;
    QString _current_background;
    QStringList _other_background;
    std::vector<Button_other_background *> _all_other_background;
    int _current_index_other_background=0;
    int _maximum_index_other_background=10;
    int _current_index=-1;
    XML *_param_file;
    All_Other_Background *_all_other_background_window=0;



};

#endif // HOME_H
