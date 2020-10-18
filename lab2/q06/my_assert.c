#include <stdio.h>
#include <stdlib.h>
#define my_assert(exp) if (!exp) {printf("assert_test:%s:%d:%s:",__FILE__,__LINE__,__func__);\
							    printf("Assertion '"#exp"' failed\n"); exit(1);}


void foo(int num)
{
	my_assert( ((num >= 0) && (num <= 100)) );
	printf("foo: num = %d\n",num);
}

int main(int argc, char *argv[])
{
	int num;

	if(argc < 2){
		fprintf(stderr,"Usage: my_assert_use aNumber(0 <= aNumber <= 100)\n");
		exit(1);
	}
	num = atoi(argv[1]);
	foo(num);
	return 0;
}
