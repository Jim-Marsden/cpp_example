#include <iostream>
#include "package_task.hpp"

#include "numbers/dll_add_numbers.h"
int main() {

    hello::say_hello();
    auto v = hello::add(3, 4);
    std::cout << v << '\n';
//    package_task_main();
//    std::cout << numbers::add(34,34);
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
