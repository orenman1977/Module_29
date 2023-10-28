#pragma once

#include "Mylist.hpp"

namespace m29hw
{
    template<typename T>
    void threadFunc(Mylist<T>& list)
    {
        for(size_t i = 0; i < 5; ++i){
            list.insertIntoMiddle(i, rand() % 10);
        }
    }
};