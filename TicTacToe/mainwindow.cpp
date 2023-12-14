#include <QMessageBox>
#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    cella[0][0] = ui->cella00;
    cella[0][1] = ui->cella01;
    cella[0][2] = ui->cella02;
    cella[1][0] = ui->cella10;
    cella[1][1] = ui->cella11;
    cella[1][2] = ui->cella12;
    cella[2][0] = ui->cella20;
    cella[2][1] = ui->cella21;
    cella[2][2] = ui->cella22;

    for(unsigned int r{0}; r< 3; ++r) {
        for(unsigned int c{0}; c< 3; ++c) {
            connect(cella[r][c],SIGNAL(clicked(bool)),this,SLOT(cellaCliccata()));
        }
    }
    connect(ui->actionNewGame,SIGNAL(triggered(bool)),this,SLOT(nuovaPartita()));
    ui->statusbar->showMessage(QString{"Inizia il giocatore %1"}.arg(giocatore));
    connect(this,SIGNAL(fineTurno(QString)),ui->statusbar,SLOT(showMessage(QString)));
    connect(this,SIGNAL(vittoria(QString)), this, SLOT(finePartita(QString)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::cellaCliccata()
{
    QPushButton* btn = dynamic_cast<QPushButton*>(sender());
    if (btn) {
        if (btn->text().isEmpty()) {
            btn->setText(giocatore);
            if (verificaVittoria()) {
                emit vittoria(giocatore);
            } else {
                giocatore = giocatore == "X" ? "O" : "X";
                emit fineTurno(QString{"È il turno di %1"}.arg(giocatore));
            }
        }
    }
}

void MainWindow::nuovaPartita()
{
    for(unsigned int r{0}; r< 3; ++r) {
        for(unsigned int c{0}; c< 3; ++c) {
            cella[r][c]->setText("");
            cella[r][c]->setEnabled(true);
        }
    }
}

void MainWindow::finePartita(const QString &vincitore)
{
    for(unsigned int r{0}; r< 3; ++r) {
        for(unsigned int c{0}; c< 3; ++c) {
            cella[r][c]->setEnabled(false);
        }
    }
    QMessageBox::information(this, "Fine partita",
                             QString{"Il giocatore %1 ha vinto"}.arg(vincitore),
                             QMessageBox::Ok);
}

bool MainWindow::verificaVittoria() const
{
    return (cella[0][0]->text()==cella[0][1]->text() && cella[0][1]->text()==cella[0][2]->text() && cella[0][2]->text() != ""
            ||cella[1][0]->text()==cella[1][1]->text() && cella[1][1]->text()==cella[1][2]->text() && cella[1][2]->text() != ""
            ||cella[2][0]->text()==cella[2][1]->text() && cella[2][1]->text()==cella[2][2]->text() && cella[2][2]->text() != ""
            ||cella[0][0]->text()==cella[1][0]->text() && cella[1][0]->text()==cella[2][0]->text() && cella[2][0]->text() != ""
            ||cella[0][1]->text()==cella[1][1]->text() && cella[1][1]->text()==cella[2][1]->text() && cella[2][1]->text() != ""
            ||cella[0][2]->text()==cella[1][2]->text() && cella[1][2]->text()==cella[2][2]->text() && cella[2][2]->text() != ""
            ||cella[0][0]->text()==cella[1][1]->text() && cella[1][1]->text()==cella[2][2]->text() && cella[2][2]->text() != ""
            ||cella[2][0]->text()==cella[1][1]->text() && cella[1][1]->text()==cella[0][2]->text() && cella[0][2]->text() != "");

}
