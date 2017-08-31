#ifndef BUTTON_OTHER_BACKGROUND_H
#define BUTTON_OTHER_BACKGROUND_H

#include <QPushButton>

class Button_other_background : public QPushButton
{
    Q_OBJECT

public:
    Button_other_background(QString background_name);

signals:
    void background_changed(QString background_name);

public slots:
    void emit_change_background();

protected:
    QString _background_name;
};

#endif // BUTTON_OTHER_BACKGROUND_H
