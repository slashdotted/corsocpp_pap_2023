#ifndef ALPHA_H
#define ALPHA_H

#include <QObject>

class Alpha : public QObject
{
    Q_OBJECT
public:
    explicit Alpha(QObject *parent = nullptr);
    void attivaAllarme();

signals:
    void allarme(QString messaggio);

};

#endif // ALPHA_H
