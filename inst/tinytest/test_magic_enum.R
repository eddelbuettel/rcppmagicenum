
library(RcppMagicEnum)
library(tinytest)

Rcpp::sourceCpp("cpp/testcode.cpp")

expect_equal(getString(), "RED")
expect_equal(getInteger(), -10)
expect_equal(getSequence(), c("RED", "BLUE", "GREEN"))

expect_equal(getValueFromString("RED"), -10)
expect_equal(getValueFromString("BLUE"), 0)
expect_equal(getValueFromString("GREEN"), 10)
expect_equal(getValueFromString("doesNotExists"), NA_integer_)

expect_equal(getCount(), 3)
