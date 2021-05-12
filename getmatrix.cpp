#include "getmatrix.h"

GetMatrix::GetMatrix(QString t)
{
    address = t;
}

int GetMatrix::checkMatrix()
{
    col.clear();
    QFile file(address);
    if (!file.open(QIODevice::ReadOnly))
    {
        qWarning("File wasn't open");
        return 1;//файл не открылся
    }
    else
    {
        QTextStream in(&file);
        int columnCount = 0;
        int rowCount = 0;
        QString columnLine = in.readLine();
        for (auto t:columnLine)
        {
            if (t == ' ')
                columnCount++;
        }
        columnCount--;//в начале строки два пробела чтобы всё нормально выглядело убираем 1
        while (!in.atEnd()) {
            QString temp = in.readLine();
            QVector<int> rows;
            for (int i = 1; i < temp.size(); i++)
            {
                if (temp.at(i) != '|')
                {
                    rows.push_back(temp[i].digitValue());
                    if ((temp[i].digitValue() > 1) || (temp[i].digitValue() < 0))
                    {
                        qWarning("Not 0 or 1");
                        col.clear();
                        return 2;//значения в матрице смежности не равны 0 или 1
                    }
                }

            }
            col.push_back(rows);
            rowCount++;
        }
        if(rowCount!=columnCount)
        {
            qWarning("Matrix not square");
            col.clear();
            return 3;//матрица не симметрична
        }
    }
    return 0;
}

QVector <QVector<int>> GetMatrix::getFullMatrix()
{
    return col;
}
