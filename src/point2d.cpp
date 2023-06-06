#include <iostream>
#include <math.h>

#include "include/point2d.hpp"

namespace stl
{
    Point2D::Point2D() : _x(0), _y(0), _z(0) { }

    Point2D::Point2D(float x, float y, float z) : _x(x), _y(y), _z(z) { }

    Point2D::Point2D(float A[3]) : _x(A[0]), _y(A[1]), _z(A[2]) { }

    Point2D Point2D::operator+(const Point2D inp) 
    {
        Point2D out;

        out.SetX( this->_x + inp.GetX() );
        out.SetY( this->_y + inp.GetY() );
        out.SetZ( this->_z + inp.GetZ() );

        return out;
    }

    Point2D Point2D::operator-(const Point2D inp) 
    {
        Point2D out;

        out.SetX( this->_x - inp.GetX() );
        out.SetY( this->_y - inp.GetY() );
        out.SetZ( this->_z - inp.GetZ() );

        return out;
    }

    Point2D Point2D::operator*(const Point2D inp) 
    {
        Point2D out;

        out.SetX( _x * inp.GetX() );
        out.SetY( _y * inp.GetY() );
        out.SetZ( _z * inp.GetZ() );

        return out;
    }

    float Point2D::sum()
    {
        return GetX() + GetY() + GetZ();
    }

    float Point2D::dot(Point2D a)
    {
        Point2D b = Point2D(_x, _y, _z);
        // std::cout<<b<<a<<std::endl;
        // std::cout<<b*a<<std::endl;
        return (b*a).sum();
    }

    float Point2D::magnitude()
    {
        return sqrt(GetX() * GetX() + GetY() * GetY() + GetZ() * GetZ());
    }

    // stl::operator<<(std::ostream&, stl::Point2D const&)

    // std::ostream& operator<< (std::ostream& out, const Triangle& B)
    // {
    //     out << B.GetT1() << B.GetT2() <<B.GetT3();

    //     return out;
    // }

    std::ostream& operator<< (std::ostream& out, const Point2D& T)
    {
        out << T.GetX() << " " << T.GetY() << " " << T.GetZ() << std::endl;

        return out;
    }
}
