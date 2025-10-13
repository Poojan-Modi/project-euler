#!/bin/bash

set -e  # Exit on error

# Optional: specify compilers (especially useful on macOS with Homebrew GCC)
C_COMPILER=gcc-15
CXX_COMPILER=g++-15

# Create build directory
echo "🔧 Creating build directory..."
mkdir -p build
cd build

# Configure CMake
echo "⚙️ Configuring project with CMake..."
cmake -DCMAKE_C_COMPILER=$C_COMPILER -DCMAKE_CXX_COMPILER=$CXX_COMPILER ..

# Build the project
echo "🚀 Building project..."
make -j$(sysctl -n hw.physicalcpu)

# Return to root
cd ..
echo "✅ Build complete."
