#include "newaccountwidget.h"

#include "database.h"

#include <QLineEdit>
#include <QPushButton>
#include <QHBoxLayout>

#include <neopluto/database.hpp>

NewAccountWidget::NewAccountWidget(Database* db_, QWidget *parent) : QWidget(parent), db(db_)
{
    const auto button = new QPushButton("Create");
    const auto name_edit = new QLineEdit;

    button->setEnabled(false);

    connect(name_edit, &QLineEdit::textEdited, [this, button](const QString& text) {
        button->setEnabled(!text.isEmpty());
    });

    connect(name_edit, &QLineEdit::returnPressed, button, &QPushButton::click);

    connect(button, &QPushButton::clicked, [this, name_edit, button](bool) {
        emit account_created(name_edit->text());
        name_edit->setText("");
        button->setEnabled(false);
    });

    const auto layout = new QHBoxLayout;

    layout->addWidget(name_edit);
    layout->addWidget(button);

    setLayout(layout);
}
