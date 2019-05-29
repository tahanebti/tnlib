//
//  install gcc or clang compiler
//  Created by taha nebti.
//  Copyright (c) 2019. All rights reserved.
//

Install the last gcc/g++ (v9)
$ sudo add-apt-repository ppa:jonathonf/gcc-9.0
$ sudo apt update
$ sudo apt install gcc-9 g++-9
$ gcc-9 --version

Install the last clang/clang++ (v8)
$ wget -O - https://apt.llvm.org/llvm-snapshot.gpg.key \
| sudo apt-key add -
$ sudo apt-add-repository \ # note: xenial version
	"deb http://apt.llvm.org/xenial/ llvm-toolchain-xenial-8.0 main"
$ sudo apt update
$ sudo apt install -y clang-8.0
$ clang-8.0 --version


How to compile?
Compile C++11, C++14, C++17 programs:
g++ -std=c++11 <program.cpp> -o program
g++ -std=c++14 <program.cpp> -o program
g++ -std=c++17 <program.cpp> -o program