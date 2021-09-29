#ifndef VEC3_H
#define VEC3_H

#include <iostream>
#include <cmath>
using std::sqrt;

class vec3 {
public:
	double e[3];
public:
	vec3() : e{ 0, 0, 0 } {}
	vec3(double e0, double e1, double e2) : e{ e0, e1, e2 } {}

	vec3 operator-() const { return vec3(-e[0], -e[1], -e[2]); }
	vec3& operator+=(const vec3& u)  {
		e[0] += u.e[0];
		e[1] += u.e[1];
		e[2] += u.e[2];
		return *this;
	}


};
#endif