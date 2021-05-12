#ifndef GETMATRIX_H
#define GETMATRIX_H
#include <QVector>
#include <QTextStream>
#include <QFile>

class GetMatrix
{
private:
    QVector <QVector<int>> col;
    QString address;
public:
    GetMatrix(QString);
    QVector <QVector<int>> getFullMatrix();
    int checkMatrix();
};

#endif // GETMATRIX_H
