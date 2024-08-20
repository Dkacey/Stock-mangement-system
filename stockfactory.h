#ifndef STOCKFACTORY_H
#define STOCKFACTORY_H

#include "stock.h"

class StockFactory
{
public:
    StockFactory();
    Stock* createStock(QString stockType, QString i, int q, QString more);

private:

};

#endif // STOCKFACTORY_H
