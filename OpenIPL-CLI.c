#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include "OIPL/OpenIPL.h"

#define printError(errPtr) (printf("[ERROR] CODE: %d MSG: %s\n", (errPtr)->code, (errPtr)->message))

inline bool argcMinCheck(const int argc);
inline bool hFlagCheck(const char* argv[]);

int main(int argc, char* argv[])
{
    if (argcMinCheck(argc))
        return 1;
    if (hFlagCheck(argv))
        return 0;

    if (strcmp(argv[3], "-turn90") == 0)
    {
        const char* inpath = argv[1];
        const char* outpath = argv[2];
        OIPL_ErrorInfo err;
        OIPL_Img* img = OIPL_imgLoad(inpath);
        err = OIPL_Turn90(img);
        if (err.code)
        {
            OIPL_imgFree(img);
            printError(&err);
            return err.code;
        }
        err = OIPL_imgWrite(outpath, img);
        OIPL_imgFree(img);
        if (err.code)
        {
            printError(&err);
            return err.code;
        }
    }
    return 0;
}

inline bool hFlagCheck(const char* argv[])
{
    if (strcmp(argv[1], "-h") == 0)
    {
        printf(
            "Basic operations:\n"
            "  OpenIPL-CLI <inpath> <outpath> -turn90\n"
            "  OpenIPL-CLI <inpath> <outpath> -negative\n"
            "  OpenIPL-CLI <inpath> <outpath> -sepia\n"
            "  OpenIPL-CLI <inpath> <outpath> -sharpen\n"
            "  OpenIPL-CLI <inpath> <outpath> -mirror\n"
            "    Example: OpenIPL-CLI C:\\Path\\In\\img.png C:\\Path\\Out\\img.png -turn90\n\n"

            "Operations with factor:\n"
            "  OpenIPL-CLI <inpath> <outpath> -bright <factor>\n"
            "  OpenIPL-CLI <inpath> <outpath> -contrast <factor>\n"
            "  OpenIPL-CLI <inpath> <outpath> -grayscale <factor>\n"
            "  OpenIPL-CLI <inpath> <outpath> -sobel <factor>\n"
            "  OpenIPL-CLI <inpath> <outpath> -blackwhite <factor>\n"
            "    Example: OpenIPL-CLI C:\\Path\\In\\img.png C:\\Path\\Out\\img.png -bright 0.5\n\n"

            "Advanced operations:\n"
            "  OpenIPL-CLI <inpath> <outpath> -addtext <x> <y> <text> <fontsize> <ttfpath> <r> <g> <b>\n"
            "    Example: OpenIPL-CLI C:\\Path\\In\\img.png C:\\Path\\Out\\img.png -addtext 256 512 \"Hello\" 24 C:\\arial.ttf 0 0 0\n"
            "  OpenIPL-CLI <inpath> <outpath> -biinterpolation <height> <width>\n"
            "    Example: OpenIPL-CLI C:\\Path\\In\\img.png C:\\Path\\Out\\img.png -biinterpolation 512 512\n"
            "  OpenIPL-CLI <inpath> <outpath> -gauss <iterations>\n"
            "    Example: OpenIPL-CLI C:\\Path\\In\\img.png C:\\Path\\Out\\img.png -gauss 50\n"
            "  OpenIPL-CLI <inpath> <outpath> -pixelate <scale>\n"
            "    Example: OpenIPL-CLI C:\\Path\\In\\img.png C:\\Path\\Out\\img.png -pixelate 4\n"
            "  OpenIPL-CLI <inpath> <outpath> -chromaber <bluex> <bluey> <redx> <redy> <threshold>\n"
            "    Example: OpenIPL-CLI C:\\Path\\In\\img.png C:\\Path\\Out\\img.png -chromaber 5 5 -3 0 0.1\n"
            "  OpenIPL-CLI <inpath> <outpath> -tint <r> <g> <b>\n"
            "    Example: OpenIPL-CLI C:\\Path\\In\\img.png C:\\Path\\Out\\img.png -tint 1.2 1.0 0.8\n"
            "  OpenIPL-CLI <inpath> <outpath> -vignette <intensity> <curve>\n"
            "    Example: OpenIPL-CLI C:\\Path\\In\\img.png C:\\Path\\Out\\img.png -vignette 0.8 1.4\n"
        );
        return true;
    }
    return false;
}

inline bool argcMinCheck(const int argc)
{
    if (argc < 2)
    {
        printf(
            "[ERROR] Incorrect number of arguments\n"
            "Usage: OpenIPL-CLI <inpath> <outpath> <command> [args...]\n");
        return true;
    }
    return false;
}
