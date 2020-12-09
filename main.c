
#include <stdbool.h>

#define IO_PRINT false
#define HOEHENMESSER_PRINT false
#define MAGAZIN_PRINT false
#define BEREICHE_PRINT false

#include "mock_io.h"
#include "io.h"
#include "fancy_task.c"

int main() {
    fancy_task_main(9);
//    scanf("%s", NULL);
    return 0;
}
