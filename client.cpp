#include "client.h"

Client::Client(QObject *parent)
    : QObject(parent), socket(new QTcpSocket(this)) {
    // Connexion des signaux aux slots
    connect(socket, &QTcpSocket::connected, this, &Client::onConnected);
    connect(socket, &QTcpSocket::readyRead, this, &Client::onReadyRead);
}

void Client::connectToServer(const QString &host, quint16 port) {
    qDebug() << "Connexion au serveur " << host << ":" << port;
    socket->connectToHost(host, port);

    if (!socket->waitForConnected(1)) {
        qDebug() << "Erreur : Impossible de se connecter au serveur.";
        return;
    }
}

void Client::onConnected() {
    qDebug() << "Connecté au serveur !";
    qDebug() << "En attente des messages du serveur...";
}

void Client::onReadyRead() {
    // Lire les données reçues
    QByteArray data = socket->readAll();
    qDebug() << "Signal readyRead capturé ! Données reçues :" << data.trimmed();

    // Vérifiez si le message est "bonjour"
    if (data.trimmed() == "bonjour") {
        // Répondre "hello"
        QByteArray response = "hello\n";
        socket->write(response);
        socket->flush();
        qDebug() << "Réponse envoyée :" << response.trimmed();
    } else {
        qDebug() << "Message inattendu reçu : " << data.trimmed();
    }
}
