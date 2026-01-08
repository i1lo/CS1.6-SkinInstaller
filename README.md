
# 🎮 CS1.6 Skin Installer (CS Revo)

![CS Revo Banner](https://img.shields.io/badge/CS_Revo-Skin_Installer-orange?style=for-the-badge&logo=counter-strike&logoColor=white)

> A simple and efficient skin installer tool for **Counter-Strike 1.6**, written in C.  
> Easily install custom weapon skins by copying files from organized skin folders to your CS 1.6 installation directory.

---

## 🚀 Features

- 🎨 **Easy Skin Management**: Organize skins in `skins/` folders
- 📊 **Progress Tracking**: Visual progress bar showing file copy
- 🎯 **Interactive Selection**: Choose skins with a numbered menu
- 🖥️ **Windows Compatible**: Designed for Windows systems
- 🎨 **Colorful Output**: Color-coded console messages
- ⚡ **Fast Installation**: Efficient file copying

---

## 🖥️ Requirements

- Windows operating system
- GCC compiler (or any C compiler)
- Counter-Strike 1.6 installed at default path

---

## ⚙️ Installation

1. Clone or download this repository
2. Compile the source code using the build script:

```bash
./build.sh
````

Or manually:

```bash
gcc -o cs16.exe src/main.c -Wall -Wextra
```

> [!TIP]
> Use the build script for faster compilation and proper flags.

---

## 🚀 Usage

1. **Prepare your skins**: Place your skin folders in `skins/`
2. **Run the installer**: Execute `cs16.exe`
3. **Select a skin**: Choose a folder from the numbered menu
4. **Wait for completion**: Files will copy with a progress bar

---

### 📂 Directory Structure

```
cs16/
├── src/
│   └── main.c          # Main source code
├── skins/              # Place your skin folders here
│   ├── purple/         # Example skin folder
├── build.sh            # Build script
├── cs16.exe            # Compiled executable
└── README.md           # Documentation
```

---

## ⚙️ How It Works

1. Scans the `skins/` directory for available folders
2. Displays a numbered list of found skins
3. Prompts user to select a folder
4. Copies all files from the selected folder to CS 1.6 `models` directory
5. Shows a visual progress bar and per-file status

---

## 🛠️ Customization

### Changing CS 1.6 Path

If CS 1.6 is installed elsewhere, modify line 109 in `src/main.c`:

```c
const char *csModelsFolder = "C:\\Your\\CS\\Path\\cstrike\\models";
```

### Adding Features

* Backup before installing skins
* Skin preview functionality
* Batch installation of multiple skins
* Skin management (list/remove/etc.)

---

## 🏗️ Building from Source

### Prerequisites

* GCC (or any C compiler)
* Windows SDK (for Windows API functions)

### Compilation

```bash
# Using build script
./build.sh

# Or manually
gcc -o cs16.exe src/main.c
```

> [!TIP]
> Running the script from the project root avoids path issues.

---

## ⚠️ Troubleshooting

### Common Issues

1. **"No skin folders found in skins/!"**

   * Create folders inside `skins/`
   * Ensure they contain skin files

2. **"Failed to copy [filename]"**

   * Close CS 1.6 before installing
   * Check write permissions
   * Verify the target path

3. **Compilation errors**

   * Ensure GCC is installed and in your PATH
   * Run build script from project root

> [!IMPORTANT]
> Always close CS 1.6 before installing skins to prevent file conflicts.

---

## 🤝 Contributing

Contributions are welcome! Suggestions:

* Cross-platform compatibility
* GUI interface
* Skin preview functionality
* Better error handling
* Config file support

---

> Open source. Use, modify, and distribute freely.

---

## 👤 Author

GitHub: [hax](https://github.com/i1lo)



