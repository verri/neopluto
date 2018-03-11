#include "accountswidget.h"

#include "database.h"
#include "accountwidget.h"
#include "newaccountwidget.h"

#include <neopluto/database.hpp>

#include <QVBoxLayout>
#include <QLabel>
#include <QMessageBox>

AccountsWidget::AccountsWidget(Database *db_, QWidget *parent) :
    QWidget(parent), db(db_), vbox_layout(nullptr)
{
    new_widget = new NewAccountWidget(db);
    connect(new_widget, &NewAccountWidget::account_created, this, &AccountsWidget::create_account);

    connect(db, &Database::modified, this, &AccountsWidget::refresh_accounts);

    vbox_layout = new QVBoxLayout;
    vbox_layout->addWidget(new_widget);
    vbox_layout->addStretch();
    setLayout(vbox_layout);

    refresh_accounts();
}

void AccountsWidget::create_account(const QString& name)
{
    try {
        db->get()->create_account(qPrintable(name));
        db->mark_modification(this);
    } catch (std::exception& ex) {
        QMessageBox msg;
        msg.setText(ex.what());
        msg.exec();
        return;
    }
}

void AccountsWidget::refresh_accounts(QWidget *)
{
    for (auto widget : account_widgets)
        delete widget;
    account_widgets.clear();

    db->get()->retrieve_accounts([this](npl::account account) {
        const auto widget = new AccountWidget(db, std::move(account));
        vbox_layout->insertWidget(1, widget);
        account_widgets.append(widget);
        return true;
    });

    // Think a way to remove it afterwards.
    // vbox_layout->addStretch();
}
