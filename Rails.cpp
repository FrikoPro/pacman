//
// Created by fredr on 02.04.2020.
//

#include "Rails.h"

Rails::Rails(int x1, int y1, int x2, int y2) : x1(x1), y1(y1), x2(x2), y2(y2)
{}

Rails::Rails()
{}

Rails::~Rails()
{}

bool Rails::operator==(const Rails &obj1)
{
    if (this->x1 == obj1.x1 && this->y1 == obj1.y1) {
        if (this->x2 == obj1.x2 && this->y2 == obj1.y2)
            return true;
    }
    return false;
}
