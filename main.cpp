#include <iostream>
#include <chrono>
#include <thread>
#include "Plane.hpp"
#include "ATC.hpp"
#include "HW2_Visualizer.hpp"

int main(int argc, char** argv) {
	// Question 5
	Airliner al_1 = Airliner("AA", "SCE", "PHL");
	Airliner al_2 = Airliner("UA", "SCE", "ORD");
	Airliner al_3 = Airliner("UA", "SCE", "EWR");
	Airliner al_4 = Airliner("AA", "SCE", "ORD");
	al_1.set_vel(470.0);
	al_2.set_vel(515.0);
	al_3.set_vel(480.0);
	al_4.set_vel(500.0);

	HW2_VIZ viz;

	GeneralAviation ga_1 = GeneralAviation("SCE", "PHL");
	GeneralAviation ga_2 = GeneralAviation("SCE", "EWR");
	GeneralAviation ga_3 = GeneralAviation("SCE", "ORD");
	ga_1.set_vel(140.0);
	ga_2.set_vel(160.0);
	ga_3.set_vel(180.0);

	// Problem 7
	ATC atc;
	atc.register_plane(&al_1);
	atc.register_plane(&al_2);
	atc.register_plane(&al_3);
	atc.register_plane(&al_4);
	atc.register_plane(&ga_1);
	atc.register_plane(&ga_2);
	atc.register_plane(&ga_3);

	// Test things
	double dt = 50;
	while (true) {
		al_1.operate(dt);
		al_2.operate(dt);
		al_3.operate(dt);
		al_4.operate(dt);

		ga_1.operate(dt);
		ga_2.operate(dt);
		ga_3.operate(dt);

		atc.control_traffic();

		// Now, visualize all of the planes
		viz.visualize_plane("AA", al_1.get_origin(), al_1.get_destination(), al_1.get_pos());
		viz.visualize_plane("UA", al_2.get_origin(), al_2.get_destination(), al_2.get_pos());
		viz.visualize_plane("UA", al_3.get_origin(), al_3.get_destination(), al_3.get_pos());
		viz.visualize_plane("AA", al_4.get_origin(), al_4.get_destination(), al_4.get_pos());

		viz.visualize_plane("NA", ga_1.get_origin(), ga_1.get_destination(), ga_1.get_pos());
		viz.visualize_plane("NA", ga_2.get_origin(), ga_2.get_destination(), ga_2.get_pos());
		viz.visualize_plane("NA", ga_3.get_origin(), ga_3.get_destination(), ga_3.get_pos());
		
		viz.update(dt);

		// Print outputs
		//std::cout << "Positions: \n";
		//al_1.print_positition();
		//al_2.print_positition();
		//al_3.print_positition();
		//al_4.print_positition();
		//ga_1.print_positition();
		//ga_2.print_positition();
		//ga_3.print_positition();
	}

	std::cout << "Program finished...\n";
};