#ifndef FRONTEND_INCLUDE_LEXEM_TABLES_HPP
#define FRONTEND_INCLUDE_LEXEM_TABLES_HPP

#include <array>
#include <cstdint>
#include "common.hpp"

namespace language {

constexpr std::size_t max_code = 256;

enum : uint8_t { KNone = 0, KBinop = 1, KIdent = 2 };

inline constexpr std::array<uint8_t, 256> kKind = []{
    std::array<uint8_t,max_code> a{}; 
    a[static_cast<unsigned char>('+')] = KBinop;
    a[static_cast<unsigned char>('-')] = KBinop;
    a[static_cast<unsigned char>('*')] = KBinop;
    a[static_cast<unsigned char>('?')] = KBinop;
    a[static_cast<unsigned char>('/')] = KBinop;
    a[static_cast<unsigned char>('^')] = KBinop;
    a[static_cast<unsigned char>('=')] = KBinop;

    a[static_cast<unsigned char>(';')] = KIdent;
    a[static_cast<unsigned char>('(')] = KIdent;
    a[static_cast<unsigned char>(')')] = KIdent;
    return a;
}();

inline constexpr std::array<uint8_t, max_code> kVal = []{
    std::array<uint8_t,max_code> a{};
    a[static_cast<unsigned char>('+')] = static_cast<uint8_t>(Binary_operators::operator_add);
    a[static_cast<unsigned char>('-')] = static_cast<uint8_t>(Binary_operators::operator_sub);
    a[static_cast<unsigned char>('*')] = static_cast<uint8_t>(Binary_operators::operator_mul);
    a[static_cast<unsigned char>('?')] = static_cast<uint8_t>(Binary_operators::operator_input);
    a[static_cast<unsigned char>('/')] = static_cast<uint8_t>(Binary_operators::operator_div);
    a[static_cast<unsigned char>('^')] = static_cast<uint8_t>(Binary_operators::operator_pow);
    a[static_cast<unsigned char>('=')] = static_cast<uint8_t>(Binary_operators::operator_assign);

    a[static_cast<unsigned char>(';')] = static_cast<uint8_t>(Identifiers::id_semicolon);
    a[static_cast<unsigned char>('(')] = static_cast<uint8_t>(Identifiers::id_left_parenthesis);
    a[static_cast<unsigned char>(')')] = static_cast<uint8_t>(Identifiers::id_right_parenthesis);
    return a;
}();

} // namespace language

#endif // FRONTEND_INCLUDE_LEXEM_TABLES_HPP