| Type                  | Bytes | Other Names                              | Range of Values                                      |
|-----------------------|-------|------------------------------------------|------------------------------------------------------|
| __int__               | 4     | signed                                   | -2,147,483,648 to 2,147,483,647                      |
| unsigned int          | 4     | unsigned                                 | 0 to 4,294,967,295                                  |
| __int8                | 1     | char                                     | -128 to 127                                         |
| unsigned __int8       | 1     | unsigned char                            | 0 to 255                                            |
| __int16               | 2     | short, short int, signed short int       | -32,768 to 32,767                                   |
| unsigned __int16      | 2     | unsigned short, unsigned short int       | 0 to 65,535                                         |
| __int32               | 4     | signed, signed int, int                  | -2,147,483,648 to 2,147,483,647                    |
| unsigned __int32      | 4     | unsigned, unsigned int                   | 0 to 4,294,967,295                                  |
| __int64               | 8     | long long, signed long long              | -9,223,372,036,854,775,808 to 9,223,372,036,854,775,807 |
| unsigned __int64      | 8     | unsigned long long                       | 0 to 18,446,744,073,709,551,615                         |
| __bool__              | 1     | none                                     | false or true                                           |
| __char__              | 1     | none                                     | -128 to 127 by default; 0 to 255 with /J                |
| signed char           | 1     | none                                     | -128 to 127                                         |
| unsigned char         | 1     | none                                     | 0 to 255                                            |
| short                 | 2     | short int, signed short int              | -32,768 to 32,767                                   |
| unsigned short        | 2     | unsigned short int                       | 0 to 65,535                                         |
| long                  | 4     | long int, signed long int                | -2,147,483,648 to 2,147,483,647                    |
| unsigned long         | 4     | unsigned long int                        | 0 to 4,294,967,295                                  |
| long long             | 8     | none (but equivalent to __int64)         | -9,223,372,036,854,775,808 to 9,223,372,036,854,775,807 |
| unsigned long long    | 8     | none (but equivalent to unsigned __int64)| 0 to 18,446,744,073,709,551,615                    |
| enum                  | varies| none                                     | Depends on underlying type                          |
| __float__                 | 4     | none                                     | 3.4E ± 38 (7 digits)                                |
| __double__               | 8     | none                                     | 1.7E ± 308 (15 digits)                              |
| long double           | 8     | none                                     | Same as double                                       |
| wchar_t               | 2     | __wchar_t                                | 0 to 65,535                                         |
