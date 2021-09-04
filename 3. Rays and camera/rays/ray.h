#ifndef RAY_H
#define RAY_H

#include "vec3.h"

class ray {
public:
	// Variables
	point3 orig;
	vec3 dir;

	// Constructor
	ray() {}
	ray(const point3& origin, const vec3& direction) : orig(origin), dir(direction) {}

	// Methods for rays
	point3 origin() const { return orig; }
	vec3 direction() const { return dir; }

	point3 at(double t) const {
		return orig + t * dir;
	}
};
#endif