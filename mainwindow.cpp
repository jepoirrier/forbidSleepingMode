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

#include <QtGui>
#include <QLibrary>

#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow){
    ui->setupUi(this);
    myTimer = new QTimer();
    connect(myTimer, SIGNAL(timeout()), this, SLOT(timerDone()));
}

MainWindow::~MainWindow(){
    delete ui;
}

void MainWindow::btnStartStop_clicked(){
  int minutes = 0;

  if(QString::compare(ui->btnStartStop->text(), "&Start", Qt::CaseInsensitive) == 0) {
    ui->btnStartStop->setText("&Stop");
    minutes = ui->spinBoxInterval->value();

    if(!myTimer->isActive()) {
      myTimer->start(minutes * 1000 * 60);
      ui->spinBoxInterval->setEnabled(false);
      ui->labelWorking->setText("... Working ...");
    } else {
      myTimer->setInterval(minutes * 1000 * 60);
    }
  } else {
    ui->btnStartStop->setText("&Start");

    if(myTimer->isActive()){
      myTimer->stop();
      ui->spinBoxInterval->setEnabled(true);
      ui->labelWorking->setText("");
    }
  }
}

void MainWindow::timerDone(){

  QLibrary library("kernel32.dll");
  if (!library.load())
    qFatal("Library loading failed.");

  typedef uint (*SetThreadExecutionState)(uint esFlag);
  SetThreadExecutionState stes = (SetThreadExecutionState)library.resolve("SetThreadExecutionState");

  stes(0x00000002);

  library.unload();
}
