/**

	Description: Base64 encoder / decoder
	Author: Zachary Bowditch (Edargorter)
	Year: 2020
	Reason: Fun

**/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//Convenient. From: https://stackoverflow.com/questions/111928/is-there-a-printf-converter-to-print-in-binary-format
#define BYTE_TO_BINARY_PATTERN "%c%c%c%c%c%c%c%c"
#define BYTE_TO_BINARY(byte)  \
  (byte & 0x80 ? '1' : '0'), \
  (byte & 0x40 ? '1' : '0'), \
  (byte & 0x20 ? '1' : '0'), \
  (byte & 0x10 ? '1' : '0'), \
  (byte & 0x08 ? '1' : '0'), \
  (byte & 0x04 ? '1' : '0'), \
  (byte & 0x02 ? '1' : '0'), \
  (byte & 0x01 ? '1' : '0') 

#define DEBUG 1

const char b64_chars[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/="; //Acceptable chars

//Convert hex char array to actual byte array 
char* chars_to_hex(char* hex_string, int n)
{
	char* arr = malloc(sizeof(char) * n/2);
	int big = 1;
	int index = 0;
	for(int i = 0; i < n; i++){
		if(hex_string[i] < 58)
			arr[index] += hex_string[i] - 48;
		else
			arr[index] += hex_string[i] - 55;
			
		if(big)
			arr[index] *= 0x10;
		else
			index++;
		big = !big;
	}	
	return arr;
}

inline size_t b64_length(size_t len)
{
	len += (len % 3) ? 3 - (len % 3) : 0;
	len /= 3;
	len *= 4;
	return len;
}

inline size_t dec_length(size_t len, char padding)
{
	len /= 4;
	len *= 3;
	len -= (size_t) padding;
	return len;
}

char* b64_decode(char *enc)
{
	size_t b64_len = strlen(enc);
	size_t count = b64_len;

	while(!(enc[--count] ^ 0x3D)); //Get padding 

	char padding = char (b64_len - count);
	size_t s_length = dec_length(b64_len, padding);

	char *str = (char*) malloc((s_length + 1) * sizeof(char)); //New base64 decoded string
	str[s_length] = "\0";
	char* start = str;

	char s_offset = 0;
	char e_offset = 2;
	int i = 0;
	
	while(i < count){
		*str |= ((*enc << e_offset) & 0xC0) >> s_offset;

		s_offset = (s_offset + 2) % 8;
		e_offset = (e_offset + 2) % 8;

		if(!s_offset){
			str++;
			i++;
		}

		if(!e_offset){
			enc++;
			e_offset += 2;
		}

	}

	return start;
}

char* b64_encode(char *str)
{
	size_t s_length = strlen(str);
	size_t b64_len = b64_length(s_length);
	size_t count = 0;

	char s_offset = 0;
	char e_offset = 2;

	char *enc = (char*) malloc((b64_len + 1) * sizeof(char)); // New base64 encoded string
	memset(enc, 0, b64_len);

	char *start = enc;
	int e_count = 0;

	enc[b64_len] = '\0';

	while(count < s_length){

		*enc |= ((*str << s_offset) & 0xC0) >> e_offset;

		s_offset = (s_offset + 2) % 8;
		e_offset = (e_offset + 2) % 8;

		if(!s_offset){
			str++;
			count++;
		}

		if(!e_offset){
			enc++;
			e_offset += 2;
			e_count++;
		}
	}

	memset(enc, 0x40, b64_len - e_count);

	for(int i = 0; i < b64_len; i++){
		start[i] = b64_chars[start[i]];	
	}

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
