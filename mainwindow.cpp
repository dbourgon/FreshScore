//::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
// This file is part of FreshScore.
//::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
// Foobar is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// Foobar is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with FreshScore.  If not, see <https://www.gnu.org/licenses/>.
//::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::	
// Copyright 2020 David Bourgon
//::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->progressBar->setValue(score);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_btnLoss_clicked()
{
    int n = ui->lblLoss->text().toInt();
    n++;
    ui->lblLoss->setText(QString::number(n));

    score--;
    ui->lblScore->setText(QString::number(score));
    scoreColor();

    ui->progressBar->setValue(score);
}

void MainWindow::on_btnWin_clicked()
{
    int n = ui->lblWin->text().toInt();
    n++;
    ui->lblWin->setText(QString::number(n));

    score++;
    ui->lblScore->setText(QString::number(score));
    scoreColor();

    ui->progressBar->setValue(score);
}

void MainWindow::on_actionReset_triggered()
{
    ui->lblWin->setText("0");
    ui->lblLoss->setText("0");
    ui->lblScore->setText("0");
    score = 0;
    ui->progressBar->setValue(score);
    scoreColor();
}

void MainWindow::on_actionQuit_triggered()
{
    MainWindow::close();
}

void MainWindow::scoreColor()
{
    if( ui->lblScore->text().toInt() > 0) {
        ui->lblScore->setStyleSheet("background-color:#023402;");
    } else if (ui->lblScore->text().toInt() < 0) {
        ui->lblScore->setStyleSheet("background-color:#750000;");
    } else {
        ui->lblScore->setStyleSheet("background-color:#2B2B2B;");
    }
}

void MainWindow::on_progressBar_valueChanged(int value)
{
    if( value == ui->progressBar->maximum() ) {
        ui->statusbar->showMessage("You did it!");
    } else {
        ui->statusbar->showMessage(" ");
    }
}

void MainWindow::on_actionSet_Goal_triggered()
{
    bool ok;
    int i = QInputDialog::getInt(this, tr("Set Goal"),
                                 tr("Goal amount:"), 10, 0, 100, 1, &ok);

    if( ok ){
       ui->progressBar->setMaximum(i);
       ui->lblTopGoal->setText(QString::fromStdString("Goal: ") + QString::number(i));
    } else {
        ui->progressBar->setMaximum(10);
    }
}
