#include "entrytypebox.h"

#include "database.h"

#include <QHBoxLayout>
#include <QComboBox>

#include <neopluto/account.hpp>
#include <neopluto/database.hpp>

EntryTypeBox::EntryTypeBox(Database *db_, QWidget *parent) : QWidget(parent), db(db_)
{
    const auto layout = new QHBoxLayout;

    type_box = new QComboBox;
    from_box = new QComboBox;
    to_box = new QComboBox;

    type_box->insertItem(0, "Income");
    type_box->insertItem(1, "Expense");
    type_box->insertItem(2, "Transfer");

    connect(type_box, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &EntryTypeBox::setType);

    layout->addWidget(type_box);
    layout->addWidget(from_box);
    layout->addWidget(to_box);

    db->get()->retrieve_accounts([this, i = 0](npl::account account) mutable {
        const auto name = account.retrieve_name();
        from_box->insertItem(i, name.c_str());
        to_box->insertItem(i, name.c_str());
        ++i;
        return true;
    });

    setLayout(layout);
    setType(0);
}


void EntryTypeBox::setType(int index)
{
    from_box->setVisible(index != 0);
    to_box->setVisible(index != 1);
}

void EntryTypeBox::setIncome()
{
    setType(0);
    type_box->setCurrentIndex(0);
}

void EntryTypeBox::setExpense()
{
    setType(1);
    type_box->setCurrentIndex(1);
}

void EntryTypeBox::setTransfer()
{
    setType(2);
    type_box->setCurrentIndex(2);
}
