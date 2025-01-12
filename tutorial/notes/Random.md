## clrscr() function

Included in <conio.h> library. The previous screen on the console is cleared whenever the clrscr () is invoked in a program. (Like running clear on the console) 

## continue statement
When we use a continue statement inside a loop, it will skip the rest of the code and force the next iteration of the loop.

## break statement
When we use a break statement inside a loop, it will exit the loop/switch.

e.g.

```c
for(int i=1; i<=20; i++){
    if(i==13){
        continue;
    }
    printf("%d\n", i);
}
```

This will output all numbers from 1 to 20 except for 13. 