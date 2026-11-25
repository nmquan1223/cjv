#ifndef CJV_LEXER_H
#define CJV_LEXER_H
#include "common.h"
#include "source.h"

typedef enum {
    TOK_EOF, TOK_IDENTIFIER, TOK_INT_LITERAL,
    TOK_PUBLIC, TOK_CLASS, TOK_STATIC, TOK_VOID,
    TOK_MAIN, TOK_STRING, TOK_INT, TOK_IF, TOK_WHILE,
    TOK_LBRACE, TOK_RBRACE, TOK_LPAREN, TOK_RPAREN,
    TOK_LBRACKET, TOK_RBRACKET, TOK_SEMICOLON, TOK_DOT,
    TOK_ASSIGN, TOK_EQUAL_EQUAL, TOK_BANG_EQUAL,
    TOK_LESS, TOK_GREATER, TOK_LESS_EQUAL, TOK_GREATER_EQUAL,
    TOK_PLUS, TOK_MINUS, TOK_STAR, TOK_SLASH
} TokenKind;

typedef struct {
    TokenKind kind;
    const char *start;
    size_t length;
    int32_t int_value;
    SourceLocation loc;
} Token;

typedef struct {
    Token *data;
    size_t count;
    size_t capacity;
} TokenArray;

typedef struct {
    const Source *source;
    size_t pos;
    unsigned line;
    unsigned column;
    bool had_error;
} Lexer;


#endif