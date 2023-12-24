/**
 * Copyright 2023 the JayCeS authors. All rights reserved. MIT license.
 */

#include <cstring>
#include <iostream>
#include <CLI/CLI.hpp>

#include <llvm/ADT/Optional.h>

auto main(int argc, char** argv) -> int {
    CLI::App app{"App description"};
    char** original_argv = argv;

    std::string filename = "default";
    app.add_option("-f,--file", filename, "A help string");

    CLI11_PARSE(app, argc, argv);
    return 0;
}
