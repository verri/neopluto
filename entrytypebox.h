#ifndef ENTRYTYPEBOX_H
#define ENTRYTYPEBOX_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>

class Database;

namespace npl
{
    class account;
}

class EntryTypeBox : public QWidget
{
    Q_OBJECT
public:
    explicit EntryTypeBox(Database *db_, QWidget *parent = nullptr);

    void setIncome(const npl::account&);
    void setExpense(const npl::account&);
    void setTransfer(const npl::account&, const npl::account&);

signals:

public slots:

private:
    Database *db;
};

#endif // ENTRYTYPEBOX_H
