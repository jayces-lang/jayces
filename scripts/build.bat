:: Copyright 2023 the JayCeS authors. All rights reserved. MIT license.

@echo off

cd ../

echo ::Build ninja
cmake -S . -B build/ninja/ -GNinja

echo ::Gathering compilation database information!
copy build\ninja\compile_commands.json .

echo ::Build MSVC solution
cmake -S . -B build/windows/
