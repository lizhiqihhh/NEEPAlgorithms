#include <cstdio>
#include <cmath>


/**
* 问题一
* 给定一个定义在[L, R]上的单调函数f(x)，求方程f(x)=0的根
* 下面给出单调递增函数的模板代码
* 减函数只需把代码中的 f(mid)>0 改为 f(mid)<0 即可
**/
const double eps = 1e-5; //精度为10^-5
//计算f(x)
double f(double x) {
    return ...;
}
double solve(double L, double R) {
    double left = L, right = R, mid; //[left, right] = [L, R]
    while (left - right > eps) {
        mid = (left + right) / 2; //取left和right的中点
        if (f(mid) > 0)
            right = mid; //往左子区间[left, mid]继续逼近
        else
            left = mid; //往右子区间[mid,right]继续逼近
    }
    return mid; //所返回的当前mid值即为f(x)=0的根
}


/**
* 问题二
* 装水问题
* 思路：在[0, R]范围内对水面高度h进行二分，计算在高度下面积比例r的值
* 需自行推导出h和r的关系式，数学问题
**/
const double PI = acos(-1.0); //PI
const double eps = 1e-5; //精度为10^-5
//计算r=f(h)，由实际含义可知r关于h递增
double f(double R, double h) {
    double alpha = 2 * acos((R - h) / R);
    double L = 2 * sqrt(R * R - (R - h) * (R - h));
    double S1 = alpha * R * R / 2 - L * (R - h) / 2;
    double S2 = PI * R * R / 2;
    return S1 / S2;
}
double solve(double R, double r) {
    double left = 0, right = R, mid; //[left, right]=[0, R]
    while (right - left > eps) {
        mid = (left + right) / 2;
        if (f(R, mid) > r)
            right = mid; //往左子区间[left, mid]继续逼近
        else
            left = mid; //往右子区间[mid,right]继续逼近
    }
    return mid;
}


/**
* 问题三
* 木棒切割问题
* 思路：根据对当前长度L来说能得到的木棒段数k与需要的木棒段数K的大小关系来进行二分
**/
