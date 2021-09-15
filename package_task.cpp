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

int do_some_math(int min, int max){
    static std::vector<int> to_add;
    to_add.reserve(max + 1);
    for(; min <= max; ++min){
        to_add.emplace_back(min);
    }

    return std::accumulate(to_add.begin(), to_add.end(), 0);
}

int package_task_main(){
    int val{};

//    pt=;
    std::packaged_task<void(int&)> pt{[](auto & v){ v = 128;}};


    std::packaged_task<int(int, int)> pt2{do_some_math};
    auto future = pt.get_future();
    auto future2 = pt2.get_future();
    pt(val);
    // -1410065407
    pt2(-88888888, 88888888);

    std::cout << val << ' '  << future2.get() << '\n';


    return 0;

}

static auto v = package_task_main();
// to run before main, or you can make this self-contained,
// and remove this, and rename 'package_task_main' to just main.