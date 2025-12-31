/**
 * Copyright 2023-2026 the JayCeS authors. All rights reserved.
 *
 * MIT license.
 */
#pragma once

#include "basic.hpp"

#include <string>
#include <unordered_map>
#include <unordered_set>

namespace jayces {
/**
 * @brief Token kind
 * @desc A list of programming syntax token.
 */
enum TokenKind {
    k_LOAD,
    k_IMPORT,

    k_VAR,
    k_CONST,
    k_ENUM,
    k_TYPE,
    k_STRUCT,
    k_FUN,
    k_OPERATOR,
    k_RETURN,
    k_IF,
    k_ELSE,
    k_FOR,
    k_WHILE,
    k_SWITCH,
    k_CAST,
    k_DEFER,

    k_BREAK,
    k_CONTINUE,

    k_TYPE_SIZE,
    k_TYPE_ALLIGN,
    k_VALUE_SIZE,

    k_TRUE,
    k_FALSE,
    k_NULL,
    k_UNDEFINED,

    k_VARARGS,

    k_DOT,
    k_DOT_DOT,
    k_COMMA,
    k_COLON,
    k_COLON_COLON,
    k_SEMICOLON,
    k_AT,

    k_PLUS,
    k_MINUS,
    k_STAR,
    k_SLASH,
    k_PERCENT,

    k_OR,
    k_OR_OR,
    k_AND,
    k_AND_AND,
    k_XOR,

    k_NOT,

    k_EQUAL,
    k_EQUAL_EQUAL,
    k_BANG,
    k_BANG_EQUAL,
    k_GREATER,
    k_GREATER_EQUAL,
    k_SMALLER,
    k_SMALLER_EQUAL,

    k_RIGHT_SHIFT,
    k_RIGHT_SHIFT_EQUAL,
    k_LEFT_SHIFT,
    k_LEFT_SHIFT_EQUAL,

    k_PLUS_EQUAL,
    k_MINUS_EQUAL,
    k_STAR_EQUAL,
    k_SLASH_EQUAL,
    k_PARCENT_EQUAL,

    k_OR_EQUAL,
    k_AND_EQUAL,
    k_XOR_EQUAL,

    k_PLUS_PLUS,
    k_MINUS_MINUS,

    k_RIGHT_ARROW,

    k_OPEN_PAREN,
    k_CLOSE_PAREN,
    k_OPEN_BRACKET,
    k_CLOSE_BRACKET,
    k_OPEN_BRACE,
    k_CLOSE_BRACE,

    k_IDENTIFIER,
    k_STRING,
    k_CHARACTER,

    k_INT,
    k_INT1,
    k_INT8,
    k_INT16,
    k_INT32,
    k_INT64,

    k_UINT8,
    k_UINT16,
    k_UINT32,
    k_UINT64,

    k_FLOAT,
    k_FLOAT32,
    k_FLOAT64,

