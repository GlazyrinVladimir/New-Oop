#include "stdafx.h"
#include "../Student/Student.h"

using namespace std;

template <typename Ex, typename Fn>
void ExpectException(Fn && fn, const string & expectedDescription)
{
	BOOST_CHECK_EXCEPTION(fn(), Ex, [&](const Ex& e) {
		return e.what() == expectedDescription;
	});
}

template <typename Ex>
void ExpectConstructorFailure(std::string name, std::string surname, std::string patronymic, int age, const string & expectedDescription)
{
	ExpectException<Ex>([&] {
		CStudent(name, surname, patronymic, age);
	}, expectedDescription);
}

void ExpectRename(CStudent student, std::string name, std::string surname, std::string patronymic)
{
	BOOST_CHECK_EQUAL(student.GetName(), name);
	BOOST_CHECK_EQUAL(student.GetSurname(), surname);
	BOOST_CHECK_EQUAL(student.GetPatronymic(), patronymic);
}

BOOST_AUTO_TEST_SUITE(Student_Tests)
	BOOST_AUTO_TEST_CASE(can_not_have_numbers_or_spaces)
	{
		ExpectConstructorFailure<invalid_argument>("Vladimir1", "Glazyrin", "Evgenyevich", 20, "name is contained invalid symbols.");
		ExpectConstructorFailure<invalid_argument>("Vladimir", "Glazyrin1", "Evgenyevich", 20, "surname is contained invalid symbols.");
		ExpectConstructorFailure<invalid_argument>("Vladimir", "Glazyrin", "Evgenyevich1", 20, "patronymic is contained invalid symbols.");
		ExpectConstructorFailure<invalid_argument>("Vladimir ", "Glazyrin", "Evgenyevich", 20, "name is contained invalid symbols.");
		ExpectConstructorFailure<invalid_argument>("Vladimir", "Glazyrin ", "Evgenyevich", 20, "surname is contained invalid symbols.");
		ExpectConstructorFailure<invalid_argument>("Vladimir", "Glazyrin", "Evgenyevich ", 20, "patronymic is contained invalid symbols.");
	}
	
	BOOST_AUTO_TEST_CASE(only_patronymic_can_be_empty)
	{
		ExpectConstructorFailure<invalid_argument>("", "Glazyrin", "Evgenyevich", 20, "name is empty.");
		ExpectConstructorFailure<invalid_argument>("Vladimir", "", "Evgenyevich", 20, "surname is empty.");
		CStudent("Vladimir", "Glazyrin", "", 20);
	}

	BOOST_AUTO_TEST_CASE(can_not_go_beyond_interval)
	{
		ExpectConstructorFailure<out_of_range>("Vladimir", "Glazyrin", "Evgenyevich", 13, "13 is not included in the range.");
		ExpectConstructorFailure<out_of_range>("Vladimir", "Glazyrin", "Evgenyevich", 61, "61 is not included in the range.");
		CStudent("Vladimir", "Glazyrin", "", 14);
		CStudent("Vladimir", "Glazyrin", "", 60);
		CStudent("Vladimir", "Glazyrin", "", 27);
	}

	BOOST_AUTO_TEST_CASE(can_not_set_new_age_less_current_age)
	{
		CStudent student("Vladimir", "Glazyrin", "Evgenyevich", 15);
		BOOST_CHECK_THROW(student.SetAge(14), domain_error);
		BOOST_CHECK_THROW(student.SetAge(13), out_of_range);
		BOOST_CHECK_EQUAL(student.GetAge(), 15);
		student.SetAge(29);
		BOOST_CHECK_EQUAL(student.GetAge(), 29);
		student.SetAge(60);
		BOOST_CHECK_EQUAL(student.GetAge(), 60);
		BOOST_CHECK_THROW(student.SetAge(59), domain_error);
		BOOST_CHECK_THROW(student.SetAge(61), out_of_range);	
	}

	BOOST_AUTO_TEST_CASE(can_change_name_surname_patronymic)
	{
		CStudent student("Vladimir", "Glazyrin", "Evgenyevich", 15);
		student.Rename("V", "G", "E");
		ExpectRename(student, "V", "G", "E");
		BOOST_CHECK_THROW(student.Rename("", "G", "E");, invalid_argument);
		BOOST_CHECK_THROW(student.Rename("V", "", "E");, invalid_argument);
		student.Rename("V", "G", "");
		ExpectRename(student, "V", "G", "");
	}

BOOST_AUTO_TEST_SUITE_END()