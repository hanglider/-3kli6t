#include <iostream>

#include "menu.hpp"
#include "menu_functions.hpp"
#include "menu_items.hpp"

int main() {
    system("chcp 65001");
    const ITrofimov::MenuItem* current = &ITrofimov::MAIN;
    while (1) {
        current = current->func(current);
    }
}