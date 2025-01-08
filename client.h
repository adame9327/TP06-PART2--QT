#ifndef CLIENT_H
#define CLIENT_H

#include <QObject>
#include <QTcpSocket>
#include <QDebug>

class Client : public QObject {
    Q_OBJECT

public:
    explicit Client(QObject *parent = nullptr);
    void connectToServer(const QString &host, quint16 port);

private slots:
    void onConnected();
    void onReadyRead();

private:
    QTcpSocket *socket;
};

#endif // CLIENT_H
