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



//pandora includes
#include "pandora_defines.h"

//self includes
#include "application.h"

//local includes
#include "watcher.h"
#include "systemtrayicon.h"

//Qt includes

Application::Application(int& argc, char** argv)
        : QApplication(argc, argv)
{
    m_watcher = new Watcher(this);
    connect(m_watcher,SIGNAL(changesMade()), this, SLOT(localChanged()));
    QTimer::singleShot(1000, this, SLOT(postLaunch()));

    m_sysTray = new SystemTrayIcon(this);

    qDebug() << "In Application ctor";
}


Application::~Application()
{
    m_watcher->unwatch();
    qDebug() << "In Application dtor";
}


void Application::postLaunch()
{
    m_watcher->watchPath("/home/tirtha/pandoratest/");
}


void Application::localChanged()
{
    qDebug() << "local path changed";
    m_sysTray->informLocalChange();
}
