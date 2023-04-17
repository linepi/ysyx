#include <stdint.h>
#include <stdio.h>

struct {
	int64_t n : 4;
} y = {.n = 0xac};
struct {
	int64_t n : 4;
} x = {.n = 0xa6};

int main (){
	printf("%d\n", y.n);
	printf("%d\n", x.n);
	return 0;
}
