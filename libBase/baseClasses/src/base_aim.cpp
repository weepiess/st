#include "base_aim.h"

void BaseAim::openPredict(){
    isPredict = true;
}

void BaseAim::setTimeDelay(double timeDelay){
    this->timeDelay = timeDelay;
}

void BaseAim::setEnemyColor(int color){
    params.enemy_color = color;
}

void BaseAim::setImgSize(Size imgSize){
    params.img_width = imgSize.width;
    params.img_height = imgSize.height;
}

void BaseAim::setPitchAndYaw(float pitch, float yaw){
    currPitch = pitch;
    currYaw = yaw;
}

Point2f BaseAim::calPitchAndYaw(float x_offset, float y_offset, float z_offset, bool useExtrinsicGuess, int flags){
    assert(currPitch!=180 && currYaw!=180);
    pnpSolver.solvePnP(useExtrinsicGuess, flags);
	//pnpSolver.showParams();
    pnpSolver.clearPoints2D();
    Point3d tvec = pnpSolver.getTvec();
    
    Point2f angle;
    angle.x = ImageTool::gravityKiller((tvec.z + z_offset)/1000.0, (tvec.y + y_offset)/1000.0, 15, currPitch);
    angle.y = -atanf((tvec.x + x_offset) / (tvec.z + z_offset))*180/CV_PI;
    return angle;
}

Point2f BaseAim::calPitchAndYaw(float x, float y, float z, float x_offset, float y_offset, float z_offset){
    assert(currPitch!=180 && currYaw!=180);
    Point2f angle;
    angle.x = ImageTool::gravityKiller((z + z_offset)/1000.0, (y + y_offset)/1000.0, 15, currPitch);
    angle.y = -atanf((x + x_offset) / (z + z_offset))*180/CV_PI;
    return angle;
}

RotatedRect BaseAim::adjustRRect(const RotatedRect & rect){
    const Size2f & s = rect.size;
    if (s.width < s.height)
        return rect;
    return RotatedRect(rect.center, Size2f(s.height, s.width), rect.angle + 90.0);
}

float BaseAim::adjustEllipseAngle(float angle){
    if(angle >= 0 && angle <= 90)
        return angle;
    return angle-180;
}

RotatedRect BaseAim::boundingRRect(const RotatedRect & left, const RotatedRect & right){
    const Point & pl = left.center, & pr = right.center;
    Point2f center = (pl + pr) / 2.0;
    Size2f wh_l = left.size;
    Size2f wh_r = right.size;
    float width = ImageTool::calc2PointDistance(pl, pr) - (wh_l.width + wh_r.width) / 2.0;
    float height = std::max(wh_l.height, wh_r.height);
    float angle = std::atan2(right.center.y - left.center.y, right.center.x - left.center.x);
    return RotatedRect(center, Size2f(width, height), angle * 180 / CV_PI);
}

bool BaseAim::makeRectSafe(Rect & rect){
    if (rect.x < 0)
        rect.x = 0;
    if (rect.x + rect.width > params.img_width)
        rect.width = params.img_width - rect.x;
    if (rect.y < 0)
        rect.y = 0;
    if (rect.y + rect.height > params.img_height)
        rect.height = params.img_height - rect.y;
    if (rect.width <= 0 || rect.height <= 0)
        return false;
    return true;
}

bool BaseAim::broadenRect(int widthAdded, int heightAdded, Rect &rect){
    rect.x -= widthAdded;
    rect.width += 2*widthAdded;
    rect.y -= heightAdded;
    rect.height += 2*heightAdded;
    return makeRectSafe(rect);
}