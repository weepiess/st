////////////////////////////////////////////////////////////////////////////////
///Copyright(c)      UESTC ROBOMASTER2018      Tool Code for robot
///ALL RIGHTS RESERVED
///@file:image_tool.cpp
///@brief: 无。
///@vesion 1.0
///@author: gezp
///@email: 1350824033@qq.com
///@date: 18-6-3
///修订历史：
////////////////////////////////////////////////////////////////////////////////
#include "image_tool.h"

using namespace std;
using namespace cv;

//绘制旋转矩形
void ImageTool::drawRotatedRect(cv::Mat &img,cv::RotatedRect r){
    RNG rng(12345);
    Scalar color = Scalar( rng.uniform(0, 255), rng.uniform(0,255), rng.uniform(0,255) );
    Point2f rect_points[4];
    r.points( rect_points );
    for( int j = 0; j < 4; j++ )
        line( img, rect_points[j], rect_points[(j+1)%4], color, 1, 8 );
}

//绘制四边形
void ImageTool::draw4Point4f(cv::Mat &img, cv::Point2f *point2fs) {
    RNG rng(12345);
    Scalar color = Scalar( rng.uniform(0, 255), rng.uniform(0,255), rng.uniform(0,255) );
    for( int j = 0; j < 4; j++ )
        line( img, point2fs[j], point2fs[(j+1)%4], color, 1, 8 );
}

void ImageTool::showRGBSplitImg(cv::Mat img){
    Mat bgr[3];
    Mat img_b,img_g,img_r;
    split(img, bgr); //将三个通道的像素值分离
    img_b = bgr[0];
    img_g = bgr[1];
    img_r = bgr[2];
    imshow("img",img);
    imshow("b",img_b);
    imshow("g",img_g);
    imshow("r",img_r);

    //r阈值处理
    Mat imgR_th;
    threshold( img_r, imgR_th,123, 255,CV_THRESH_BINARY );
    imshow("r_th",imgR_th);

    //r-b处理
    Mat imgRsB;
    imgRsB=(img_r-img_b)*10;
    imshow("imgR-B",imgRsB);
    //r-g处理
    Mat imgRsG;
    imgRsG=(img_r-img_g)*10;
    imshow("imgR-G",imgRsG);
    waitKey(0);

}

void ImageTool::showHSVInRangeImg(cv::Mat img) {
    Mat imgHSV;
    cvtColor(img, imgHSV, CV_BGR2HSV);

    int iLowH = 25;
    int iHighH = 67;
    int iLowS = 42;
    int iHighS = 180;

    int iLowV = 0;
    int iHighV = 255;
    namedWindow("Control", CV_WINDOW_AUTOSIZE); //create a window called "Control"
    cvCreateTrackbar("LowH", "Control", &iLowH, 179); //Hue (0 - 179)
    cvCreateTrackbar("HighH", "Control", &iHighH, 179);

    cvCreateTrackbar("LowS", "Control", &iLowS, 255); //Saturation (0 - 255)
    cvCreateTrackbar("HighS", "Control", &iHighS, 255);

    cvCreateTrackbar("LowV", "Control", &iLowV, 255); //Value (0 - 255)
    cvCreateTrackbar("HighV", "Control", &iHighV, 255);

    Mat imgThre;
    while(1){
        inRange(imgHSV, Scalar(iLowH, iLowS, iLowV), Scalar(iHighH, iHighS, iHighV), imgThre);
        imshow("hsv",imgHSV);
        imshow("hsvInRange",imgThre);
        waitKey(1);
    }

    waitKey(0);
}