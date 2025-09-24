import os
import subprocess
import time
import logging
from datetime import datetime
from typing import List, Tuple
import shutil
import sys
from itertools import cycle
import threading

try:
    from colorama import init, Fore, Style
    init(autoreset=True)  # Initialize colorama
except ImportError:
    print("Installing required package: colorama")
    subprocess.check_call([sys.executable, "-m", "pip", "install", "colorama"])
    from colorama import init, Fore, Style
    init(autoreset=True)

# Configure logging with colored output


class ColoredFormatter(logging.Formatter):
    COLORS = {
        'WARNING': Fore.YELLOW,
        'ERROR': Fore.RED,
        'INFO': Fore.CYAN,
        'DEBUG': Fore.GREEN
    }

    def format(self, record):
        if record.levelname in self.COLORS:
            record.msg = f"{self.COLORS[record.levelname]}{record.msg}{Style.RESET_ALL}"
        return super().format(record)


# Configure logging
logger = logging.getLogger('ProjectEuler')
logger.setLevel(logging.INFO)

# File handler
file_handler = logging.FileHandler("cpp_run_log.txt")
file_handler.setFormatter(logging.Formatter(
    '%(asctime)s [%(levelname)s] %(message)s',
    datefmt='%Y-%m-%d %H:%M:%S'
))

# Console handler with colors
console_handler = logging.StreamHandler()
console_handler.setFormatter(ColoredFormatter(
    '%(message)s'
))

logger.addHandler(file_handler)
logger.addHandler(console_handler)


class Spinner:
    def __init__(self, message="Working"):
        self.spinner = cycle(
            ['⠋', '⠙', '⠹', '⠸', '⠼', '⠴', '⠦', '⠧', '⠇', '⠏'])
        self.message = message
        self.running = False
        self.spinner_thread = None

    def spin(self):
        while self.running:
            sys.stdout.write(
                f"\r{Fore.CYAN}{self.message} {next(self.spinner)}{Style.RESET_ALL}")
            sys.stdout.flush()
            time.sleep(0.1)
        sys.stdout.write('\r' + ' ' * (len(self.message) + 2) + '\r')

    def __enter__(self):
        self.running = True
        self.spinner_thread = threading.Thread(target=self.spin)
        self.spinner_thread.start()

    def __exit__(self, exc_type, exc_val, exc_tb):
        self.running = False
        self.spinner_thread.join()


def get_terminal_size() -> Tuple[int, int]:
    return shutil.get_terminal_size()


def print_header():
    term_width, _ = get_terminal_size()
    header = "Project Euler Runner"
    print(f"\n{Fore.CYAN}{'=' * term_width}")
    print(f"{Fore.YELLOW}{header:^{term_width}}")
    print(f"{Fore.CYAN}{'=' * term_width}{Style.RESET_ALL}\n")


def list_cpp_files() -> List[str]:
    return sorted([f for f in os.listdir('.') if f.endswith('.cpp')])


def compile_cpp(file_name: str, exe_name: str) -> Tuple[bool, float]:
    start = time.time()
    with Spinner(f"Compiling {file_name}"):
        result = subprocess.run(['g++', '-std=c++17', file_name, '-o', exe_name],
                                capture_output=True, text=True)

    duration = round(time.time() - start, 2)
    if result.returncode != 0:
        logger.error(f"Compilation failed for {file_name}")
        logger.error(f"Error: {result.stderr}")
        return False, duration

    logger.info(
        f"✓ Compiled {Fore.GREEN}{file_name}{Style.RESET_ALL} successfully in {Fore.GREEN}{duration}s{Style.RESET_ALL}")
    return True, duration


def run_executable(exe_name: str) -> float:
    start = time.time()
    try:
        with Spinner(f"Running {exe_name}"):
            result = subprocess.run(
                [f'./{exe_name}'] if os.name != 'nt' else [exe_name],
                capture_output=True, text=True)

        duration = round(time.time() - start, 2)
        print(f"\n{Fore.GREEN}Output:{Style.RESET_ALL}")
        print(result.stdout)

        if result.stderr:
            print(f"{Fore.RED}Errors:{Style.RESET_ALL}")
            print(result.stderr)

        logger.info(f"✓ Executed in {Fore.GREEN}{duration}s{Style.RESET_ALL}")
        return duration
    except Exception as e:
        logger.error(f"Execution failed: {e}")
        return 0


