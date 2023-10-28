#pragma once

#include "Mylist.hpp"

namespace m29hw
{
    template<typename T>
    void threadFunc(Mylist<T>& list)
    {
        T value = 0;
        for(size_t i = 0; i < 5; ++i){
            list.insertIntoMiddle(i + value, rand() % 10);
        }
    }
};