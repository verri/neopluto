#ifndef DATABASE_H
#define DATABASE_H

#include <QObject>

#include <memory>

namespace npl {
class database;
}

class Database : public QObject
{
    Q_OBJECT
public:
    explicit Database(QObject *parent = nullptr);

    auto get() const -> std::shared_ptr<npl::database>;

signals:
    void modified(QWidget*);

public slots:
    void mark_modification(QWidget*widget);

private:
    std::shared_ptr<npl::database> db_;
};

#endif // DATABASE_H
