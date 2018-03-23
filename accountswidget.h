#ifndef ACCOUNTSWIDGET_H
#define ACCOUNTSWIDGET_H

#include <QWidget>

class Database;
class NewAccountWidget;
class QVBoxLayout;
class AccountWidget;

class AccountsWidget : public QWidget
{
    Q_OBJECT
public:
    explicit AccountsWidget(Database* db, QWidget *parent = nullptr);

signals:

public slots:
    void refresh_accounts(QWidget* = nullptr);

private slots:
    void create_account(const QString&name);

private:
    Database *db;
    QVBoxLayout *list_layout;
    NewAccountWidget *new_widget;
    QVector<AccountWidget*> account_widgets;
};

#endif // ACCOUNTSWIDGET_H
