/**
 * Copyright 2023-2025 the JayCeS authors. All rights reserved.
 *
 * MIT license.
 */

#include "../include/env.hpp"
#include "../include/logger.hpp"

#include <CLI/CLI.hpp>
#include <iostream>
#include <llvm/ADT/Optional.h>
#include <vector>

void add_command_compile(CLI::App &app)
{
    CLI::App *sub = app.add_subcommand(
        "compile", "Compile source files to executables with options");

    sub->parse_complete_callback([]() { std::cout << "do compile"; });
}

void add_command_emit_ir(CLI::App &app)
{
    CLI::App *sub = app.add_subcommand(
        "emit-ir", "Compile source to llvm ir files with options");

    sub->parse_complete_callback([]() { std::cout << "do emit-ir"; });
}

int main(int argc, char **argv)
{
    CLI::App app(JAYCES_APP_DESC);

    app.set_version_flag("-v,--version", std::string(JAYCES_VERSION));

    std::vector<std::string> files;

    CLI::Option *opt = app.add_option(
        "-f,--file,file", files, "program read from script file");

    add_command_compile(app);
    add_command_emit_ir(app);

    CLI11_PARSE(app, argc, argv);

    jayces::Logger::Init();
    JCS_ERROR("File size {}", files.size());

    return 0;
}
