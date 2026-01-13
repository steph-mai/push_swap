*This project has been created as part of the 42 curriculum by marberge.*

___

<div align="center">
<br>
  <img src="https://encrypted-tbn0.gstatic.com/images?q=tbn:ANd9GcTQPzuYKu7n0cWUYa5Kbg0_LrlEQAIURWeo9A&s" alt="42 Logo" width="400" />

  <br>
</div>

# ft_printf


![Language](https://img.shields.io/badge/Language-C-blue)
![Score](https://img.shields.io/badge/Score-100%2F100-brightgreen)

## 📝 Description

The goal of this project is to recreate the famous `printf` function from the C standard library (libc). This project is an introduction to **variadic functions** in C, allowing us to manage a variable number of arguments.

Beyond the basic functionality, this implementation focuses on **performance optimization** and robust **error management**. Instead of writing characters one by one to the standard output, this project utilizes a buffering system to minimize system calls.

## 🛠️ Instructions

### Requirements
This project is written in C and requires a compiler (gcc/clang) and the standard C libraries.

### Compilation
To compile the library `libftprintf.a`, simply run the following command at the root of the repository:

```bash
make
```

### Usage
To use `ft_printf` in your own project:

1. Include the header file in your code:
   ```c
   #include "ft_printf.h"
   ```
2. Compile your code linking the library:
   ```bash
   cc main.c -L. -lftprintf -o my_program
   ```

### Example
```c
int main(void)
{
    ft_printf("Hello %s, you are %d years old.\n", "Marco", 42);
    return (0);
}
```

## ⚙️ Technical Choices & Algorithm

This section details the specific implementation choices made for this project, particularly regarding memory management and I/O operations.

### The Data Structure: Buffered Output
Unlike a standard implementation that might use `write(1, &c, 1)` for every character, this project uses a **local buffer** (Stack memory) defined by `BUFFER_SIZE` (default: 1024 bytes).

```c
char buffer[BUFFER_SIZE];
int  buf_index;
```

### The Algorithm
The logic follows a **producer-consumer** pattern simplified for a single thread:

1.  **Parsing:** The format string is read character by character.
2.  **Buffering:**
    * Regular characters are added directly to the buffer.
    * Format specifiers (`%d`, `%s`, etc.) are converted to strings and appended to the buffer.
3.  **The Flush Mechanism:**
    * Before adding any data, the function checks if the buffer has enough space.
    * If the buffer is full (or if the data to add exceeds the remaining space), the content is "flushed" to standard output using a single `write` syscall, and the index is reset.
4.  **Finalization:** Before returning, the remaining content in the buffer is flushed.

### Justification
The choice of a buffered approach is driven by performance optimization.
> **Why?** Switching between User Space and Kernel Space (syscall) is "expensive" for the CPU. By aggregating data into chunks (1024 bytes) before writing, we significantly reduce the number of syscalls compared to a char-by-char approach.

### Error Management
The project implements strict error handling. If a `write` operation fails (returns -1) at any point during the execution (even inside a sub-function), the error is propagated up to the main function, which cleanly terminates the process, frees allocated resources, and returns -1.

## ✅ Supported Conversions

| Conversion | Description |
| :---: | :--- |
| `%c` | Prints a single character. |
| `%s` | Prints a string (as defined by the common C convention). |
| `%p` | The `void *` pointer argument has to be printed in hexadecimal format. |
| `%d` / `%i` | Prints a decimal (base 10) number. |
| `%u` | Prints an unsigned decimal (base 10) number. |
| `%x` | Prints a number in hexadecimal (base 16) lowercase format. |
| `%X` | Prints a number in hexadecimal (base 16) uppercase format. |
| `%%` | Prints a percent sign. |

## 📚 Resources

### References
* `man 3 printf`
* `man 3 stdarg` (Handling variadic lists)
* [Wikipedia: Variadic function](https://en.wikipedia.org/wiki/Variadic_function)

### AI Usage Declaration
As required by the new subject guidelines, here is the detail of AI usage for this project:

* **Code Implementation:** The code was entirely written by the author (`marberge`). No AI-generated code was copy-pasted into the final project.
* **Debugging:** AI was used to analyze crash reports (segfaults) and identify logical errors in the return value propagation (specifically handling `-1` across multiple function calls).
* **Optimization:** AI was consulted to discuss the pros and cons of buffer sizes (`BUFFER_SIZE`) regarding system performance (User Space vs Kernel Space).
* **Testing:** AI was used to generate edge-case scenarios (e.g., buffer overflow limits) to verify the robustness of the `flush_buffer` function.
* **README:** This README has been written by AI.


<br>

___

<p align="center">Made by ❤️ by marberge<p>
