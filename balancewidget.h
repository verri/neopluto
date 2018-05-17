#ifndef BALANCEWIDGET_H
#define BALANCEWIDGET_H

#include <QWidget>

class Database;

class BalanceWidget : public QWidget
{
    Q_OBJECT
public:
    explicit BalanceWidget(Database* db_, QWidget *parent = nullptr);

signals:

public slots:

private:
    Database* db;
};

#endif // BALANCEWIDGET_H
