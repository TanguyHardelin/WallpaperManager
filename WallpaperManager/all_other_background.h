#ifndef ALL_OTHER_BACKGROUND_H
#define ALL_OTHER_BACKGROUND_H

#include <QWidget>

namespace Ui {
class All_Other_Background;
}

class All_Other_Background : public QWidget
{
    Q_OBJECT

public:
    explicit All_Other_Background(QWidget *parent = 0);
    ~All_Other_Background();

private:
    Ui::All_Other_Background *ui;
};

#endif // ALL_OTHER_BACKGROUND_H
