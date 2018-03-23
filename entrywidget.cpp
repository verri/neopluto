#include "entrywidget.h"

#include "utils.h"
#include "database.h"

EntryWidget::EntryWidget(Database *db_, npl::entry ent_, QWidget *parent) :
    QWidget(parent), db(db_), entry(std::move(ent_))
{

}

auto EntryWidget::erase_entry(bool) -> void
{
    if (are_you_sure_message(this) == QMessageBox::Cancel)
        return;

    entry.erase();
    db->mark_modification(this);
}
