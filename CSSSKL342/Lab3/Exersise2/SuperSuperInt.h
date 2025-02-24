#pragma once
#include <iostream>
#include "SuperInt.h"
class SuperSuperInt : public SuperInt
{
    public:
    SuperSuperInt(int init, const char *name);

    const int& theValue();
     ~SuperSuperInt();
    private:
    SuperSuperInt();
};