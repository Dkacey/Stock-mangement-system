#ifndef READINGMATERIAL_H
#define READINGMATERIAL_H

#include "stock.h"

class ReadingMaterial : public Stock
{
    Q_OBJECT
public:
    ReadingMaterial();
    ReadingMaterial(QString i, int q, QString f);

    QString getFrequency() const;
    void setFrequency(QString f);

    QString toString() const;

private:
    QString frequency;
};

#endif // READINGMATERIAL_H
