#ifndef SHA1_UTILS_H
#define SHA1_UTILS_H

/**
 * struct sha1 - helper struct holding a computed sha1
 *
 * @hash:	computed digest
 * @size:	size of the digest in bytes
 *
 * This struct should be freed with sha1_destroy()
 */
struct sha1 {
	uint8_t hash[EVP_MAX_MD_SIZE];
	unsigned int size;
};

/**
 * sha1_build() - build a sha1 digest from buffer
 *
 * @sz:		size of buf in bytes
 *
 * The computed sha1 should be liberated with sha1_destroy()
 *
 * Return: computed sha1 or NULL on error
 */
struct sha1 *sha1_build(const char *buf, size_t sz);

/**
 * sha1_destroy() - destroy an sha1 helper struct
 */
void sha1_destroy(struct sha1 *sha1);

#endif /* !SHA1_UTILS_H */
