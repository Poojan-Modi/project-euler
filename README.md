# Project Euler Solutions in C++

This repository contains my solutions to Project Euler problems using C++.
I'm using this project to improve my algorithmic thinking and C++ skills as part of my journey into robotics and embedded systems.

## 📁 Structure

- All problem solutions are in the project root directory, named `problem_XXXX.cpp` (e.g., `problem_0001.cpp`).
- The script `run.ps1` allows you to interactively compile and run any solution file.
- Compilation logs and execution statistics are saved in `cpp_run_log.txt`.

## 🛠️ How to Compile & Run

### Manual Compilation

```bash
g++ problem_0001.cpp -o problem_0001.exe
./problem_0001.exe
```

### Using PowerShell Script

You can use the provided PowerShell script to select, compile, and run any solution:

```powershell
.\run.ps1
```

This will:
- List available `.cpp` files.
- Compile the selected file.
- Run the executable and display output.
- Log compile and execution times in `cpp_run_log.txt`.

## 📝 Logging

- Each run appends compile time, execution time, and executable size to `cpp_run_log.txt`.

## 📦 Ignore List

- Build artifacts and temporary files are excluded via `.gitignore`.

## 🚀 Getting Started

1. Clone the repository.
2. Open in Visual Studio Code or your preferred editor.
3. Add new solutions as `problem_XXXX.cpp`.
4. Use `run.ps1` or compile manually as shown above.

---

Happy coding!
