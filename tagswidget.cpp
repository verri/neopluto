#include "tagswidget.h"

#include "database.h"

#include <neopluto/database.hpp>

#include <QVBoxLayout>
#include <QLabel>

TagsWidget::TagsWidget(Database *db_, QWidget *parent) :
    QWidget(parent), db(db_)
{
    const auto layout = new QVBoxLayout;

    db->get()->retrieve_tags([layout](npl::tag tag) {
        layout->addWidget(new QLabel(tag.retrieve_name().c_str()));
        return true;
    });

    setLayout(layout);
}
