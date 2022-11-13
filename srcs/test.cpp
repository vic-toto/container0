#include "../includes/ft_containers.hpp"

time_t start1, start2, end1, end2 = 0;

time_t timer()
{
	struct timeval start = {};
	gettimeofday(&start, nullptr);
	time_t msecs_time = (start.tv_sec * 1000) + (start.tv_usec / 1000);
	return msecs_time;
}

void print_green_result(std::string s)
{
	s = std::string("\x1B[1;32m") + s + std::string("\033[0m");
	std::cout << std::left << std::setw(30) << std::setfill(' ') << s;
}

void print_red_result(std::string s)
{
	s = std::string("\x1B[1;31m") + s + std::string("\033[0m");
	std::cout << std::left << std::setw(30) << std::setfill(' ') << s;
}

int run_unit_test(std::string test_name, std::vector<int>(func1)(), std::vector<int>(func2)())
{
	int result;
	time_t t1;
	time_t t2;
	std::vector<int> res1;
	std::vector<int> res2;

	std::cout << std::left << std::setw(30) << std::setfill(' ') << test_name;
	res1 = func1();
	res2 = func2();
	if (res1 == res2)
	{
		print_green_result(std::string("OK"));
		result = 0;
	}
	else
	{
		print_red_result("FAILED");
		result = 1;
	}
	t1 = end1 - start1, t2 = end2 - start2;
	(t1 >= t2 / 20) ? print_green_result(std::to_string(t2) + "ms") : print_green_result(std::to_string(t2) + "ms");
	(t1 > t2 / 20) ? print_red_result(std::to_string(t1) + "ms") : print_red_result(std::to_string(t1) + "ms");
	std::cout << std::endl;

	return !result;
}

int run_bool_unit_test(std::string test_name, bool(func1)())
{
	int ret = 0;
	time_t t1;
	time_t t2;
	bool res;

	start1 = start2 = end1 = end2 = 0;
	std::cout << std::left << std::setw(30) << std::setfill(' ') << test_name;
	res = func1();
	if (res)
	{
		print_green_result(std::string("OK"));
		ret = 0;
	}
	else
	{
		print_red_result(std::string("FAILED"));
		ret = 1;
	}
	t1 = end1 - start1, t2 = end2 - start2;
	(t1 >= t2 / 20) ? print_green_result(std::to_string(t2) + "ms") : print_red_result(std::to_string(t2) + "ms");
	(t1 >= t2 / 20) ? print_red_result(std::to_string(t1) + "ms") : print_green_result(std::to_string(t1) + "ms");
	std::cout << std::endl;

	return ret;
}