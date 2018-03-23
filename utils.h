#ifndef UTILS_H
#define UTILS_H

#include <QScrollArea>
#include <QMessageBox>
#include <QString>

template <typename Widget>
static inline auto scrolled(Widget* widget) {
    const auto area = new QScrollArea;
    area->setWidget(widget);
    area->setWidgetResizable(true);
    return area;
}

template <typename Widget>
static inline auto are_you_sure_message(Widget* parent) {
    return QMessageBox::question(parent,
                                 "Are you sure?",
                                 "This change is irreversible.",
                                 QMessageBox::Ok | QMessageBox::Cancel,
                                 QMessageBox::Cancel);
}

#endif // UTILS_H
