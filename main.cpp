#include <iostream>
#include <mutex>
#include "main.hpp"
#include "Mylist.hpp"
#include <thread>

int main(int, char**){
    m29hw::Mylist<int> list_int;
    m29hw::Mylist<double> list_double;

    std::thread t1(m29hw::threadFunc<int>, std::ref(list_int));
    std::thread t2(m29hw::threadFunc<int>, std::ref(list_int));
    std::thread t3(m29hw::threadFunc<int>, std::ref(list_int));
    t1.join();
    t2.join();
    t3.join();
    std::cout << "Print list int\n";
    std::cout << list_int;

    std::thread t4(m29hw::threadFunc<double>, std::ref(list_double));
    std::thread t5(m29hw::threadFunc<double>, std::ref(list_double));
    std::thread t6(m29hw::threadFunc<double>, std::ref(list_double));
    t4.join();
    t5.join();
    t6.join();
    std::cout << "Print list double\n";
    std::cout << list_double;

    std::cout << "Hello, from module 29 home work!\n";
}
