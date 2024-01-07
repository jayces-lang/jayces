/**
 * Copyright 2023 the JayCeS authors. All rights reserved.
 *
 * MIT license.
 */

#include "../include/lexer.hpp"

#include <cctype>

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
    skip_whitespaces();

    start_position = current_position;
    column_start = column_current;

    char c = advance();

    ++start_position;
    current_position = start_position;

    ++column_start;
    column_current = column_start;

    std::string c1 = std::string() + c;
    std::string c2 = std::string() + c + peek();

    switch (c) {
        case 'A':
    case 'B':
    case 'C':
    case 'D':
    case 'E':
    case 'F':
    case 'G':
    case 'H':
    case 'I':
    case 'J':
    case 'K':
    case 'L':
    case 'M':
    case 'N':
    case 'O':
    case 'P':
    case 'Q':
    case 'R':
    case 'S':
    case 'T':
    case 'U':
    case 'V':
    case 'W':
    case 'X':
    case 'Y':
    case 'Z':
    case 'a':
    case 'b':
    case 'c':
    case 'd':
    case 'e':
    case 'f':
    case 'g':
    case 'h':
    case 'i':
    case 'j':
    case 'k':
    case 'l':
    case 'm':
    case 'n':
    case 'o':
    case 'p':
    case 'q':
    case 'r':
    case 's':
    case 't':
    case 'u':
    case 'v':
    case 'w':
    case 'x':
    case 'y':
    case 'z':
    case '_': return consume_symbol();
    
    }

    // One character token
    if (token_kind_literal_r.find(c1) != token_kind_literal_r.end())
        return build_token(token_kind_literal_r[c1]);

    // One or Two character(s) token
    if (token_kind_literal_r.find(c2) != token_kind_literal_r.end())
        return build_token(token_kind_literal_r[c2]);

    return build_token(TokenKind::k_INVALID, "unexpected character");
}

Token Lexer::consume_symbol()
{
    while (std::isalnum(peek()) or peek() == '_') {
        advance();
    }
    size_t len = current_position - start_position + 1;
    auto literal = source_code.substr(start_position - 1, len);
    auto kind = resolve_keyword_token_kind(literal.c_str());
    return build_token(kind, literal);
}

Token Lexer::build_token(TokenKind kind)
{
    return build_token(kind, "");
}

Token Lexer::build_token(TokenKind kind, std::string literal)
{
    return { kind, build_token_span(), literal };
}

TokenSpan Lexer::build_token_span()
{
    return { source_file_id, line_number, column_start, column_current };
}

bool Lexer::match(char current)
{
    if (!is_source_available() || current != peek()) {
        return false;
    }
    ++current_position;
    ++column_current;
    return true;
}

char Lexer::advance()
{
    if (is_source_available()) {
        ++current_position;
        ++column_current;
        return source_code[current_position - 1];
    }
    return '\0';
}

char Lexer::peek()
{
    return source_code[current_position];
}

char Lexer::peek_next()
{
    if (current_position + 1 < source_code_length) {
        return source_code[current_position + 1];
    }
    return '\0';
}

bool Lexer::is_hex_digit(char c)
{
    return std::isdigit(c) || ('F' >= c && c >= 'A') || ('f' >= c && c >= 'a');
}

bool Lexer::is_binary_digit(char c)
{
    return '1' == c || '0' == c;
}

bool Lexer::is_octal_digit(char c)
{
    return '7' >= c && c >= '0';
}

void Lexer::skip_whitespaces()
{
    while (is_source_available()) {
        char c = peek();
        switch (c) {
        case ' ':
        case '\r':
        case '\t':
            advance();
            break;
        case '\n':
            line_number++;
            advance();
            column_current = 0;
            break;
        case '/': {
            if (peek_next() == '/' || peek_next() == '*') {
                advance(); // Skip next character / or *
            } else {
                return;
            }
            if (match('/')) {
                skip_single_line_comment();
            } else if (match('*')) {
                skip_multi_lines_comment();
            }
            break;
        }
        default:
            return;
        }
    }
}

void Lexer::skip_single_line_comment()
{
    while (is_source_available() && peek() != '\n') {
        advance();
    }
}

void Lexer::skip_multi_lines_comment()
{
    while (is_source_available() && (peek() != '*' || peek_next() != '/')) {
        advance();
        if (peek() == '\n') {
            ++line_number;
            column_current = 0;
        }
    }
    advance(); // Skip character *
    advance(); // Skip character /

    // If multi line comments end with new line update the line number
    if (peek() == '\n') {
        ++line_number;
        column_current = 0;
    }
}

TokenKind Lexer::resolve_keyword_token_kind(const char *keyword)
{
    if (token_kind_literal_r.find(keyword) == token_kind_literal_r.end())
        return TokenKind::k_IDENTIFIER;
    return token_kind_literal_r[keyword];
}

int Lexer::get_source_file_id()
{
    return source_file_id;
}

bool Lexer::is_source_available()
{
    return current_position < source_code_length;
}
} // namespace jayces
