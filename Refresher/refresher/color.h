#ifndef COLOR_H
#define COLOR_H

#include "vec3.h"
#include<iostream>

void write_color(std::ostream& out, const color pixel, int samples_per_pixel) {
	auto r = pixel.x();
	auto g = pixel.y();
	auto b = pixel.z();

	auto scale = 1.0 / samples_per_pixel;
	r = sqrt(r * scale);
	g = sqrt(g * scale);
	b = sqrt(b * scale);

	out << static_cast<int>(256 * clamp(r, 0.0, 0.999)) << ' '
		<< static_cast<int>(256 * clamp(g, 0.0, 0.999)) << ' '
		<< static_cast<int>(256 * clamp(b, 0.0, 0.999)) << '\n';
}
#endif