#include <stdio.h>
#include <stdlib.h>
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

//Needs uppercase hex values E.g. 0x3C
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

int main(int argc, char **argv)
{
	if(argc < 3){
		printf("Usage: %s {string} {string}\n", argv[0]);
		exit(1);
	}
		
	char* a = argv[1];
	char* b = argv[2];
	int n = strlen(a);

	printf("Length: %d\n", n);

	if(n != strlen(b)){
		printf("Lengths of strings are not equal.\n");
		exit(2);
	}

	char* a_hex = chars_to_hex(a, n);
	char* b_hex = chars_to_hex(b, n);
	char* xored = malloc(sizeof(char) * n/2);

	for(int i = 0; i < n/2; i++){
		xored[i] = a_hex[i] ^ b_hex[i];
	}

	printf("A: %s\n", a);
	printf("B: %s\n", b);

	printf("XORED: %s\n", xored);

	//Output as hex bytes 
	for(int i = 0; i < n/2; i++){
		printf("%x", xored[i]);
	}
	printf("\n");

	return 0;
}
