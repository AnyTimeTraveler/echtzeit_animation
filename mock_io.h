
#include <stdio.h>
#include <stdarg.h>

void rt_printk(char* fmt, ...){
    va_list my_args;

    va_start(my_args, fmt);
    printf("[  913.280940] ");
    vprintf(fmt, my_args);

    va_end(my_args);
}
