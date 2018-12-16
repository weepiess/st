////////////////////////////////////////////////////////////////////////////////
///Copyright(c)      UESTC ROBOMASTER2019      Base aim for all aim
///ALL RIGHTS RESERVED
///@file:base_aim.h
///@brief: 瞄准基类头文件，封装基本瞄准函数。
///@vesion 1.0
///@author: wyx
///@email: 1418555317@qq.com
///@date: 2018.10.27
///修订历史：
////////////////////////////////////////////////////////////////////////////////
#ifndef BASE_AIM_H
#define BASE_AIM_H

#include <opencv2/opencv.hpp>
#include <pnp_solver.h>
#include <basic_tool.h>
#include <iostream>

using namespace cv;
using namespace std;

//aim()返回的结果标志位
typedef enum: unsigned char{
    AIM_TARGET_FOUND,
    AIM_TARGET_NOT_FOUND,
    AIM_IMAGE_ERROR
}AimResult;

//装甲板
struct Armor{
    bool is_big_armor;
    cv::RotatedRect light_bar_pairs[2];

    Armor(const cv::RotatedRect& rect1, const cv::RotatedRect& rect2){
        is_big_armor = false;
        light_bar_pairs[0] = rect1;
        light_bar_pairs[1] = rect2;
    }
};

class BaseAim{
public:
    /** 是否使用roi
     * @param: is_use_roi, 是否使用roi
     */
    void setUseRoi(bool is_use_roi);

    /** 选择跟踪的装甲板下标
     * @param: armor_index, 装甲板下标
     */
    void setChooseArmorIndex(int armor_index);

protected:
    /** 纠正矩形拟合后矩形的宽不一定比长短的情况
     * @param: rect, 需要进行变换的旋转矩形，一般为矩形拟合后调用
     * @return: RotatedRect, 变换后的旋转矩形，长一定比宽长
     */
    cv::RotatedRect adjustRRect(const cv::RotatedRect & rect);

    /** 纠正椭圆拟合后的角度问题
     * @param: rect, 传入的椭圆拟合出来的矩形
     * @return:void
     */
    void adjustEllipseAngle(cv::RotatedRect & rect);

    /** 两个旋转矩形顶点依次相连构成四边形
     * @param: left, 左边的旋转矩形
     * @param: right, 右边的旋转矩形
     * @return: RotatedRect, 以两个矩形为对边的旋转矩形
     */
    cv::RotatedRect boundingRRect(const cv::RotatedRect &left, const cv::RotatedRect &right);

    /** 调整rect的大小，使得在接触边界时能够自动贴边
     * @param: rect, 需要调整的rect
     * @param: image_size, 图像分辨率
     * @return: bool, 如果调整到rect.width<0或者rect.height<0则返回false, 否则返回true
     */
    bool makeRectSafe(Rect & rect, const Size& image_size);

    /** 扩大rect
     * @param: rect, 需要扩大的rect
     * @return: bool, 内部调用makeRectSafe(Rect &rect)返回是否还能调整大小
     */
    bool broadenRect(int widthAdded, int heightAdded, Rect &rect, const Size& image_size);

protected:
    //每一个子类中都默认拥有，方便调用pnp解算
    PNPSolver pnp_solver;

    //是否使用roi
    bool use_roi = false;

    //选中跟踪的装甲板下标
    int choose_armor_index;
};

#endif