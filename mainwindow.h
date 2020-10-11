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

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include <QInputDialog>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    int score = 0;

private slots:

    void on_btnLoss_clicked();

    void on_btnWin_clicked();

    void on_actionReset_triggered();

    void on_actionQuit_triggered();

    void on_progressBar_valueChanged(int value);

    void on_actionSet_Goal_triggered();

private:
    Ui::MainWindow *ui;

    void scoreColor();
};
#endif // MAINWINDOW_H
