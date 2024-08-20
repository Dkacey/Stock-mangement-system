#include "readingmaterial.h"

ReadingMaterial::ReadingMaterial() : Stock{"Unknown", 0}, frequency{"Unknown"}
{}

ReadingMaterial::ReadingMaterial(QString i, int q, QString f) : Stock{i, q}, frequency{f}
{}

QString ReadingMaterial::getFrequency() const
{
    return frequency;
}

void ReadingMaterial::setFrequency(QString f)
{
    frequency = f;
}

QString ReadingMaterial::toString() const
{
    return "Reading material: " + item + ", Quantity: " + QString::number(quantity) + ", Frequency: " + frequency;
}
