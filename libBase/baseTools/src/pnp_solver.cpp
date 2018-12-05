////////////////////////////////////////////////////////////////////////////////
///Copyright(c)      UESTC ROBOMASTER2019      tool for pnp
///ALL RIGHTS RESERVED
///@file:pnp_solver.cpp
///@brief: 封装pnp解算函数。
///@vesion 1.0
///@author: wyx
///@email: 1418555317@qq.com
///@date: 2018.10.27
///修订历史: 
////////////////////////////////////////////////////////////////////////////////
#include "pnp_solver.h"

PNPSolver::PNPSolver(){}
PNPSolver::~PNPSolver(){}

void PNPSolver::setCameraMatrix(float a, float b, float c, float d, float e, float f, float g, float h, float i){
    camera_matrix = (Mat_<float>(3,3) << a,b,c,d,e,f,g,h,i);
}

void PNPSolver::setDistortionCoef(float a, float b, float c, float d, float e){
    distortion_coef = (Mat_<float>(5,1) << a,b,c,d,e);
}

void PNPSolver::pushPoints3D(double x, double y, double z){
    if(Points3D.size() > 4){
        cout<<"you have selected over four points, check your method in PNPSolver::solvePnP() to ensure your input."<<endl;
    }
    Points3D.push_back(Point3d(x, y, z));
}

void PNPSolver::clearPoints3D(){
    Points3D.clear();
}

void PNPSolver::pushPoints2D(const Point2d points){
    if(Points3D.size()!=0 && Points2D.size()>Points3D.size()){
        cout<<"Points2D.size() is not equal to Points3D.size(), can not push more points."<<endl;
        return;
    }
    Points2D.push_back(points);
}

void PNPSolver::clearPoints2D(){
    Points2D.clear();
}

void PNPSolver::solvePnP(bool useExtrinsicGuess, int flags){
    assert(!camera_matrix.empty() && !distortion_coef.empty());
    if(Points3D.size()==0){
        cout<<"Points3D has not initialized."<<endl;
        return;
    }
    if(Points3D.size() != Points2D.size()){
        cout<<"Points.size() match error."<<endl;
        return;
    }
    cv::solvePnP(Points3D, Points2D, camera_matrix, distortion_coef, rvec, tvec, useExtrinsicGuess, flags);
}

Point3d PNPSolver::getTvec(){
    Point3d temp;
    assert(!tvec.empty());
    //tvec返回的是double类型
    temp.x = tvec.at<double>(0);
    temp.y = tvec.at<double>(1);
    temp.z = tvec.at<double>(2);
    return temp;
}

vector<cv::Point2f> PNPSolver::WorldFrame2ImageFrame(vector<cv::Point3f> WorldPoints)
{
    vector<cv::Point2f> projectedPoints;
    cv::projectPoints(WorldPoints, rvec, tvec, camera_matrix, distortion_coef, projectedPoints);
    return projectedPoints;
}

void PNPSolver::showParams(){
    cout<<"-----------------------------"<<endl;
    cout<<"PNPSovler's params:"<<endl;
    cout<<"camera_matrix:   "<<camera_matrix<<endl;
    cout<<"distortion_coef:   "<<distortion_coef<<"\n"<<endl;
    cout<<"Points3D:\n"<<Points3D<<"\n"<<endl;
    cout<<"Points2D:\n"<<Points2D<<endl;
    cout<<"-----------------------------"<<endl;
}
