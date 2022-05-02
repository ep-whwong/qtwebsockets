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

#ifndef QDEFAULTMASKGENERATOR_P_H
#define QDEFAULTMASKGENERATOR_P_H

//
//  W A R N I N G
//  -------------
//
// This file is not part of the Qt API.  It exists purely as an
// implementation detail.  This header file may change from version to
// version without notice, or even be removed.
//
// We mean it.
//

#include <QtWebSockets/qmaskgenerator.h>

QT_BEGIN_NAMESPACE
class QObject;

class Q_AUTOTEST_EXPORT QDefaultMaskGenerator : public QMaskGenerator
{
    Q_DISABLE_COPY(QDefaultMaskGenerator)

public:
    explicit QDefaultMaskGenerator(QObject *parent = nullptr);
    ~QDefaultMaskGenerator() override;

    bool seed() noexcept override;
    quint32 nextMask() noexcept override;
};

QT_END_NAMESPACE

#endif // QDEFAULTMASKGENERATOR_P_H
