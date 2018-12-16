////////////////////////////////////////////////////////////////////////////////
///Copyright(c)      UESTC ROBOMASTER2018      Tool Code for robot
///ALL RIGHTS RESERVED
///@file:basic_tool.cpp
///@brief: 无。
///@vesion 1.0
///@author: gezp
///@email: 1350824033@qq.com
///@date: 18-6-13
///修订历史：
////////////////////////////////////////////////////////////////////////////////

#include "basic_tool.h"

float BasicTool::calc2PointDistance(cv::Point2f point1, cv::Point2f point2) {
    return sqrt(((point1.x-point2.x)*(point1.x-point2.x)+(point1.y-point2.y)*(point1.y-point2.y)));
}

float BasicTool::calc2PointApproDistance(cv::Point2f point1, cv::Point2f point2){
    return abs(point1.x - point2.x) + abs(point1.y - point2.y);
}

float BasicTool::calc2PointAngle(cv::Point2f point1, cv::Point2f point2) {
    if(point1.x == point2.x){
        return 90;
    } else{
        double k;
        k= -(point1.y - point2.y) / (point1.x - point2.x);//符号取反，图像坐标系和实际坐标系不统一
        return  (float)(atan(k)*180/CV_PI);
    }
}

float BasicTool::calcTriangleInnerAngle(cv::Point2f vertexPoint, cv::Point2f point1, cv::Point2f point2) {
    float a,b,c;//求角C
    float angleC;
    a=calc2PointDistance(vertexPoint,point1);
    b=calc2PointDistance(vertexPoint,point2);
    c=calc2PointDistance(point1,point2);
    angleC=static_cast<float>(acos((a * a + b * b - c * c) / (2 * a * b)) / CV_PI * 180);
    return angleC;
}

double BasicTool::gravityKiller(double z_distance, double y_distance, double bullet_speed, double current_pitch){
    constexpr double GRAVITY = 9.7913;
    double alpha = current_pitch*CV_PI/180;
    double x = -y_distance*sin(alpha)+z_distance*cos(alpha);
    double y = z_distance*sin(alpha)+y_distance*cos(alpha);
    double v = bullet_speed;
    double m = 2*((y*GRAVITY+v*v)-sqrt((y*GRAVITY+v*v)*(y*GRAVITY+v*v)-GRAVITY*GRAVITY*(y_distance*y_distance+z_distance*z_distance)))/(GRAVITY*GRAVITY);
    double time = sqrt(m);
    double beta = asin((2*y-GRAVITY*time*time)/(2*v*time))*180/CV_PI;
    double offset = beta-current_pitch;
    return offset;
}