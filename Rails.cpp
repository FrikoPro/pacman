//
// Created by fredr on 02.04.2020.
//

#include "Rails.h"

Rails::Rails(SDL_Point start, SDL_Point end) : start(start), end(end)
{}

Rails::Rails()
{}

Rails::~Rails()
{}

bool Rails::operator==(const Rails &obj1)
{
    if (&this->start == obj1.start) {
        if (&this->end == obj1.end)
            return true;
    }
    return false;
}

bool Rails::operator==(const SDL_Point &point)
{
    return (point.x >= this->start.x && point.x <= this->end.x) &&
    point.y >= this->start.y && point.y <= this->end.y;
}
