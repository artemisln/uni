## String functions found in string.h

Functions that alter the string itself
- `strlwr(string1)`: Converts a string to lowercase.
- `strupr(string1)`: Converts a string to uppercase.
- `strcat(string1, string2)`: Appends `string2` to the end of `string1`.
- `strcpy(string1, string2)`: Copies `string2` to `string1`.
- `strncat(string1, string2, n)`: Appends `n` characters from `string2` to `string1`.
- `strncpy(string1, string2, n)`: Copies `n` characters of `string2` to `string1`.

Functions that return an integer value 
- `strlen(string1)`: Returns the length of `string1`.
- `strcmp(string1, string2)`: Compares all characters of `string1` and `string2`.
- `strncmp(string1, string2, n)`: Compares the first `n` characters of `string1` and `string2`.
- `strcmpi(string1, string2)`: Compares all characters of `string1` and `string2`, ignoring case.
- `strnicmp(string1, string2, n)`: Compares the first `n` characters of `string1` and `string2`, ignoring case.

Not commonly used: 
- `strrev(string1)`: Reverses string1.