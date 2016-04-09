#include <iostream>
#include <numeric>
#include <cmath>
#include <stdlib.h>

using namespace std;
struct objects{
	int x;
	int y;
	int z;
	int r = -1;
};



//float dx21 = x2-x1;
//float dx31 = x3-x1;
//float dy21 = y2-y1;
//float dy31 = y3-y1;
//float m12 = sqrt( dx21*dx21 + dy21*dy21 );
//float m13 = sqrt( dx31*dx31 + dy31*dy31 );
//float theta = acos( (dx21*dx31 + dy21*dy31) / (m12 * m13) );



//#include <math.h>
//#include <iostream>
//
//template <typename T> class Vector2D
//{
//private:
//    T x;
//    T y;
//
//public:
//    explicit Vector2D(const T& x=0, const T& y=0) : x(x), y(y) {}
//    Vector2D(const Vector2D<T>& src) : x(src.x), y(src.y) {}
//    virtual ~Vector2D() {}
//
//    // Accessors
//    inline T X() const { return x; }
//    inline T Y() const { return y; }
//    inline T X(const T& x) { this->x = x; }
//    inline T Y(const T& y) { this->y = y; }
//
//    // Vector arithmetic
//    inline Vector2D<T> operator-() const
//        { return Vector2D<T>(-x, -y); }
//
//    inline Vector2D<T> operator+() const
//        { return Vector2D<T>(+x, +y); }
//
//    inline Vector2D<T> operator+(const Vector2D<T>& v) const
//        { return Vector2D<T>(x+v.x, y+v.y); }
//
//    inline Vector2D<T> operator-(const Vector2D<T>& v) const
//        { return Vector2D<T>(x-v.x, y-v.y); }
//
//    inline Vector2D<T> operator*(const T& s) const
//        { return Vector2D<T>(x*s, y*s); }
//
//    // Dot product
//    inline T operator*(const Vector2D<T>& v) const
//        { return x*v.x + y*v.y; }
//
//    // l-2 norm
//    inline T norm() const { return sqrt(x*x + y*y); }
//
//    // inner angle (radians)
//    static T angle(const Vector2D<T>& v1, const Vector2D<T>& v2)
//    {
//        return acos( (v1 * v2) / (v1.norm() * v2.norm()) );
//    }
//};

//int main()
//{
//    Vector2D<double> p1(215, 294);
//    Vector2D<double> p2(174, 228);
//    Vector2D<double> p3(303, 294);
//
//    double rad = Vector2D<double>::angle(p2-p1, p3-p1);
//    double deg = rad * 180.0 / M_PI;
//
//    std::cout << "rad = " << rad << "\tdeg = " << deg << std::endl;
//
//    p1 = Vector2D<double>(153, 457);
//    p2 = Vector2D<double>(19, 457);
//    p3 = Vector2D<double>(15, 470);
//
//    rad = Vector2D<double>::angle(p2-p1, p3-p1);
//    deg = rad * 180.0 / M_PI;
//
//    std::cout << "rad = " << rad << "\tdeg = " << deg << std::endl;
//
//    return 0;
//}
float magnitude(int a[]){
	return sqrt(a[0]*a[0]+a[1]*a[1]+a[2]*a[2]);
}

void iterBullet(float &bul_x,float &bul_y,float &bul_z,float &bv_x,float &bv_y,float &bv_z){
	bul_x = bul_x+bv_x;
	bul_y = bul_y+bv_y;
	bul_z = bul_z+bv_z;
}

int main(){
//	cout << test << endl;
	float h_x;
	float h_y;
	float h_z;
	float h_r;
	float b_x;
	float b_y;
	float b_z;
	float b_r;
	float bt_x;
	float bt_y;
	float bt_z;
	cin >> b_x >> b_y >> b_z;
	cin >> bt_x >> bt_y >> bt_z;
	cin >> b_r;
	cin >> h_x >> h_y >> h_z;
	cin >> h_r;

	float currLocation;
	float prevLocation;

	float radius=b_r+h_r;
	int closestShot = 99999999;
	do
	{
		float xDiff, yDiff, zDiff;
		xDiff = abs(h_x-b_x);
		yDiff = abs(h_y-b_y);
		zDiff = abs(h_z-b_z);
		prevLocation = xDiff+yDiff+zDiff;

		if (closestShot > xDiff+yDiff+zDiff)
		{
			closestShot = xDiff+yDiff+zDiff;
		}

		std::cout << "xdiff: " << xDiff << std::endl;
		if (xDiff < radius && yDiff < radius && zDiff < radius)
		{
			std::cout << "HEADSHOT" << std::endl;
			return 0;
		}

		iterBullet(b_x,b_y,b_z,bt_x,bt_y,bt_z);
		xDiff = abs(h_x-b_x);
				yDiff = abs(h_y-b_y);
				zDiff = abs(h_z-b_z);
		std::cout << "x: " << b_x << std::endl;

		std::cout << "xdiff: " << xDiff << std::endl;

		if (xDiff < radius && yDiff < radius && zDiff < radius)
				{
					std::cout << "HEADSHOT" << std::endl;
					return 0;
				}
		if (closestShot > xDiff+yDiff+zDiff)
				{
					closestShot = xDiff+yDiff+zDiff;
				}

		currLocation = xDiff+yDiff+zDiff;


	} while(prevLocation > currLocation);

	std::cout << closestShot << std::endl;

//	cout << b_x << b_y << b_z << endl;
//	cout << bt_x << bt_y << bt_z<< endl;
//	cout << b_r<< endl;
//	cout << h_x << h_y << h_z<< endl;
//	cout << h_r<< endl;
}
