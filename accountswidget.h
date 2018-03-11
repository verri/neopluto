#ifndef ACCOUNTSWIDGET_H
#define ACCOUNTSWIDGET_H

#include <QWidget>

class Database;

class AccountsWidget : public QWidget
{
    Q_OBJECT
public:
    explicit AccountsWidget(Database* db, QWidget *parent = nullptr);

signals:

public slots:

private:
    Database *db;
};

#endif // ACCOUNTSWIDGET_H
