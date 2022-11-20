#include "../includes/test_utils.hpp"
#include "../includes/test_vector.hpp"
#include "../includes/test_stack.hpp"

void	vector_tester()
{
	std::cout << "__     __             _                " << std::endl;
	std::cout << "\\ \\   / /  ___   ___ | |_   ___   _ __ " << std::endl;
	std::cout << " \\ \\ / /  / _ \\ / __|| __| / _ \\ | '__|" << std::endl;
	std::cout << "  \\ V /  |  __/| (__ | |_ | (_) || |   " << std::endl;
	std::cout << "   \\_/    \\___| \\___| \\__| \\___/ |_|   " << std::endl;
	std::cout << " _____             _                    _           _    _                _              _  " << std::endl;
	std::cout << "|_   _|  ___  ___ | |_   ___  _ __     / \\     ___ | |_ (_)__   __  __ _ | |_   ___   __| | " << std::endl;
	std::cout << "  | |   / _ \\/ __|| __| / _ \\| '__|   / _ \\   / __|| __|| |\\ \\ / / / _` || __| / _ \\ / _` | " << std::endl;
	std::cout << "  | |  |  __/\\__ \\| |_ |  __/| |     / ___ \\ | (__ | |_ | | \\ V / | (_| || |_ |  __/| (_| | " << std::endl;
	std::cout << "  |_|   \\___||___/ \\__| \\___||_|    /_/   \\_\\ \\___| \\__||_|  \\_/   \\__,_| \\__| \\___| \\__,_| " << std::endl;                                                                                          
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	run_unit_test("constructor", &vector_constructor_test_std<int>, &vector_constructor_test_ft<int>);
	run_unit_test("constructor input iterator", &vector_constructor_it_test_std<int>, &vector_constructor_it_test_ft<int>);
	run_unit_test("iterator", &vector_iterator_test_std<int>, &vector_iterator_test_ft<int>);
	run_unit_test("begin()", &vector_begin_test_std<int>, &vector_begin_test_ft<int>);
	run_unit_test("end()", &vector_end_test_std<int>, &vector_end_test_ft<int>);
	run_unit_test("rbegin()", &vector_rbegin_test_std<int>, &vector_rbegin_test_ft<int>);
	run_unit_test("rend()", &vector_rend_test_std<int>, &vector_rend_test_ft<int>);
	run_unit_test("size()", &vector_size_test_std<int>, &vector_size_test_ft<int>);
	run_unit_test("max_size()", &vector_maxsize_test_std<int>, &vector_maxsize_test_ft<int>);
	run_unit_test("resize()", &vector_resize_test_std<int>, &vector_resize_test_ft<int>);
	run_unit_test("capacity()", &vector_capacity_test_std<int>, &vector_capacity_test_ft<int>);
	run_unit_test("empty()", &vector_empty_test_std<int>, &vector_empty_test_ft<int>);
	run_unit_test("reserve()", &vector_reserve_test_std<int>, &vector_reserve_test_ft<int>);
	run_unit_test("operator []", &vector_operator_assign_test_std<int>, &vector_operator_assign_test_ft<int>);
	run_unit_test("at()", &vector_at_test_std<int>, &vector_at_test_ft<int>);
	run_unit_test("front()", &vector_front_test_std<int>, &vector_front_test_ft<int>);
	run_unit_test("back()", &vector_back_test_std<int>, &vector_back_test_ft<int>);
	run_unit_test("assign()", &vector_assign_test_std<int>, &vector_assign_test_ft<int>);
	run_unit_test("assign() iterator", &vector_assign_it_test_std<int>, &vector_assign_it_test_ft<int>);
	run_unit_test("push_back()", &vector_push_back_test_std<int>, &vector_push_back_test_ft<int>);
	run_unit_test("pop_back()", &vector_pop_back_test_std<int>, &vector_pop_back_test_ft<int>);
	run_unit_test("insert(value)", &vector_insert_value_test_std<int>, &vector_insert_value_test_ft<int>);
	run_unit_test("insert(fill)", &vector_insert_fill_test_std<int>, &vector_insert_fill_test_ft<int>);
	run_unit_test("insert(range)", &vector_insert_range_test_std<int>, &vector_insert_range_test_ft<int>);
	run_unit_test("insert(iterator)", &vector_insert_it_test_std<int>, &vector_insert_it_test_ft<int>);
	run_unit_test("erase(value)", &vector_erase_value_test_std<int>, &vector_erase_value_test_ft<int>);
	run_unit_test("erase(range)", &vector_erase_range_test_std<int>, &vector_erase_range_test_ft<int>);
	run_unit_test("swap()", &vector_swap_test_std<int>, &vector_swap_test_ft<int>);
	run_unit_test("clear()", &vector_clear_test_std<int>, &vector_clear_test_ft<int>);
	run_bool_unit_test("operator ==", &vector_operator_equal_test);
	run_bool_unit_test("operator !=", &vector_operator_not_equal_test);
	run_bool_unit_test("operator <", &vector_operator_less_test);
	run_bool_unit_test("operator >", &vector_operator_more_test);
	run_bool_unit_test("operator <=", &vector_operator_less_equal_test);
	run_bool_unit_test("operator >=", &vector_operator_more_equal_test);
	std::cout << std::endl;
}

