#include "aim_predict.h"
using namespace cv;
Aim_predict::Aim_predict(){}
Aim_predict::~Aim_predict(){}

void Aim_predict::model_init(){
    mKf.measurementMatrix=(Mat_<float>(2, 3) <<   
            1,0,0,   
            0,1,0);  
    mKf.measurementNoiseCov=(Mat_<float>(2, 2) <<   
            0.001,0, 
            0,0.001);

    mKf.processNoiseCov=(Mat_<float>(3,3) <<
			100,0,0,
			0,100,0,
			0,0,1); 
    mKf.init(3,2,3);
}

void Aim_predict::reset_kf_statepost(Mat statepost){
    mKf.set_statepost(statepost);
}

Mat Aim_predict::predict(Mat measurement, float dt){
    mKf.set_samplingtime(dt);
    mKf.correct(measurement);
    return mKf.predict();
}
void Aim_predict::clear(){
    mAngle_Velocity.clear();
    mYaw.clear();
    mPredict_Angle.clear();
}
bool Aim_predict::shoot_logic(float initYaw, float angel_velocity, float predict_angle){
    if(mAngle_Velocity.size()<3){
        mAngle_Velocity.push_back(angel_velocity);
        mYaw.push_back(initYaw);
        mPredict_Angle.push_back(predict_angle);
        if(mPredict_Angle.size()==3){
            float iYaw_mean=std::accumulate(std::begin(mYaw),std::end(mYaw),0.0)/3;
            float v_a_mean=std::accumulate(std::begin(mAngle_Velocity),std::end(mAngle_Velocity),0.0)/3;
            float pred_angle_mean=std::accumulate(std::begin(mPredict_Angle),std::end(mPredict_Angle),0.0)/3;
            clear();
            if(v_a_mean<0&&iYaw_mean>0&&pred_angle_mean<0) return true;
            else if(v_a_mean>0&&iYaw_mean<0&&pred_angle_mean>0) return true;
            else if(fabs(iYaw_mean)<=0.003&&fabs(v_a_mean)<=0.003) return true;
            else return false;
        }else return false;
    }else{
        clear();
        return false;
    }
}
