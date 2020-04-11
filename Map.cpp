//
// Created by fredr on 02.04.2020.
//

#include "Map.h"

Map *Map::instance = nullptr;

Map::Map() {
    txMap = Screen::loadImage("../data/gfx/hintergrund2.png", -1);
    arrayOfRails.emplace_back(Rails({138, 37}, {207, 37}));
    arrayOfRails.emplace_back(Rails({207, 37}, {290, 37}));
    arrayOfRails.emplace_back(Rails({330, 37}, {412, 37}));
    arrayOfRails.emplace_back(Rails({412, 37}, {480, 37}));
    arrayOfRails.emplace_back(Rails({138, 92}, {207, 92}));
    arrayOfRails.emplace_back(Rails({207, 92}, {249, 92}));
    arrayOfRails.emplace_back(Rails({249, 92}, {290, 92}));
    arrayOfRails.emplace_back(Rails({290, 92}, {330, 92}));
    arrayOfRails.emplace_back(Rails({330, 92}, {371, 92}));
    arrayOfRails.emplace_back(Rails({371, 92}, {412, 92}));
    arrayOfRails.emplace_back(Rails({412, 92}, {480, 92}));
    arrayOfRails.emplace_back(Rails({138, 133}, {207, 133}));

    arrayOfRails.emplace_back(Rails({249, 133}, {290, 133}));

    arrayOfRails.emplace_back(Rails({330, 133}, {371, 133}));
    arrayOfRails.emplace_back(Rails({412, 133}, {480, 133}));
    arrayOfRails.emplace_back(Rails({249, 174}, {290, 174}));
    castleRails.emplace_back(arrayOfRails.back());
    arrayOfRails.emplace_back(Rails({290, 174}, {310, 174}));
    castleRails.emplace_back(arrayOfRails.back());
    arrayOfRails.emplace_back(Rails({310, 174}, {330, 174}));
    castleRails.emplace_back(arrayOfRails.back());
    arrayOfRails.emplace_back(Rails({330, 174}, {371, 174}));
    castleRails.emplace_back(arrayOfRails.back());
    arrayOfRails.emplace_back(Rails({100, 215}, {207, 215})); // tunnel left
    castleRails.emplace_back(arrayOfRails.back());
    arrayOfRails.emplace_back(Rails({207, 215}, {249, 215}));
    castleRails.emplace_back(arrayOfRails.back());
    arrayOfRails.emplace_back(Rails({371, 215}, {412, 215}));
    castleRails.emplace_back(arrayOfRails.back());
    arrayOfRails.emplace_back(Rails({412, 215}, {515, 215})); // tunnel right
    castleRails.emplace_back(arrayOfRails.back());
    arrayOfRails.emplace_back(Rails({249, 257}, {371, 257}));
    castleRails.emplace_back(arrayOfRails.back());
    arrayOfRails.emplace_back(Rails({138, 298}, {207, 298}));
    arrayOfRails.emplace_back(Rails({207, 298}, {249, 298}));
    arrayOfRails.emplace_back(Rails({249, 298}, {290, 298}));
    arrayOfRails.emplace_back(Rails({330, 298}, {371, 298}));
    arrayOfRails.emplace_back(Rails({371, 298}, {412, 298}));
    arrayOfRails.emplace_back(Rails({412, 298}, {480, 298}));
    arrayOfRails.emplace_back(Rails({138, 339}, {166, 339}));
    arrayOfRails.emplace_back(Rails({207, 339}, {249, 339}));
    arrayOfRails.emplace_back(Rails({249, 339}, {290, 339}));
    arrayOfRails.emplace_back(Rails({290, 339}, {330, 339}));
    arrayOfRails.emplace_back(Rails({330, 339}, {371, 339}));
    arrayOfRails.emplace_back(Rails({371, 339}, {412, 339}));
    arrayOfRails.emplace_back(Rails({452, 339}, {480, 339}));
    arrayOfRails.emplace_back(Rails({138, 380}, {166, 380}));
    arrayOfRails.emplace_back(Rails({166, 380}, {207, 380}));
    arrayOfRails.emplace_back(Rails({249, 380}, {290, 380}));
    arrayOfRails.emplace_back(Rails({330, 380}, {371, 380}));
    arrayOfRails.emplace_back(Rails({412, 380}, {452, 380}));
    arrayOfRails.emplace_back(Rails({452, 380}, {480, 380}));
    arrayOfRails.emplace_back(Rails({138, 421}, {290, 421}));
    arrayOfRails.emplace_back(Rails({290, 421}, {330, 421}));
    arrayOfRails.emplace_back(Rails({330, 421}, {480, 421}));


    //vertikalt
    arrayOfRails.emplace_back(Rails({138, 37}, {138, 92}));
    arrayOfRails.emplace_back(Rails({138, 92}, {138, 133}));
    arrayOfRails.emplace_back(Rails({138, 298}, {138, 339}));
    arrayOfRails.emplace_back(Rails({138, 380}, {138, 421}));
    arrayOfRails.emplace_back(Rails({166, 339}, {166, 380}));
    arrayOfRails.emplace_back(Rails({207, 37}, {207, 92}));
    arrayOfRails.emplace_back(Rails({207, 92}, {207, 133}));
    arrayOfRails.emplace_back(Rails({207, 133}, {207, 215}));
    arrayOfRails.emplace_back(Rails({207, 215}, {207, 298}));
    arrayOfRails.emplace_back(Rails({207, 298}, {207, 339}));
    arrayOfRails.emplace_back(Rails({207, 339}, {207, 380}));
    arrayOfRails.emplace_back(Rails({249, 92}, {249, 133}));
    arrayOfRails.emplace_back(Rails({249, 174}, {249, 215}));
    castleRails.emplace_back(arrayOfRails.back());
    arrayOfRails.emplace_back(Rails({249, 215}, {249, 257}));
    castleRails.emplace_back(arrayOfRails.back());
    arrayOfRails.emplace_back(Rails({249, 257}, {249, 298}));
    castleRails.emplace_back(arrayOfRails.back());
    arrayOfRails.emplace_back(Rails({249, 339}, {249, 380}));
    arrayOfRails.emplace_back(Rails({290, 37}, {290, 92}));
    arrayOfRails.emplace_back(Rails({290, 133}, {290, 174}));
    castleRails.emplace_back(arrayOfRails.back());
    arrayOfRails.emplace_back(Rails({290, 298}, {290, 339}));
    arrayOfRails.emplace_back(Rails({290, 380}, {290, 421}));
    arrayOfRails.emplace_back(Rails({330, 37}, {330, 92}));
    arrayOfRails.emplace_back(Rails({330, 133}, {330, 174}));
    castleRails.emplace_back(arrayOfRails.back());
    arrayOfRails.emplace_back(Rails({330, 298}, {330, 339}));
    arrayOfRails.emplace_back(Rails({330, 380}, {330, 421}));
    arrayOfRails.emplace_back(Rails({371, 92}, {371, 133}));
    arrayOfRails.emplace_back(Rails({371, 174}, {371, 215}));
    castleRails.emplace_back(arrayOfRails.back());
    arrayOfRails.emplace_back(Rails({371, 215}, {371, 257}));
    castleRails.emplace_back(arrayOfRails.back());
    arrayOfRails.emplace_back(Rails({371, 257}, {371, 298}));
    castleRails.emplace_back(arrayOfRails.back());
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
    castleRails.emplace_back(arrayOfRails.back());
    arrayOfRails.emplace_back(Rails({310, 222}, {340, 222}));
    castleRails.emplace_back(arrayOfRails.back());
    arrayOfRails.emplace_back(Rails({280, 200}, {280, 222}));
    castleRails.emplace_back(arrayOfRails.back());
    arrayOfRails.emplace_back(Rails({310, 174}, {310, 222}));
    castleRails.emplace_back(arrayOfRails.back());
    arrayOfRails.emplace_back(Rails({340, 200}, {340, 222}));
    castleRails.emplace_back(arrayOfRails.back());

}

