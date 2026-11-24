#ifndef CJV_SOURCE_H
#define CJV_SOURCE_H
#include "common.h"

typedef struct {
    char *text;
    size_t length;
    const char *filename;
} Source;

bool source_load(Source *out, const char *path);
void source_destroy(Source *source);

#endif