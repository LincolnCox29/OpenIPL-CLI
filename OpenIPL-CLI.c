#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

int main(int argc, char* argv[])
{
	if (argc < 2)
	{
		printf("%s\n%s",
			   "[ERROR] Incorrect number of arguments",
			   "Usage: OpenIPL-CLI <path> <command> [args...]");
		return 1;
	}
	if (strcmp(argv[1], "-h") == 0)
	{
		printf("%s\n%s\n%s",
			   "commands:",
			   "	OpenIPL-CLI <path> <-bright> <factor>",
			   "    e.g. OpenIPL-CLI C:\\Users\\User\\Desktop\\img.png -bright 0.5");
	}
}