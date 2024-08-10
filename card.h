//
// Created by sahbi on 8/10/2024.
//

#ifndef CARD_H
#define CARD_H
#include <string>
#include <Graphics/Sprite.hpp>
#include <utility>


class card {
private:
public:
    int value{};
    std::string suit;
public:
    sf:: Sprite img;
    card()= default;
    void getcard(int v, std::string s, sf::Sprite i ) {
        value = v;
        suit = std::move(s);
        img = std::move(i);
    };
};



#endif //CARD_H
