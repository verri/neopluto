#include "accountwidget.h"

#include "database.h"
#include "utils.h"

#include <QHBoxLayout>
#include <QLineEdit>
#include <QPushButton>

AccountWidget::AccountWidget(Database *db_, npl::account acc_, QWidget *parent)
    : QWidget(parent), db(db_), acc(std::move(acc_))
{
    name_edit = new QLineEdit(acc.retrieve_name().c_str());
    update_button = new QPushButton("Update");
    revert_button = new QPushButton("Revert");
    erase_button = new QPushButton("Erase");

    update_button->setEnabled(false);
    revert_button->setEnabled(false);

    connect(name_edit, &QLineEdit::textEdited, this, &AccountWidget::toggle_buttons);
    connect(update_button, &QPushButton::clicked, this, &AccountWidget::update_account_name);
    connect(revert_button, &QPushButton::clicked, this, &AccountWidget::revert_account_name);
    connect(erase_button, &QPushButton::clicked, this, &AccountWidget::erase_account);

    const auto layout = new QHBoxLayout;

    layout->addWidget(name_edit);
    layout->addWidget(update_button);
    layout->addWidget(revert_button);
    layout->addWidget(erase_button);

    setLayout(layout);
}


void AccountWidget::toggle_buttons(const QString& new_name)
{
    const auto changed = new_name != acc.retrieve_name().c_str();
    update_button->setEnabled(changed);
    revert_button->setEnabled(changed);
}

void AccountWidget::update_account_name(bool)
{
    acc.update_name(qPrintable(name_edit->text()));
    db->mark_modification(this);

    update_button->setEnabled(false);
    revert_button->setEnabled(false);
}

void AccountWidget::revert_account_name(bool)
{
    name_edit->setText(acc.retrieve_name().c_str());
    update_button->setEnabled(false);
    revert_button->setEnabled(false);
}

void AccountWidget::erase_account(bool)
{
    if (are_you_sure_message(this) == QMessageBox::Cancel)
        return;

    acc.erase();
    db->mark_modification(this);
}
