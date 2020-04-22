#include <iostream>
#include <sstream>
#include <string>
#define CATCH_CONFIG_MAIN

#include "../../../catch2/catch.hpp"
#include "../TVSet/CTVSet.h"

using namespace std;
SCENARIO("CTVSet tests") {

	CTVSet* Tv = new CTVSet();

	WHEN("First turn on") {
		THEN("Turn on and channel is 1") {
			CHECK(Tv->TurnOn());
			CHECK(Tv->GetChannel() == 1);
		}
	}

	WHEN("Try turn on turned on tv") {
		Tv->TurnOn();
		THEN("Nothing to do") {
			CHECK(Tv->TurnOn() == false);
			CHECK(Tv->GetChannel() == 1);
		}
	}

	WHEN("TV turn off") {
		Tv->TurnOn();
		THEN("Turn off tv and channel is 0") {
			CHECK(Tv->TurnOff());
			CHECK(Tv->GetChannel() == 0);
		}
	}

	WHEN("Change channel(1-99)") {
		Tv->TurnOn();
		THEN("Success change channel") {
			CHECK(Tv->SelectChannel(45));
			CHECK(Tv->GetChannel() == 45);
		}
	}

	WHEN("Try turn off TV which is turned off TV") {
		Tv->TurnOn();
		Tv->TurnOff();
		THEN("Nothing to do") {
			CHECK(Tv->TurnOff() == false);
			CHECK(Tv->GetChannel() == 0);
		}
	}

	WHEN("Try turn on tv") {
		Tv->TurnOn();
		Tv->SelectChannel(45);
		Tv->TurnOff();
		THEN("Turn on on last channel") {
			CHECK(Tv->TurnOn());
			CHECK(Tv->GetChannel() == 45);
		}
	}

	WHEN("Try to change channel out of range 1 - 99") {
		Tv->TurnOn();
		Tv->SelectChannel(45);
		THEN("Error - channel doestn't change") {
			CHECK(Tv->SelectChannel(100) == false);
			CHECK(Tv->GetChannel() == 45);
		}
	}

	WHEN("Get info about TV when it's turned off") {
		ostringstream output;
		THEN("Return correct information") {
			Tv->Info(output);
			CHECK(output.str() == "\nTV is turned off\nTV on channel 0\n");
		}
	}

	WHEN("Get info about TV when it's turned on(99 channel)") {
		ostringstream output;
		THEN("Return correct information") {
			Tv->TurnOn();
			Tv->SelectChannel(99);
			Tv->Info(output);
			CHECK(output.str() == "\nTV is turned on\nTV on channel 99\n");
		}
	}
}