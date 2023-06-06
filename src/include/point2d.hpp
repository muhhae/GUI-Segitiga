#ifndef __POINT2D_HPP__
#define __POINT2D_HPP__

#include <cmath>
#include <iostream>

namespace stl
{
    class Point2D {
        private:
            float _x, _y, _z;

        public:
            Point2D();
            Point2D(float x, float y, float z);
            Point2D(float A[3]);

            float GetX() const { return _x; };
            float GetY() const { return _y; };
            float GetZ() const { return _z; };

            float sum();
            float dot(const Point2D a);
            float magnitude();

            inline void SetX(float x) { _x = x; }
            inline void SetY(float y) { _y = y; }
            inline void SetZ(float z) { _z = z; }

            Point2D operator+(const Point2D inp);
            Point2D operator-(const Point2D inp);
            Point2D operator*(const Point2D inp);

            friend std::ostream& operator<<(std::ostream& out, const Point2D& T);
            
    };
} 


#endif 
