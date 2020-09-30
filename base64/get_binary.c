#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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

int b64_length(int s_len)
{
	int b64_len = s_len;
	b64_len += (b64_len % 3) ? 3 - (b64_len % 3) : 0;
	b64_len /= 3;
	b64_len *= 4;
	return b64_len;
}


int main(int argc, char **argv)
{
	if(argc < 2){
		printf("Nope...");
		exit(1);
	}

	char *arr = argv[1];
	int n = 10;
	int b_count = 0;
	int i = 0;
	int offset = 0;

	int n_len = b64_length(n);

	for(int j = 0; j < n; j++){
		printf(BYTE_TO_BINARY_PATTERN" ", BYTE_TO_BINARY(arr[j]));
	}

	printf("\n");

	while(i < n){
		printf("%c", (0x1 & (arr[i] >> (7 - offset))) ? '1' : '0');
		b_count++;
		if(!(b_count % 6)) printf(" ");
		offset = (offset + 1) % 8;
		if(!offset) i++;
	}	

	while(b_count % 6){
		printf("0");
		b_count++;
	}
	 
	printf("\n");
	
	return 0;
}
