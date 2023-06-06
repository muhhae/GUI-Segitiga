/* 
Anda diminta untuk mengimplementasikan class dengan nama Triangle 
yang didalamnya memuat 3 data dalam class Point2D yang telah diimplementasikan

Tujuan dari program adalah menentukan apakah suatua Triangle adalah 
sama kaki, sama sisi, siku-siku, dan sembarang

Input:
    vector dari suatu Triangle (dengan banyak sebesar 3*N) --> N = total Triangle

Output
    print setiap line dengan "sama kaki", "sama sisi", "siku-siku", atau "sembarang"


Silahkan gunakan teori dan implementasi yang telah diajarkan dikelas
*/

#define PI 3.14159265359

#include "include/triangles.hpp"

namespace stl
{
    Triangle::Triangle()
    {
        Point2D zero(0, 0, 0);

        this->_t1 = zero;
        this->_t2 = zero;
        this->_t3 = zero;
    }

    Triangle::Triangle(Point2D t1, Point2D t2, Point2D t3)
    {
        this->_t1 = t1;
        this->_t2 = t2;
        this->_t3 = t3;
    }

    Triangle::Triangle(float temp[3][3])
    {
        SetT1(Point2D(temp[0]));
        SetT2(Point2D(temp[1]));
        SetT3(Point2D(temp[2]));
    }

    void Triangle::SetT1(Point2D t1)
    {
        this->_t1 = t1;
    }

    void Triangle::SetT2(Point2D t2)
    {
        this->_t2 = t2;
    }

    void Triangle::SetT3(Point2D t3)
    {
        this->_t3 = t3;
    }

    std::string Triangle::TriangleType()
    {
        Point2D A = _t1;
        Point2D B = _t2;
        Point2D C = _t3;

        Point2D AB = A - B;
        Point2D AC = A - C;
        Point2D BA = B - A;
        Point2D BC = B - C;
        Point2D CA = C - A;
        Point2D CB = C - B;


        float s[3];
        //sudut antara AB AC
        s[0] = acos((AB.dot(AC)) / (AB.magnitude() * AC.magnitude())) / PI * 180;

        //sudut antara BA BC
        s[1] = acos((BA.dot(BC)) / (BA.magnitude() * BC.magnitude())) / PI * 180;

        //sudut antara CA CB
        s[2] = acos((CA.dot(CB)) / (CA.magnitude() * CB.magnitude())) / PI * 180;

        int sama = 0;

        for (int i = 0; i < 3; i++) 
        {
            if (abs(s[i] - 90) < 1e-5 )
            {
                return "Siku-Siku";
            }
            
            for (int j = 0; j < 3; j++)
            {
                if (j != i && abs(s[i] - s[j]) < 1e-5)
                {
                    //std::cout<<"tes"<<std::endl;
                    sama++;
                    break;
                }
            }

            // std::cout<<s[i]<<std::endl;
        }

        switch (sama)
        {
        case 2:
            return "Sama Kaki";
            break;
        case 3:
            return "Sama Sisi";
            break;
        default:
            break;
        }
        return "Sembarang";

    }

    std::ostream& operator<< (std::ostream& out, const Triangle& B)
    {
        out << B.GetT1() << B.GetT2() <<B.GetT3();

        return out;
    }
}



