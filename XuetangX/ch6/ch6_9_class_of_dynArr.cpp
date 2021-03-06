/*
 * 动态数组类
**/
#include <iostream>
#include <cassert>
#include <utility>

using namespace std;

class Point{
private:
    int x;
    int y;
public:
    Point(int xx, int yy);
    Point();
    ~Point();
    void setXY(int x_coor, int y_coor);
};

class DynPoint{
private:
    int arr_size;
    Point* arr_ptr; // 动态数组的首地址
public:
    DynPoint(int s);
    DynPoint();
    ~DynPoint();
    Point& element(int index);
};

int main(int argc, char** argv)
{
    DynPoint dp(2);
    dp.element(0).setXY(1,2);
    dp.element(2).setXY(2,3);
    return 0;
}

Point::Point(int xx, int yy):x(xx), y(yy)
{
    cout << "constructing point" << endl;
}

Point::Point():Point::Point(0,0)
{}

Point::~Point()
{
    cout << "destructing point" << endl;
}

void Point::setXY(int x_coor, int y_coor)
{
    x = x_coor;
    y = y_coor;
}

DynPoint::DynPoint(int s):arr_size(s)
{
    cout << "requesting!" << endl;
    arr_ptr = new Point[arr_size];
}

DynPoint::DynPoint():DynPoint::DynPoint(1)
{}

DynPoint::~DynPoint()
{
    delete[] arr_ptr;
    cout << "deleting!" << endl;
}

// 返回值类型是 对象的引用
Point& DynPoint::element(int index)
{
    assert(index >= 0 && index < arr_size);
    return arr_ptr[index];
}