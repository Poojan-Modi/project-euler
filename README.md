# Project Euler Solutions in C++

This repository contains my solutions to Project Euler problems using C++.
I'm using this project to improve my algorithmic thinking and C++ skills as part of my journey into robotics and embedded systems.

## 📁 Project Structure

- Each solution is in the project root directory, following the naming convention:
  - Main solutions: `problem_XXXX.cpp` (e.g., `problem_0001.cpp`)
  - Alternative solutions: `problem_XXXXa.cpp`, `problem_XXXXb.cpp`, etc.
- `run.py`: Interactive Python script for compiling and running solutions
- `cpp_run_log.txt`: Compilation and execution logs

## 🛠️ Requirements

- C++ Compiler (g++)
- Python 3.x
- Required Python packages:
  - colorama (automatically installed when running the script)

## 🚀 Getting Started

1. Clone the repository:
   ```bash
   git clone https://github.com/Poojan-Modi/project-euler.git
   cd project-euler
   ```

2. Run solutions using the interactive Python script:
   ```bash
   python run.py
   ```

   The script will:
   - Show a colored, interactive menu of available solutions
   - Compile and run your chosen solution
   - Display real-time progress with visual indicators
   - Show execution statistics with time distribution charts
   - Automatically clean up build artifacts

## 💻 Run Script Features

The `run.py` script provides:

- 🎨 **Colored Interface**: Easy-to-read, color-coded output
- 📊 **Visual Progress**:
  - Real-time compilation and execution progress
  - Time distribution visualization
  - Performance statistics
- 🔍 **Detailed Output**:
  - Compilation status and errors
  - Execution time analysis
  - Memory usage statistics
- 🧹 **Automatic Cleanup**: Removes executables after running

## 📝 Logging

All operations are logged in `cpp_run_log.txt`, including:
- Compilation times and status
- Execution times
- Executable sizes
- Error messages (if any)

## 🔧 Manual Compilation

If you prefer to compile manually:

```bash
g++ problem_XXXX.cpp -o problem_XXXX
./problem_XXXX
```

## 📦 Development

To add a new solution:

1. Create a new file named `problem_XXXX.cpp`
2. Include problem description and approach in comments
3. Implement your solution
4. Run using `python run.py`

## 🎯 Best Practices

- Include problem description in comments
- Document your approach and complexity analysis
- Consider multiple solutions (a, b variants) for optimization
- Use appropriate data structures and algorithms
- Test with example cases before submitting

## 📚 Resources

- [Project Euler Official Website](https://projecteuler.net/)
- [C++ Reference](https://en.cppreference.com/)
- [Algorithm Complexity Guide](https://www.bigocheatsheet.com/)

---

Happy Problem Solving! 🎉
