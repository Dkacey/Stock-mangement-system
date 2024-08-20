#include "datadialog.h"
#include <QtWidgets>

DataDialog::DataDialog(QWidget *parent):
    QDialog(parent),
    dataGrid{new QGridLayout(this)},
    itemTypeConfectionery{new QRadioButton("Confectionery")},
    itemTypeReadingMaterial{new QRadioButton("ReadingMaterial")},
    itemName{new QLineEdit},
    itemQuantity{new QSpinBox},
    itemWeight{new QSpinBox},
    itemFrequency{new QLineEdit},
    process{new QPushButton("Process data")}
{
    dataGrid->addWidget(new QLabel{"Complete the required data"}, 0, 0, 1, 2, Qt::AlignHCenter);
    dataGrid->addWidget(new QLabel{"Stock type"}, 1, 0, 2, 1);
    dataGrid->addWidget(itemTypeConfectionery, 1, 1);
    dataGrid->addWidget(itemTypeReadingMaterial, 2, 1);
    itemTypeConfectionery->setChecked(true);
    dataGrid->addWidget(new QLabel{"Name of item:"}, 3, 0);
    dataGrid->addWidget(itemName, 3, 1);
    dataGrid->addWidget(new QLabel{"Number of items:"}, 4, 0);
    dataGrid->addWidget(itemQuantity, 4, 1);
    dataGrid->addWidget(new QLabel{"Confectionery\nItem weight:"}, 5, 0);
    dataGrid->addWidget(itemWeight, 6, 0);
    dataGrid->addWidget(new QLabel{"ReadingMaterial\nItem frequency:"}, 5, 1);
    dataGrid->addWidget(itemFrequency, 6, 1);
    itemFrequency->setEnabled(false);
    dataGrid->addWidget(process, 7, 0, 1, 2, Qt::AlignHCenter);

    itemQuantity->setMinimum(0);
    itemQuantity->setMaximum(10000);
    itemWeight->setMinimum(0);
    itemWeight->setMaximum(10000);

    connect(itemTypeReadingMaterial, &QRadioButton::toggled, this, &DataDialog::manageRadioButtons);
    connect(process, &QPushButton::clicked, this, &DataDialog::processButtonClicked);
}

void DataDialog::manageRadioButtons()
{
    if (itemTypeConfectionery->isChecked())
    {
        itemWeight->setEnabled(true);
        itemFrequency->setEnabled(false);
    }
    else
    {
        itemWeight->setEnabled(false);
        itemFrequency->setEnabled(true);
    }
}

void DataDialog::processButtonClicked()
{
    QStringList data;
    if (itemTypeConfectionery->isChecked())
        data << "Confectionery";
    else
        data << "ReadingMaterial";
    data << itemName->text();
    data << QString::number(itemQuantity->value());
    if (itemTypeConfectionery->isChecked())
        data << QString::number(itemWeight->value());
    else
        data << itemFrequency->text();

    itemName->clear();
    itemQuantity->setValue(0);
    itemWeight->setValue(0);
    itemFrequency->clear();
    itemTypeConfectionery->setFocus();

    emit dataEntered(data);
}
