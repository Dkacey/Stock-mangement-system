#include "stockfactory.h"
#include "confectionery.h"
#include "readingmaterial.h"

StockFactory::StockFactory() {}

Stock* StockFactory::createStock(QString stockType, QString i, int q, QString other)
{
    if (stockType == "Confectionery")
        return new Confectionery(i, q, other.toInt());
    else if (stockType == "ReadingMaterial")
        return new ReadingMaterial(i, q, other);
    return nullptr;
}
