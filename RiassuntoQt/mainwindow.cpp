#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "beta.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow{parent}, ui{new Ui::MainWindow}, alpha{nullptr}
{
    ui->setupUi(this);
    connect(ui->actionSaluta, SIGNAL(triggered()), this, SLOT(saluta()));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    // Crea oggetto alpha
    if (!alpha) {
        alpha = new Alpha{this};
        for(int i{0}; i<10; ++i) {
            auto b{new Beta(alpha)};
            b->setObjectName(QString{"Beta_%1"}.arg(i));
            connect(alpha, SIGNAL(allarme(QString)), b, SLOT(riceviAllarme(QString)));
            qDebug() << "Creazione di Beta";
            for (int j{0}; j <10; ++j) {
                auto a{new Alpha(b)};
            }
        }
        alpha->attivaAllarme();
    }
}


void MainWindow::on_pushButton_2_clicked()
{
    delete alpha;
    alpha = nullptr;
}


void MainWindow::on_pushButton_3_clicked()
{
    if (alpha) {
        qDebug() << "I figli di Alpha sono:";
        for (const auto& c : alpha->children()) {
            qDebug() << c->objectName();
        }
    }
}

static void foo(const Alpha& x) {
    // ...
}

static void bar(Alpha x) {
    // ...
}


void MainWindow::on_pushButton_4_clicked()
{
    Alpha a;
    foo(a);
    // bar(a); // Non posso copiare
}

void MainWindow::saluta()
{
    qDebug() << "Ciao";
}

