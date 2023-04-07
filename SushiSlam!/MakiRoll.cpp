#include "MakiRoll.h"
// maki roll card

MakiRoll::MakiRoll(int numRolls) : m_numRolls(numRolls), m_type(CardType::MakiRoll_1) {
    switch (numRolls) {
        // valid entries, once match is made, break
    case 1: m_type = MakiRoll_1; break;
    case 2: m_type = MakiRoll_2; break;
    case 3: m_type = MakiRoll_3; break;
    }
}
MakiRoll::CardType MakiRoll::Type() const {
    return m_type;
}
// tostring
std::string MakiRoll::str() const  {
    return "MakiRoll (" + std::to_string(m_numRolls) + ")";
}
