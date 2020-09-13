/**

	Description: Base64 encoder / decoder
	Author: Zachary Bowditch (Edargorter)
	Year: 2020

**/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

const char b64_chars[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/"; //Acceptable chars

size_t b64_length(size_t s_length)
{
	size_t b64_size = s_length;
	if(b64_size % 3)
		b64_size += 3 - (b64_size % 3);
	b64_size /= 3;
	b64_size *= 4;
	return b64_size;
}

char *b64_encode(char *str)
{
	size_t s_length = strlen(str);
	size_t b64_size = b64_length(s_length);
	size_t count = 0;

	size_t s_index = 0;
	size_t e_index = 0;

	char s_offset;
	char e_offset;

	char *enc = (char*) malloc((b64_size + 1) * sizeof(char)); // New base64 encoded string
	memset(enc, 0, b64_size);

	printf("Old length: %ld New length: %ld\n", s_length, b64_size);

	char *start = enc;

	enc[b64_size] = '\0';

	for(s_offset = 0, e_offset = 0; count < s_length;){

		*enc |= (*str & (0xC0 >> s_offset)) >> 2;

		s_offset = (s_offset + 1) % 4;
		e_offset = (e_offset + 1) % 3;

		if(!s_offset){
			str++;
			count++;
		}
		if(!e_offset){
			*enc = b64_chars[*enc];
			printf("enc byte: %x \n", *enc);
			enc++;
		}
	}

	memset(enc, 0x3D, b64_size);

	return start;
}

int main(int argc, char **argv)
{
	if(argc < 2){
		printf("Usage: %s [ string ]\n", argv[0]);
		exit(0);
	}
	
	printf("Encoding: %s\n", argv[1]);

	char *enc = b64_encode(argv[1]);

	printf("%s\n", enc);
	return 0;
}
