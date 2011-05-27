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
#include "watcher.h"

//local includes

//Qt includes
#include <QtCore/QFileSystemWatcher>
#include <QtCore/QTimer>

Watcher::Watcher(QObject* parent)
        : QObject(parent)
{
    m_watcher = new QFileSystemWatcher(this);
    connect(m_watcher, SIGNAL(directoryChanged(QString)), this, SLOT(waitToSettle(QString)));

    m_timer = new QTimer(this);
    m_timer->setInterval(timeToSettle);
    m_timer->setSingleShot(true);
    connect(m_timer, SIGNAL(timeout()), this, SIGNAL(changesMade()));
}


void Watcher::watchPath(QString path)
{
    unwatch();
    m_pathToWatch = path;
    m_watcher->addPath(m_pathToWatch);
}


void Watcher::unwatch()
{
    if (!m_pathToWatch.isNull() && !m_pathToWatch.isEmpty())
    {
        m_watcher->removePath(m_pathToWatch);
        m_pathToWatch = "";
    }
}


void Watcher::waitToSettle(QString)
{
    qDebug() << "waiting for changes to settle";
    m_timer->stop();
    m_timer->start();
}
