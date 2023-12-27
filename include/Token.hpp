/**
 * Copyright 2023 the JayCeS authors. All rights reserved.
 *
 * MIT license.
 */
#pragma once

namespace jayces
{
/**
 * @brief Token kind
 * @desc Type of token
 */
enum TokenKind
{
    LOAD,
    IMPORT,

    VAR,
    CONST,
    ENUM,
    TYPE,
    STRUCT,
    FUN,
    OPERATOR,
    RETURN,
    IF,
    ELSE,
    FOR,
    WHILE,
    SWITCH,
    CAST,
    DEFER,

    BREAK,
    CONTINUE,

    TYPE_SIZE,
    TYPE_ALLIGN,
    VALUE_SIZE,

    TRUE,
    FALSE,
    NULL,
    UNDEFINED,

    VARARGS,

    DOT,
    DOT_DOT,
    COMMA,
    COLON,
    COLON_COLON,
    SEMICOLON,
    AT,

    PLUS,
    MINUS,
    STAR,
    SLASH,
    PERCENT,

    OR,
    OR_OR,
    AND,
    AND_AND,
    XOR,

    NOT,

    EQUAL,
    EQUAL_EQUAL,
    BANG,
    BANG_EQUAL,
    GREATER,
    GREATER_EQUAL,
    SMALLER,
    SMALLER_EQUAL,

    RIGHT_SHIFT,
    RIGHT_SHIFT_EQUAL,
    LEFT_SHIFT,
    LEFT_SHIFT_EQUAL,

    PLUS_EQUAL,
    MINUS_EQUAL,
    STAR_EQUAL,
    SLASH_EQUAL,
    PARCENT_EQUAL,

    OR_EQUAL,
    AND_EQUAL,
    XOR_EQUAL,

    PLUS_PLUS,
    MINUS_MINUS,

    RIGHT_ARROW,

    OPEN_PAREN,
    CLOSE_PAREN,
    OPEN_BRACKET,
    CLOSE_BRACKET,
    OPEN_BRACE,
    CLOSE_BRACE,

    IDENTIFIER,
    STRING,
    CHARACTER,

    INT,
    INT1,
    INT8,
    INT16,
    INT32,
    INT64,

    UINT8,
    UINT16,
    UINT32,
    UINT64,

    FLOAT,
    FLOAT32,
    FLOAT64,

    INVALID,
    END_OF_FILE,
};
} // namespace jayces
