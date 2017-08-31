#ifndef ALL_OTHER_BACKGROUND_H
#define ALL_OTHER_BACKGROUND_H

#include <vector>

#include <QWidget>
#include <QGridLayout>

#include "button_other_background.h"

namespace Ui {
class All_Other_Background;
}

class All_Other_Background : public QWidget
{
    Q_OBJECT

public:
    explicit All_Other_Background(QWidget *parent = 0);
    void getOtherBackground();
    ~All_Other_Background();
signals:
    void background_changed(QString background_name);

public slots:
    void emit_background_changed(QString background_name);

private:
    Ui::All_Other_Background *ui;
    QStringList _other_background;
    QGridLayout *_all_other_background_layout;

    std::vector<Button_other_background *> _buttons_all_other_background;
};

#endif // ALL_OTHER_BACKGROUND_H
