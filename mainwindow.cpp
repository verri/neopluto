#include "mainwindow.h"

#include <QTabWidget>
#include <QMenuBar>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    this->setCentralWidget(new QTabWidget);
    this->setMenuBar(new QMenuBar);

    this->ui_create_actions();
    this->ui_create_menus();
}

MainWindow::~MainWindow()
{
}

auto MainWindow::ui_create_actions() -> void
{
    export_action = new QAction(tr("&Export..."), this);
    export_action->setShortcut(tr("Ctrl+E", "File|Export"));
    export_action->setStatusTip(tr("Export database"));
    // connect(export_action, &QAction::triggered, ...)

    quit_action = new QAction(tr("&Quit"), this);
    quit_action->setShortcut(tr("Ctrl+Q", "File|Quit"));
    quit_action->setStatusTip(tr("Exit the application"));
    connect(quit_action, &QAction::triggered, this, &QWidget::close);

    add_income_action = new QAction(tr("Add &income..."), this);
    add_income_action->setShortcut(tr("Ctrl+I", "Edit|Income"));
    add_income_action->setStatusTip(tr("Add a new income entry"));
    // connect(add_income_action, &QAction::triggered, ...)

    add_expense_action = new QAction(tr("Add e&xpense..."), this);
    add_expense_action->setShortcut(tr("Ctrl+X", "Edit|Expense"));
    add_expense_action->setStatusTip(tr("Add a new expense entry"));
    // connect(add_expense_action, &QAction::triggered, ...)

    add_transfer_action = new QAction(tr("Add &transfer..."), this);
    add_transfer_action->setShortcut(tr("Ctrl+T", "Edit|Transfer"));
    add_transfer_action->setStatusTip(tr("Add a new transfer entry"));
    // connect(add_transfer_action, &QAction::triggered, ...)
}

auto MainWindow::ui_create_menus() -> void
{
    file_menu = menuBar()->addMenu(tr("&File"));
    file_menu->addAction(export_action);
    file_menu->addSeparator();
    file_menu->addAction(quit_action);

    edit_menu = menuBar()->addMenu(tr("&Edit"));
    edit_menu->addAction(add_income_action);
    edit_menu->addAction(add_expense_action);
    edit_menu->addAction(add_transfer_action);
}
