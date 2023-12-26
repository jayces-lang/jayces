/**
 * Copyright 2023 the JayCeS authors. All rights reserved.
 *
 * MIT license.
 */

#include <CLI/CLI.hpp>
#include <cstring>
#include <iostream>

#include <llvm/ADT/Optional.h>

#include "../include/Env.hpp"

void add_command_compile(CLI::App& app)
{
    CLI::App* sub = app.add_subcommand(
        "compile", "Compile source files to executables with options");

    sub->parse_complete_callback([]() { std::cout << "complete"; });
}

void add_command_emit_ir(CLI::App& app)
{
    CLI::App* sub = app.add_subcommand(
        "emit-ir", "Compile source to llvm ir files with options");
}

void add_positional(CLI::App& app)
{
    std::string file;
    CLI::Option* opt =
        app.add_option("-f,--file,file", file, "program read from script file");
}

int main(int argc, char** argv)
{
    CLI::App app(JAYCES_APP_DESC);

    app.set_version_flag("-v,--version", std::string(JAYCES_VERSION));

    add_positional(app);

    add_command_compile(app);
    add_command_emit_ir(app);

    CLI11_PARSE(app, argc, argv);

    return 0;
}
