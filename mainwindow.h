#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPlainTextEdit>
#include <QList>
class StockList;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void addStock();
    void addStockData(QStringList);
    void listConfectionery();
    void listReadingMaterial();

private:
    QAction *stockAddAction;
    QAction *listConfectioneryAction;
    QAction *listReadingMaterialAction;
    QPlainTextEdit *displayfield;

    StockList *stockList;

    void setupGui();
    void closeEvent(QCloseEvent *event);

};
#endif // MAINWINDOW_H
