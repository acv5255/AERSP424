#include <iostream>
#include <chrono>
#include <thread>
#include "Plane.hpp"

int main(void) {
	// Question 5
	Airliner al_1 = Airliner("AA", "SCE", "PHL");
	Airliner al_2 = Airliner("UA", "SCE", "ORD");
	Airliner al_3 = Airliner("UA", "SCE", "EWR");
	Airliner al_4 = Airliner("AA", "SCE", "ORD");
	al_1.set_vel(470);
	al_2.set_vel(515);
	al_3.set_vel(480);
	al_4.set_vel(500);

	GeneralAviation ga_1 = GeneralAviation("SCE", "PHL");
	GeneralAviation ga_2 = GeneralAviation("SCE", "EWR");
	GeneralAviation ga_3 = GeneralAviation("SCE", "ORD");
	ga_1.set_vel(140);
	ga_2.set_vel(160);
	ga_3.set_vel(180);

	// Test things
	double dt = 100;
	while (true) {
		al_1.operate(dt);
		//al_2.operate(dt);
		//al_3.operate(dt);
		//al_4.operate(dt);

		//ga_1.operate(dt);
		//ga_2.operate(dt);
		//ga_3.operate(dt);

		al_1.print_positition();
		//al_2.print_positition();
		//al_3.print_positition();
		//al_4.print_positition();
		//ga_1.print_positition();
		//ga_2.print_positition();
		//ga_3.print_positition();

		std::cout << "\n\n";

		// Pause for 3 seconds
		std::chrono::milliseconds sleep_time(500);
		std::this_thread::sleep_for(sleep_time);
	}

	std::cout << "Program finished...\n";
};