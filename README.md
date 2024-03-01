
# C++ Investigation Project

This C++ project is a university student registration system. It reads student data from a file, processes it, and writes the processed data to another file. The data includes student names, IDs, registration status, level, and credits. The user is prompted to input the institution's name, campus, and professor's name. The processed data, including the institution's name, campus, department, semester, professor's name, course, and the table of students' information, is then written to a new file named "output.csv".


## 🛠️ Installation

This project requires MinGW to compile and run. The minimum version requirement is MinGW 3.6.0-1 from 2019, but the recommended version is MinGW w64 version 11.0 or 12.0. The code has been tested in MinGW 3.6.0-1, MinGW w64 11.0 and 12.0.

### MinGW Installation

1. Download the MinGW Installation Manager from [here](https://sourceforge.net/projects/mingw/).

2. Open the downloaded file and follow the instructions to install MinGW Installation Manager.

3. Once installed, open the MinGW Installation Manager.

4. Select the packages you need (at least `mingw32-base` and `mingw32-gcc-g++`).

5. Apply changes and wait for the packages to be installed.

⚠️ **Warning**: This version of MinGW is outdated. Use at your own risk.

For a visual guide on installing MinGW, you can watch this [YouTube video](https://www.youtube.com/watch?v=fzOmcmUcl_E).

### MinGW w64 Installation

1. Download MSYS2 from the [official page](https://www.msys2.org/) or directly via this [installer link](https://www.msys2.org/).

2. Run the installer and follow the on-screen instructions. Choose your installation folder (the default is usually fine) and ensure to check `Run MSYS2 now` at the end.

3. Once installed, open MSYS2 terminal.

4. In the MSYS2 terminal, execute: `pacman -S --needed base-devel mingw-w64-ucrt-x86_64-toolchain`

5. Type `Y` and press Enter when prompted to confirm the installation.

For a visual guide on installing MinGW w64, you can watch this [YouTube video](https://www.youtube.com/watch?v=DMWD7wfhgNY).

### MinGW Environment Variable Set-up

1. Open the System Properties (Right click Computer in the start menu, or use the keyboard shortcut Win+Pause)

2. Click Advanced system settings

3. Click Environment Variables

4. Under System Variables, find and select the Path variable

5. Click Edit

6. In the Edit System Variable window, click New

7. Type the path to the MinGW bin folder (e.g., `C:\MinGW\bin` or `C:\msys64\mingw64\bin` for MinGW w64)

8. Click OK in all windows to apply the changes

You may need to restart any open command prompt windows for changes to take effect.

### Testing Installation

After installing MinGW or MinGW w64, you can test whether the installation was successful by running the following commands in the command prompt:

```cmd
gcc --version
g++ --version
gdb --version
```
## 🏃‍♂️How to Run

To run the code, you need to have MinGW installed with a release higher than `6.3.0-1` from 2019. The code also works with current iterations of MinGW (MinGW-w64 such as 11.0 w64 the latest version of MSYS2 12.0 w64).

### Running in jGrasp

1. **Set up the workspace**: Install and open jGrasp. Navigate to `Settings > PATH/CLASSPATH > Workspace`. From the Workspace, select the `PATH` tab, then select the `PATHS` tab. Click on `New` and insert the path of your MinGW directory (For MSYS2, it's `C:\msys64\ucrt64`. For MinGW 6.3.0-1 it's `C:\MinGW`).

2. **Set the compiler**: Go to the `Compiler` tab, set the language to `C++`, and in the `Environment` tab, select `g++ generic`. Click `Apply` then `Close`.

3. **Run the code**: In the `Browse` tab on the left side of jGrasp, navigate to the path of the project folder and open `main.cpp`. Click on the double green `+` icon in the header to compile and link the codes, then click on the red running icon to run the `main.exe` executable file.

For a visual guide on setting up the jGrasp environment and running a C++ file, you can watch this [YouTube video](https://youtu.be/fzOmcmUcl_E?si=7SDH4_e3-i4Be46x&t=253).

### Running in Visual Studio Code

1. **Install Visual Studio Code and MinGW**: If you haven't already, install Visual Studio Code and MinGW. Make sure to add MinGW to your system's PATH.

2. **Install the C++ extension**: Go to the Extensions view (`View > Extensions`), search for `c++`, and then install the `C/C++` extension provided by Microsoft.

3. **Open the project in Visual Studio Code**: Open Visual Studio Code, then go to `File > Open Folder` and select the project folder.

4. **Run the code**: Click `Run or Debug...` on the top right corner, click Run and select `C/C++: g++ from C:\msys64\mingw64\bin\g++.exe` to build the code. This will create an executable file in the same directory as your source code as well as run it (might have to run it 2 times).

For a visual guide on setting up the Visual Studio Code environment and running a C++ file, you can watch this [YouTube video](https://www.youtube.com/watch?v=DMWD7wfhgNY).
## 📝 Authors

This section lists the authors who contributed to the different files in the project:

- `main.cpp`: Eduardo A. Sosa Torres
- `FileParser.cpp`/`FileParser.h`: [DEFAULT]
- `FileReader.cpp`/`FileReader.h`: [DEFAULT]
- `FileWriter.cpp`/`FileWriter.h`: [DEFAULT]
- `HeaderMaker.cpp`/`HeaderMaker.h`: [DEFAULT]
- `Students.cpp`/`Students.h`: [DEFAULT]
- `README.md`: Eduardo A. Sosa Torres
- Made the code runnable in jGrasp: Eduardo A. Sosa Torres
## 📋[TEMPORARY] To-Do

### Coding Requirements
- [✔️] Develop a C++ application that processes content from a Studlist-generated page, saved in a text file, into a CSV format compatible with Excel.
- [✔️] The application must request additional information not included in the Studlist file (e.g., name of the institution, campus) from the user.
- [✔️] The application should prompt the user for the name of the input text file and the output CSV file.
- [✔️] Ensure the application can handle any number of student records, from 1 to many.
- [] The program must be well-documented, with detailed comments on functions and methods, including objective, pre-conditions, post-conditions, argument descriptions, author, and date of completion.
  - [] Word Documentation
  - [✔️] Comment Documentation
  - [✔️] Function Documentation

### Turnable Requirements:
- [] A single file containing all the program code.
- [] A video (5-10 minutes, mp4 format) demonstrating the application's functionality, including a walkthrough of the code and examples of executions. The video must have clear voice explanations and legible on-screen text.
- [] Test files used in the video and for program testing, showcasing the application's capability to load and process data.
- [] A peer evaluation document as provided by the professor, filled out and submitted individually.
- [] All files (code, video, tests, peer evaluation) must be named according to the format COMP3800MemberCpp## and compressed into a single folder for submission.