#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDomDocument>
#include <QDomElement>
#include <QFile>
#include "UDPReceiver/UDPReceiver.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
public slots:
    void generateXML(ShopStruct structShop);

private:
    Ui::MainWindow *ui;
    UDPReceiver *receiverUDP{};
};
#endif // MAINWINDOW_H
