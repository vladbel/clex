
#include "app.h"

int runApp(void)
{
	setDependencies();
	execute();
	printf("before getchar()\n");
	getchar();
	printf("after getchar()\n");
	return 0;
}

uint8_t setDependencies(void)
{
	uint8_t result = 0x01;
	return result;
}
uint8_t execute(void)
{
	uint8_t first = 0x70;
	uint8_t second = 0x80;
	uint8_t result;
	result = add(first, second);
	printf("%02X + %02X = %02X\n", first, second, result);
	printf("%02u + %002u = %003u\n", first, second, result);
	printf("%02d + %02d = %02d\n", first, second, result);

	return result;
}

uint8_t add(uint8_t first, uint8_t second)
{
	return first + second;
}