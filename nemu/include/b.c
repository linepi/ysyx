#include <stdio.h>
struct Flags {
  unsigned int has_data : 4;   // 1-bit flag
  unsigned int is_valid : 4;   // 1-bit flag
  unsigned int reserved : 8;  // 14-bit unused field
  unsigned int error_code : 16; // 16-bit error code
};

int main() {
  struct Flags flags = { 0xab, 0xcd, 0x567, 0 };
  
  // Set the error code to 0xABCD
  flags.error_code = 0xEABCD;

  // Print the values of the bit-fields
  printf("has_data=%u\n", flags.has_data);
  printf("is_valid=%u\n", flags.is_valid);
  printf("reserved=%u\n", flags.reserved);
  printf("error_code=%u\n", flags.error_code);

  return 0;
}
