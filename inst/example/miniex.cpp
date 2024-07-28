
// [[Rcpp::depends(RcppMagicEnum)]]

#include <RcppMagicEnum>

// define a simple enum class, it uses optional typing as well as optional assigned values
enum class Color : int { RED = -10, BLUE = 0, GREEN = 10 };

// [[Rcpp::export]]
void example() {
    // instantiate an enum value in variable 'val'
    auto val = Color::RED;

    // show the current value on stdout
    Rcpp::Rcout << "Name of enum: " << magic_enum::enum_name(val) << std::endl;
    Rcpp::Rcout << "Integer value of enum: " << magic_enum::enum_integer(val) << std::endl;
}

/*** R
example()
*/
