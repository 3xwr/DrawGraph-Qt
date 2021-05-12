#ifndef SAMPLE_H
#define SAMPLE_H

#include <QPainter>

class TSample
{
    int count;
     QVector <QVector<int>> graph;
public:
    void setGraph(QVector <QVector<int>>);
    TSample();
    void draw(QPainter*);
};

#endif // SAMPLE_H
