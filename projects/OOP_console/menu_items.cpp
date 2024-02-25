#include "menu_items.hpp"

#include <cstddef>

#include "menu_functions.hpp"

const ITrofimov::MenuItem ITrofimov::TECNOLOGY_DATA_BASE = {
    "1 - Бызы данных", ITrofimov::data_base, &ITrofimov::STUDY_TECNOLOGY
};
const ITrofimov::MenuItem ITrofimov::TECNOLOGY_POTOK = {
    "2 - Многопоточное программирование!", ITrofimov::potok, &ITrofimov::STUDY_TECNOLOGY
};
const ITrofimov::MenuItem ITrofimov::TECNOLOGY_NET = {
    "3 - Сетевые технологии", ITrofimov::net, &ITrofimov::STUDY_TECNOLOGY
};
const ITrofimov::MenuItem ITrofimov::TECNOLOGY_GO_BACK = {
        "0 - Выйти в предыдущее меню", ITrofimov::go_back, &ITrofimov::STUDY_TECNOLOGY
};

namespace {
    const ITrofimov::MenuItem* const tecnology_children[] = {
        &ITrofimov::TECNOLOGY_GO_BACK,
        &ITrofimov::TECNOLOGY_DATA_BASE,
        &ITrofimov::TECNOLOGY_POTOK,
        &ITrofimov::TECNOLOGY_NET
    };
    const int tecnology_size = sizeof(tecnology_children) / sizeof(tecnology_children[0]);
}

const ITrofimov::MenuItem ITrofimov::STUDY_PROGRAMMING = {
        "1 - Изучать языки программирования", ITrofimov::show_menu, &ITrofimov::LEARNING, nullptr, NULL
};
const ITrofimov::MenuItem ITrofimov::STUDY_ALGORITHMS = {
        "2 - Алгоритмы и структуры данных", ITrofimov::show_menu, &ITrofimov::LEARNING, nullptr, NULL
};
const ITrofimov::MenuItem ITrofimov::STUDY_TECNOLOGY = {
    "3 - Другие технологии", ITrofimov::show_menu, &ITrofimov::LEARNING, tecnology_children, tecnology_size
};
const ITrofimov::MenuItem ITrofimov::STUDY_GO_BACK = {
        "0 - Выйти в главное меню", go_back, &ITrofimov::LEARNING
};

namespace {
    const ITrofimov::MenuItem* const study_children[] = {
            &ITrofimov::STUDY_GO_BACK,
            &ITrofimov::STUDY_PROGRAMMING,
            &ITrofimov::STUDY_ALGORITHMS,
            &ITrofimov::STUDY_TECNOLOGY
    };
    const int study_size = sizeof(study_children) / sizeof(study_children[0]);
}

const ITrofimov::MenuItem ITrofimov::LEARNING = {
    "1 - Изучать програмиирование", ITrofimov::show_menu, &ITrofimov::MAIN, study_children, study_size
};
const ITrofimov::MenuItem ITrofimov::FOOTBALL = {
    "0 - Пойти играть в футбол", ITrofimov::exit, &ITrofimov::MAIN
};

namespace {
    const ITrofimov::MenuItem* const main_children[] = {
        &ITrofimov::FOOTBALL,
        &ITrofimov::LEARNING
    };
    const int main_size = sizeof(main_children) / sizeof(main_children[0]);
}

const ITrofimov::MenuItem ITrofimov::MAIN = {
    nullptr, ITrofimov::show_menu, nullptr, main_children, main_size
};