def log_summary(file_name: str, exe_name: str, compile_time: float, exec_time: float):
    term_width, _ = get_terminal_size()
    size_kb = round(os.path.getsize(exe_name) / 1024, 2)

    print(f"\n{Fore.CYAN}{'=' * term_width}")
    print(f"{Fore.YELLOW}Execution Summary")
    print(f"{Fore.CYAN}{'=' * term_width}{Style.RESET_ALL}")

    # Create a simple bar chart for time distribution
    max_bar_width = 30
    total_time = compile_time + exec_time
    compile_bar = int((compile_time / total_time) *
                      max_bar_width) if total_time > 0 else 0
    exec_bar = int((exec_time / total_time) *
                   max_bar_width) if total_time > 0 else 0

    print(f"\n{Fore.WHITE}Program:{Style.RESET_ALL} {file_name}")
    print(f"{Fore.WHITE}Executable Size:{Style.RESET_ALL} {size_kb:.2f} KB")
    print(f"\n{Fore.WHITE}Time Distribution:{Style.RESET_ALL}")
    print(
        f"Compile Time: {Fore.BLUE}{'█' * compile_bar}{Style.RESET_ALL} {compile_time:.2f}s")
    print(
        f"Execute Time: {Fore.GREEN}{'█' * exec_bar}{Style.RESET_ALL} {exec_time:.2f}s")
    print(f"{Fore.CYAN}{'-' * term_width}{Style.RESET_ALL}")


def print_menu(cpp_files: List[str]):
    term_width, _ = get_terminal_size()
    print(f"\n{Fore.YELLOW}Available C++ Programs:{Style.RESET_ALL}")
    print(f"{Fore.CYAN}{'-' * term_width}{Style.RESET_ALL}")

    # Calculate the maximum width needed for the numbers
    max_num_width = len(str(len(cpp_files)))

    for i, f in enumerate(cpp_files, 1):
        print(f"{Fore.GREEN}{i:>{max_num_width}}{Style.RESET_ALL}. {f}")

    print(f"{Fore.RED}0{Style.RESET_ALL}. Exit")
    print(f"{Fore.CYAN}{'-' * term_width}{Style.RESET_ALL}")


def main():
    print_header()

    while True:
        cpp_files = list_cpp_files()
        if not cpp_files:
            logger.warning("No C++ files found in the current directory.")
            break

        print_menu(cpp_files)
        choice = input(
            f"\n{Fore.YELLOW}Enter program number to run:{Style.RESET_ALL} ")

        if choice == '0':
            break

        if not choice.isdigit() or not (1 <= int(choice) <= len(cpp_files)):
            logger.warning("Invalid choice. Please try again.")
            continue

        selected_file = cpp_files[int(choice) - 1]
        base_name = os.path.splitext(selected_file)[0]
        exe_name = f"{base_name}.exe" if os.name == 'nt' else base_name

        logger.info("Processing %s", selected_file)
        success, compile_time = compile_cpp(selected_file, exe_name)
        if not success:
            continue

        exec_time = run_executable(exe_name)
        log_summary(selected_file, exe_name, compile_time, exec_time)

        try:
            os.remove(exe_name)
            logger.info("Cleaned up executable: %s", exe_name)
        except OSError as e:
            logger.warning("Failed to clean up executable: %s", e)

        input(f"\n{Fore.YELLOW}Press Enter to continue...{Style.RESET_ALL}")

    logger.info(f"{Fore.GREEN}Session ended. Goodbye!{Style.RESET_ALL}")


if __name__ == "__main__":
    try:
        main()
    except KeyboardInterrupt:
        print(f"\n{Fore.YELLOW}Program terminated by user.{Style.RESET_ALL}")
    except Exception as e:
        logger.error("Unexpected error: %s", e)
        sys.exit(1)
