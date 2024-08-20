#include "confectionery.h"

Confectionery::Confectionery() : Stock{"Unknown", 0}, weight{0}
{}

Confectionery::Confectionery(QString i, int q, int w) : Stock{i, q}, weight{w}
{}

int Confectionery::getWeight() const
{
    return weight;
}

void Confectionery::setWeight(int w)
{
    weight = w;
}

QString Confectionery::toString() const
{
    return "Confectionery: " + item + ", Quantity: " + QString::number(quantity) + ", Weight: " + QString::number(weight);
}
