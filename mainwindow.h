#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class Database;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    // Old style because moc is dumb.
    void new_balance_window();
    void new_accounts_window();
    void new_tags_window();

private:
    auto ui_create_actions() -> void;
    auto ui_create_menus() -> void;

    Database *db;

    QTabWidget *tabs;

    QMenu *file_menu;
    QMenu *edit_menu;
    QMenu *import_menu;
    QMenu *view_menu;

    QAction *export_action;
    QAction *close_tab_action;
    QAction *quit_action;

    QAction *add_income_action;
    QAction *add_expense_action;
    QAction *add_transfer_action;

    QAction *view_balance_action;
    QAction *view_accounts_action;
    QAction *view_tags_action;
};

#endif // MAINWINDOW_H
