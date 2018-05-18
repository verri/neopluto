#include "entrywidget.h"

#include "utils.h"
#include "database.h"
#include "entrytypebox.h"

#include <QDateEdit>
#include <QHBoxLayout>
#include <QDoubleSpinBox>
#include <QLineEdit>

EntryWidget::EntryWidget(Database *db_, npl::entry ent_, QWidget *parent) :
    QWidget(parent), db(db_), entry(std::move(ent_))
{
    const auto date = entry.retrieve_date();
    date_edit = new QDateEdit(QDate(date.year, date.month, date.day));

    desc_edit = new QLineEdit;
    desc_edit->setText(entry.retrieve_description().c_str());

    type_box = new EntryTypeBox(db);
    if (entry.is_income())
        type_box->setIncome();
    else if (entry.is_expense())
        type_box->setExpense();
    else if (entry.is_transfer())
        type_box->setTransfer();
    else
        throw std::runtime_error{"Invalid entry."};

    value_spin = new QDoubleSpinBox;
    value_spin->setRange(0.0, std::numeric_limits<double>::max());
    value_spin->setDecimals(2);
    value_spin->setSingleStep(1.0);
    value_spin->setValue(entry.retrieve_value() / 100.0);

    /* LabelBox *label_box;*/

    const auto layout = new QHBoxLayout;

    layout->addWidget(date_edit);
    layout->addWidget(desc_edit);
    layout->addWidget(type_box);
    layout->addWidget(value_spin);

    setLayout(layout);
}

auto EntryWidget::erase_entry(bool) -> void
{
    if (are_you_sure_message(this) == QMessageBox::Cancel)
        return;

    entry.erase();
    db->mark_modification(this);
}
