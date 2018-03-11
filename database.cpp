#include "database.h"

#include <QStandardPaths>
#include <QDir>

#include <neopluto/database.hpp>

Database::Database(QObject *parent) : QObject(parent)
{
    QDir data_dir(QStandardPaths::writableLocation(QStandardPaths::AppDataLocation));
    if (!data_dir.exists())
        data_dir.mkpath(data_dir.path());

    db_ = npl::database::open(qPrintable(data_dir.filePath("main.db")));
}

auto Database::get() const -> std::shared_ptr<npl::database>
{
    return db_;
}
