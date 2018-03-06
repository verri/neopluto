#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    auto ui_create_actions() -> void;
    auto ui_create_menus() -> void;

    QMenu *file_menu;
    QMenu *edit_menu;
    QMenu *view_menu;

    QAction *export_action;
    QAction *quit_action;

    QAction *add_income_action;
    QAction *add_expense_action;
    QAction *add_transfer_action;

    QAction *create_balance_action;
};

#endif // MAINWINDOW_H
