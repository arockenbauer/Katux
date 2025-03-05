# Katux OS

Katux OS is a minimal operating system developed from scratch. It combines an assembly bootloader and a C kernel to provide an interactive shell with basic commands. This project is designed for learning low-level programming and operating system development.

## Prerequisites

Before compiling and running Katux OS, you need to install some tools and packages on your Linux distribution.

### Required Packages (for Debian/Ubuntu)

```bash
sudo apt update
sudo apt install nasm qemu-system-x86 gcc binutils make i686-linux-gnu-gcc i686-linux-gnu-binutils
```

These packages provide:
- **nasm**: Assembler for the bootloader.
- **gcc** and **i686-linux-gnu-gcc**: Compilers for the C kernel.
- **binutils** and **i686-linux-gnu-binutils**: Linker tools.
- **qemu-system-x86**: To test Katux OS in QEMU.
- **make**: To automate the compilation process.

## Installation

The project uses a `setup.py` script to automate the compilation process and generate the disk image `Katux.img`.

### Installation Steps

1. **Clone the GitHub repository:**

   ```bash
   git clone https://github.com/arockenbauer/katux.git
   cd katux
   ```

2. **Run the installation script:**

   ```bash
   python3 setup.py
   ```

   The script performs the following operations:
   - Cleans up previous build files.
   - Compiles the bootloader, kernel, and modules (keyboard, screen, lib).
   - Creates the disk image `Katux.img` by concatenating the bootloader and the kernel.

## Project Structure

The project is organized as follows:

```
Katux/
├── bootloader.asm     # Assembly bootloader (loads the kernel from disk)
├── kernel.c           # Core system (shell and command processing)
├── keyboard.c         # Keyboard handling
├── keyboard.h         # Prototypes for keyboard.c
├── screen.c           # Display functions (print, print_char, clear_screen)
├── screen.h           # Prototypes for screen.c
├── lib.c              # Utility functions (e.g., strcmp)
├── lib.h              # Prototypes for lib.c
├── link.ld            # Linker script (loads the kernel at 0x1000)
├── Makefile           # Manual build instructions
└── setup.py           # Python script to automate installation
```

## Usage

Once the installation is complete, you can launch Katux OS in QEMU:

```bash
qemu-system-x86_64 -drive format=raw,file=Katux.img
```

The system will boot, and you should see the bootloader message **"Loading Katux Kernel..."** followed by the kernel starting up and displaying an interactive shell with the prompt `Katux~#`.

## Development and Contributions

To contribute to Katux OS:

1. Fork the repository on GitHub.
2. Clone your fork locally.
3. Create a branch for your modifications.
4. Test your changes using QEMU.
5. Submit a pull request explaining your changes.

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.

## setup.py

The `setup.py` script automates the compilation of the project. Run it to automaticly run the OS.

## Notes

- **Kernel Size:** Ensure that the number of sectors read in the bootloader corresponds to the actual size of your kernel. Adjust `mov al, X` in `bootloader.asm` if necessary.
- **Virtual Disk:** In QEMU, the "disk" corresponds to the `Katux.img` image. Ensure that the image is correctly generated and that the Makefile properly concatenates the bootloader and the kernel.
- This project is intended for educational purposes. Future improvements may include features such as KatFS™ (a file system), a graphical interface, and more.
