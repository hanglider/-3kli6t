#include "menu_functions.hpp"

#include <cstdlib>
#include <iostream>

const char* message = "u are owerlocking third level!";
const char* pick = "Make a choise!";

const ITrofimov::MenuItem* ITrofimov::show_menu(const MenuItem* current) {
    std::cout << pick << '\n';
    for (int i = 1; i < current->children_count; i++) {
        std::cout << current->children[i]->title << "\n";
    }
    std::cout << current->children[0]->title << "\n";
    std::cout << " > ";

    int user_input;
    std::cin >> user_input;
    std::cout << "\n";

    return current->children[user_input];
}

const ITrofimov::MenuItem* ITrofimov::exit(const MenuItem* current) {
    std::exit(0);
}

const ITrofimov::MenuItem* ITrofimov::data_base(const MenuItem* current) {
    std::cout << message << "\n";
    return current->parent;
}

const ITrofimov::MenuItem* ITrofimov::potok(const MenuItem* current) {
    std::cout << message << "\n";
    return current->parent;
}

const ITrofimov::MenuItem* ITrofimov::net(const MenuItem* current) {
    std::cout << message << "\n";
    return current->parent;
}

const ITrofimov::MenuItem* ITrofimov::go_back(const MenuItem* current) {
    //std::cout << message << "\n";
    return current->parent->parent;
}

