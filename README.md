# CS1.6 Skin Installer (CS Revo)

A simple and efficient skin installer tool for Counter-Strike 1.6, written in C. This tool allows you to easily install custom weapon skins by copying files from organized skin folders to your CS 1.6 installation directory.

## Features

- 🎨 **Easy Skin Management**: Organize your skins in separate folders within the `skins/` directory
- 📊 **Progress Tracking**: Visual progress bar showing copy progress
- 🎯 **Interactive Selection**: Choose from available skin folders with a simple menu
- 🖥️ **Windows Compatible**: Built specifically for Windows systems
- 🎨 **Colorful Output**: Color-coded console output for better user experience
- ⚡ **Fast Installation**: Efficient file copying with progress indication

## Requirements

- Windows operating system
- GCC compiler (or any C compiler)
- Counter-Strike 1.6 installed at default path

## Installation

1. Clone or download this repository
2. Compile the source code using the provided build script:
   ```bash
   ./build.sh
   ```
   Or manually compile with:
   ```bash
   gcc -o cs16.exe src/main.c -Wall -Wextra
   ```

## Usage

1. **Prepare your skins**: Place your skin folders inside the `skins/` directory
2. **Run the installer**: Execute `cs16.exe`
3. **Select a skin**: Choose from the available skin folders using the numbered menu
4. **Wait for completion**: The tool will copy all files and show progress

### Directory Structure

```
cs16/
├── src/
│   └── main.c          # Main source code
├── skins/              # Place your skin folders here
│   ├── purple/         # Example skin folder
├── build.sh            # Build script
├── cs16.exe            # Compiled executable
└── README.md           # This file
```

## How It Works

1. The program scans the `skins/` directory for available skin folders
2. Displays a numbered list of found skin folders
3. Prompts you to select a skin folder by number
4. Copies all files from the selected skin folder to your CS 1.6 models directory
5. Shows progress with a visual progress bar and file-by-file status

## Customization

### Changing CS 1.6 Path

If your Counter-Strike 1.6 is installed in a different location, modify line 109 in `src/main.c`:

```c
const char *csModelsFolder = "C:\\Your\\CS\\Path\\cstrike\\models";
```

### Adding More Features

The code is well-structured and easy to extend. You can add features like:
- Backup functionality before installing skins
- Skin preview capabilities
- Batch installation of multiple skins
- Skin management (list, remove, etc.)

## Building from Source

### Prerequisites
- GCC compiler (or any C compiler)
- Windows SDK (for Windows API functions)

### Compilation
```bash
# Using the build script
./build.sh

# Or manually
gcc -o cs16.exe src/main.c
```

## Troubleshooting

### Common Issues

1. **"No skin folders found in skins/!"**
   - Make sure you have created folders inside the `skins/` directory
   - Ensure the folders contain skin files

2. **"Failed to copy [filename]"**
   - Check if CS 1.6 is running (close it before installing skins)
   - Verify you have write permissions to the CS 1.6 directory
   - Make sure the target path is correct

3. **Compilation errors**
   - Ensure you have GCC installed and in your PATH
   - Make sure you're running the build script from the project root

## Contributing

Feel free to contribute to this project! Some areas for improvement:
- Cross-platform compatibility
- GUI interface
- Skin preview functionality
- Better error handling
- Configuration file support

## License

This project is open source. Feel free to use, modify, and distribute as needed.

## Author

**hax**  
GitHub: [https://github.com/6hax](https://github.com/6hax)


