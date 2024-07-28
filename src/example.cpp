
// This file is adapted from the upstream example by swapping in Rcpp::Rcout as
// to keep R happy, making it R callable, adding a roxygen header for the example
// function and including a catch-all header

// catch-all header also include Rcpp if not already included
#include <RcppMagicEnum>

enum class Color : int { RED = -10, BLUE = 0, GREEN = 10 };

template <typename E>
auto to_integer(magic_enum::Enum<E> value) {
    // magic_enum::Enum<E> - C++17 Concept for enum type.
    return static_cast<magic_enum::underlying_type_t<E>>(value);
}

//' Examples of \sQuote{magic_enum} use via \pkg{RcppMagicEnum}
//'
//' This example, directly almost verbatim from the upstream \code{README.md}
//' shows several simple usage patterns for enumerations enabled by the package.
//' @examples
//' magic_enum_example()
// [[Rcpp::export]]
void magic_enum_example() {
    // Enum variable to string name.
    Color c1 = Color::RED;
    auto c1_name = magic_enum::enum_name(c1);
    Rcpp::Rcout << c1_name << std::endl; // RED

    // String enum name sequence.
    constexpr auto names = magic_enum::enum_names<Color>();
    Rcpp::Rcout << "Color names:";
    for (const auto& n : names) {
        Rcpp::Rcout << " " << n;
    }
    Rcpp::Rcout << std::endl;
    // Color names: RED BLUE GREEN

    // String name to enum value.
    auto c2 = magic_enum::enum_cast<Color>("BLUE");
    if (c2.has_value()) {
        Rcpp::Rcout << "BLUE = " << to_integer(c2.value()) << std::endl; // BLUE = 0
    }

    // Case insensitive enum_cast.
    c2 = magic_enum::enum_cast<Color>("blue", magic_enum::case_insensitive);
    if (c2.has_value()) {
        Rcpp::Rcout << "BLUE = " << to_integer(c2.value()) << std::endl; // BLUE = 0
    }

    // Integer value to enum value.
    auto c3 = magic_enum::enum_cast<Color>(10);
    if (c3.has_value()) {
        Rcpp::Rcout << "GREEN = " << magic_enum::enum_integer(c3.value()) << std::endl; // GREEN = 10
    }

    // Enum value to integer value.
    auto c4_integer = magic_enum::enum_integer(Color::RED);
    Rcpp::Rcout << "RED = " << c4_integer << std::endl; // RED = -10

    using magic_enum::iostream_operators::operator<<; // out-of-the-box ostream operator for all enums.
    // Ostream operator for enum.
    Rcpp::Rcout << "Color: " << c1 << " " << c2 << " " << c3 << std::endl; // Color: RED BLUE GREEN

    // Number of enum values.
    Rcpp::Rcout << "Color enum size: " << magic_enum::enum_count<Color>() << std::endl; // Color size: 3

    // Indexed access to enum value.
    Rcpp::Rcout << "Color[0] = " << magic_enum::enum_value<Color>(0) << std::endl; // Color[0] = RED

    // Enum value sequence.
    constexpr auto values = magic_enum::enum_values<Color>();
    Rcpp::Rcout << "Colors values:";
    for (const auto c : values) {
        Rcpp::Rcout << " " << c; // Ostream operator for enum.
    }
    Rcpp::Rcout << std::endl;
    // Color values: RED BLUE GREEN

    enum class Flags { A = 1, B = 2, C = 4, D = 8 };
    using namespace magic_enum::bitwise_operators; // out-of-the-box bitwise operators for all enums.
    // Support operators: ~, |, &, ^, |=, &=, ^=.
    Flags flag = Flags::A | Flags::C;
    Rcpp::Rcout << flag << std::endl; // 5

    enum color { red, green, blue };

    // Checks whether type is an Unscoped enumeration.
    static_assert(magic_enum::is_unscoped_enum_v<color>);
    static_assert(!magic_enum::is_unscoped_enum_v<Color>);
    static_assert(!magic_enum::is_unscoped_enum_v<Flags>);

    // Checks whether type is an Scoped enumeration.
    static_assert(!magic_enum::is_scoped_enum_v<color>);
    static_assert(magic_enum::is_scoped_enum_v<Color>);
    static_assert(magic_enum::is_scoped_enum_v<Flags>);

    // Enum pair (value enum, string enum name) sequence.
    constexpr auto entries = magic_enum::enum_entries<Color>();
    Rcpp::Rcout << "Colors entries:";
    for (const auto& e : entries) {
        Rcpp::Rcout << " "  << e.second << " = " << static_cast<int>(e.first);
    }
    Rcpp::Rcout << std::endl;
    // Color entries: RED = -10 BLUE = 0 GREEN = 10

    //return 0;
}
