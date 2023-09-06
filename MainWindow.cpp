#include "MainWindow.h"
#include "./ui_MainWindow.h"

#include <QFileInfo>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    receiverUDP = new UDPReceiver();
    connect(AppEventsEmitter::getEventEmitter(),&AppEventsEmitter::notifyStruct,
            this,&MainWindow::generateXML);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::generateXML(ShopStruct structShop)
{
    // Create a QDomDocument
    QDomDocument xmlDoc;

    // Create the root element
    QDomElement rootElement = xmlDoc.createElement("ModelData");
    xmlDoc.appendChild(rootElement);

    // Create the first-level elements (Books and Magazines) with attributes
    QDomElement booksElement = xmlDoc.createElement("Customer");
    QDomAttr booksAttr = xmlDoc.createAttribute("Customer Name");
    booksAttr.setValue(structShop.customerName);
    booksElement.setAttributeNode(booksAttr);
    rootElement.appendChild(booksElement);

    // Create the second-level elements (Book and Magazine entries) with attributes
    QDomElement bookElement1 = xmlDoc.createElement("Transaction");
    QDomAttr bookAttr1 = xmlDoc.createAttribute("date");
    bookAttr1.setValue(structShop.transactionDate);
    bookElement1.setAttributeNode(bookAttr1);
    booksElement.appendChild(bookElement1);

    // Create third-level elements (Title, Author, IssueDate for each Book and Magazine)
    QDomElement titleElement1 = xmlDoc.createElement("lineItem");
    QDomAttr bookAttr2 = xmlDoc.createAttribute("name");
    bookAttr2.setValue(structShop.typeName);
    bookElement1.setAttributeNode(bookAttr2);

    QDomAttr bookAttr3 = xmlDoc.createAttribute("Type");
    bookAttr3.setValue(structShop.type);
    bookElement1.setAttributeNode(bookAttr3);

    QDomAttr bookAttr4 = xmlDoc.createAttribute("Quantity");
    bookAttr4.setValue(structShop.qty);
    bookElement1.setAttributeNode(bookAttr4);

    booksElement.appendChild(titleElement1);

    // Create third-level elements (Title, Author, IssueDate for each Book and Magazine)


    // Convert the QDomDocument to a QString
    QString xmlString = xmlDoc.toString();

    // Save the XML to a file (optional)
    QFile file("shop.xml");
    if (file.open(QIODevice::WriteOnly)) {
        QTextStream out(&file);
        out << xmlString;
        file.close();
    }

    // Print the generated XML
    //qDebug() << xmlString;
    ui->lblXML->setText(xmlString);
}

