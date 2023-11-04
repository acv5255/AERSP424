#pragma once

#include <map>
#include <vector>
#include "Plane.hpp"

using std::map;
using std::vector;

using uint = unsigned int;

// Problem 6
class ATC {
	// Air traffic controller class

	private:
		vector<Plane *> registered_planes;
		uint MAX_LANDED_PLANE_NUM = 2;
		uint AIRSPACE_DISTANCE = 50;

	public:
		ATC();
		~ATC();
		void register_plane(Plane* new_plane);
		void control_traffic();
};