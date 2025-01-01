/**
 * Copyright 2023-2025 the JayCeS authors. All rights reserved.
 *
 * MIT license.
 */
#pragma once

#include "token.hpp"

#include <string>
#include <vector>

namespace jayces {
/**
 * @class Lexer
 * @brief Class description...
 */
class Lexer {
private:
    /* Variables */

    std::string source_code;

    int source_file_id;

    size_t source_code_length;

    size_t start_position;

    size_t current_position;

    int line_number;

    int column_start;

    int column_current;

public:
    Lexer(int source_file_id, std::string source);

    std::vector<Token> scan_all_tokens();

    Token scan_next_token();

    int get_source_file_id();

private:
    Token build_token(TokenKind);

    Token build_token(TokenKind, std::string);

    TokenSpan build_token_span();

    bool is_source_available();

    Token consume_symbol();

    Token consume_hex_number();

    bool match(char);

    char advance();

    char peek();

    char peek_next();

    void skip_whitespaces();

    void skip_single_line_comment();

    void skip_multi_lines_comment();

    TokenKind resolve_keyword_token_kind(const char *keyword);

    static bool is_underscore(char);

    static bool is_binary_digit(char);

    static bool is_octal_digit(char);

    static auto hex_to_int(char c) -> int8_t;

    static std::int64_t hex_to_decimal(const std::string&);

    static std::int64_t binary_to_decimal(const std::string&);

    static std::int64_t octal_to_decimal(const std::string&);

    /* Operators */

    /* Setter & Getter */
};
} // namespace jayces
