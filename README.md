# c-cels-fahr-converter

### 0. Purpose
- MJU Computer Engineering System Programming class project (Fall, 2020)
- To learn UDP socket programming

### 1. Features
- Provides number-selecting console menu for client-side app
- User input validation
- Celsius-to-Fahrenheit and Fahrenheit-to-Celsius conversion
- Makefile to compile both server and client app easier

### 2. How to use
- About prerequisites
  - This app requires <b>gcc</b> and <b>make</b>.
  - For Windows user, follow these links to download prerequisites:
    - [MinGW](https://sourceforge.net/projects/mingw/)
    - [Make for Windows](http://gnuwin32.sourceforge.net/packages/make.htm)
- Usage
  1.     git clone https://github.com/13circle/c-cels-fahr-converter
  2.     make
  3. Open new terminal window and go to <b>c-cels-fahr-converter</b> directory.
  4.     ./temp_server
  5. Come back to the original terminal window.
  6.     ./temp_client
  7.  Now follow the instruction from the client app.
- Details
  - Both server and client apps terminate after client app select "Quit & Exit".
  - As user input validation is handled, any input mistakes including type mismatch are acceptable.
- Miscellaneous <b>make</b> commands
  - Remove all object files
    -     make cleanobj
  - Remove all executables
    -     make cleanexe
  - Remove all object files and executables
    -     make clean

