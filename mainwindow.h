#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

using namespace cv;
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    IplImage* image, *GryImg;
    IplImage* BP[8];
    IplImage* grayscale();
    void BitPlane();
    void process();

private slots:
    void on_pushButton_clicked();

    void on_bit0Bt_clicked();
    void on_bit1Bt_clicked();
    void on_bit2Bt_clicked();
    void on_bit3Bt_clicked();
    void on_bit4Bt_clicked();
    void on_bit5Bt_clicked();
    void on_bit6Bt_clicked();
    void on_bit7Bt_clicked();
    void on_inputBt_clicked();
};

#endif // MAINWINDOW_H
