#include "mainwindow.h"

#include "balancewidget.h"
#include "accountswidget.h"
#include "tagswidget.h"
#include "database.h"

#include <neopluto/database.hpp>

#include <QTabWidget>
#include <QMenuBar>
#include <QScrollArea>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    setCentralWidget(tabs = new QTabWidget);
    setMenuBar(new QMenuBar);

    setMinimumWidth(640);
    setMinimumHeight(480);

    ui_create_actions();
    ui_create_menus();

    db = new Database(this);

    tabs->setTabsClosable(true);
    connect(tabs, &QTabWidget::tabCloseRequested, [this](int index) {
        const auto widget = tabs->widget(index);
        tabs->removeTab(index);
        delete widget;
    });
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

    view_balance_action = new QAction(tr("View &balance window"), this);
    view_balance_action->setShortcut(tr("Ctrl+B", "View|Balance"));
    view_balance_action->setStatusTip(tr("Create a new balance view"));
    connect(view_balance_action, &QAction::triggered, this, &MainWindow::new_balance_window);

    view_accounts_action = new QAction(tr("View &accounts window"), this);
    view_accounts_action->setShortcut(tr("Ctrl+A", "View|Accounts"));
    view_accounts_action->setStatusTip(tr("Create a new accounts view"));
    connect(view_accounts_action, &QAction::triggered, this, &MainWindow::new_accounts_window);

    view_tags_action = new QAction(tr("View &tags window"), this);
    view_tags_action->setShortcut(tr("Ctrl+L", "View|Tags"));
    view_tags_action->setStatusTip(tr("Create a new tags view"));
    connect(view_tags_action, &QAction::triggered, this, &MainWindow::new_tags_window);
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
    edit_menu->addSeparator();
    import_menu = edit_menu->addMenu(tr("Im&port"));

    view_menu = menuBar()->addMenu(tr("&View"));
    view_menu->addAction(view_balance_action);
    view_menu->addAction(view_accounts_action);
    view_menu->addAction(view_tags_action);
}

template <typename Widget>
static inline auto scrolled(Widget* widget) {
    const auto area = new QScrollArea;
    area->setWidget(widget);
    area->setWidgetResizable(true);
    return area;
}

auto MainWindow::new_balance_window() -> void
{
    tabs->addTab(scrolled(new BalanceWidget), "Balance");
    tabs->setCurrentIndex(tabs->count() - 1);
}

auto MainWindow::new_accounts_window() -> void
{
    tabs->addTab(scrolled(new AccountsWidget(db)), "Accounts");
    tabs->setCurrentIndex(tabs->count() - 1);
}

auto MainWindow::new_tags_window() -> void
{
    tabs->addTab(scrolled(new TagsWidget(db)), "Tags");
    tabs->setCurrentIndex(tabs->count() - 1);
}
