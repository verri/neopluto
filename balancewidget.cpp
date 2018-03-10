#include "balancewidget.h"

#include <QVBoxLayout>
#include <QLabel>

BalanceWidget::BalanceWidget(QWidget *parent) : QWidget(parent)
{
    const auto layout = new QVBoxLayout;

    layout->addWidget(new QLabel("Foo"));
    layout->addWidget(new QLabel("Bar"));

    setLayout(layout);
}
