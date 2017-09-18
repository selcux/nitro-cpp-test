# Nitro	C++	Proficiency	Test

## Prerequisites

In order to build the program, the necessary components are required for the development environment.

### Build Tools

* [CMake](https://cmake.org/) - CMake is an open-source, cross-platform family of tools designed to build, test and package software.

* A C++ compiler - Since CMake is a cross-platform, compiler-independent tool, it supports many compilers. The project files can be generated by using CMake for any desired compiler.
For more information please visit [CMake Generators](https://cmake.org/cmake/help/latest/manual/cmake-generators.7.html) page.

## How to Build

### Using Command Line

#### Windows

There are several options on Windows as a development environment.

To use MS Visual C++, open the developer console and go to the project directory.

CMake can detect and generate project files for the default building tools.

```
..> md build
..> cd build
..\build> cmake ..
..\build> msbuild NitroAssignment.sln
```

In order to prevent the mess, it is recommended to generate files in a different directory, like _build_ in our example.

Generators can be specified for a particular development platform.

```
..\build> cmake .. -G "Visual Studio 12 2013 Win64"
``` 

**MinGW** and **Cygwin** are also supported. Use Make instead of MS Build Engine.

```
..> md build
..> cd build
..\build> cmake ..
..\build> make
```

#### Linux and Mac OS

Since Linux and Mac have similar development environments, the code can be built in the same way.

```
..> md build
..> cd build
..\build> cmake ..
..\build> make
```

### Using an IDE

#### MS Visual Studio

Visual Studio 2017 directly supports CMake projects. By opening the assignment folder the project will be ready to compile and run.

For older versions of Visual Studio, the solution files can be generated on the [command line](#windows)

#### JetBrains CLion

CLion supports CMake by default.

## How to Run

The program takes one command line argument as a file path with a JSON content.

```
> NitroAssignment example.json
```

And prints the intersection info as requested format to the console.

## Third Party Libraries

Two libraries are used for this assignment.

[json](https://github.com/nlohmann/json): For JSON input.

[Catch](https://github.com/philsquared/Catch): For unit testing.

To keep it simple and portable both libraries are included in the project as header files.

## Development Platforms

During the development, the code is developed, built and tested on these the tools and platforms: 

#### Operating Systems

* Windows 10
* Linux (Arch)
* Mac OS (Sierra)

The code is expected to compile and run without any problems on those platforms.

#### Development Tools

* [CLion](https://www.jetbrains.com/clion/)
* [Visual Studio Community 2017](https://www.visualstudio.com/) + [ReSharper](https://www.jetbrains.com/resharper/)

#### Build Platforms

* Visual C++
* MinGW
* Linux
* Mac OS

### Testing

The unit testing library generates another executable file named _AssignmentTest_.
It takes the test data directory path as a single argument. The directory is in the _{assignmet folder}/tests/data_.

The testing files are not integrated to CMake testing system.