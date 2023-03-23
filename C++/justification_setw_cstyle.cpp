#include<bits/stdc++.h>
using namespace std;
int main(){
    printf("%7.3f\t %10.2f\n",6.2029393,45544.2323);
    printf("%10.5s\n","hello world");
    printf("%*.*s\n",10,3,"hello world");
}

// %-.2f left justification,default is right justification
// %7.3f 7 column total with 3 decimal places
// %10.5s field-width 10 column, but prints 5 chars of the string specified
// %*.*(type-specifier) , give field-width using variable

/* Right justification:
   hello world
        worlda
         hello
           tha
            nd
             a       */
/* Left justification:
   hello worlda
   worlda
   hello
   tha
   nd
   a                  */
