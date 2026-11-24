#ifndef CJV_COMMON_H
#define CJV_COMMON_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

typedef struct {
    unsigned line;
    unsigned column;
} SourceLocation;

#endif