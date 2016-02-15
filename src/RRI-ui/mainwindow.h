#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDir>
#include <QFileDialog>
#include <rricore.h>

namespace Ui {
class MainWindow;
enum State { DEFAULT, NEWFILE, TIMESLICE, PARAMETER, NOCHANGE };
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_actionOpen_triggered();

    void on_timeSliceNumberSpinBox_editingFinished();

    void on_runButton_clicked();

    void on_homeButton_clicked();

    void on_previousButton_clicked();

    void on_nextButton_clicked();

private:
    Ui::MainWindow *ui;
    Ui::State state;
    QString currentFile;
    RRICore core;

};

#endif // MAINWINDOW_H
