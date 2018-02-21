#ifndef MODEXP_H_
#define MODEXP_H_

#include <openssl/bn.h>

BIGNUM *modexp(BIGNUM *base, BIGNUM *exponent, BIGNUM *modulus, BIGNUM *result);

#endif