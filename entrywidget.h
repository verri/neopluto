#ifndef ENTRYWIDGET_H
#define ENTRYWIDGET_H

#include <QWidget>

#include <neopluto/entry.hpp>

class QPushButton;
class QLineEdit;
class QDateEdit;
class QDoubleSpinBox;

class Database;
class EntryTypeBox;
class LabelBox;

class EntryWidget : public QWidget
{
    Q_OBJECT
public:
    explicit EntryWidget(Database* db_, npl::entry ent_, QWidget *parent = nullptr);

private slots:
    void erase_entry(bool);

signals:

public slots:

private:
    Database *db;
    npl::entry entry;

    QDateEdit *date_edit;
    QLineEdit *desc_edit;
    EntryTypeBox *type_box;
    QDoubleSpinBox *value_spin;
    LabelBox *label_box;

    QPushButton *update_button;
    QPushButton *revert_button;
    QPushButton *erase_button;
};

#endif // ENTRYWIDGET_H
