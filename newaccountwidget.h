#ifndef NEWACCOUNTWIDGET_H
#define NEWACCOUNTWIDGET_H

#include <QWidget>

class Database;

class NewAccountWidget : public QWidget
{
    Q_OBJECT
public:
    explicit NewAccountWidget(Database* db_, QWidget *parent = nullptr);

signals:
    void account_created(const QString&);

public slots:

private:
    Database* db;
};

#endif // NEWACCOUNTWIDGET_H
