/*
 *  main.cpp - CLI setup and argument parsing
 *  Copyright (C) 2024  Sebastian Pineda (spineda.wpi.alum@gmail.com)
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License along
 *  with this program. If not, see <https://www.gnu.org/licenses/>
 */

#include <argparse/argparse.hpp>
#include <iostream>

int main(int argc, char** argv) {
    constexpr const char* version{"0.0.1"};
    constexpr const char* program{"CNew"};

    argparse::ArgumentParser argument_parser{program, version,
                                             argparse::default_arguments::none};

    argument_parser.add_argument("-h", "--help")
        .help("Print Help Message & Exit")
        .flag();

    argument_parser.add_argument("-v", "--version")
        .help("Display Program Version")
        .flag();

    try {
        argument_parser.parse_args(argc, argv);
    } catch (const std::exception& err) {
        std::cerr << err.what() << std::endl;
        std::cerr << argument_parser;
        return 1;
    }

    if (argument_parser.get<bool>("-h")) {
        std::cout << argument_parser;
        return 0;
    } else if (argument_parser.get<bool>("-v")) {
        std::cout << program << " " << version << std::endl;
        std::cout << "Copyright (c) 2024 Sebastian Pineda "
                     "(spineda.wpi.alum@gmail.com)"
                  << std::endl;
        std::cout
            << "This program is free software; you may redistribute it under "
               "the "
               "terms of the\nGNU General Public License version 2 or (at your "
               "option) any later version. This\nprogram has absolutely no "
               "warranty."
            << std::endl
            << std::endl;
        return 0;
    }

    return 0;
}
