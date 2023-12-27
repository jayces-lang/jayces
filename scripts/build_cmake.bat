:: Copyright 2023 the JayCeS authors. All rights reserved.
::
:: MIT license.

@echo off

cd ../

del /s /q build

echo.
echo ::Build ninja
cmake -S . -B build/ninja/ -GNinja

echo.
echo ::Gathering compilation database information!
copy build\ninja\compile_commands.json .

echo.
echo ::Build MSVC solution
cmake -S . -B build/msvc/
