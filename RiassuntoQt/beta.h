#ifndef BETA_H
#define BETA_H

#include <QObject>

class Beta : public QObject
{
    Q_OBJECT
public:
    explicit Beta(QObject *parent = nullptr);
    ~Beta() noexcept;

public slots:
    void riceviAllarme(QString m);

signals:

};

#endif // BETA_H
