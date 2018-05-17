#include "balancewidget.h"

#include "database.h"
#include "utils.h"
#include "entrywidget.h"

#include <neopluto/entry.hpp>
#include <neopluto/database.hpp>

#include <QVBoxLayout>
#include <QLabel>

BalanceWidget::BalanceWidget(Database* db_, QWidget *parent) : QWidget(parent), db(db_)
{
    const auto vbox_layout = new QVBoxLayout;
    // vbox_layout->addWidget(new_widget);
    // vbox_layout->addStretch();

    const auto account_list = new QWidget;
    list_layout = new QVBoxLayout;
    list_layout->addStretch();
    account_list->setLayout(list_layout);

    vbox_layout->addWidget(scrolled(account_list));
    setLayout(vbox_layout);

    refresh_entries();
}


void BalanceWidget::refresh_entries(QWidget*)
{
    for (auto widget : entry_widgets)
        delete widget;

    entry_widgets.clear();
    list_layout->removeItem(list_layout->itemAt(0));

    db->get()->retrieve_entries(npl::query{}, [this](npl::entry entry) {
        const auto widget = new EntryWidget(db, std::move(entry));
        list_layout->addWidget(widget);
        entry_widgets.append(widget);
        return true;
    });
    list_layout->addStretch();
}
