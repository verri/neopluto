#ifndef ENTRYDIALOG_H
#define ENTRYDIALOG_H

#include <QDialog>

class QDialogButtonBox;
class Database;
class QDateEdit;
class QLineEdit;
class EntryTypeBox;
class QDoubleSpinBox;
class LabelBox;

#include <neopluto/entry.hpp>

class EntryDialog : public QDialog
{
    Q_OBJECT

public:
    EntryDialog(Database* db_, QWidget *parent = nullptr);
    EntryDialog(Database* db_, npl::entry entry_, QWidget *parent = nullptr);

public slots:
    void setIncome();
    void setExpense();
    void setTransfer();

private:
    Database *db;
    std::optional<npl::entry> entry;

    QDateEdit *date_edit;
    QLineEdit *desc_edit;
    EntryTypeBox *type_box;
    QDoubleSpinBox *value_spin;
    LabelBox *label_box;

    QDialogButtonBox *button_box;
};

#endif // ENTRYDIALOG_H
