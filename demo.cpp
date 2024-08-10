#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>
#include <random>
#include "card.h"
#include "paths.h"


int main() {
    // Array to hold textures
    sf::Texture textures[52];
    std::vector<card> deck(52);

    int count = 0;
    for (int i = 0; i < 4; i++) {
        for (int j = 1; j < 14; j++) {
            if (!textures[count].loadFromFile(cardpaths[i][j])) {
                std::cout << "Error loading texture: " << cardpaths[i][j] << std::endl;
                return -1;  // Exit if texture loading fails
            }

            sf::Sprite sprite;
            sprite.setTexture(textures[count]);
            sprite.scale(0.2f, 0.2f);

            deck[count].getcard(j, cardpaths[i][0], sprite);
            count++;
        }
    }

    std::random_device rd;  // Obtain a random number from hardware
    std::mt19937 g(rd());   // Seed the generator
    std::shuffle(deck.begin(), deck.end(), g);  // Shuffle the deck
    sf::RenderWindow window(sf::VideoMode(1000, 800), "Sprite Example");

    while (window.isOpen()) {
        sf::Event event{};
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }
        sf::Texture back;
        if(!back.loadFromFile("../card img/jocker/backview.jpg")) {
            std::cout<<"error";
        }

        sf::Sprite deckview;
        deckview.scale(0.2f, 0.2f);
        deckview.setTexture(back);

        deckview.setPosition(800.f, 240.f);  // Example: position first card


        deck[0].img.setPosition(100.f, 520.f);  // Example: position first card
        deck[1].img.setPosition(200.f, 520.f);
        deck[2].img.setPosition(300.f, 520.f);  // Example: position first card
        deck[3].img.setPosition(400.f, 520.f);
        deck[4].img.setPosition(500.f, 520.f);  // Example: position first card
        deck[5].img.setPosition(600.f, 520.f);
        deck[6].img.setPosition(700.f, 520.f);  // Example: position first card

        window.clear();

        window.draw(deck[0].img);  // Draw the first card after shuffling
        window.draw(deck[1].img);
        window.draw(deck[2].img);
        window.draw(deck[3].img);
        window.draw(deck[4].img);
        window.draw(deck[5].img);
        window.draw(deck[6].img);
        window.draw(deckview);
        window.display();
    }


    return 0;
}
