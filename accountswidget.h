#ifndef ACCOUNTSWIDGET_H
#define ACCOUNTSWIDGET_H

#include <QWidget>
#include <memory>

namespace npl
{
class database;
}

class AccountsWidget : public QWidget
{
    Q_OBJECT
public:
    explicit AccountsWidget(std::shared_ptr<npl::database> db, QWidget *parent = nullptr);

signals:

public slots:

private:
    std::shared_ptr<npl::database> db;
};

#endif // ACCOUNTSWIDGET_H
