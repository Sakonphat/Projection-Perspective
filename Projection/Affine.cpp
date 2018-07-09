//5709612005 Sakonphat Buayam
//assignment 1
//Computer Graphics 1 CS299
//semester 1/2016
#include "Affine.h"
using namespace std;
Hcoords::Hcoords() {
	x = 0;
	y = 0;
	z = 0;
	w = 0;
}
Hcoords::Hcoords(float X, float Y, float Z, float W) {
	x = X;
	y = Y;
	z = Z;
	w = W;
}
Point::Point() {
	x = 0;
	y = 0;
	z = 0;
	w = 1;
}
Point::Point(float X, float Y,float Z) {
	x = X;
	y = Y;
	z = Z;
	w = 1;
}
Vector::Vector() {
	x = 0;
	y = 0;
	z = 0;
	w = 0;
}
Vector::Vector(float X, float Y, float Z) {
	x = X;
	y = Y;
	z = Z;
	w = 0;
}
bool Vector::Normalize(void) {
	if (x == 0 && y == 0 && z==0)
		return false;
	else
		return true;
}
Affine::Affine() {
	row[0] = Hcoords(0, 0, 0, 0);
	row[1] = Hcoords(0, 0, 0, 0);
	row[2] = Hcoords(0, 0, 0, 0);
	row[3] = Hcoords(0, 0, 0, 1);
}
Affine::Affine(const Vector& Lx, const Vector& Ly, const Vector& Lz, const Point& disp) {
	row[0] = Hcoords(Lx.x, Ly.x, Lz.x, disp.x);
	row[1] = Hcoords(Lx.y, Ly.y, Lz.y, disp.y);
	row[2] = Hcoords(Lx.z, Ly.z, Lz.z, disp.z);
	row[3] = Hcoords(Lx.w, Ly.w, Lz.w, disp.w);
}
Hcoords operator+(const Hcoords& u, const Hcoords& v) {
	Hcoords sum = Hcoords();
	sum.x = u.x + v.x;
	sum.y = u.y + v.y;
	sum.z = u.z + v.z;
	//sum.w = u.w + v.w;
	return sum;
}
Hcoords operator-(const Hcoords& u, const Hcoords& v) {
	Hcoords diff = Hcoords();
	diff.x = u.x - v.x;
	diff.y = u.y - v.y;
	diff.z = u.z - v.z;
	//diff.w = u.w - v.w;
	return diff;
}
Hcoords operator-(const Hcoords& v) {
	Hcoords result = Hcoords();
	float minus = -1;
	result.x = v.x * minus;
	result.y = v.y * minus;
	result.z = v.z * minus;
	//result.w = v.w * minus;
	return result;
}
Hcoords operator*(float r, const Hcoords& v) {
	Hcoords product = Hcoords();
	product.x = r * v.x;
	product.y = r * v.y;
	product.z = r * v.z;
	//product.w = r * v.w;
	return product;
}
Hcoords operator*(const Affine& A, const Hcoords& v) {
	Hcoords result = Hcoords();
	result.x = (A.row[0].x * v.x) + (A.row[0].y * v.y) + (A.row[0].z * v.z) + (A.row[0].w * v.w);
	result.y = (A.row[1].x * v.x) + (A.row[1].y * v.y) + (A.row[1].z * v.z) + (A.row[1].w * v.w);
	result.z = (A.row[2].x * v.x) + (A.row[2].y * v.y) + (A.row[2].z * v.z) + (A.row[2].w * v.w);
	result.w = (A.row[3].x * v.x) + (A.row[3].y * v.y) + (A.row[3].z * v.z) + (A.row[3].w * v.w);
	return result;
}
Affine operator*(const Affine& A, const Affine& B) {
	Affine result = Affine();

	result.row[0].x = (A.row[0].x * B.row[0].x) + (A.row[0].y * B.row[1].x) + (A.row[0].z * B.row[2].x) + (A.row[0].w * B.row[3].x);
	result.row[0].y = (A.row[0].x * B.row[0].y) + (A.row[0].y * B.row[1].y) + (A.row[0].z * B.row[2].y) + (A.row[0].w * B.row[3].y);
	result.row[0].z = (A.row[0].x * B.row[0].z) + (A.row[0].y * B.row[1].z) + (A.row[0].z * B.row[2].z) + (A.row[0].w * B.row[3].z);
	result.row[0].w = (A.row[0].x * B.row[0].w) + (A.row[0].y * B.row[1].w) + (A.row[0].z * B.row[2].w) + (A.row[0].w * B.row[3].w);

	result.row[1].x = (A.row[1].x * B.row[0].x) + (A.row[1].y * B.row[1].x) + (A.row[1].z * B.row[2].x) + (A.row[1].w * B.row[3].x);
	result.row[1].y = (A.row[1].x * B.row[0].y) + (A.row[1].y * B.row[1].y) + (A.row[1].z * B.row[2].y) + (A.row[1].w * B.row[3].y);
	result.row[1].z = (A.row[1].x * B.row[0].z) + (A.row[1].y * B.row[1].z) + (A.row[1].z * B.row[2].z) + (A.row[1].w * B.row[3].z);
	result.row[1].w = (A.row[1].x * B.row[0].w) + (A.row[1].y * B.row[1].w) + (A.row[1].z * B.row[2].w) + (A.row[1].w * B.row[3].w);

	result.row[2].x = (A.row[2].x * B.row[0].x) + (A.row[2].y * B.row[1].x) + (A.row[2].z * B.row[2].x) + (A.row[2].w * B.row[3].x);
	result.row[2].y = (A.row[2].x * B.row[0].y) + (A.row[2].y * B.row[1].y) + (A.row[2].z * B.row[2].y) + (A.row[2].w * B.row[3].y);
	result.row[2].z = (A.row[2].x * B.row[0].z) + (A.row[2].y * B.row[1].z) + (A.row[2].z * B.row[2].z) + (A.row[2].w * B.row[3].z);
	result.row[2].w = (A.row[2].x * B.row[0].w) + (A.row[2].y * B.row[1].w) + (A.row[2].z * B.row[2].w) + (A.row[2].w * B.row[3].w);

	result.row[3].x = (A.row[3].x * B.row[0].x) + (A.row[3].y * B.row[1].x) + (A.row[3].z * B.row[2].x) + (A.row[3].w * B.row[3].x);
	result.row[3].y = (A.row[3].x * B.row[0].y) + (A.row[3].y * B.row[1].y) + (A.row[3].z * B.row[2].y) + (A.row[3].w * B.row[3].y);
	result.row[3].z = (A.row[3].x * B.row[0].z) + (A.row[3].y * B.row[1].z) + (A.row[3].z * B.row[2].z) + (A.row[3].w * B.row[3].z);
	result.row[3].w = (A.row[3].x * B.row[0].w) + (A.row[3].y * B.row[1].w) + (A.row[3].z * B.row[2].w) + (A.row[3].w * B.row[3].w);

	return result;
}
float dot(const Vector& u, const Vector& v) {
	return (u.x * v.x) + (u.y * v.y) + (u.z * v.z) + (u.w * v.w);
}
float abs(const Vector& v) {
	return sqrtf(powf(v.x, 2) + powf(v.y, 2) + powf(v.z, 2));
}
Affine CamtoWorld(const Vector& x, const Vector& y, const Vector& z) {
	Point disp;

	Vector c1(x.x, y.x, z.x);
	Vector c2(x.y, y.y, z.y);
	Vector c3(x.z, y.z, z.z);

	return Affine(c1,c2,c3,disp);
}
Affine WorldtoCam(const Vector& x, const Vector& y, const Vector& z) {
	Point disp;

	Vector w1(x.x, x.y, x.z);
	Vector w2(y.x, y.y, y.z);
	Vector w3(z.x, z.y, z.z);

	return Affine(w1, w2, w3, disp);
}
Affine Trans(const Vector& v) {
	//Point b ;
	Affine result = Affine();
	result.row[0].x = 1;
	result.row[1].y = 1;
	result.row[2].z = 1;

	result.row[0].w = v.x;
	result.row[1].w = v.y;
	result.row[2].w = v.z;

	return result;
}
Affine Scale(float r) {
	//Point b ;
	Affine result = Affine();

	result.row[0].x = r;
	result.row[1].y = r;
	result.row[2].z = r;

	return result;
}
Affine Scale(float rx, float ry, float rz) {
	Affine result = Affine();

	result.row[0].x = rx;
	result.row[1].y = ry;
	result.row[2].z = rz;

	return result;
}
Vector Cross(const Vector& u, const Vector& v) {
	Vector result = Vector();

	result.x = (u.y)*(v.z) - (v.y)*(u.z);
	result.y = -1*((u.x)*(v.z) - (v.x)*(u.z));
	result.z = (u.x)*(v.y) - (v.x)*(u.y);

	return result;
}
Affine Shear(float rx, float ry) {
	Affine result = Affine();
	result.row[0].x = 1;
	result.row[1].y = 1;
	result.row[2].z = 1;

	result.row[0].z = rx;
	result.row[1].z = ry;

	return result;
}