#ifndef UTILS_H
#define UTILS_H

#include <QScrollArea>

template <typename Widget>
static inline auto scrolled(Widget* widget) {
    const auto area = new QScrollArea;
    area->setWidget(widget);
    area->setWidgetResizable(true);
    return area;
}

#endif // UTILS_H
