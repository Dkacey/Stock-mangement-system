#ifndef STOCKLIST_H
#define STOCKLIST_H

#include <QList>

class Stock;

class StockList
{
public:
    static StockList* getInstance();
    static void deleteInstance();

    void addStock(Stock* s);

    QList<Stock*> returnList(QString stockType) const;

private:
    StockList();
    ~StockList();

    static StockList* onlyInstance;

    QList<Stock*> listConfectionery;
    QList<Stock*> listReadingMaterial;
};

#endif // STOCKLIST_H
