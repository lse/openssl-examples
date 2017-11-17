#include <openssl/evp.h>

#include "sha1-utils.h"

struct sha1 *sha1_build(const char *buf, size_t sz)
{
	EVP_MD_CTX *md_ctx;
	const EVP_MD *md = EVP_sha1();

	md_ctx = EVP_MD_CTX_new();
	if (!md_ctx)
		return NULL;

	EVP_DigestInit_ex(md_ctx, md, NULL);
	EVP_DigestUpdate(md_ctx, buf, sz);

	struct sha1 *sha1digest = malloc(sizeof(*sha1digest));
	if (!sha1digest) {
		EVP_MD_CTX_free(md_ctx);
		return NULL;
	}

	EVP_DigestFinal_ex(md_ctx, sha1digest->hash, &sha1digest->size);

	EVP_MD_CTX_free(md_ctx);

	return sha1digest;
}

void sha1_destroy(struct sha1 *sha1)
{
	free(sha1);
}
