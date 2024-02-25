#pragma once

#include "menu.hpp"

namespace ITrofimov {
    const MenuItem* show_menu(const MenuItem* current);

    const MenuItem* exit(const MenuItem* current);

    const MenuItem* data_base(const MenuItem* current);
    const MenuItem* potok(const MenuItem* current);
    const MenuItem* net(const MenuItem* current);
    const MenuItem* go_back(const MenuItem* current);
}
