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
        printf(
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
            "    Example: OpenIPL-CLI C:\\Path\\To\\img.png -addtext 256 512 \"Hello\" 24 C:\\arial.ttf 255 255 255\n"
            "  OpenIPL-CLI <path> -biinterpolation <height> <width>\n"
            "    Example: OpenIPL-CLI C:\\Path\\To\\img.png -biinterpolation 512 512\n"
            "  OpenIPL-CLI <path> -gauss <iterations>\n"
            "    Example: OpenIPL-CLI C:\\Path\\To\\img.png -gauss 50\n"
            "  OpenIPL-CLI <path> -pixelate <scale>\n"
            "    Example: OpenIPL-CLI C:\\Path\\To\\img.png -pixelate 4\n"
            "  OpenIPL-CLI <path> -chromaber <bluex> <bluey> <redx> <redy> <threshold>\n"
            "    Example: OpenIPL-CLI C:\\Path\\To\\img.png -chromaber 5 5 -3 0 0.1\n"
            "  OpenIPL-CLI <path> -tint <r> <g> <b>\n"
            "    Example: OpenIPL-CLI C:\\Path\\To\\img.png -tint 1.2 1.0 0.8\n"
            "  OpenIPL-CLI <path> -vignette <intensity> <curve>\n"
            "    Example: OpenIPL-CLI C:\\Path\\To\\img.png -vignette 0.8 1.4\n"
        );
        return 0;
	}
}