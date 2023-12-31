/**
 * Copyright 2023 the JayCeS authors. All rights reserved.
 *
 * MIT license.
 */

#include "../include/Lexer.hpp"

namespace jayces {
Lexer::Lexer(int source_file_id, std::string source)
    : source_code(std::move(source)),
      source_file_id(source_file_id),
      source_code_length(source_code.size()),
      start_position(0),
      current_position(0),
      line_number(1),
      column_start(0),
      column_current(0)
{
    // ..
}

std::vector<Token> Lexer::scan_all_tokens()
{
    std::vector<Token> tokens;
    while (is_source_available()) {
        tokens.push_back(scan_next_token());
    }
    tokens.push_back(build_token(TokenKind::k_END_OF_FILE));
    return tokens;
}

Token Lexer::scan_next_token()
{
    // ..
}

int Lexer::get_source_file_id()
{
    // ..
}

Token Lexer::consume_symbol()
{
    // ..
}

Token Lexer::build_token(TokenKind kind)
{
    // ..
}

Token Lexer::build_token(TokenKind kind, std::string literal)
{
    // ..
}

TokenSpan Lexer::build_token_span()
{
    // ..
}

void Lexer::skip_whitespaces()
{
    // ..
}

bool Lexer::is_source_available()
{
    return current_position < source_code_length;
}

} // namespace jayces
