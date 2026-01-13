*This project has been created as part of the 42 curriculum by marberge.*

___

<div align="center">
<br>
  <img src="https://encrypted-tbn0.gstatic.com/images?q=tbn:ANd9GcTQPzuYKu7n0cWUYa5Kbg0_LrlEQAIURWeo9A&s" alt="42 Logo" width="400" />
<br>
</div>

# Libft

![Language](https://img.shields.io/badge/Language-C-blue)
![Score](https://img.shields.io/badge/Score-125%2F100-brightgreen)

## 📝 Description

**Libft** is the very first project at 42. The goal is to recreate a set of functions from the C standard library (`libc`) as well as some other useful functions that will be used throughout the curriculum.

This library serves as a personal toolkit for future projects, emphasizing strict adherence to standard behaviors, memory management, and robust code structure.

## 🛠️ Instructions

### Requirements
This project is written in C and requires a compiler (gcc/clang) and the standard C libraries.

### Compilation
To compile the library `libft.a`, simply run the following command at the root of the repository:

```bash
make
```

### Usage
To use `libft` in your own project:

1. Include the header file in your code:
   ```c
   #include "libft.h"
   ```
2. Compile your code linking the library:
   ```bash
   cc main.c -L. -lft -o my_program
   ```

## ⚙️ Technical Choices

This library is built with a focus on **reusability** and **strict compliance** with the original libc behavior.
* **Memory Safety:** Special attention is paid to prevent leaks and segmentation faults, especially in string manipulation and list handling.
* **Modularity:** Each function is contained in its own file to minimize the binary size when linking.

## ✅ Function List

### Libc Functions
| Function | Description |
| :--- | :--- |
| `ft_isalpha` | Checks for an alphabetic character. |
| `ft_isdigit` | Checks for a digit (0 through 9). |
| `ft_isalnum` | Checks for an alphanumeric character. |
| `ft_isascii` | Checks whether c fits into the ASCII character set. |
| `ft_isprint` | Checks for any printable character including space. |
| `ft_strlen` | Calculates the length of a string. |
| `ft_memset` | Fills memory with a constant byte. |
| `ft_bzero` | Zeroes a byte string. |
| `ft_memcpy` | Copies memory area. |
| `ft_memmove` | Copies memory area, handling overlapping memory correctly. |
| `ft_strlcpy` | Copies a string to a specific size with NUL-termination. |
| `ft_strlcat` | Concatenates a string to a specific size with NUL-termination. |
| `ft_toupper` | Converts a lower-case letter to upper-case. |
| `ft_tolower` | Converts an upper-case letter to lower-case. |
| `ft_strchr` | Locates the first occurrence of a character in a string. |
| `ft_strrchr` | Locates the last occurrence of a character in a string. |
| `ft_strncmp` | Compares two strings up to a specific number of characters. |
| `ft_memchr` | Scans memory for a character. |
| `ft_memcmp` | Compares memory areas. |
| `ft_strnstr` | Locates a substring in a string. |
| `ft_atoi` | Converts a string to an integer. |
| `ft_calloc` | Allocates memory and sets its bytes to zero. |
| `ft_strdup` | Creates a duplicate for the string passed as parameter. |

### Additional Functions
| Function | Description |
| :--- | :--- |
| `ft_substr` | Allocates and returns a substring from the string 's'. |
| `ft_strjoin` | Allocates and returns a new string, which is the result of the concatenation of 's1' and 's2'. |
| `ft_strtrim` | Allocates and returns a copy of 's1' with the characters specified in 'set' removed from the beginning and the end of the string. |
| `ft_split` | Allocates and returns an array of strings obtained by splitting 's' using the character 'c' as a delimiter. |
| `ft_itoa` | Allocates and returns a string representing the integer received as an argument. |
| `ft_strmapi` | Applies a function to each character of a string to create a new string. |
| `ft_striteri` | Applies a function to each character of a string, passing its index as the first argument. |
| `ft_putchar_fd` | Outputs the character 'c' to the given file descriptor. |
| `ft_putstr_fd` | Outputs the string 's' to the given file descriptor. |
| `ft_putendl_fd` | Outputs the string 's' to the given file descriptor, followed by a newline. |
| `ft_putnbr_fd` | Outputs the integer 'n' to the given file descriptor. |

### Bonus Functions (Linked Lists)
| Function | Description |
| :--- | :--- |
| `ft_lstnew` | Allocates and returns a new node. |
| `ft_lstadd_front` | Adds the node 'new' at the beginning of the list. |
| `ft_lstsize` | Counts the number of nodes in a list. |
| `ft_lstlast` | Returns the last node of the list. |
| `ft_lstadd_back` | Adds the node 'new' at the end of the list. |
| `ft_lstdelone` | Takes as a parameter a node and frees the memory of the node’s content using the function 'del' given as a parameter and free the node. |
| `ft_lstclear` | Deletes and frees the given node and every successor of that node, using the function 'del' and free(3). |
| `ft_lstiter` | Iterates the list 'lst' and applies the function 'f' on the content of each node. |
| `ft_lstmap` | Iterates the list 'lst' and applies the function 'f' on the content of each node to create a new list. |

## 📚 Resources

### References
* `man 3 ...` (Consult the man pages for the standard libc functions)
* [The C Programming Language](https://en.wikipedia.org/wiki/The_C_Programming_Language) (Kernighan & Ritchie)

### AI Usage Declaration
As required by the new subject guidelines, here is the detail of AI usage for this project:

* **Code Implementation:** The code was entirely written by the author (`marberge`). No AI-generated code was copy-pasted into the final project.
* **README:** This README has been written by AI to summarize the project structure and function definitions.

<br>

___

<p align="center">Made with ❤️ by marberge</p>