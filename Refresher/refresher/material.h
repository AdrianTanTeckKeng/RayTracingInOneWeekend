#ifndef MATERIAL_H
#define MATERIAL_H

#include "rtweekend.h"

struct hit_record;

class material {
public:
	virtual bool scatter(const ray& r_in, const hit_record& rec, color& attenuation, ray& scattered) const = 0;
};

class lambertian : public material {
public:
	color albedo;
public:
	lambertian(const color& a) : albedo(a) {}
	bool scatter(const ray& r_in, const hit_record& rec, color& attenuation, ray& scattered) const override {
		// We first need to determine scattered direction. For diffusive materials, we find a random direction.
		vec3 scattered_direction = rec.normal + random_unit_vector();
		// We perform checks to ensure that the scattered direction is not zero
		if (scattered_direction.near_zero()) {
			scattered_direction = rec.normal;
		}

		// We construct the scattered ray
		scattered = ray(rec.p, scattered_direction);

		// We record the color
		attenuation = albedo;
		return true;
	}
};

class metal : public material {
public:
	color albedo;
	double fuzz;
public:
	metal(const color& a, double f) : albedo(a), fuzz(f < 1 ? f : 1) {}
	bool scatter(const ray& r_in, const hit_record& rec, color& attenuation, ray& scattered) const override {
		// The scattering mechanism for metals is just pure reflection
		vec3 reflected = reflect(r_in.direction(), rec.normal);

		// We construct the scattered ray
		scattered = ray(rec.p, reflected + fuzz * random_in_unit_sphere());

		// We record the attenuation
		attenuation = albedo;
		return true;
	}
};
#endif