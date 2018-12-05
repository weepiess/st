#include "kalman_filter_by_opencv.h"

Kalman_filter::Kalman_filter(){}
Kalman_filter::~Kalman_filter(){}

void Kalman_filter::init(int dynamParams,int measureParams ,int controlParams){
    Kf.init(dynamParams,measureParams,controlParams);
    
    Kf.measurementMatrix = measurementMatrix;
    Kf.measurementNoiseCov = measurementNoiseCov;
    Kf.processNoiseCov = processNoiseCov;
    Kf.controlMatrix = controlMatrix;
    setIdentity(Kf.errorCovPost, Scalar::all(1)); 
    
}
void Kalman_filter::set_samplingtime(float dt){
   transitionMatrix=(Mat_<float>(3, 3) <<   
            1,dt,dt*dt/2,   
            0,1,dt, 
            0,0,1);
    Kf.transitionMatrix = transitionMatrix;
}

void Kalman_filter::set_statepost(Mat statePost){
    Kf.statePost=statePost;
}

Mat Kalman_filter::predict(){
    
    return Kf.predict();
}

void Kalman_filter::correct(Mat measurement){
    Kf.correct(measurement);
}