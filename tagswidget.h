#ifndef TAGSWIDGET_H
#define TAGSWIDGET_H

#include <QWidget>

class Database;

class TagsWidget : public QWidget
{
    Q_OBJECT
public:
    explicit TagsWidget(Database* db, QWidget *parent = nullptr);

signals:

public slots:

private:
    Database* db;
};

#endif // TAGSWIDGET_H
