/**
 * Copyright 2023 the JayCeS authors. All rights reserved.
 *
 * MIT license.
 */

#include <CLI/CLI.hpp>
#include <cstring>
#include <iostream>

#include <llvm/ADT/Optional.h>

void print_version(int cound) { std::cout << "0.1.0"; }

auto main(int argc, char** argv) -> int
{
    CLI::App app("");

    app.add_flag_function("-v", print_version, "Show version number");

    CLI::App* sub_compile = app.add_subcommand("compile", "Compile source files to executables with options");

    CLI11_PARSE(app, argc, argv);

    return 0;
}
