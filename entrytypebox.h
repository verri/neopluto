#ifndef ENTRYTYPEBOX_H
#define ENTRYTYPEBOX_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>

class Database;
class QComboBox;

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
    void setType(int index);
    void setIncome();
    void setExpense();
    void setTransfer();

private:
    Database *db;
    QComboBox *type_box;
    QComboBox *from_box;
    QComboBox *to_box;
};

#endif // ENTRYTYPEBOX_H
