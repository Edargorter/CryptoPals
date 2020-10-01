#include "../lib/local_lib.h"

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

	char* a_hex = chars_to_hex(a, n, 0);
	char* b_hex = chars_to_hex(b, n, 0);
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
