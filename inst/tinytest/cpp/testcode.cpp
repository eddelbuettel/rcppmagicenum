
// [[Rcpp::depends(RcppMagicEnum)]]
#include <RcppMagicEnum>

enum class Color : int { RED = -10, BLUE = 0, GREEN = 10 };

// [[Rcpp::export]]
std::string getString() {
    Color c1 = Color::RED;
    std::string s{magic_enum::enum_name(c1)};
    return s;
}

// [[Rcpp::export]]
int getInteger() {
    Color c1 = Color::RED;
    int i{magic_enum::enum_integer(c1)};
    return i;
}

// [[Rcpp::export]]
Rcpp::CharacterVector getSequence() {
    constexpr auto names = magic_enum::enum_names<Color>();
    auto n = names.size();
    Rcpp::CharacterVector sv(n);
    for (auto i = 0; i < n; ++i) sv[i] = std::string(names[i]);
    return sv;
}

template <typename E>
auto to_integer(magic_enum::Enum<E> value) {
    // magic_enum::Enum<E> - C++17 Concept for enum type.
    return static_cast<magic_enum::underlying_type_t<E>>(value);
}

// [[Rcpp::export]]
int getValueFromString(std::string key) {
    auto c2 = magic_enum::enum_cast<Color>(key);
    if (c2.has_value()) {
        return to_integer(c2.value());
    } else {
        return NA_INTEGER;
    }
}

// [[Rcpp::export]]
int getCount() {
    return magic_enum::enum_count<Color>();
}
