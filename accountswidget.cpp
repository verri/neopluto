#include "accountswidget.h"

#include "database.h"

#include <neopluto/database.hpp>

#include <QVBoxLayout>
#include <QLabel>

AccountsWidget::AccountsWidget(Database *db_, QWidget *parent) :
    QWidget(parent), db(db_)
{
    const auto layout = new QVBoxLayout;

    db->get()->retrieve_accounts([layout](npl::account account) {
        layout->addWidget(new QLabel(account.retrieve_name().c_str()));
        return true;
    });

    setLayout(layout);
}
