////////////////////////////////////////////////////////////////////////////////
///Copyright(c)      UESTC ROBOMASTER2018      Tool Code for robot
///ALL RIGHTS RESERVED
///@file:basic_tool.h
///@brief: 无。
///@vesion 1.0
///@author: gezp
///@email: 1350824033@qq.com
///@date: 18-6-13
///修订历史：
////////////////////////////////////////////////////////////////////////////////

#ifndef BASIC_TOOL_H
#define BASIC_TOOL_H

#include "opencv2/opencv.hpp"

class BasicTool{
public:
    static double gravityKiller(double z_distance, double y_distance, double bullet_speed, double current_pitch);

    static float calc2PointDistance(cv::Point2f point1,cv::Point2f point2);
    //计算两点间的近似距离，用两个直角边的和近似代替斜边的长度
    static float calc2PointApproDistance(cv::Point2f point1, cv::Point2f point2);

    static float calc2PointAngle(cv::Point2f point1,cv::Point2f point2);

    static float calcTriangleInnerAngle(cv::Point2f vertexPoint,cv::Point2f point1,cv::Point2f point2);
};

#endif //SENTRYDEMO_BASIC_TOOL_H
