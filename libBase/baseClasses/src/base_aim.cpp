#include "base_aim.h"

RotatedRect BaseAim::adjustRRect(const RotatedRect & rect){
    const Size2f & s = rect.size;
    if (s.width < s.height)
        return rect;
    return RotatedRect(rect.center, Size2f(s.height, s.width), rect.angle + 90.0);
}

void BaseAim::adjustEllipseAngle(cv::RotatedRect & rect){
    if(rect.angle > 90) rect.angle -= 180;
}

RotatedRect BaseAim::boundingRRect(const RotatedRect & left, const RotatedRect & right){
    const Point & pl = left.center, & pr = right.center;
    Point2f center = (pl + pr) / 2.0;
    Size2f wh_l = left.size;
    Size2f wh_r = right.size;
    float width = BasicTool::calc2PointDistance(pl, pr) - (wh_l.width + wh_r.width) / 2.0;
    float height = std::max(wh_l.height, wh_r.height);
    float angle = std::atan2(right.center.y - left.center.y, right.center.x - left.center.x);
    return RotatedRect(center, Size2f(width, height), angle * 180 / CV_PI);
}

bool BaseAim::makeRectSafe(Rect & rect,const Size& image_size){
    if (rect.x < 0)
        rect.x = 0;
    if (rect.x + rect.width > image_size.width)
        rect.width = image_size.width - rect.x;
    if (rect.y < 0)
        rect.y = 0;
    if (rect.y + rect.height > image_size.height)
        rect.height = image_size.height - rect.y;
    if (rect.width <= 0 || rect.height <= 0)
        return false;
    return true;
}

bool BaseAim::broadenRect(int widthAdded, int heightAdded, Rect &rect,const Size& image_size){
    rect.x -= widthAdded;
    rect.width += 2*widthAdded;
    rect.y -= heightAdded;
    rect.height += 2*heightAdded;
    return makeRectSafe(rect, image_size);
}