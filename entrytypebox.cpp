#include "entrytypebox.h"

#include <QHBoxLayout>
#include <QComboBox>
#include <QRadioButton>

EntryTypeBox::EntryTypeBox(Database *db_, QWidget *parent) : QWidget(parent), db(db_)
{
    const auto layout = new QHBoxLayout;
    const auto combo_box = new QComboBox;

    const auto income_button = new QRadioButton(tr("I"));
    const auto expense_button = new QRadioButton(tr("E"));
    const auto transfer_button = new QRadioButton(tr("T"));

    const auto type_widget = new QWidget;

    const auto type_layout = new QHBoxLayout;

    type_layout->addWidget(income_button);
    type_layout->addWidget(expense_button);
    type_layout->addWidget(transfer_button);

    type_widget->setLayout(type_layout);

    layout->addWidget(type_widget);
    layout->addWidget(combo_box);

    setLayout(layout);
}
