#include "stdafx.h"
#include "..\task1\Car.h"

using namespace std;

struct CarSetFixture
{
	CCarSet car;
};

BOOST_FIXTURE_TEST_SUITE(START_ENGINE_CHECK, CarSetFixture)

	BOOST_AUTO_TEST_CASE(engine_is_off)
	{
		BOOST_CHECK(!car.IsTurnedOn());
	}

	BOOST_AUTO_TEST_CASE(cant_select_speed_when_engine_off)
	{
		car.SelectSpeed(10);
		BOOST_CHECK(car.GetSpeed() == 0);
	}

	BOOST_AUTO_TEST_CASE(cant_select_gear_when_engine_off)
	{
		car.SelectGear(1);
		BOOST_CHECK(car.GetGear() == 0);
	}

	BOOST_AUTO_TEST_CASE(engine_is_on)
	{
		car.TurnOn();
		BOOST_CHECK(car.IsTurnedOn());
	}

	struct WhenEngineOn : CarSetFixture
	{
		WhenEngineOn()
		{
			car.TurnOn();
		}
	};

	BOOST_FIXTURE_TEST_SUITE(START_CAR_SIMULATOR, WhenEngineOn)

		BOOST_AUTO_TEST_CASE(change_speed_and_gear_to_move_forward)
		{
			BOOST_CHECK(car.SelectGear(1) && car.SelectSpeed(20));
		}

		BOOST_AUTO_TEST_CASE(try_to_change_speed_and_gear_in_out_of_max_interval)
		{
			car.SelectGear(1);
			car.SelectSpeed(30);
			car.SelectGear(3);
			car.SelectSpeed(60);
			car.SelectGear(5);
			car.SelectSpeed(150);
			BOOST_CHECK(!car.SelectGear(6) && !car.SelectSpeed(200));
		}

		BOOST_AUTO_TEST_CASE(try_to_move_back)
		{
			car.SelectGear(-1);
			car.SelectSpeed(15);
			BOOST_CHECK(car.GetMovement() == "back");
		}

		BOOST_AUTO_TEST_CASE(cant_change_gear_to_reverse_when_speed_more_zero)
		{
			car.SelectGear(1);
			car.SelectSpeed(10);
			BOOST_CHECK(!car.SelectGear(-1));
		}

		BOOST_AUTO_TEST_CASE(cant_change_gear_from_reverse_to_first_when_speed_more_zero)
		{
			car.SelectGear(-1);
			car.SelectSpeed(10);
			BOOST_CHECK(!car.SelectGear(1));
		}

		BOOST_AUTO_TEST_CASE(cant_change_gear_from_neutral_when_move_back_to_first_gear)
		{
			car.SelectGear(-1);
			car.SelectSpeed(10);
			car.SelectGear(0);
			BOOST_CHECK(!car.SelectGear(1));
		}

		BOOST_AUTO_TEST_CASE(try_to_simulate_a_ride)
		{
			car.SelectGear(-1);
			car.SelectSpeed(10);
			car.SelectGear(0);
			car.SelectSpeed(0);
			car.SelectGear(1);
			car.SelectSpeed(30);
			BOOST_CHECK(!car.SelectGear(5));
			car.SelectGear(3);
			car.SelectSpeed(60);
			car.SelectSpeed(30);
			car.SelectGear(0);
			car.SelectSpeed(0);
			BOOST_CHECK(car.TurnOff());
		}
	BOOST_AUTO_TEST_SUITE_END()
BOOST_AUTO_TEST_SUITE_END()


