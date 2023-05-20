# get_next_line

The get_next_line function is a utility that allows reading a file descriptor line by line. This project was developed as part of the 42 curriculum.

## Table of Contents
- [Getting Started](#getting-started)
- [Usage](#usage)
- [Support](#support)
- [Acknowledgments](#acknowledgments)

## Getting Started

To use the get_next_line function in your project, follow these steps:

1. Clone this repository to your local machine.
2. Copy the get_next_line.c, get_next_line_utils.c and get_next_line.h files into your project directory.
3. Include the get_next_line.h header file in your source files.


````
#include "get_next_line.h"
````

## Usage

The get_next_line function reads a line from a file descriptor and returns it as a null-terminated string. 
It provides a convenient way to process large files line by line, without having to load the entire file into memory.

To use get_next_line, call the function in a loop until it returns NULL, indicating the end of the file. 
Make sure to free the allocated memory for each line when you're done with it.

````
#include "get_next_line.h"
#include <fcntl.h>  // for file descriptor constants

int main()
{
    int fd = open("file.txt", O_RDONLY);
    if (fd == -1) {
        perror("Failed to open file");
        return 1;
    }

    char *line;
    while ((line = get_next_line(fd))) {
        // Process the line
        printf("%s\n", line);
        free(line);
    }
    close(fd);
    return 0;
}

````

If needed you can specify the buffer size at compilation for the get_next_line project, you can use the -D flag followed by the BUFFERSIZE macro when compiling your code. This allows you to define the buffer size to be used in the get_next_line function.

For example, when using GCC to compile your code, you can use the following command:
```
gcc main.c get_next_line.c get_next_line_utils.c -D BUFFERSIZE=100
```
This will set the BUFFERSIZE macro to a value of 100 during compilation, which will be used as the buffer size in the get_next_line function.

Using this approach, you can customize the buffer size according to your requirements, providing flexibility and control over the memory allocation for reading lines from the file descriptor.

## Support

Feel free to contact me on slack or via email

email - `tehuanmelo@gmail.com`

twitter - `@tehuanmelo`

slack - `tde-melo`

## Acknowledgments
I would like to express my sincere gratitude to @42AbuDhabi , and all of the staff members and who have supported me throughout my journey here.
