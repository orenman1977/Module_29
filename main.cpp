#include <iostream>
#include <mutex>
#include "main.hpp"
#include "Mylist.hpp"
#include <thread>

int main(int, char**){
    m29hw::Mylist<int> list_int;

    std::thread t1(m29hw::threadFunc<int>, std::ref(list_int));
    std::thread t2(m29hw::threadFunc<int>, std::ref(list_int));
    std::thread t3(m29hw::threadFunc<int>, std::ref(list_int));
    t1.join();
    t2.join();
    t3.join();
    std::cout << list_int;
    std::cout << "Hello, from module 29 home work!\n";
}
