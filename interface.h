#ifndef TINTERFACE_H
#define TINTERFACE_H

#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QFileDialog>
#include <QMessageBox>
#include "getmatrix.h"
#include "sample.h"
#include "canvas.h"

class TInterface : public QWidget
{
    Q_OBJECT

    QPushButton* open_file_btn;
    QLabel* file_name;
    TSample* sample;
    TCanvas* canvas;

public:
    TInterface(QWidget *parent = nullptr);
    ~TInterface();

public slots:
    void openFile();
};
#endif // TINTERFACE_H
