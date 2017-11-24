#ifndef IMAGEDOWNLOADER_H
#define IMAGEDOWNLOADER_H

#include <QString>
#include <QObject>

class ImageDownloader : public QObject
{
    Q_OBJECT
public:
    explicit ImageDownloader(QString current_site,QObject *parent = 0);
    QStringList getListOfPictureExisting();
    void getAllBackground();

    inline QString getLastBackground(){return last_background;}

signals:

public slots:


protected:
    QString _current_site;
    QString last_background;
};

#endif // IMAGEDOWNLOADER_H
