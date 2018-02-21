#include <openssl/bn.h>
#include "modexp.h"

char *g_str = "5";
char *p_str = "FBBA474C369C0E9D80931431413387BC74DA3A018CB2F9E6D40481B80C380D2681C8822B4EDC2FAA77A4D25654CEFCD1270CBC71385AF1AAA9A1C07C21E9079EBF2BA13DB2C369F5D28A9373DCA85CAE0E9CFC4C5070D48BDBD8863829370F4EE2BE2567";
char *s_str = "75043E106CD4B0858CC7D6AE74EC335CE5CB303ECC40158539AE7F2E38FC87E8FDBEEE7F413DF5F054E6EB5939C387B8F5A3903C863CCB9035EC273B800B7A7380370C69FBAD1F1D88B8B0580399CC7F48733DD37F6473E674C1A3283701650F98ACD0BC";

int main(int argc, char *argv[])
{
	BIGNUM *g = BN_new();
	BN_dec2bn(&g, g_str);

	BIGNUM *s = BN_new();
	BN_hex2bn(&s, s_str);
	BIGNUM *p = BN_new();
	BN_hex2bn(&p, p_str);
	BIGNUM *gtothesmodp = BN_new();

	printf("\n\ng: %s\n\n", BN_bn2dec(g));
	printf("s: %s\n\n", BN_bn2dec(s));
	printf("p: %s\n\n\n\n", BN_bn2dec(p));

	modexp(g, s, p, gtothesmodp);
	char *result_str = BN_bn2dec(gtothesmodp);
	
	printf("g ^ s mod p = %s\n\n\n\n", result_str);

	if (argc > 1)
	{
		BN_dec2bn(&g, g_str);
		BN_hex2bn(&s, s_str);
		BIGNUM *gtothetmodp = BN_new();
		BN_dec2bn(&gtothetmodp, argv[1]);
		printf("g ^ t mod p: %s\n\n\n\n", BN_bn2dec(gtothetmodp));

		BIGNUM *result = BN_new();
		modexp(gtothetmodp, s, p, result);

		printf("(g ^ t mod p) ^ s mod p = %s\n\n", BN_bn2dec(result));
	}



	BN_free(g);
	BN_free(s);
	BN_free(p);
	BN_free(gtothesmodp);

	OPENSSL_free(result_str);

	return 0;
}