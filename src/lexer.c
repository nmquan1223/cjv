#include "common.h"
#include "lexer.h"

static int peek(const Lexer *l) {
    if (l->pos == l->source->length) {
        return -1;
    }
    return (unsigned char)l->source->text[l->pos];
}

static int peek_next(const Lexer *l) {
    if (l->pos + 1 >= l->source->length) {
        return -1;
    }
    return (unsigned char)l->source->text[l->pos + 1];
}

static int advance(Lexer *l) {
    int value = peek(l);
    if (value == -1) {
        return -1;
    }
    l->pos += 1;
    if (value != '\n') {
        l->column += 1;
    }
    else {
        l->line += 1;
        l->column = 1;
    }
    return value;
}

static void skip_trivia(Lexer *l) {
    while (l->pos < l->source->length) {
        if (is_whitespace(peek(l))) {
            advance(l);
            continue;
        }
        if (peek(l) == '/' && peek_next(l) == '/') {
            advance(l);
            advance(l);
            while (peek(l) != '\n' && peek(l) != '\0') {
                advance(l);
            }
            continue;
        }
        if (peek(l) == '/' && peek_next(l) == '*') {
            advance(l); // '/'
            advance(l); // '*'
            while (!(peek(l) == '*' && peek_next(l) == '/')) {
                advance(l);
            }
            if (l->pos < l->source->length) {
                advance(l); // '*'
                advance(l); // '/'
            }
            continue;
        }
        break;
    }
}

