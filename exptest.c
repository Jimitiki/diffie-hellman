#include <openssl/bn.h>
#include "modexp.h"

int main(int argc, char *argv[])
{
	BIGNUM *base = BN_new();
	BIGNUM *exponent = BN_new();
	BIGNUM *modulus = BN_new();
	BIGNUM *result = BN_new();

	BN_dec2bn(&base, argv[1]);
	BN_dec2bn(&exponent, argv[2]);
	BN_dec2bn(&modulus, argv[3]);

	modexp(base, exponent, modulus, result);
	char *result_str = BN_bn2dec(result);
	printf("%s ^ %s mod %s = %s\n", argv[1], argv[2], argv[3], result_str);

	BN_free(base);
	BN_free(exponent);
	BN_free(modulus);
	BN_free(result);

	OPENSSL_free(result_str);

	return 0;
}