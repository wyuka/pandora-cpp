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


#ifndef WATCHER_H
#define WATCHER_H

#include <QtCore/QObject>

class QFileSystemWatcher;
class QTimer;

static const int timeToSettle = 1000;

class Watcher : public QObject
{
    Q_OBJECT
public:
    explicit Watcher(QObject* parent = 0);

signals:
    void changesMade();

public slots:
    void watchPath(QString path);
    void unwatch();

protected slots:
    void waitToSettle(QString);

protected:
    QFileSystemWatcher* m_watcher;
    QTimer* m_timer;
    QString m_pathToWatch;
};

#endif // WATCHER_H
