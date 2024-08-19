
## RcppMagicEnum: Rcpp Bindings to Magic Enum Library

[![CI](https://github.com/eddelbuettel/rcppmagicenum/workflows/ci/badge.svg)](https://github.com/eddelbuettel/rcppmagicenum/actions?query=workflow%3Aci)
[![License](https://img.shields.io/badge/License-MIT-orange.svg)](https://opensource.org/licenses/MIT)
[![CRAN](https://www.r-pkg.org/badges/version/RcppMagicEnum)](https://cran.r-project.org/package=RcppMagicEnum)
[![Dependencies](https://tinyverse.netlify.app/badge/RcppMagicEnum)](https://cran.r-project.org/package=RcppMagicEnum)
[![Last Commit](https://img.shields.io/github/last-commit/eddelbuettel/rcppmagicenum)](https://github.com/eddelbuettel/rcppmagicenum)

### Motivation

Even Modern C++ does not have proper reflection (yet). The [Magic Enum][magic enum] library by
Daniil Goncharov fills this void for `enum` types, and does so in a header-only fashion that is eay
to deploy (provided recent-enough compilers).

A compelling example is included in the package, more examples are at the [Magic Enum][magic enum]
repository.

### Example

The following file can be passed to `Rcpp::sourceCpp()` as is:

```c++
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
```

It produces the following output (where the 'meta-comment' at the end ensure the included and
created-by-sourcing function `example()` is also called):

```r
> Rcpp::sourceCpp("miniex.cpp")

> example()
Name of enum: RED
Integer value of enum: -10
>
```

### Status

The package is complete and contains a mature version of Magic Enum.

### Contributing

Any problems, bug reports, or features requests for the package can be submitted and handled most
conveniently as [Github issues][issues] in the repository.

Before submitting pull requests, it is frequently preferable to first discuss need and scope in such
an issue ticket.  See the file
[Contributing.md](https://github.com/RcppCore/Rcpp/blob/master/Contributing.md) (in the
[Rcpp](https://github.com/RcppCore/Rcpp) repo) for a brief discussion.

### Authors

For the R package, [Dirk Eddelbuettel](https://github.com/eddelbuettel).

For everything pertaining to Magic Enum: [Daniil Goncharov](https://github.com/Neargye).


[magic enum]: https://github.com/Neargye/magic_enum
[issues]: https://github.com/eddelbuettel/rcppmagicenum/issues
