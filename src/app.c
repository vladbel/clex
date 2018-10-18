
#include "clex.h"

 int runApp()
{
	printf("2 + 4 = %d", add (2, 4));
	getchar();
	return 0;
}
 int add(int first, int second)
{
	return first + second;
} 