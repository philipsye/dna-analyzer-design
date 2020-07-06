//
// Created by a on 7/5/20.
//

#include "commands.h"

size_t commands::m_id = 0;

size_t commands::returnId() {
    return ++m_id;
}