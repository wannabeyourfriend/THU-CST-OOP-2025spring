#pragma once
#include "card.h"
#include <vector>
#include <list>
#include <iostream>
#include <string>

class Cards {
	std::list<Card> card_pile;
public:
	Cards() = default;
	Cards(std::string name, std::vector<int> vec) {
        for (int num : vec) {
            card_pile.push_back(Card(name, num));
        }
    }
	void put(Card card) {
        card_pile.push_front(card);
    }
	void print() {
        if (card_pile.empty()) {
            std::cout << "empty" << std::endl;
            return;
        }

        bool first = true;
        for (const auto& c : card_pile) {
            if (!first) {
                std::cout << ' ';
            }
            // Uses the overloaded << operator from card.h
            std::cout << c;
            first = false;
        }
        std::cout << std::endl;
    }
	int count() {
        return card_pile.size();
    }
	void merge(Cards &other) {
        // If both piles have cards, perform the XOR operation.
        if (!this->card_pile.empty() && !other.card_pile.empty()) {
            this->card_pile.back().number ^= other.card_pile.front().number;
        }

        // Use splice to efficiently move all cards from the other pile
        // to the end of this pile. This also empties the other pile.
        this->card_pile.splice(this->card_pile.end(), other.card_pile);
    }
};