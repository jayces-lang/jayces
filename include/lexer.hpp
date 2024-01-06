/**
 * Copyright 2023 the JayCeS authors. All rights reserved.
 *
 * MIT license.
 */
#pragma once

#include "Token.hpp"

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

    bool match(char);

    char advance();

    char peek();

    char peek_next();

    bool is_digit(char);

    bool is_hex_digit(char);

    bool is_binary_digit(char);

    bool is_octal_digit(char);

    bool is_alpha(char);

    bool is_alpha_num(char);

    void skip_whitespaces();

    void skip_single_line_comment();

    void skip_multi_lines_comment();

    TokenKind resolve_keyword_token_kind(const char *keyword);

    /* Operators */

    /* Setter & Getter */
};
} // namespace jayces
