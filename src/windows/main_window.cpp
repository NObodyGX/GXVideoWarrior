
#include <QLabel>
#include <QPixmap>
#include <QWidget>
#include <QStatusBar>
#include <QString>
#include <QVBoxLayout>
#include <QSplitter>

#include "main_window.h"
#include "src/widgets/video_widget.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    _initUI();
}


void MainWindow::_initUI()
{

    QSplitter* splitter = new QSplitter(Qt::Orientation::Horizontal, this);
    setCentralWidget(splitter);

    VideoWidget* wi = new VideoWidget(this);
    QLabel* lb = new QLabel(this);
    QImage *img = new QImage();
    img->load(":resource/images/open.png");
    lb->setPixmap(QPixmap::fromImage(*img));

    splitter->addWidget(wi);
    splitter->addWidget(lb);

    return ;
}

void MainWindow::showLimitMessage(std::string text, int timeout /*=2000ms*/)
{
    statusBar()->showMessage(QString::fromStdString(text), timeout);
}

void MainWindow::showUnlimitMessage(std::string text)
{
    statusBar()->showMessage(QString::fromStdString(text), 0);
}

MainWindow::~MainWindow()
{
}

