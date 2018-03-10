#include "accountswidget.h"

#include <neopluto/database.hpp>

#include <QVBoxLayout>
#include <QLabel>

AccountsWidget::AccountsWidget(std::shared_ptr<npl::database> db_, QWidget *parent) :
    QWidget(parent), db(std::move(db_))
{
    const auto layout = new QVBoxLayout;

    db->retrieve_accounts([layout](npl::account account) {
        layout->addWidget(new QLabel(account.retrieve_name().c_str()));
        return true;
    });

    setLayout(layout);
}
