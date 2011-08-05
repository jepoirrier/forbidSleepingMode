/**
 * @file
 * @author  Jean-Etienne Poirrier <jepoirrier@gmail.com>
 * @version 0.2
 *
 * @section LICENSE
 *
 * This file is part of ForbidSleepingMode.
 *
 * ForbidSleepingMode is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * ForbidSleepingMode is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with ForbidSleepingMode. If not, see <http://www.gnu.org/licenses/>.
 *
 * @section DESCRIPTION
 *
 * Main window and call to kernel32 SetThreadExecutionState function
 */

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
  void btnStartStop_clicked();
  void timerDone();

private:
    Ui::MainWindow *ui;
    QTimer *myTimer;
};

#endif // MAINWINDOW_H
