/**

	Description: CryptoPals Lib
	Author: Zachary Bowditch (Edargorter)
	Year: 2020
	Reason: Fun

**/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
