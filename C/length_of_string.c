#include <stdio.h>
int main()
{
    char str[100];
    int i = 0, length;
    printf("\n Enter the string : ");
    gets(str);
    while(str[i] != '\0')
            i++;
    length = i;
    printf("\n The length of the string is : %d", length);
    return 0;
}
