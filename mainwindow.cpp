#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setCentralWidget(ui->textEdit);
}

MainWindow::~MainWindow()
{
    delete ui;
}

/*
*
* File menu items
*
*/

// new
void MainWindow::on_actionNew_triggered()
{
    mFilename = "";
    ui->textEdit->setPlainText("");
}

// open
void MainWindow::on_actionOpen_triggered()
{
    QString file = QFileDialog::getOpenFileName(this, "Open a file");

    if(!file.isEmpty()) {
        QFile sFile(file);

        if(sFile.open(QFile::ReadOnly | QFile::Text)) {

            mFilename = file;
            QTextStream in(&sFile);
            QString text = in.readAll();
            sFile.close();

            ui->textEdit->setPlainText(text);
        }
    }
}


// save
void MainWindow::on_actionSave_triggered()
{

    // test for file name
    QFile sFile(mFilename);

    if(mFilename.isEmpty()){

        on_actionSave_As_triggered();

    } else {

        if(sFile.open(QFile::WriteOnly | QFile::Text)) {
            QTextStream out(&sFile);

            out << ui->textEdit->toPlainText();

            sFile.flush();
            sFile.close();
        }

    }


}

// save as
void MainWindow::on_actionSave_As_triggered()
{
    QString file = QFileDialog::getSaveFileName(this, "Save file as:");

    if(!file.isEmpty()) {

        mFilename = file;
        on_actionSave_triggered();

    }
}

// exit program
void MainWindow::on_actionExit_triggered()
{

}

 /*
 *
 * Edit menu items
 *
 */

void MainWindow::on_actionCopy_triggered()
{
    ui->textEdit->copy();
}

void MainWindow::on_actionCut_triggered()
{
     ui->textEdit->cut();
}

void MainWindow::on_actionPaste_triggered()
{
     ui->textEdit->paste();
}

void MainWindow::on_actionUndo_triggered()
{
    ui->textEdit->undo();
}

void MainWindow::on_actionRedo_triggered()
{
    ui->textEdit->redo();
}

/*
*
* About menu items
*
*/
void MainWindow::on_actionAbout_QCode_triggered()
{

}
