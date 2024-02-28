#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    socket = new QTcpSocket(this);
    connect(socket, &QTcpSocket::readyRead, this, &MainWindow::slotReadyRead);
    //Typically, you would connect the readyRead() signal to a slot and read all available data there.
    connect(socket, &QTcpSocket::disconnected, socket, &QTcpSocket::deleteLater);
    connect(socket, &QTcpSocket::connected, this, &MainWindow::slotInfo);
    nextBlockSize = 0;
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    socket->connectToHost("192.168.0.19", 2323); //Attempts to make a connection to hostName on the given port.
}

void MainWindow::slotInfo()
{
    qDebug() << "INFORMATION ABOUT CLIENT CONNECTION SOCKET";
    qDebug() << "socketDescriptor()" << socket->socketDescriptor();
    qDebug() << "isValid()" << socket->isValid();
    qDebug() << "PeerPort()" << socket->peerPort() << "PeerAddress()" << socket->peerAddress() << "PeerName()" << socket->peerName();
    qDebug() << "localPort()" << socket->localPort() << "localAddress()" << socket->localAddress();
}

void MainWindow::SendToServer(QString str)
{
    //Read or write data by calling read() or write(), or use the convenience functions readLine() and readAll().
    Data.clear();
    QDataStream out(&Data, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_5_15);
    out << quint16(0) << QTime::currentTime() << str;
    out.device()->seek(0); // This function sets the current position to pos
    out << quint16(Data.size() - sizeof(quint16)); // Lenght of send block
    //qDebug() << "out" << out.;
    qDebug() << "Data to server" << socket->write(Data);
    socket->write(Data); // QAbstractSocket remembers the address and port passed to connectToHost(), and functions like read() and write() use these values.
    ui->lineEdit->clear();
    // The readyRead() signal is emitted every time a new chunk of data has arrived
}

void MainWindow::slotReadyRead()
{
    QDataStream in(socket);
    in.setVersion(QDataStream::Qt_5_15);
    if(in.status() == QDataStream::Ok)
    {
        for(;;)
        {
            if(nextBlockSize == 0)
            {
                if(socket->bytesAvailable() < 2)
                {
                    break;
                }
                in >> nextBlockSize;
                qDebug() << "nextBlockSize client" << nextBlockSize;
            }
            if(socket->bytesAvailable() < nextBlockSize)
            {
                break;
            }
            QString str;
            QTime time;
            in >> time >> str;
            nextBlockSize = 0;
            qDebug() << "Data client" << str;
            ui->textBrowser->append(time.toString() + " " + str);
        }
    }
    else
    {
        ui->textBrowser->append("read error");
    }
}


void MainWindow::on_pushButton_2_clicked()
{
    SendToServer(ui->lineEdit->text());
}


void MainWindow::on_lineEdit_returnPressed()
{
    SendToServer(ui->lineEdit->text());
}

