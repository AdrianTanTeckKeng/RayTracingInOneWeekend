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

	void add(std::shared_ptr<hittable> object) { objects.push_back(object); }
	void clear() { objects.clear(); }

	virtual bool hit(const ray& r, double t_min, double t_max, hit_record& rec) const override;
};

bool hittable_list::hit(const ray& r, double t_min, double t_max, hit_record& rec) const {
	hit_record temp_rec;
	bool hit_anything = false;
	auto closest_so_far = t_max;

	for (const auto& object : objects) {
		if (object->hit(r, t_min, closest_so_far , temp_rec)) {
			hit_anything = true;
			rec = temp_rec;
			closest_so_far = rec.t;
		}
	}

	return hit_anything;
}
#endif