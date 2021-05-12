#include "interface.h"

TInterface::TInterface(QWidget *parent)
    : QWidget(parent)
{
    setWindowTitle("Работа №6");
    setFixedSize(300,250);

    open_file_btn = new QPushButton("открыть файл", this);
    open_file_btn->setGeometry(100,150,100,30);

    file_name = new QLabel(this);
    file_name->setGeometry(10,170,300,30);

    sample = new TSample();
    canvas = new TCanvas(sample);
    canvas->setAttribute( Qt::WA_QuitOnClose, false );

    connect(open_file_btn, SIGNAL(pressed()),this,SLOT(openFile()));
}

TInterface::~TInterface()
{
    delete open_file_btn;
    delete file_name;
    delete sample;
    delete canvas;
}

void TInterface::openFile()
{
    QString fname = QFileDialog::getOpenFileName(this, "Откройте файл", "C://");
    QFile file(fname);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
            return;
    QString last_opened_file("Последний открытый файл: ");
    last_opened_file+=fname;
    file_name->setText(last_opened_file);

    GetMatrix matrix(fname);
    int getResult = matrix.checkMatrix();

    if(getResult == 0) //если файл с матрицей корректный
    {
        sample->setGraph(matrix.getFullMatrix());
        canvas->update();
        canvas->show();
    }
    else
    {
        QMessageBox messageBox;
        messageBox.critical(0,"Ошибка","Неверный формат матрицы!");
        messageBox.setFixedSize(500,200);
    }
}
