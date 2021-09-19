//
// Created by Jim on 9/14/21.
//

#include "package_task.hpp"
#include <future>
#include <iostream>
#include <memory>
#include <vector>
#include <algorithm>
#include <numeric>
#include "numbers/dll_add_numbers.h"

unsigned long long do_some_math(unsigned  long long min, unsigned long long max){
    std::vector< unsigned long long> to_add;
    auto counter{0ull};
    to_add.reserve(max + 1);
    for(; min <= max; ++min){
        to_add.emplace_back(min);
    }
    std::for_each(to_add.begin(), to_add.end(), [&counter](unsigned long long e){counter = hello::add(counter, e);});
    return counter;
}
int package_task_main(){


    std::vector<std::future<decltype(do_some_math(1, 1))>> futures;
    std::packaged_task p1(do_some_math), p2(do_some_math), p3(do_some_math), p4(do_some_math), p5(do_some_math),
            p6(do_some_math), p7(do_some_math), p8(do_some_math);

    futures.push_back(p1.get_future());    p1(00000000, 9999999);
    futures.push_back(p2.get_future());    p2(10000000, 19999999);
    futures.push_back(p3.get_future());    p3(20000000, 29999999);
    futures.push_back(p4.get_future());    p4(30000000, 39999999);
    futures.push_back(p5.get_future());    p5(40000000, 49999999);
    futures.push_back(p6.get_future());    p6(50000000, 59999999);
    futures.push_back(p7.get_future());    p7(60000000, 69999999);
    futures.push_back(p8.get_future());    p8(70000000, 79999999);





    long long acc{};
    long long temp{};
    for(auto & e : futures){
        temp = e.get();
        acc += temp;
        std::cout << "val:" << temp << "\t total:" << acc << '\n';
    }

    return 0;
}

static auto v = package_task_main();
// to run before main, or you can make this self-contained,
// and remove this, and rename 'package_task_main' to just main.