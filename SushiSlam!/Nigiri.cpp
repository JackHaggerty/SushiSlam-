#include "Nigiri.h"

// nigiri card

Nigiri::Nigiri(const std::string& protein) : m_protein(protein), m_type(CardType::Nigiri_egg) {
 

    if (protein == "Salmon") {
        m_type = Nigiri_salmon;
    }
    else if (protein == "Egg") {
        m_type = Nigiri_egg;
    }
    else if (protein == "Squid") {
        m_type = Nigiri_squid;
    }
}
Card::CardType Nigiri::Type() const {
    return m_type;
}
std::string Nigiri::str() const {
    return "Nigiri (" + m_protein + ")";
}

    