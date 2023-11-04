#include "ATC.hpp"

// Problem 6
ATC::ATC() {

}

ATC::~ATC() {

}

void ATC::register_plane(Plane* new_plane) {
	this->registered_planes.push_back(new_plane);
}

void ATC::control_traffic() {
	uint landed_planes = 0;
	uint i = 0;

	for (auto plane : registered_planes) {
		landed_planes += plane->get_at_SCE();
	}

	if (landed_planes >= MAX_LANDED_PLANE_NUM) {
		for (auto plane : registered_planes) {
			if (
				(plane->get_at_SCE() == false) and
				(plane->distance_to_SCE() <= AIRSPACE_DISTANCE) and
				(std::abs(plane->get_loiter_time()) <= 1e-12)
				) {
				plane->set_loiter_time(100.0);
			}
		}
	}
	else return;
}