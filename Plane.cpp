#include "Plane.hpp"
#include <random>
#include <iostream>
#include <cmath>


// Constructor
Plane::Plane() {
	this->distances = {};
	this->pos = 0.0;
	this->vel = 0.0;
	this->wait_time = 0.0;
	this->loiter_time = 0.0;
	this->at_SCE = false;

	this->destination = "";
	this->origin = "";
}

Plane::Plane(const string& to, const string& from) {
	if ((to != "SCE") and (from != "SCE")) {
		std::cerr << "Error: Either 'to' or 'from' must be SCE\n";
		exit(-1);
	}
	this->distances = {
		{"PHL", 160.0},
		{"ORD", 640.0},
		{"EWR", 220.0}
	};
	this->pos = 0.0;
	this->vel = 0.0;
	this->wait_time = 0.0;
	this->loiter_time = 0.0;
	this->at_SCE = false;

	this->origin = from;
	this->destination = to;
	if (to != "SCE") this->distance = this->distances[to];
	else this->distance = this->distances[from];

}

// Getters
double Plane::get_pos() { return this->pos;};
double Plane::get_vel() { return this->vel;};
double Plane::get_loiter_time() { return this->loiter_time; };
string Plane::get_origin() { return this->origin; };
string Plane::get_destination() { return this->destination; };
bool Plane::get_at_SCE() { return this->at_SCE; };

// Setters
void Plane::set_vel(double new_val) { this->vel = new_val; };
void Plane::set_loiter_time(double new_val) { this->loiter_time = new_val; };

void Plane::operate(double dt) {
	
	if (loiter_time > 0.0) {
		loiter_time -= dt;
		return;
	}

	if (wait_time > 0.0) {
		wait_time -= dt;
		return;
	}

	if (get_pos() < distance) {
		const double inches_traveled = get_vel() * MPH_TO_IPS * dt;
		const double miles_traveled = inches_traveled * INCHES_TO_MILES;
		pos += miles_traveled;
		at_SCE = false;
		return;
	}

	if (destination == "SCE") {
		at_SCE = true;
	}

	wait_time = std::max(0.0, time_on_ground());
	std::swap(origin, destination);
	pos = 0.0;
	//wait_time = 0.0;
	//loiter_time = 0.0;
	return;
}

Plane::~Plane() {

}

double Plane::distance_to_SCE() {
	if (destination == "SCE") return std::abs(distance - get_pos());
	else return -999.0;
}

string Plane::plane_type() { return "GA"; };

double Plane::draw_from_normal_dist(double mean, double std) {
	std::random_device  rd{} ;
	std::mt19937 gen{ rd() };
	std::normal_distribution<> d{ mean, std };
	return d(gen);
}

void Plane::print_positition() {
	std::cout << "Position: " << get_pos() << std::endl;
}

// Question 4
Airliner::Airliner(const string& Airline, const string& to, const string& from) : Plane(to, from) {
	this->Airline = Airline;
	return;
}

Airliner::~Airliner() {

}

double Airliner::time_on_ground() {
	wait_time = draw_from_normal_dist(1800.0, 600.0);
	return wait_time;
}

string Airliner::plane_type() {
	return "Airliner";
}


GeneralAviation::GeneralAviation(const string& to, const string& from) : Plane(to, from) {

}

double GeneralAviation::time_on_ground() {
	return this->wait_time;
}

GeneralAviation::~GeneralAviation() {

}