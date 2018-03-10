#include "accountswidget.h"

AccountsWidget::AccountsWidget(std::shared_ptr<npl::database> db, QWidget *parent) :
    QWidget(parent), db(std::move(db))
{

}
