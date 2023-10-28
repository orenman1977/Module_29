#include <iostream>
#include "main.hpp"
#include "Mylist.hpp"
#include <thread>
#include <future>

int main(int, char**){
    m29hw::Mylist<int> list_int;
    m29hw::Mylist<double> list_double;
    m29hw::Mylist<char> list_char;

    std::future<void> f1, f2, f3;
    f1 = std::async(std::launch::async, m29hw::threadFunc<int>, std::ref(list_int));
    f2 = std::async(std::launch::async, m29hw::threadFunc<int>, std::ref(list_int));
    f3 = std::async(std::launch::async, m29hw::threadFunc<int>, std::ref(list_int));
    f1.wait();
    f2.wait();
    f3.wait();
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