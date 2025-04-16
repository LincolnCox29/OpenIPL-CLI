#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include "OIPL/OpenIPL.h"
#include "stdlib.h"

#define printError(errPtr) (printf("[ERROR] CODE: %d MSG: %s\n", (errPtr)->code, (errPtr)->message))

#define CALL_FUNCTION(func, inpath, outpath, ...)          \
{                                                          \
    OIPL_Img* img = OIPL_imgLoad(inpath);                  \
    OIPL_ErrorInfo err = func(img, ##__VA_ARGS__);         \
    if (err.code)                                          \
    {                                                      \
        OIPL_imgFree(img);                                 \
        printError(&err);                                  \
        return err.code;                                   \
    }                                                      \
    err = OIPL_imgWrite(outpath, img);                     \
    OIPL_imgFree(img);                                     \
    if (err.code)                                          \
    {                                                      \
        printError(&err);                                  \
        return err.code;                                   \
    }                                                      \
    return 0;                                              \
}                                                          \

inline bool argcMinCheck(const int argc);
inline bool hFlagCheck(const char* argv[]);

int main(int argc, char* argv[])
{
    if (argcMinCheck(argc))
        return 1;
    if (hFlagCheck(argv))
        return 0;

    const char* inpath = argv[1];
    const char* outpath = argv[2];
    const char* command = argv[3];

    if (strcmp(command, "-turn90") == 0)
        CALL_FUNCTION(OIPL_Turn90, inpath, outpath)
    if (strcmp(command, "-negative") == 0)
        CALL_FUNCTION(OIPL_Negative, inpath, outpath);
    if (strcmp(command, "-sepia") == 0)
        CALL_FUNCTION(OIPL_SepiaFilter, inpath, outpath);
    if (strcmp(command, "-sharpen") == 0)
        CALL_FUNCTION(OIPL_Sharpen, inpath, outpath);
    if (strcmp(command, "-mirror") == 0)
        CALL_FUNCTION(OIPL_ToMirror, inpath, outpath);

    const float factor = (float)atof(argv[4]);

    if (strcmp(command, "-bright") == 0)
        CALL_FUNCTION(OIPL_AdjustBrightness, inpath, outpath, factor);
    if (strcmp(command, "-contrast") == 0)
        CALL_FUNCTION(OIPL_AdjustContrast, inpath, outpath, factor);
    if (strcmp(command, "-grayscale") == 0)
        CALL_FUNCTION(OIPL_ToGrayscale, inpath, outpath, factor);
    if (strcmp(command, "-sobel") == 0)
        CALL_FUNCTION(OIPL_SobelFilter, inpath, outpath, factor);
    if (strcmp(command, "-blackwhite") == 0)
        CALL_FUNCTION(OIPL_ToBlackAndWhite, inpath, outpath, factor);

    if (strcmp(command, "-addtext") == 0)
    {
        const int x = atoi(argv[4]);
        const int y = atoi(argv[5]);
        const char* text = argv[6];
        const unsigned fontsize = (unsigned)atoi(argv[7]);
        OIPL_Font* font = OIPL_fontLoad(argv[8]);
        const int r = atoi(argv[9]);
        const int g = atoi(argv[10]);
        const int b = atoi(argv[11]);
        CALL_FUNCTION(OIPL_AddText, inpath, outpath, x, y, text, fontsize, font, r, g, b);
        OIPL_fontFree(font);
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
