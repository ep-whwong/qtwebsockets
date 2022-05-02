/****************************************************************************
**
** Copyright (C) 2016 Kurt Pattyn <pattyn.kurt@gmail.com>.
** Contact: https://www.qt.io/licensing/
**
** This file is part of the QtWebSockets module of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:COMM$
**
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see https://www.qt.io/terms-conditions. For further
** information use the contact form at https://www.qt.io/contact-us.
**
** $QT_END_LICENSE$
**
**
**
**
**
**
**
**
**
**
**
**
**
**
**
**
**
**
**
******************************************************************************/

#ifndef QQMLWEBSOCKET_H
#define QQMLWEBSOCKET_H

#include <QObject>
#include <QQmlParserStatus>
#include <QtQml>
#include <QScopedPointer>
#include <QtWebSockets/QWebSocket>

QT_BEGIN_NAMESPACE

class QQmlWebSocket : public QObject, public QQmlParserStatus
{
    Q_OBJECT
    Q_DISABLE_COPY(QQmlWebSocket)
    Q_INTERFACES(QQmlParserStatus)

    Q_PROPERTY(QUrl url READ url WRITE setUrl NOTIFY urlChanged)
    Q_PROPERTY(Status status READ status NOTIFY statusChanged)
    Q_PROPERTY(QString errorString READ errorString NOTIFY errorStringChanged)
    Q_PROPERTY(bool active READ isActive WRITE setActive NOTIFY activeChanged)

public:
    explicit QQmlWebSocket(QObject *parent = 0);
    explicit QQmlWebSocket(QWebSocket *socket, QObject *parent = 0);
    ~QQmlWebSocket() override;

    enum Status
    {
        Connecting  = 0,
        Open        = 1,
        Closing     = 2,
        Closed      = 3,
        Error       = 4
    };
    Q_ENUM(Status)

    QUrl url() const;
    void setUrl(const QUrl &url);
    Status status() const;
    QString errorString() const;

    void setActive(bool active);
    bool isActive() const;

    Q_INVOKABLE qint64 sendTextMessage(const QString &message);
    Q_REVISION(1) Q_INVOKABLE qint64 sendBinaryMessage(const QByteArray &message);

Q_SIGNALS:
    void textMessageReceived(QString message);
    Q_REVISION(1) void binaryMessageReceived(QByteArray message);
    void statusChanged(QQmlWebSocket::Status status);
    void activeChanged(bool isActive);
    void errorStringChanged(QString errorString);
    void urlChanged();

public:
    void classBegin() override;
    void componentComplete() override;

private Q_SLOTS:
    void onError(QAbstractSocket::SocketError error);
    void onStateChanged(QAbstractSocket::SocketState state);

private:
    QScopedPointer<QWebSocket> m_webSocket;
    Status m_status;
    QUrl m_url;
    bool m_isActive;
    bool m_componentCompleted;
    QString m_errorString;

    // takes ownership of the socket
    void setSocket(QWebSocket *socket);
    void setStatus(Status status);
    void open();
    void close();
    void setErrorString(QString errorString = QString());
};

QT_END_NAMESPACE

#endif // QQMLWEBSOCKET_H
