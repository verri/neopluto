#include "balancewidget.h"

#include "database.h"

#include <QVBoxLayout>
#include <QLabel>

BalanceWidget::BalanceWidget(Database* db_, QWidget *parent) : QWidget(parent), db(db_)
{
    const auto layout = new QVBoxLayout;

    layout->addWidget(new QLabel("Foo"));
    layout->addWidget(new QLabel("Bar"));

    setLayout(layout);
}
