
#include "clex.h"

 int runApp()
{
	printf("2 + 2 = %d", add (2, 2));
	getchar();
	return 0;
}
 int add(int first, int second)
{
	return first + second;
} 