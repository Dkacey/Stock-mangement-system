#include "stocklist.h"
#include "stock.h"

StockList* StockList::onlyInstance = nullptr;

StockList* StockList::getInstance()
{
    if (onlyInstance == nullptr)
        onlyInstance = new StockList();
    return onlyInstance;
}

StockList::StockList()
{
}

void StockList::addStock(Stock* s)
{
    const QMetaObject* metaS = s->metaObject();
    if (QString(metaS->className()) == "Confectionery")
        listConfectionery.append(s);
    if (QString(metaS->className()) == "ReadingMaterial")
        listReadingMaterial.append(s);
}

QList<Stock*> StockList::returnList(QString stockType) const
{
    if (stockType == "Confectionery")
        return listConfectionery;
    if (stockType == "ReadingMaterial")
        return listReadingMaterial;
    return QList<Stock*>();
}

void StockList::deleteInstance()
{
    delete onlyInstance;
}

StockList::~StockList()
{
    qDeleteAll(listConfectionery);
    listConfectionery.clear();
    qDeleteAll(listReadingMaterial);
    listReadingMaterial.clear();
}
