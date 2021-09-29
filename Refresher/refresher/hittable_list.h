#ifndef HITTABLE_LIST_H
#define HITTABLE_LIST_H

#include "hittable.h"
#include <memory>
#include <vector>

class hittable_list : public hittable {
public:
	std::vector<std::shared_ptr<hittable>> objects;
public:
	hittable_list() {}
	hittable_list(std::shared_ptr<hittable> object) { add(object); }

	void clear() { objects.clear(); }
	void add(std::shared_ptr<hittable> object) { objects.push_back(object); }

	bool hit(const ray& r, double t_min, double t_max, hit_record& rec) const override;
};

bool hittable_list::hit(const ray& r, double t_min, double t_max, hit_record& rec) const {
	hit_record temp_rec;
	double closest_so_far = t_max;
	bool hit_anything = false;
	
	for (const auto& object : objects) {
		if (object->hit(r, t_min, closest_so_far, temp_rec)) {
			rec = temp_rec;
			closest_so_far = rec.t;
			hit_anything = true;

		}
	}
	return hit_anything;
}
#endif