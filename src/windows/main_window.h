#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include <QMainWindow>
#include <string>


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void showLimitMessage(std::string text, int timeout=2000);
    void showUnlimitMessage(std::string text);

private:
    void _initUI();
};
#endif // MAIN_WINDOW_H
