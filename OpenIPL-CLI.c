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
        printf("%s\n\n",
            "Basic operations:\n"
            "  OpenIPL-CLI <path> -turn90\n"
            "  OpenIPL-CLI <path> -negative\n"
            "  OpenIPL-CLI <path> -sepia\n"
            "  OpenIPL-CLI <path> -sharpen\n"
            "  OpenIPL-CLI <path> -mirror\n"
            "    Example: OpenIPL-CLI C:\\Path\\To\\img.png -turn90\n\n"

            "Operations with factor:\n"
            "  OpenIPL-CLI <path> -bright <factor>\n"
            "  OpenIPL-CLI <path> -contrast <factor>\n"
            "  OpenIPL-CLI <path> -grayscale <factor>\n"
            "  OpenIPL-CLI <path> -sobel <factor>\n"
            "  OpenIPL-CLI <path> -blackwhite <factor>\n"
            "    Example: OpenIPL-CLI C:\\Path\\To\\img.png -bright 0.5\n\n"

            "Advanced operations:\n"
            "  OpenIPL-CLI <path> -addtext <x> <y> <text> <fontsize> <ttfpath> <r> <g> <b>\n"
            "    Example: OpenIPL-CLI C:\\Path\\To\\img.png -addtext 256 512 \"Hello\" 24 C:\\arial.ttf 255 255 255\n\n"

            "Resize:\n"
            "  OpenIPL-CLI <path> -biinterpolation <height> <width>\n"
            "    Example: OpenIPL-CLI C:\\Path\\To\\img.png -biinterpolation 512 512\n"
        );
        return 0;
	}
}