# Description
This is a library for AVR projects written in C. It contains frequently used code that I often rewrote for each new project.

# Use in Your Project
Add the following code to your `CMakeLists.txt` file:

```cmake
# Set the microcontroller frequency and name
set(F_CPU 16000000UL)   # Define the microcontroller frequency (e.g., 16 MHz)
set(MCU atmega328p)     # Define the microcontroller model (e.g., ATmega328P)

# Download and compile the avr-utils library
FetchContent_Declare(
  avr_utils
  GIT_REPOSITORY https://github.com/fomgleb/avr-utils
  GIT_TAG v0.1    # Specify the library version
  GIT_SHALLOW TRUE
  SYSTEM)
FetchContent_MakeAvailable(avr_utils)

# Link the avr-utils library to your target
target_link_libraries(${ELF_FILE} PRIVATE avr_utils)
```
