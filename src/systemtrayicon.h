/*
    <one line to give the program's name and a brief idea of what it does.>
    Copyright (C) 2011  Tirtha Chatterjee <email>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/


#ifndef SYSTEMTRAYICON_H
#define SYSTEMTRAYICON_H

#include <QtGui/QIcon>
#include <QtGui/QSystemTrayIcon>

class SystemTrayIcon : public QSystemTrayIcon
{
public:
    SystemTrayIcon(QObject* parent = 0);

public slots:
    void informLocalChange(QString message = "");
    void informRemoteChange(QString message = "");

private slots:
    void setupMenu();

protected:
    QIcon m_defaultIcon;
    QIcon m_sendingIcon;
    QIcon m_fetchingIcon;
};

#endif // SYSTEMTRAYICON_H
