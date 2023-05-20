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

To use get_next_line, call the function in a loop until it returns 0, indicating the end of the file, or -1 in case of an error. 
Make sure to free the allocated memory for each line when you're done with it.

````
#include "get_next_line.h"
#include <fcntl.h>  // for file descriptor constants

int main()
{
    int fd = open("example.txt", O_RDONLY);
    if (fd == -1) {
        perror("Failed to open file");
        return 1;
    }

    char *line;
    int ret;
    while ((ret = get_next_line(fd, &line)) > 0) {
        // Process the line
        printf("%s\n", line);
        free(line);
    }

    if (ret == -1) {
        perror("Error reading file");
        return 1;
    }

    close(fd);
    return 0;
}

````

## Support

Feel free to contact me on slack or via email

email - `tehuanmelo@gmail.com`

twitter - `@tehuanmelo`

slack - `tde-melo`

## Acknowledgments
I would like to express my sincere gratitude to @42AbuDhabi , and all of the staff members and who have supported me throughout my journey here.
