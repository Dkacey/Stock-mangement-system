#ifndef DATADIALOG_H
#define DATADIALOG_H

#include <QDialog>

class QRadioButton;
class QLineEdit;
class QSpinBox;
class QGridLayout;
class QPushButton;

class DataDialog : public QDialog
{
    Q_OBJECT
public:
    DataDialog(QWidget *parent = nullptr);

signals:
    void dataEntered(QStringList);

private slots:
    void manageRadioButtons();
    void processButtonClicked();

private:
    QGridLayout *dataGrid;
    QRadioButton *itemTypeConfectionery;
    QRadioButton *itemTypeReadingMaterial;
    QLineEdit *itemName;
    QSpinBox *itemQuantity;
    QSpinBox *itemWeight;
    QLineEdit *itemFrequency;
    QPushButton *process;
};

#endif // DATADIALOG_H