void	stack_tester()
{
	std::cout << " ____   _                 _    " << std::endl;
	std::cout << "/ ___| | |_   __ _   ___ | | __" << std::endl;
	std::cout << "\\___ \\ | __| / _` | / __|| |/ /" << std::endl;
	std::cout << " ___) || |_ | (_| || (__ |   < " << std::endl;
	std::cout << "|____/  \\__| \\__,_| \\___||_|\\_\\" << std::endl;
	std::cout << " _____             _                    _           _    _                _              _  " << std::endl;
	std::cout << "|_   _|  ___  ___ | |_   ___  _ __     / \\     ___ | |_ (_)__   __  __ _ | |_   ___   __| | " << std::endl;
	std::cout << "  | |   / _ \\/ __|| __| / _ \\| '__|   / _ \\   / __|| __|| |\\ \\ / / / _` || __| / _ \\ / _` | " << std::endl;
	std::cout << "  | |  |  __/\\__ \\| |_ |  __/| |     / ___ \\ | (__ | |_ | | \\ V / | (_| || |_ |  __/| (_| | " << std::endl;
	std::cout << "  |_|   \\___||___/ \\__| \\___||_|    /_/   \\_\\ \\___| \\__||_|  \\_/   \\__,_| \\__| \\___| \\__,_| " << std::endl;  
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	run_unit_test("constructor", &stack_constructor_test_std<int>, &stack_constructor_test_ft<int>);
	run_unit_test("push()", &stack_push_test_std<int>, &stack_push_test_ft<int>);
	run_unit_test("top()", &stack_top_test_std<int>, &stack_top_test_ft<int>);
	run_unit_test("pop()", &stack_pop_test_std<int>, &stack_pop_test_ft<int>);
	run_unit_test("size()", &stack_size_test_std<int>, &stack_size_test_ft<int>);
	run_unit_test("empty()", &stack_empty_test_std<int>, &stack_empty_test_ft<int>);
	run_bool_unit_test("operator ==", &stack_stack_equal_test);
	run_bool_unit_test("operator !=", &stack_stack_not_equal_test);
	run_bool_unit_test("operator <", &stack_stack_less_than_test);
	run_bool_unit_test("operator >", &stack_stack_more_than_test);
	run_bool_unit_test("operator <=", &stack_less_or_equal_test);
	run_bool_unit_test("operator >=", &stack_more_or_equal_test);
}

int main()
{
	vector_tester();
	stack_tester();
	return (0);
}