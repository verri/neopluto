#ifndef BALANCEWIDGET_H
#define BALANCEWIDGET_H

#include <QWidget>

class Database;
class EntryWidget;
class QVBoxLayout;

class BalanceWidget : public QWidget
{
    Q_OBJECT
public:
    explicit BalanceWidget(Database* db_, QWidget *parent = nullptr);

signals:

public slots:
    void refresh_entries(QWidget* = nullptr);

private:
    Database* db;
    QVBoxLayout *list_layout;
    QVector<EntryWidget*> entry_widgets;
};

#endif // BALANCEWIDGET_H
