#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <neopluto/database.hpp>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    // Old style because moc is dumb.
    void new_balance_window();

private:
    auto ui_create_actions() -> void;
    auto ui_create_menus() -> void;

    QTabWidget *tabs;

    QMenu *file_menu;
    QMenu *edit_menu;
    QMenu *import_menu;
    QMenu *view_menu;

    QAction *export_action;
    QAction *quit_action;

    QAction *add_income_action;
    QAction *add_expense_action;
    QAction *add_transfer_action;

    QAction *new_balance_action;

    std::shared_ptr<npl::database> db;
};

#endif // MAINWINDOW_H
