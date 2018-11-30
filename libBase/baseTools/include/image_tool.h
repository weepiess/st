////////////////////////////////////////////////////////////////////////////////
///Copyright(c)      UESTC ROBOMASTER2018      Tool Code for robot
///ALL RIGHTS RESERVED
///@file:image_tool.h
///@brief: 通用图像处理工具类
///@vesion 1.0
///@author: gezp
///@email: 1350824033@qq.com
///@date: 18-6-3
///修订历史：
////////////////////////////////////////////////////////////////////////////////
#include "opencv2/opencv.hpp"
#include "sys/time.h"
#include "time.h"

#ifndef SENTRYDEMO_IMAGE_TOOL_H
#define SENTRYDEMO_IMAGE_TOOL_H

class ImageTool{
public:
    static struct timeval start,end;
    static clock_t currentClock;
public:
    static void showRGBSplitImg(cv::Mat img);
    static void showHSVInRangeImg(cv::Mat img);

    static void drawRotatedRect(cv::Mat &img,cv::RotatedRect r);
    static void draw4Point4f(cv::Mat &img,cv::Point2f point2fs[4]);

    static float calc2PointDistance(cv::Point2f point1,cv::Point2f point2);
    //计算两点间的近似距离，用两个直角边的和近似代替斜边的长度
    static float calc2PointApproDistance(cv::Point2f point1, cv::Point2f point2);
    static float calc2PointAngle(cv::Point2f point1,cv::Point2f point2);
    static float calcTriangleInnerAngle(cv::Point2f vertexPoint,cv::Point2f point1,cv::Point2f point2);

    static double gravityKiller(double z_distance, double y_distance, double bullet_speed, double current_pitch);

    static void timeInit();
    static void timeCout();
    //毫秒计时
    static double timeCount();
    static void timeInitClock();
    static void timeCoutClock();
    static double timeGet();


};


#endif //SENTRYDEMO_IMAGE_TOOL_H

