#include "accountswidget.h"

#include "database.h"
#include "accountwidget.h"

#include <neopluto/database.hpp>

#include <QVBoxLayout>
#include <QLabel>

AccountsWidget::AccountsWidget(Database *db_, QWidget *parent) :
    QWidget(parent), db(db_)
{
    const auto layout = new QVBoxLayout;

    db->get()->retrieve_accounts([layout](npl::account account) {
        layout->addWidget(new AccountWidget(std::move(account)));
        return true;
    });

    setLayout(layout);
}
