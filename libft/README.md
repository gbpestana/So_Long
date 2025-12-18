This project is to replicate some functions according to Libft PDF from 42 School.

*isalpha = Check if the 'int' is alphabetic
*isdigit = Check if the 'int' is a digit (0 a 9)
*isalnum = Check if the 'int' is alphabetic or number
*isacii = Check if the 'int' is ASCII (0 - 127)
*isprint = Check if the 'int' is printable (ASCII 32 a 126)
*strlen = Return the size of a string 's'
*memset = Copy 'n' numbers of 'int' to the string 's'
*bzero = Copy 'n' numbers of '\0' to the string 's'
*memcpy = Copy 'n' spaces from 'src' to 'dest'
*memmove = Move 'n' spaces from 'src' to 'dest' 
*strlcpy = Return size of 'src' string and copy 'n' spaces 'src' to 'dest'
*strlcat = Return size of 'src' or 'src' + 'n' and concatane 'dest' in the end of 'src'
*toupper = Check 'isalpha' and go uppercase if is not yet
*tolower = Check 'isalpha' and go lowercase if is not yet
*strchr = Return a pointer to the first occurance of int 'c' on string 's'
*strrchr = Return a pointer to the last occurance of int 'c' on string 's'
*strncmp = Compare 'n' positions of 2 strings 's1' and 's2' and return the difference 
*memchr = Put 'c' character on 'n' spaces of 's' pointer memory
*strnstr = Return a pointer of the beginning when string 'little' starts on string 'big'
*atoi = Return a integer received as a pointer character
*calloc = Mallocs 'nmemb' of 'size' spaces and return a pointer
*strdup = Returns a pointer that mallocs and copies the content of string 's' the space

**substr = Returns a pointer to a substring from a string 's' that starts on 'start' and have 'size' as size.
**strjoin = Returns a pointer to a string that unites strings 's1' and 's2'
**strtrim = Return a pointer to a string between the first and last occurance of 'set' on 's1'
**split = Returns a pointer to an array of strings created from string 's' and splitted by char 'c'
**itoa = Returns a pointer to a string representing a number 'n' received as argument
**strmapi = Returns a pointer to a string that contains the result of a function 'f' applied in every character of string 's'
**striteri = Apply a function 'f' on every character of string 's'
**putchar_fd = Write the char 'c' according to 'fd' file decriptor passed
**putstr_fd = Put the string 's' according to 'fd' file decriptor passed
**putendl_fd = Put the string 's' according to 'fd' file decriptor passed with '\n' in the end
**putnbr_fd = Write the number 'n' according to 'fd' file decriptor passed

Bonus
The bonus part we have to work with structed list. The struct is defined on libft.h.

***lst_new = Returns a pointer to the new node created to the list with 'content' inside and 'NULL' on 'next'
***lstadd_front = Add a new node at the beggining of the 'lst'
***lstsize = Returns a 'int' size of the 'lst'
***lstlast = Returns a pointer to the last node of the 'lst'
***lstadd_back = Add a new node at the end of the 'lst'
***lstdelone = Del one node from 'lst'
***lstclear = Clears all 'content' and free the list 'lst'
***lstiter = Apply the function 'f' on every 'content' of the list 'lst'
***lstmap = Iterates through the list 'lst', applies the function 'f' to each node's content, and creates a new list resulting of the successive applications of the function 'f'. The 'del' function is used to delete the content of a node if needed.
