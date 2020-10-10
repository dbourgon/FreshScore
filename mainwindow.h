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
