#include "entrydialog.h"

#include "entrytypebox.h"

#include <QDialogButtonBox>
#include <QVBoxLayout>
#include <QDate>
#include <QDateEdit>
#include <QLineEdit>
#include <QDoubleSpinBox>

EntryDialog::EntryDialog(Database* db_, QWidget *parent) : QDialog(parent), db(db_)
{
    date_edit = new QDateEdit(QDate::currentDate());
    date_edit->setDisplayFormat("dd/MM/yyyy");

    desc_edit = new QLineEdit;

    type_box = new EntryTypeBox(db);

    value_spin = new QDoubleSpinBox;
    value_spin->setRange(0.0, std::numeric_limits<double>::max());
    value_spin->setDecimals(2);
    value_spin->setPrefix("$ ");
    value_spin->setSingleStep(1.0);

    /* LabelBox *label_box; */

    button_box = new QDialogButtonBox(QDialogButtonBox::Ok
                                      | QDialogButtonBox::Cancel);

    connect(button_box, &QDialogButtonBox::accepted, this, &QDialog::accept);
    connect(button_box, &QDialogButtonBox::rejected, this, &QDialog::reject);

    auto *const layout = new QVBoxLayout;

    layout->addWidget(date_edit);
    layout->addWidget(desc_edit);
    layout->addWidget(value_spin);
    layout->addWidget(type_box);
    layout->addWidget(button_box);

    setLayout(layout);
}


EntryDialog::EntryDialog(Database* db_, npl::entry entry_, QWidget *parent) : EntryDialog(db_, parent)
{



    entry = std::move(entry_);
}

void EntryDialog::setIncome()
{
    type_box->setIncome();
}

void EntryDialog::setExpense()
{
    type_box->setExpense();
}

void EntryDialog::setTransfer()
{
    type_box->setTransfer();
}
