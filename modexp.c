#include "modexp.h"
#include <openssl/bn.h>

#define print_bn(bn) BN_print_fp(stdout, bn)

BIGNUM *modexp(BIGNUM *base, BIGNUM *exponent, BIGNUM *modulus, BIGNUM *result)
{
	if (BN_is_one(modulus))
	{
		BN_zero(result);
		return result;
	}

	BN_one(result);
	BIGNUM *remainder = BN_new();
	BN_CTX *bn_ctx = BN_CTX_new();
	BN_mod(remainder, base, modulus, bn_ctx);
	BN_copy(base, remainder);

	while (!BN_is_zero(exponent) && !BN_is_negative(exponent))
	{
		if (BN_is_odd(exponent))
		{
			BN_mul(result, result, base, bn_ctx);
			BN_mod(remainder, result, modulus, bn_ctx);
			BN_copy(result, remainder);
		}
		BN_rshift1(exponent, exponent);
		BN_sqr(base, base, bn_ctx);
		BN_mod(remainder, base, modulus, bn_ctx);
		BN_copy(base, remainder);
	}

	BN_free(remainder);
	BN_CTX_free(bn_ctx);
	return result;
}