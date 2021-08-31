#ifndef TOKICOLOR_H
#define TOKICOLOR_H
#include <QRgb>
#include <Eigen/Dense>
using namespace std;
using namespace Eigen;


class ColorSet;
class TokiColor
{
public:
    TokiColor(const QRgb&,char);
    TokiColor();
    //QRgb Raw;//相当于Key
    float c3[3];//三通道的颜色值。可能为RGB,HSV,Lab,XYZ
    float sideSelectivity[2];//记录与result的深度值不同的两个有损优化候选色选择系数（升序排列），Depth=3时无效
    unsigned char sideResult[2];//记录与result的深度值不同的两个有损优化候选色（升序排列），Depth=3时无效
    char ColorSpaceType;
    unsigned char Result;//最终调色结果
    float ResultDiff;
    static bool needFindSide;
    static ColorSet * Basic;
    static ColorSet * Allowed;
    static short DepthIndexEnd[4];
    static unsigned char DepthCount[4];
    unsigned char apply(QRgb);
private:
    unsigned char apply();
    unsigned char applyRGB();
    unsigned char applyRGB_plus();
    unsigned char applyHSV();
    unsigned char applyXYZ();
    unsigned char applyLab_old();
    unsigned char applyLab_new();
    void doSide(VectorXf);
};

#endif // TOKICOLOR_H
