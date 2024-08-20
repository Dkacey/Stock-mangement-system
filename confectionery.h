#ifndef CONFECTIONERY_H
#define CONFECTIONERY_H

#include "stock.h"

class Confectionery : public Stock
{
    Q_OBJECT
public:
    Confectionery();
    Confectionery(QString i, int q, int w);

    int getWeight() const;
    void setWeight(int w);

    QString toString() const;

private:
    int weight;
};

#endif // CONFECTIONERY_H
