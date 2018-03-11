#ifndef ACCOUNTWIDGET_H
#define ACCOUNTWIDGET_H

#include <QWidget>

#include <neopluto/account.hpp>

class QPushButton;
class QLineEdit;
class Database;

class AccountWidget : public QWidget
{
    Q_OBJECT

public:
    AccountWidget(Database* db_, npl::account acc_, QWidget *parent = nullptr);

private slots:
    void toggle_buttons(const QString&);
    void update_account_name(bool);
    void revert_account_name(bool);
    void erase_account(bool);

private:
    Database *db;
    npl::account acc;

    QLineEdit *name_edit;
    QPushButton *update_button;
    QPushButton *revert_button;
    QPushButton *erase_button;

};

#endif // ACCOUNTWIDGET_H
