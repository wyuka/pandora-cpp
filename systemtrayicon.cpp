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
#include "systemtrayicon.h"

//local includes
#include "application.h"
#include "watcher.h"

//Qt includes
#include <QtGui/QAction>
#include <QtGui/QIcon>
#include <QtGui/QMenu>
#include <QtGui/QSystemTrayIcon>

SystemTrayIcon::SystemTrayIcon(QObject* parent)
        : QSystemTrayIcon(parent)
{
    m_defaultIcon.addFile("data/pandora.svg"); // TODO find a better way to do this
    setIcon(m_defaultIcon);

    setupMenu();

    show();
}


void SystemTrayIcon::setupMenu()
{
    QMenu* menu = new QMenu();

    QAction* quitAction = new QAction(tr("&Quit"), this);
    connect(quitAction, SIGNAL(triggered()), qApp, SLOT(quit()));
    menu->addAction(quitAction);

    setContextMenu(menu);
}


void SystemTrayIcon::informLocalChange(QString message)
{
    if (message.isNull() || message.isEmpty())
    {
        showMessage(tr("Local Changes Detected"), tr("Changes have been detected in your local Pandora files.  Syncing with server to match local copy..."));
    }
    else
    {
        showMessage(("Local Changes Detected"), message);
    }
}


void SystemTrayIcon::informRemoteChange(QString message)
{
    
    if (message.isNull() || message.isEmpty())
    {
        showMessage("Remote Changes Detected", "Changes have been detected in the remote server. Syncing local copy to match changes...");
    }
    else
    {
        showMessage("Local Changes Detected", message);
    }
}