Map::~Map() {
}

Map *Map::getInstance() {
    if (!instance) {
        instance = new Map;
    }
    return instance;
}

void Map::initPills() {

    double initDistance = 0;
    SDL_Point start = {138, 37};

    for (Rails rail : arrayOfRails) {
        bool nextRail = false;
        for (Rails castleRails : castleRails) {
            if (castleRails == rail) {
                nextRail = true;
                break;
            }
        }

        if (nextRail == true)
            continue;
        if (rail.start.y == rail.end.y) {
            if (&rail.start == start) {
                initDistance += abs(rail.start.x - rail.end.x);
                start = rail.end;
            } else {
                int maxPills = round(initDistance / 15);
                int spacing = 10;
                int distance = initDistance;
                for (int pill = 0; pill < maxPills; pill++) {
                    pills.emplace_back(new Pill({start.x - distance + spacing, start.y + 10}));
                    spacing += 15;
                }
                if (rail.start.y == rail.end.y)
                    initDistance = abs(rail.start.x - rail.end.x);
                else
                    initDistance = abs(rail.start.y - rail.end.y);
                start = rail.end;
            }
        } else if (rail.start.x == rail.end.x) {
            if (&rail.start == start) {
                initDistance += abs(rail.start.y - rail.end.y);
                start = rail.end;
            } else {
                initDistance - 15;
                int maxPills = round(initDistance / 15);
                int spacing = 25;
                int distance = initDistance;
                for (int pill = 0; pill < maxPills; pill++) {
                    pills.emplace_back(new Pill({start.x + 10, start.y - distance + spacing}));
                    spacing += 15;
                }
                initDistance = abs(rail.start.y - rail.end.y);
                start = rail.end;
            }
        }
    }

    /*7for (Rails &rail : arrayOfRails) {
        bool nextRail = false;
        for (Rails castleRails : castleRails) {
            if (castleRails == rail) {
                nextRail = true;
                break;
            }
        }

        if (nextRail == true)
            continue;
        int spacing = 10;

        if (rail.start.y == rail.end.y) {
            double distance = rail.end.x - rail.start.x;
            int maxPills = round(distance / spacing);
            for (int pill = 0; pill < maxPills; pill++) {
                bool nextPill = false;
                for (Rails rail2 : arrayOfRails) {
                    if (nextPill)
                        break;
                    for (Pill *pill1 : rail2.pills) {
                        SDL_Point pos = pill1->getPos();
                        if (!(pos.x + spacing == rail.start.x && pos.y + 10 == rail.start.y)) {
                            continue;
                        } else {
                            nextPill = true;
                            break;
                        }
                    }
                }

                if (nextPill) {
                    spacing += 14;
                    continue;
                }
                if ((spacing + rail.start.x) > rail.end.x || (rail.start.x + spacing) > (rail.end.x - 14)) {
                    rail.pills.emplace_back(new Pill({rail.end.x, rail.start.y + 10}));
                } else {
                    rail.pills.emplace_back(new Pill({rail.start.x + spacing, rail.start.y + 10}));
                    spacing += 14;
                }
            }
        } else if (rail.start.x == rail.end.x) {
            double distance = rail.end.y - rail.start.y;
            int maxPills = round(distance / spacing);
            for (int pill = 0; pill < maxPills; pill++) {
                bool nextPill = false;
                for (Rails rail2 : arrayOfRails) {
                    if (nextPill)
                        break;
                    for (Pill *pill1 : rail2.pills) {
                        SDL_Point pos = pill1->getPos();
                        if (!(pos.x + 10 == rail.start.x && pos.y == rail.start.y + spacing)) {
                            continue;
                        } else {
                            nextPill = true;
                            break;
                        }
                    }
                }

                if (nextPill) {
                    spacing += 14;
                    continue;
                }
                if ((spacing + rail.start.y) > rail.end.y || (rail.start.y + spacing) > (rail.end.y - 14))
                    rail.pills.emplace_back(new Pill({rail.start.x + 10, rail.end.y}));
                else {
                    rail.pills.emplace_back(new Pill({rail.start.x + 10, rail.start.y + spacing}));
                    spacing += 14;
                }
            }
        }

        if (&rail.start == SDL_Point{330, 133} && &rail.end == SDL_Point{371, 133}) {
            rail.pills.emplace_back(new Pill({rail.end.x + 10, rail.end.y + 10}));
        } else if (&rail.start == SDL_Point{249, 133} && &rail.end == SDL_Point{290, 133}) {
            rail.pills.emplace_back(new Pill({rail.end.x + 10, rail.end.y + 10}));
        } else if (&rail.start == SDL_Point{166, 380} && &rail.end == SDL_Point{207, 380}) {
            rail.pills.emplace_back(new Pill({rail.end.x + 10, rail.end.y + 10}));
        } else if (&rail.start == SDL_Point{412, 133} && &rail.end == SDL_Point{480, 133}) {
            rail.pills.emplace_back(new Pill({rail.end.x + 10, rail.end.y + 10}));
        } else if (&rail.start == SDL_Point{452, 339} && &rail.end == SDL_Point{480, 339}) {
            rail.pills.emplace_back(new Pill({rail.end.x + 10, rail.end.y + 10}));
        } else if (&rail.start == SDL_Point{330, 421} && &rail.end == SDL_Point{480, 421}) {
            rail.pills.emplace_back(new Pill({rail.end.x + 10, rail.end.y + 10}));
        } else if(&rail.start == SDL_Point{330, 380} && &rail.end == SDL_Point{371, 380}) {
            rail.pills.emplace_back(new Pill({rail.end.x + 10, rail.end.y + 10}));
        }
    }*/
}

void Map::deleteInstance() {
    if (instance) {
        delete instance;
    }
    instance = nullptr;
}

std::vector<Rails> Map::getRails() {
    return arrayOfRails;
}

std::vector<Pill*> Map::getPills()
{
    return pills;
}

void Map::renderMap() {
    SDL_RenderCopy(Screen::renderer, Map::txMap, nullptr, nullptr);
}