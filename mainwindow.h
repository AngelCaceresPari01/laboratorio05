#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QListWidget>
#include <QLabel>
#include <QVBoxLayout>
#include <QWidget>

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void mostrarInfo(QListWidgetItem *item);

private:
    QListWidget *listaPaises;
    QLabel *infoLabel;

    // Información de países, idiomas y capitales
    QMap<QString, QPair<QString, QString>> paisesInfo;
};

#endif // MAINWINDOW_H
