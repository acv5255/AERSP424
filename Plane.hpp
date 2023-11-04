#pragma once

#include <map>
#include <string>
#include <iostream>

using std::string;
using std::map;


// Question 1
const double MPH_TO_IPS = 17.6;							// Miles per hour to inches per second
const double INCHES_TO_MILES = 1.0 / (12 * 5'280);

const map<string, double> DISTANCES = {
	{"PHL", 160.0},
	{"ORD", 640.0},
	{"EWR", 220.0}
};

// Question 2
class Plane {
	protected:
		double wait_time;

	private:
		double pos;
		double vel;
		double distance;
		double loiter_time;
		bool at_SCE;
		string origin;			// Starting point
		string destination;		// Ending point
		map<string, double> distances;
	
	public:
		Plane();	
		Plane(const string& to, const string& from); // Default constructor
		virtual ~Plane();
		void operate(double dt);
		double get_pos();
		double get_vel();
		double get_loiter_time();
		string get_origin();
		string get_destination();
		bool get_at_SCE();
		void set_vel(double new_vel);
		void set_loiter_time(double new_loiter_time);
		double distance_to_SCE();
		virtual double time_on_ground() = 0;
		virtual string plane_type();
		static double draw_from_normal_dist(double mean, double std);

		// Debug functions
		void print_positition();
};


class Airliner : public Plane {
	private:
		string Airline; 

	public:
		Airliner(const string& Airline, const string& to, const string& from);
		~Airliner();
		string plane_type() override;
		double time_on_ground() override;

};

class GeneralAviation : public Plane {
	private:

	public:
		GeneralAviation(const string& to, const string& from);
		double time_on_ground() override;
		~GeneralAviation();
};