#include "tagswidget.h"

#include <neopluto/database.hpp>

#include <QVBoxLayout>
#include <QLabel>

TagsWidget::TagsWidget(std::shared_ptr<npl::database> db_, QWidget *parent) :
    QWidget(parent), db(std::move(db_))
{
    const auto layout = new QVBoxLayout;

    db->retrieve_tags([layout](npl::tag tag) {
        layout->addWidget(new QLabel(tag.retrieve_name().c_str()));
        return true;
    });

    setLayout(layout);
}
