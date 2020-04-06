//
// Created by fredr on 02.04.2020.
//

#include "Map.h"

Map *Map::instance = nullptr;

Map::Map()
{
    txMap = Screen::loadImage("../data/gfx/hintergrund2.png", -1);
    arrayOfRails.emplace_back(SDL_Point{138, 37}, SDL_Point{207, 37});
    arrayOfRails.emplace_back(SDL_Point{207, 37}, SDL_Point{290, 37});
    arrayOfRails.emplace_back(SDL_Point{330, 37}, SDL_Point{412, 37});
    arrayOfRails.emplace_back(SDL_Point{412, 37}, SDL_Point{480, 37});
    arrayOfRails.emplace_back(SDL_Point{138, 92}, SDL_Point{207, 92});
    arrayOfRails.emplace_back(SDL_Point{207, 92}, SDL_Point{249, 92});
    arrayOfRails.emplace_back(SDL_Point{249, 92}, SDL_Point{290, 92});
    arrayOfRails.emplace_back(SDL_Point{290, 92}, SDL_Point{330, 92});
    arrayOfRails.emplace_back(SDL_Point{330, 92}, SDL_Point{371, 92});
    arrayOfRails.emplace_back(SDL_Point{371, 92}, SDL_Point{412, 92});
    arrayOfRails.emplace_back(SDL_Point{412, 92}, SDL_Point{480, 92});
    arrayOfRails.emplace_back(SDL_Point{138, 133}, SDL_Point{207, 133});

    arrayOfRails.emplace_back(SDL_Point{249, 133}, SDL_Point{290, 133});

    arrayOfRails.emplace_back(SDL_Point{330, 133}, SDL_Point{371, 133});
    arrayOfRails.emplace_back(SDL_Point{412, 133}, SDL_Point{480, 133});
    arrayOfRails.emplace_back(SDL_Point{249, 174}, SDL_Point{290, 174});
    arrayOfRails.emplace_back(SDL_Point{290, 174}, SDL_Point{310, 174});
    arrayOfRails.emplace_back(SDL_Point{310, 174}, SDL_Point{330, 174});
    arrayOfRails.emplace_back(SDL_Point{330, 174}, SDL_Point{371, 174});
    arrayOfRails.emplace_back(SDL_Point{100, 215}, SDL_Point{207, 215}); // tunnel left
    arrayOfRails.emplace_back(SDL_Point{207, 215}, SDL_Point{249, 215});
    arrayOfRails.emplace_back(SDL_Point{371, 215}, SDL_Point{412, 215});
    arrayOfRails.emplace_back(SDL_Point{412, 215}, SDL_Point{515, 215}); // tunnel right
    arrayOfRails.emplace_back(SDL_Point{249, 257}, SDL_Point{371, 257});
    arrayOfRails.emplace_back(SDL_Point{138, 298}, SDL_Point{207, 298});
    arrayOfRails.emplace_back(SDL_Point{207, 298}, SDL_Point{249, 298});
    arrayOfRails.emplace_back(SDL_Point{249, 298}, SDL_Point{290, 298});
    arrayOfRails.emplace_back(SDL_Point{330, 298}, SDL_Point{371, 298});
    arrayOfRails.emplace_back(SDL_Point{371, 298}, SDL_Point{412, 298});
    arrayOfRails.emplace_back(SDL_Point{412, 298}, SDL_Point{480, 298});
    arrayOfRails.emplace_back(SDL_Point{138, 339}, SDL_Point{166, 339});
    arrayOfRails.emplace_back(SDL_Point{207, 339}, SDL_Point{249, 339});
    arrayOfRails.emplace_back(SDL_Point{249, 339}, SDL_Point{290, 339});
    arrayOfRails.emplace_back(SDL_Point{290, 339}, SDL_Point{330, 339});
    arrayOfRails.emplace_back(SDL_Point{330, 339}, SDL_Point{371, 339});
    arrayOfRails.emplace_back(SDL_Point{371, 339}, SDL_Point{412, 339});
    arrayOfRails.emplace_back(SDL_Point{452, 339}, SDL_Point{480, 339});
    arrayOfRails.emplace_back(SDL_Point{138, 380}, SDL_Point{166, 380});
    arrayOfRails.emplace_back(SDL_Point{166, 380}, SDL_Point{207, 380});
    arrayOfRails.emplace_back(SDL_Point{249, 380}, SDL_Point{290, 380});
    arrayOfRails.emplace_back(SDL_Point{330, 380}, SDL_Point{371, 380});
    arrayOfRails.emplace_back(SDL_Point{412, 380}, SDL_Point{452, 380});
    arrayOfRails.emplace_back(SDL_Point{452, 380}, SDL_Point{480, 380});
    arrayOfRails.emplace_back(SDL_Point{138, 421}, SDL_Point{290, 421});
    arrayOfRails.emplace_back(SDL_Point{290, 421}, SDL_Point{330, 421});

    //vertikalt
    arrayOfRails.emplace_back(SDL_Point{330, 421}, SDL_Point{480, 421});
    arrayOfRails.emplace_back(SDL_Point{138, 37}, SDL_Point{138, 92});
    arrayOfRails.emplace_back(SDL_Point{138, 92}, SDL_Point{138, 133});
    arrayOfRails.emplace_back(SDL_Point{138, 298}, SDL_Point{138, 339});
    arrayOfRails.emplace_back(SDL_Point{138, 380}, SDL_Point{138, 421});
    arrayOfRails.emplace_back(SDL_Point{166, 339}, SDL_Point{166, 380});
    arrayOfRails.emplace_back(SDL_Point{207, 37}, SDL_Point{207, 92});
    arrayOfRails.emplace_back(SDL_Point{207, 92}, SDL_Point{207, 133});
    arrayOfRails.emplace_back(SDL_Point{207, 133}, SDL_Point{207, 215});
    arrayOfRails.emplace_back(SDL_Point{207, 215}, SDL_Point{207, 298});
    arrayOfRails.emplace_back(SDL_Point{207, 298}, SDL_Point{207, 339});
    arrayOfRails.emplace_back(SDL_Point{207, 339}, SDL_Point{207, 380});
    arrayOfRails.emplace_back(SDL_Point{249, 92}, SDL_Point{249, 133});
    arrayOfRails.emplace_back(SDL_Point{249, 174}, SDL_Point{249, 215});
    arrayOfRails.emplace_back(Rails({249, 215}, {249, 257}));
    arrayOfRails.emplace_back(Rails({249, 257}, {249, 298}));
    arrayOfRails.emplace_back(Rails({249, 339}, {249, 380}));
    arrayOfRails.emplace_back(Rails({290, 37}, {290, 92}));
    arrayOfRails.emplace_back(Rails({290, 133}, {290, 174}));
    arrayOfRails.emplace_back(Rails({290, 298}, {290, 339}));
    arrayOfRails.emplace_back(Rails({290, 380}, {290, 421}));
    arrayOfRails.emplace_back(Rails({330, 37}, {330, 92}));
    arrayOfRails.emplace_back(Rails({330, 133}, {330, 174}));
    arrayOfRails.emplace_back(Rails({330, 298}, {330, 339}));
    arrayOfRails.emplace_back(Rails({330, 380}, {330, 421}));
    arrayOfRails.emplace_back(Rails({371, 92}, {371, 133}));
    arrayOfRails.emplace_back(Rails({371, 174}, {371, 215}));
    arrayOfRails.emplace_back(Rails({371, 215}, {371, 257}));
    arrayOfRails.emplace_back(Rails({371, 257}, {371, 298}));
    arrayOfRails.emplace_back(Rails({371, 339}, {371, 380}));

    arrayOfRails.emplace_back(Rails({412, 37}, {412, 92}));
    arrayOfRails.emplace_back(Rails({412, 92}, {412, 133}));
    arrayOfRails.emplace_back(Rails({412, 133}, {412, 215}));
    arrayOfRails.emplace_back(Rails({412, 215}, {412, 298}));
    arrayOfRails.emplace_back(Rails({412, 298}, {412, 339}));
    arrayOfRails.emplace_back(Rails({412, 339}, {412, 380}));
    arrayOfRails.emplace_back(Rails({452, 339}, {452, 380}));
    arrayOfRails.emplace_back(Rails({480, 37}, {480, 92}));
    arrayOfRails.emplace_back(Rails({480, 92}, {480, 133}));
    arrayOfRails.emplace_back(Rails({480, 298}, {480, 339}));
    arrayOfRails.emplace_back(Rails({480, 380}, {480, 421}));

    // ghost castle
    arrayOfRails.emplace_back(Rails({280, 222}, {310, 222}));
    arrayOfRails.emplace_back(Rails({310, 222}, {340, 222}));
    arrayOfRails.emplace_back(Rails({280, 200}, {280, 222}));
    arrayOfRails.emplace_back(Rails({310, 174}, {310, 222}));
    arrayOfRails.emplace_back(Rails({340, 200}, {340, 222}));

}

Map::~Map()
{}

Map *Map::getInstance()
{
    if (!instance) {
        instance = new Map;
    }
    return instance;
}

void Map::deleteInstance()
{
    if (instance) {
        delete instance;
    }
    instance = nullptr;
}

std::vector<Rails> Map::getRails()
{
    return arrayOfRails;
}

void Map::renderMap()
{
    SDL_RenderCopy(Screen::renderer, Map::txMap, nullptr, nullptr);
}