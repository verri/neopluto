#include "entrywidget.h"

#include "utils.h"
#include "database.h"

#include <QDateEdit>
#include <QHBoxLayout>
#include <QDoubleSpinBox>

EntryWidget::EntryWidget(Database *db_, npl::entry ent_, QWidget *parent) :
    QWidget(parent), db(db_), entry(std::move(ent_))
{
    const auto date = entry.retrieve_date();
    date_edit = new QDateEdit(QDate(date.year, date.month, date.day));

    value_spin = new QDoubleSpinBox;

    const auto layout = new QHBoxLayout;

    layout->addWidget(date_edit);
    layout->addWidget(value_spin);

    setLayout(layout);

    /*
     * QDateEdit *date_edit
    QLineEdit *desc_edit;
    EntryTypeBox *type_box;
    QDoubleSpinBox *value_spin;
    LabelBox *label_box;*/


}

auto EntryWidget::erase_entry(bool) -> void
{
    if (are_you_sure_message(this) == QMessageBox::Cancel)
        return;

    entry.erase();
    db->mark_modification(this);
}
