/****************************************************************************
**
** SPDX-FileCopyrightText: 2014 Digia Plc and/or its subsidiary(-ies)
** SPDX-License-Identifier: (LGPL-2.0-or-later AND LicenseRef-DigiaQtLGPLException-1.1) OR LicenseRef-DigiaCommercialUsage
** Contact: http://www.qt-project.org/legal
**
** This file is part of Qt Creator.
**
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and Digia.  For licensing terms and
** conditions see http://qt.digia.com/licensing.  For further information
** use the contact form at http://qt.digia.com/contact-us.
**
** GNU Lesser General Public License Usage
** Alternatively, this file may be used under the terms of the GNU Lesser
** General Public License version 2.1 as published by the Free Software
** Foundation and appearing in the file LICENSE.LGPL included in the
** packaging of this file.  Please review the following information to
** ensure the GNU Lesser General Public License version 2.1 requirements
** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
** In addition, as a special exception, Digia gives you certain additional
** rights.  These rights are described in the Digia Qt LGPL Exception
** version 1.1, included in the file LGPL_EXCEPTION.txt in this package.
**
****************************************************************************/

#include <QCoreApplication>

namespace SharedTools {

class QtLocalPeer;

class QtSingleCoreApplication : public QCoreApplication
{
    Q_OBJECT

public:
    QtSingleCoreApplication(int &argc, char **argv);
    QtSingleCoreApplication(const QString &id, int &argc, char **argv);

    bool isRunning();
    [[nodiscard]] QString id() const;
    void setBlock(bool value);

public Q_SLOTS:
    bool sendMessage(const QString &message, int timeout = 5000);


Q_SIGNALS:
    void messageReceived(const QString &message);


private:
    QtLocalPeer* peer;
    bool block = false;
};

} // namespace SharedTools
