*This project has been created as part of the 42 curriculum by mcrenn.*

# :fast_forward: GET NEXT LINE

## :page_facing_up: Description:
This project is about programming a function that returns a line read from a file descriptor. If there is nothing left to read or an error  occurs, it return **NULL**. When a line is return, the buffer stored in a static variable is updated and the returnes line is removed.

In bonus part, the get next line function can manage multiple file descriptors .

## :straight_ruler: Instructions:
To execute the function correctly, you have to adding your own **file.txt** and a main who use the **open** function to give the file director to get_next_line function.

Main exemple:
```c
/**
* Including all dependencies:
* get_next_line.h is my header
* <stdio.h> is the library to use printf
* <fcntl.h> is the library to use open
*/
#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int main(void)
{
	int		fd; //The file director
	char	*next_line; //The line returned by GNL
	int		count;//Show the line numbers

	count = 1;
	fd = open("file.txt", O_RDONLY); //Give to fd an ID
	next_line = get_next_line(fd); //Use GNL function to file.txt
	while (next_line) //While line remaining in the txt
	{
		printf("[%d]:%s\n", count, next_line); //Print the line returned and his line count
		free(next_line); //Free the allocated memory by the line returned
		next_line = get_next_line(fd); //Return the next line
		count++; //Incrementing the line counter
	}
	free(next_line); //Free allocated memory by the last line
	next_line = NULL; //Put the variale to NULL pointer
	close(fd); //Close the file directory
	return (0);
}
```
In your terminal, compile the main, get nex line and utils with the flags. And execute the a.out !

```
cc -Wall -Wextra -Werror main.c get_next_line.c get_next_line_utils.c
```

## :books: Resources:
- What is a ["static variable"](https://en.wikipedia.org/wiki/Static_variable)
- What is [read](https://pubs.opengroup.org/onlinepubs/009604599/functions/read.html), how to use it ?
- What is [open](https://pubs.opengroup.org/onlinepubs/007904875/functions/open.html),how to use it ?
- [Francinette](https://github.com/xicodomingues/francinette) (to test my function)
