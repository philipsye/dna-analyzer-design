#ifndef DNA_SEQUENCE_DNA_H
#define DNA_SEQUENCE_DNA_H

#include "DnaSequence.h"
enum Status{
    E_New,
    E_Modified,
    E_UpToDate
};


class DNA {

public:
   DNA(const DnaSequence& seq, const std::string& name, size_t id);

    void setSeq(const DnaSequence&);
    void setName(const std::string&);
    void setId(size_t);

    DnaSequence getSeq();
    std::string getName();
    size_t getId();

private:
    DnaSequence m_seq;
    std::string m_name;
    size_t m_id;
    Status m_status;
};


#endif //DNA_SEQUENCE_DNA_H
