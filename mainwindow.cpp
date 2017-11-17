#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>


using namespace cv;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // read an image

    //cvWaitKey(0); //讓視窗停在畫面
    //cvReleaseImage(&image); //要釋放資源
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_inputBt_clicked()
{
     process();
}

void MainWindow::process()
{
    char filename[100];
    QString getname = ui->FileNameField->text();
    strcpy(filename, getname.toLatin1().data());
    image = cvLoadImage(filename);
    if(!image){
        QMessageBox::information(this, tr("Error!"), tr("Image Not Found!"));
        return ;
    }
    // create image window named "My Image"
    cvNamedWindow("Original Image", CV_WINDOW_AUTOSIZE); //CV_WINDOW_AUTOSIZE 表示保留原有照片大小 相當於值=1
                                                   //cvNamedWindow("lena", CV_WINDOW_AUTOSIZE);  CV_WINDOW_AUTOSIZE 改成 0  則可以改變視窗大小
    cvShowImage("Original Image", image);  //上面建立好視窗後，這裡在視窗內顯示圖片
    BitPlane();
}

void MainWindow::on_pushButton_clicked()
{
       //Gray Scaling
       GryImg = grayscale();
       cvNamedWindow("Gray Scale", CV_WINDOW_AUTOSIZE); //CV_WINDOW_AUTOSIZE 表示保留原有照片大小 相當於值=1
                                                      //cvNamedWindow("lena", CV_WINDOW_AUTOSIZE);  CV_WINDOW_AUTOSIZE 改成 0  則可以改變視窗大小
       cvShowImage("Gray Scale", GryImg);  //上面建立好視窗後，這裡在視窗內顯示圖片
}

IplImage *MainWindow::grayscale()
{
        IplImage* GryImg = cvCreateImage(cvSize(image->width, image->height), image->depth, image->nChannels);
        int height = image->height;
        int width = image->width;
        for (int i = 0; i < height; i++)
        {
            for (int j = 0; j < width; j++)
            {
                CvScalar a = cvGet2D(image, i, j);
                int c = a.val[2] * 0.299 + a.val[1] * 0.587 + a.val[0] * 0.114;

                cvSet2D(GryImg, i, j, CV_RGB(c, c, c));

            }
        }

        return GryImg;
}

void MainWindow::BitPlane()
{
    int height = image->height;
    int width = image->width;
    for (int num = 0; num < 8; num++)
            BP[num] = cvCreateImage(cvSize(width, height), image->depth, image->nChannels);

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            CvScalar a = cvGet2D(image, i, j);
            int c = a.val[2] * 0.299 + a.val[1] * 0.587 + a.val[0] * 0.114;
            for(int k = 0; k < 8; k++)
            {
                int result = (c >> k) & 1;
                if (result == 1)
                    result = 255;
                else
                    result = 0;
                cvSet2D(BP[k], i, j, CV_RGB(result, result, result));
            }

        }
    }
}

void MainWindow::on_bit0Bt_clicked()
{
    cvNamedWindow("Bit-0 Plane", CV_WINDOW_AUTOSIZE); //CV_WINDOW_AUTOSIZE 表示保留原有照片大小 相當於值=1
                                                   //cvNamedWindow("lena", CV_WINDOW_AUTOSIZE);  CV_WINDOW_AUTOSIZE 改成 0  則可以改變視窗大小
    cvShowImage("Bit-0 Plane", BP[0]);  //上面建立好視窗後，這裡在視窗內顯示圖片

}

void MainWindow::on_bit1Bt_clicked()
{
    cvNamedWindow("Bit-1 Plane", CV_WINDOW_AUTOSIZE); //CV_WINDOW_AUTOSIZE 表示保留原有照片大小 相當於值=1
                                                   //cvNamedWindow("lena", CV_WINDOW_AUTOSIZE);  CV_WINDOW_AUTOSIZE 改成 0  則可以改變視窗大小
    cvShowImage("Bit-1 Plane", BP[1]);  //上面建立好視窗後，這裡在視窗內顯示圖片
}

void MainWindow::on_bit2Bt_clicked()
{
    cvNamedWindow("Bit-2 Plane", CV_WINDOW_AUTOSIZE); //CV_WINDOW_AUTOSIZE 表示保留原有照片大小 相當於值=1
                                                   //cvNamedWindow("lena", CV_WINDOW_AUTOSIZE);  CV_WINDOW_AUTOSIZE 改成 0  則可以改變視窗大小
    cvShowImage("Bit-2 Plane", BP[2]);  //上面建立好視窗後，這裡在視窗內顯示圖片

}

void MainWindow::on_bit3Bt_clicked()
{
    cvNamedWindow("Bit-3 Plane", CV_WINDOW_AUTOSIZE); //CV_WINDOW_AUTOSIZE 表示保留原有照片大小 相當於值=1
                                                   //cvNamedWindow("lena", CV_WINDOW_AUTOSIZE);  CV_WINDOW_AUTOSIZE 改成 0  則可以改變視窗大小
    cvShowImage("Bit-3 Plane", BP[3]);  //上面建立好視窗後，這裡在視窗內顯示圖片
}

void MainWindow::on_bit4Bt_clicked()
{
    cvNamedWindow("Bit-4 Plane", CV_WINDOW_AUTOSIZE); //CV_WINDOW_AUTOSIZE 表示保留原有照片大小 相當於值=1
                                                   //cvNamedWindow("lena", CV_WINDOW_AUTOSIZE);  CV_WINDOW_AUTOSIZE 改成 0  則可以改變視窗大小
    cvShowImage("Bit-4 Plane", BP[4]);  //上面建立好視窗後，這裡在視窗內顯示圖片
}

void MainWindow::on_bit5Bt_clicked()
{
    cvNamedWindow("Bit-5 Plane", CV_WINDOW_AUTOSIZE); //CV_WINDOW_AUTOSIZE 表示保留原有照片大小 相當於值=1
                                                   //cvNamedWindow("lena", CV_WINDOW_AUTOSIZE);  CV_WINDOW_AUTOSIZE 改成 0  則可以改變視窗大小
    cvShowImage("Bit-5 Plane", BP[5]);  //上面建立好視窗後，這裡在視窗內顯示圖片


}

void MainWindow::on_bit6Bt_clicked()
{
    cvNamedWindow("Bit-6 Plane", CV_WINDOW_AUTOSIZE); //CV_WINDOW_AUTOSIZE 表示保留原有照片大小 相當於值=1
                                                   //cvNamedWindow("lena", CV_WINDOW_AUTOSIZE);  CV_WINDOW_AUTOSIZE 改成 0  則可以改變視窗大小
    cvShowImage("Bit-6 Plane", BP[6]);  //上面建立好視窗後，這裡在視窗內顯示圖片


}

void MainWindow::on_bit7Bt_clicked()
{
    cvNamedWindow("Bit-7 Plane", CV_WINDOW_AUTOSIZE); //CV_WINDOW_AUTOSIZE 表示保留原有照片大小 相當於值=1
                                                   //cvNamedWindow("lena", CV_WINDOW_AUTOSIZE);  CV_WINDOW_AUTOSIZE 改成 0  則可以改變視窗大小
    cvShowImage("Bit-7 Plane", BP[7]);  //上面建立好視窗後，這裡在視窗內顯示圖片
}


