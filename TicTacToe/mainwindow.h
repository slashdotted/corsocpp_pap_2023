#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void cellaCliccata();
    void nuovaPartita();

signals:
    void fineTurno(QString prossimoGiocatore);

private:
    Ui::MainWindow *ui;
    QPushButton *cella[3][3];
    QString giocatore{"X"};
};
#endif // MAINWINDOW_H
