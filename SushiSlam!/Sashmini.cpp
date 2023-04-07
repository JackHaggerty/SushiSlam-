#include "Sashimi.h"

// sashimi card

Card::CardType Sashimi::Type() const {
    return m_type;
}
std::string Sashimi::str() const {
    return "Sashimi";
}
