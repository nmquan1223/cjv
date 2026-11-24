#include "common.h"
#include "source.h"

bool source_load(Source *out, const char *path) {
    FILE *file = fopen(path, "rb");
    if (file == NULL) {
        return false;
    }
    if (fseek(file, 0, SEEK_END) != 0) {
        fclose(file);
        return false;
    }
    long file_size = ftell(file);
    if (file_size < 0) {
        fclose(file);
        return false;
    }
    rewind(file);

    char *buffer = malloc((size_t)file_size + 1);
    if (buffer == NULL) {
        fclose(file);
        return false;
    }
    size_t n = fread(buffer, 1, (size_t)file_size, file);
    if (n != (size_t)file_size) {
        free(buffer);
        fclose(file);
        return false;
    }
    buffer[n] = '\0';
    fclose(file);
    out->text = buffer;
    out->length = n;
    out->filename = path;
    return true;
}

void source_destroy(Source *source) {
    free(source->text);
    source->text = NULL;
    source->length = 0;
    source->filename = NULL;
}