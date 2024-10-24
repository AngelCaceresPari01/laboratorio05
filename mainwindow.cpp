#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {

    setWindowTitle("Lista de Países");
    resize(300, 300);
    QWidget *widgetCentral = new QWidget(this);
    QVBoxLayout *layout = new QVBoxLayout(widgetCentral);
    listaPaises = new QListWidget(this);
    listaPaises->addItems({"Argentina", "Francia", "Alemania", "Japón", "México"});
    connect(listaPaises, &QListWidget::itemClicked, this, &MainWindow::mostrarInfo);

    infoLabel = new QLabel("Selecciona un país para ver el idioma y la capital.", this);

    layout->addWidget(listaPaises);
    layout->addWidget(infoLabel);

    widgetCentral->setLayout(layout);
    setCentralWidget(widgetCentral);

    paisesInfo.insert("Argentina", qMakePair(QString("Español"), QString("Buenos Aires")));
    paisesInfo.insert("Francia", qMakePair(QString("Francés"), QString("París")));
    paisesInfo.insert("Alemania", qMakePair(QString("Alemán"), QString("Berlín")));
    paisesInfo.insert("Japón", qMakePair(QString("Japonés"), QString("Tokio")));
    paisesInfo.insert("México", qMakePair(QString("Español"), QString("Ciudad de México")));
}

MainWindow::~MainWindow() {}

void MainWindow::mostrarInfo(QListWidgetItem *item) {
    QString pais = item->text();
    QPair<QString, QString> info = paisesInfo[pais];
    infoLabel->setText(QString("Idioma: %1\nCapital: %2").arg(info.first, info.second));
}
