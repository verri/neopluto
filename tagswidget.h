#ifndef TAGSWIDGET_H
#define TAGSWIDGET_H

#include <QWidget>
#include <memory>

namespace npl
{
class database;
}

class TagsWidget : public QWidget
{
    Q_OBJECT
public:
    explicit TagsWidget(std::shared_ptr<npl::database> db, QWidget *parent = nullptr);

signals:

public slots:

private:
    std::shared_ptr<npl::database> db;
};

#endif // TAGSWIDGET_H
