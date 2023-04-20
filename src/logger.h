#pragma once
#include <stdio.h>

#define SPG_LOG_TEXT(MSG, ...)\
{\
    printf("\x1b[32m");\
    printf(MSG, __VA_ARGS__);\
    printf("\033[37m");\
}

#define SPG_LOG_MESSAGE(MSG, ...)\
{\
    printf("\x1b[32m[MESSAGE]: ");\
    printf(MSG, __VA_ARGS__);\
    printf("\n\033[37m");\
}

#define SPG_LOG_WARN(MSG, ...)\
{\
    printf("\033[33m[WARNING]: ");\
    printf(MSG, __VA_ARGS__);\
    printf("\n\033[37m");\
}


#define SPG_LOG_ERROR(MSG, ...)\
{\
    printf("\033[31m[ERROR]: ");\
    printf(MSG, __VA_ARGS__);\
    printf("\n\033[37m");\
}



#define SPG_LOG_FATAL(MSG, ...)\
{\
    printf("\033[31m[FATAL] ");\
    printf(MSG, __VA_ARGS__);\
    printf("\n\033[37m");\
    assert(false);\
}
