# Project Euler Solutions in C++

This repository contains my solutions to Project Euler problems using C++.
I'm using this project to improve my algorithmic thinking and C++ skills as part of my journey into robotics and embedded systems.

## 📁 Project Structure

```
project-euler/
├── src/                    # Source files
│   └── problems/           # Problem solutions
├── include/                # Header files
├── build/                  # Build directory
├── .vscode/                # VS Code configuration
├── CMakeLists.txt          # CMake configuration
└── README.md
```

## 🛠️ Requirements

- CMake (3.10 or higher)
- C++23 compliant compiler
- OpenMP support (automatically installed)
- VS Code with C/C++ extension

## 🚀 Getting Started

1. **Clone the repository:**
   ```bash
   git clone https://github.com/Poojan-Modi/project-euler.git
   cd project-euler
   ```

2. **Install Dependencies (macOS):**
   ```bash
   brew install cmake
   brew install libomp
   ```

3. **Build the project:**
   - Using VS Code:
     - Press `Cmd+Shift+B` to build
     - Select "Run Problem" from Command Palette to execute
   
   - Using Terminal:
     ```bash
     mkdir -p build
     cd build
     cmake ..
     make
     ```

## 💻 VS Code Tasks

The project includes preconfigured VS Code tasks:

- **Build Project** (`Cmd+Shift+B`): Builds all solutions
- **Clean Build**: Removes and rebuilds everything
- **Run Problem**: Executes a specific problem solution

## 🔧 Building and Running

### Using VS Code:
1. Press `Cmd+Shift+B` to build
2. `Cmd+Shift+P` → "Tasks: Run Task" → "Run Problem"
3. Enter the problem number (e.g., "0004")

### Using Terminal:
```bash
# Build specific problem
cd build
make problem_XXXX

# Run specific problem
./problem_XXXX
```

## 📦 Development

To add a new solution:

1. Create `src/problems/problem_XXXX.cpp`
2. Include problem description and approach
3. Build using CMake
4. Run using VS Code tasks or terminal

## 🎯 Best Practices

- Document problem description and approach
- Use OpenMP for parallel processing when applicable
- Follow C++23 best practices
- Include performance considerations
- Add test cases in comments

## 🔍 Features

- C++23 support
- OpenMP parallel processing
- CMake build system
- VS Code integration
- Automatic dependency management

## 📚 Resources

- [Project Euler](https://projecteuler.net/)
- [C++ Reference](https://en.cppreference.com/)
- [CMake Documentation](https://cmake.org/documentation/)
- [OpenMP Documentation](https://www.openmp.org/specifications/)

---

Happy Problem Solving! 🎉