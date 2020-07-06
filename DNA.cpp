#include "DNA.h"

DNA::DNA(const DnaSequence& seq, const std::string& name, size_t id):m_seq(seq), m_name(name), m_id(id) {}


void DNA::setSeq(const DnaSequence& seq) {
    m_seq = seq;
}

void DNA::setName(const std::string& name) {
    m_name = name;
}

void DNA::setId(size_t id) {
    m_id = id;
}

DnaSequence DNA::getSeq() {
    return m_seq;
}

std::string DNA::getName() {
    return m_name;
}

size_t DNA::getId() {
    return m_id;
}