    k_INVALID,
    k_END_OF_FILE,
};

struct TokenSpan {
    int file_id;
    int line_number;
    int column_start;
    int column_end;
};

struct Token {
    TokenKind kind;
    TokenSpan position;
    std::string literal;
};

// Used for error messages and debugging
static std::unordered_map<TokenKind, std::string> token_kind_literal = {
    { TokenKind::k_LOAD, "load" },
    { TokenKind::k_IMPORT, "import" },
    { TokenKind::k_VAR, "var" },
    { TokenKind::k_CONST, "const" },
    { TokenKind::k_FUN, "fun" },
    { TokenKind::k_OPERATOR, "operator" },
    { TokenKind::k_ENUM, "enum" },
    { TokenKind::k_TYPE, "type" },
    { TokenKind::k_STRUCT, "struct" },
    { TokenKind::k_RETURN, "return" },
    { TokenKind::k_IF, "if" },
    { TokenKind::k_ELSE, "else" },
    { TokenKind::k_FOR, "for" },
    { TokenKind::k_WHILE, "while" },
    { TokenKind::k_SWITCH, "switch" },
    { TokenKind::k_CAST, "cast" },
    { TokenKind::k_DEFER, "defer" },

    { TokenKind::k_TRUE, "true" },
    { TokenKind::k_FALSE, "false" },
    { TokenKind::k_NULL, "null" },
    { TokenKind::k_UNDEFINED, "undefined" },

    { TokenKind::k_BREAK, "break" },
    { TokenKind::k_CONTINUE, "continue" },

    { TokenKind::k_TYPE_SIZE, "type_size" },
    { TokenKind::k_TYPE_ALLIGN, "type_allign" },
    { TokenKind::k_VALUE_SIZE, "value_size" },

    { TokenKind::k_VARARGS, "varargs" },

    { TokenKind::k_DOT, "." },
    { TokenKind::k_DOT_DOT, ".." },
    { TokenKind::k_COMMA, "," },
    { TokenKind::k_COLON, ":" },
    { TokenKind::k_COLON_COLON, "::" },
    { TokenKind::k_SEMICOLON, ";" },
    { TokenKind::k_AT, "@" },

    { TokenKind::k_PLUS, "+" },
    { TokenKind::k_MINUS, "-" },
    { TokenKind::k_STAR, "*" },
    { TokenKind::k_SLASH, "/" },
    { TokenKind::k_PERCENT, "%" },

    { TokenKind::k_AND, "&" },
    { TokenKind::k_AND_AND, "&&" },
    { TokenKind::k_OR, "|" },
    { TokenKind::k_OR_OR, "||" },
    { TokenKind::k_XOR, "^" },

    { TokenKind::k_NOT, "~" },

    { TokenKind::k_EQUAL, "=" },
    { TokenKind::k_EQUAL_EQUAL, "==" },
    { TokenKind::k_BANG, "!" },
    { TokenKind::k_BANG_EQUAL, "!=" },

    { TokenKind::k_GREATER, ">" },
    { TokenKind::k_GREATER_EQUAL, ">=" },
    { TokenKind::k_SMALLER, "<" },
    { TokenKind::k_SMALLER_EQUAL, "<=" },

    { TokenKind::k_RIGHT_SHIFT, ">>" },
    { TokenKind::k_RIGHT_SHIFT_EQUAL, ">>=" },
    { TokenKind::k_LEFT_SHIFT, "<<" },
    { TokenKind::k_LEFT_SHIFT_EQUAL, "<<=" },

    { TokenKind::k_PLUS_EQUAL, "+=" },
    { TokenKind::k_MINUS_EQUAL, "-=" },
    { TokenKind::k_STAR_EQUAL, "*=" },
    { TokenKind::k_SLASH_EQUAL, "/=" },
    { TokenKind::k_PARCENT_EQUAL, "%=" },

    { TokenKind::k_PLUS_PLUS, "++" },
    { TokenKind::k_MINUS_MINUS, "--" },

    { TokenKind::k_RIGHT_ARROW, "->" },

    { TokenKind::k_OPEN_PAREN, "(" },
    { TokenKind::k_CLOSE_PAREN, ")" },
    { TokenKind::k_OPEN_BRACKET, "[" },
    { TokenKind::k_CLOSE_BRACKET, "]" },
    { TokenKind::k_OPEN_BRACE, "{" },
    { TokenKind::k_CLOSE_BRACE, "}" },

    { TokenKind::k_IDENTIFIER, "identifier" },
    { TokenKind::k_STRING, "string" },
    { TokenKind::k_CHARACTER, "char" },
    { TokenKind::k_INT, "int" },
    { TokenKind::k_INT1, "int1" },
    { TokenKind::k_INT8, "int8" },
    { TokenKind::k_INT16, "int16" },
    { TokenKind::k_INT32, "int32" },
    { TokenKind::k_INT64, "int64" },
    { TokenKind::k_UINT8, "uint8" },
    { TokenKind::k_UINT16, "uint16" },
    { TokenKind::k_UINT32, "uint32" },
    { TokenKind::k_UINT64, "uint64" },
    { TokenKind::k_FLOAT, "float" },
    { TokenKind::k_FLOAT32, "float32" },
    { TokenKind::k_FLOAT64, "float64" },

    { TokenKind::k_INVALID, "Invalid" },
    { TokenKind::k_END_OF_FILE, "End of the file" },
};
static std::unordered_map<std::string, TokenKind> token_kind_literal_r =
    reverse_map(token_kind_literal);

static std::unordered_set<TokenKind> unary_operators = {
    TokenKind::k_MINUS, TokenKind::k_BANG, TokenKind::k_STAR,
    TokenKind::k_AND,   TokenKind::k_NOT,
};

static std::unordered_set<TokenKind> overloading_postfix_operators = {
    TokenKind::k_PLUS_PLUS,
    TokenKind::k_MINUS_MINUS,
};

} // namespace jayces
