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


#ifndef APPLICATION_H
#define APPLICATION_H

// Pandora Includes
#include "pandora_defines.h"

// Qt Includes
#include <QtGui/QApplication>

class Watcher;
class SystemTrayIcon;

class Application : public QApplication
{
    Q_OBJECT
public:
    Application(int& argc, char** argv);
    virtual ~Application();

    QString pandoraPath();
signals:
    //void localChanged();

protected slots:
    void localChanged();
    void postLaunch();

protected:
    Watcher* m_watcher;
    SystemTrayIcon* m_sysTray;
};

#endif // APPLICATION_H
