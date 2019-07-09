#ifndef __SHA1_H__
#define __SHA1_H__

#ifndef __palm_os__
#define __palm_os__
#include <PalmOS.h>
#endif

typedef struct {
	unsigned long state[5];
	unsigned long count[2];
	unsigned char buffer[64];
} SHA1_CTX;

void SHA1Init(SHA1_CTX* context);
void SHA1Update(SHA1_CTX* context, unsigned char* data, unsigned long len);	/* JHB */
void SHA1Final(unsigned char digest[20], SHA1_CTX* context);

#endif