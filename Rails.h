//
// Created by fredr on 02.04.2020.
//

#ifndef PACMAN_RAILS_H
#define PACMAN_RAILS_H


class Rails {

public:
    Rails(int x1, int y1, int x2, int y2);
    ~Rails();

    bool operator==(const Rails &obj1);

    int x1;
    int y1;
    int x2;
    int y2;

};


#endif //PACMAN_RAILS_H
