/**

	Description: CryptoPals Lib
	Author: Zachary Bowditch (Edargorter)
	Year: 2020
	Reason: Fun

**/

//Convenient. From: https://stackoverflow.com/questions/111928/is-there-a-printf-converter-to-print-in-binary-format
#define byte_to_bin_format "%c%c%c%c%c%c%c%c"
#define byte_to_bin_convert(byte)  \
  (byte & 0x80 ? '1' : '0'), \
  (byte & 0x40 ? '1' : '0'), \
  (byte & 0x20 ? '1' : '0'), \
  (byte & 0x10 ? '1' : '0'), \
  (byte & 0x08 ? '1' : '0'), \
  (byte & 0x04 ? '1' : '0'), \
  (byte & 0x02 ? '1' : '0'), \
  (byte & 0x01 ? '1' : '0') 

#define DEBUG 1

char* chars_to_hex(char* hex_string, int n);
