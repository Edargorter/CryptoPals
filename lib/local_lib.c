/**

	Description: CryptoPals Lib
	Author: Zachary Bowditch (Edargorter)
	Year: 2020
	Reason: Fun

**/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Convert from hex chars to byte array 
char* chars_to_hex(char* hex_string, int n, int upper)
{
	char* arr = malloc(sizeof(char) * n/2);
	int big = 1;
	int l_offset = upper ? 55 : 85;
	int index = 0;
	for(int i = 0; i < n; i++){
		if(hex_string[i] < 58)
			arr[index] += hex_string[i] - 48;
		else
			arr[index] += hex_string[i] - l_offset;
			
		if(big)
			arr[index] *= 0x10;
		else
			index++;
		big = !big;
	}	
	return arr;
}
