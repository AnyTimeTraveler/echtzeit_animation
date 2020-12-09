#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>

#define ROWS 32
#define COLS 90
#define INIT_COLS 85

char *data;

char initial_frame[] =
        "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\n"
        "X                                                                                        X\n"
        "X                                                                                        X\n"
        "X                                                                                        X\n"
        "X                                                                               |   |    X\n"
        "X                                                                               |   |    X\n"
        "X                                                                               |   |    X\n"
        "X                                                                               |   |    X\n"
        "X                                                                               |   |    X\n"
        "X                                                                               |   |    X\n"
        "X         | |         | |         | |                                           |   |    X\n"
        "X         | |         | |         | |   [X ]                                    |   |    X\n"
        "X         |o|         |o|         |o|     ||                                    |   |    X\n"
        "X         / /         / /         / /     ||            [/\\]                    |   |    X\n"
        "X    --|-/ /----|----/ /----|----/ /-------------|------//\\\\---------|----------    |    X\n"
        "X                                                      //  \\\\         \\             |    X\n"
        "X    --|--------|-----------|--------------------|------+   +--------|--------------     X\n"
        "X                                                        \\   \\                           X\n"
        "X                                                         \\   \\                          X\n"
        "X                                                          \\   \\                         X\n"
        "X                                                           \\   \\                        X\n"
        "X                                                            \\   \\                       X\n"
        "X                                                             \\   \\                      X\n"
        "X                                                              \\   \\                     X\n"
        "X                                                               \\   \\                    X\n"
        "X                                                                                        X\n"
        "X                                                                                        X\n"
        "X                                                                                        X\n"
        "X                                                                                        X\n"
        "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX";

void move_o(int i);

void remove_o(int pos);

void remove_char_if_equal(int i1, char i2);

#define is_changed_and_set(bit) (is_set(diff, bit) && is_set(input, bit))
#define is_changed_and_clear(bit) (is_set(diff, bit) && !is_set(input, bit))

#define MAX_TICKS 10

void fancy_task_main(long id) {
    int i, c, ticks = 0, finished = 0, dropped = 0, counter;
    unsigned int input = 0, old_input = 0, diff;
    data = (char *) malloc(INIT_COLS + ROWS * COLS + 1);

    for (i = 0; i < INIT_COLS + ROWS * COLS; i++) {
        data[i] = initial_frame[i];
    }
    data[INIT_COLS + ROWS * COLS] = 0;


//    rt_printk("%s\n", data);


    for (counter = 0; counter < 100; counter++) {
//        rt_mbx_receive(&tasks[id].input_mbx, &input, sizeof(unsigned int));
        diff = old_input ^ input;
//        if (input == 0u) {
        // timer

        remove_o(1365);
        for (i = 1365; i >= 1357; i--) {
            move_o(i);
        }

        remove_o(1377);
        for (i = 1377; i >= 1366; i--) {
            move_o(i);
        }

        remove_o(1398);
        for (i = 1398; i >= 1378; i--) {
            move_o(i);
        }

        remove_o(1418);
        for (i = 1418; i >= 1399; i--) {
            move_o(i);
        }

        remove_o(1432);
        for (i = 1432; i >= 1419; i--) {
            move_o(i);
        }

        c = 0;

        if (data[1432] == 'o') {
            data[1432] = ' ';
            finished++;
        }
        for (i = 431; i <= 1341 && c++ < finished; i += 91) {
            data[i] = 'o';
        }

        c = 0;
        remove_o(2235);
        for (i = 2235; i >= 1499 && c++ < dropped; i -= 92) {
            data[i] = 'o';
        }

        // move arrows
        for (i = 1432; i >= 1355; i--) {
            if (data[i] == '>') {
                data[i] = ' ';
            }
            if (i % MAX_TICKS == ticks % MAX_TICKS) {
                if (data[i] == ' ') {
                    data[i] = '>';
                }
            }
        }
        ticks++;

//        }

        data[1088] = is_set(input, IN_MAGAZIN_1_TEIL_DA) ? 'o' : ' ';
        data[1100] = is_set(input, IN_MAGAZIN_2_TEIL_DA) ? 'o' : ' ';
        data[1112] = is_set(input, IN_MAGAZIN_3_TEIL_DA) ? 'o' : ' ';
        if (is_changed_and_set(IN_VEREINZELER_AUSGANG_TEIL_DA)) {
            data[1419] = 'o';
        }

        data[1179] = is_set(input, IN_MAGAZIN_1_AUSGEFAHREN) ? '/' : ' ';
        data[1269] = is_set(input, IN_MAGAZIN_1_AUSGEFAHREN) ? '/' : ' ';
        if (is_changed_and_set(IN_MAGAZIN_1_AUSGEFAHREN)) {
            data[1359] = 'o';
        }

        data[1191] = is_set(input, IN_MAGAZIN_2_AUSGEFAHREN) ? '/' : ' ';
        data[1281] = is_set(input, IN_MAGAZIN_2_AUSGEFAHREN) ? '/' : ' ';
        if (is_changed_and_set(IN_MAGAZIN_2_AUSGEFAHREN)) {
            data[1371] = 'o';
        }

        data[1203] = is_set(input, IN_MAGAZIN_3_AUSGEFAHREN) ? '/' : ' ';
        data[1293] = is_set(input, IN_MAGAZIN_3_AUSGEFAHREN) ? '/' : ' ';
        if (is_changed_and_set(IN_MAGAZIN_3_AUSGEFAHREN)) {
            data[1383] = 'o';
        }

        if (is_changed_and_set(IN_BAND_MAGAZINE_TEIL_AM_BANDANFANG)) {
            data[1357] = 'o';
        }
        if (is_changed_and_set(IN_BAND_MAGAZINE_TEIL_ZW_MAG_1_UND_MAG_2)) {
            data[1366] = 'o';
        }
        if (is_changed_and_set(IN_BAND_MAGAZINE_TEIL_ZW_MAG_2_UND_MAG_3)) {
            data[1378] = 'o';
        }
        if (is_changed_and_set(IN_BAND_MAGAZINE_TEIL_VOR_WEICHE)) {
            data[1399] = 'o';
        }
        if (is_changed_and_set(IN_VEREINZELER_AUSGANG_TEIL_DA)) {
            data[1419] = 'o';
        }

        data[1315] = (is_set(input, IN_AUSWERFER_AUSSCHUSS_NACH_LINKS_AUSGEFAHREN) ||
                      is_set(input, IN_AUSWERFER_AUSSCHUSS_IN_MITTELPOSITION)) ? '/' : ' ';
        data[1316] = (is_set(input, IN_AUSWERFER_AUSSCHUSS_NACH_LINKS_AUSGEFAHREN) ||
                      is_set(input, IN_AUSWERFER_AUSSCHUSS_IN_MITTELPOSITION)) ? '/' : ' ';
        data[1317] = (is_set(input, IN_AUSWERFER_AUSSCHUSS_NACH_RECHTS_AUSGEFAHREN) ||
                      is_set(input, IN_AUSWERFER_AUSSCHUSS_IN_MITTELPOSITION)) ? '\\' : ' ';
        data[1318] = (is_set(input, IN_AUSWERFER_AUSSCHUSS_NACH_RECHTS_AUSGEFAHREN) ||
                      is_set(input, IN_AUSWERFER_AUSSCHUSS_IN_MITTELPOSITION)) ? '\\' : ' ';

        if (is_set(input, IN_AUSWERFER_AUSSCHUSS_NACH_LINKS_AUSGEFAHREN)) {
            data[1405] = '/';
            data[1406] = '/';
        } else if (is_set(input, IN_AUSWERFER_AUSSCHUSS_NACH_RECHTS_AUSGEFAHREN)) {
            data[1409] = '\\';
            data[1410] = '\\';
        } else {
            remove_char_if_equal(1405, '/');
            remove_char_if_equal(1406, '/');
            remove_char_if_equal(1409, '\\');
            remove_char_if_equal(1410, '\\');
        }

        data[1499] = is_set(input, IN_RUTSCHE_AUSSCHUSS_RUTSCHE_VOLL) ? 'o' : ' ';

        if (is_changed_and_clear(IN_VEREINZELER_AUSGANG_GESETZT)) {
            data[1420] = '\\';
        } else if (is_changed_and_set(IN_VEREINZELER_AUSGANG_GESETZT)) {
            data[1420] = 'o';
        }

        if (is_set(input, IN_HOEHENSENSOR_MESSUNG_IN_ORDNUNG)) {
            if (!is_set(input, IN_HOEHENSENSOR_WERKSTUECK_VERDREHT)) {
                data[1031] = 'O';
                data[1032] = 'K';
                data[1033] = '!';
                data[1034] = ' ';
                data[1035] = ' ';
                data[1036] = ' ';
            } else {
                data[1031] = 'W';
                data[1032] = 'R';
                data[1033] = 'O';
                data[1034] = 'N';
                data[1035] = 'G';
                data[1036] = '!';
            }
        } else {
            data[1031] = 'E';
            data[1032] = 'R';
            data[1033] = 'R';
            data[1034] = 'O';
            data[1035] = 'R';
            data[1036] = '!';
        }


        if (is_changed_and_set(IN_RUTSCHE_AUSSCHUSS_RUTSCHE_VOLL)) {
            dropped++;
            printf("Dropped: %d\n", dropped);
        }

        if (is_set(input, IN_BAND_MASSENMAGAZIN_TEIL_AM_BANDENDE)) {
            dropped = 0;
            finished = 0;
        }

//            if (is_changed_and_clear(IN_BAND_MAGAZINE_TEIL_VOR_WEICHE)) {
//                finished++;
//            }

        old_input = input;
        switch (counter) {
            case 1:
                input = (1u << (IN_MAGAZIN_1_TEIL_DA)) |
                        (1u << (IN_MAGAZIN_2_TEIL_DA)) |
                        (1u << (IN_MAGAZIN_3_TEIL_DA));
                break;
            case 2:
                input = (1u << (IN_MAGAZIN_1_AUSGEFAHREN)) |
                        (1u << (IN_MAGAZIN_2_AUSGEFAHREN)) |
                        (1u << (IN_MAGAZIN_3_AUSGEFAHREN));
                break;
            case 9:
                input = (1u << (IN_BAND_MAGAZINE_TEIL_ZW_MAG_1_UND_MAG_2)) |
                        (1u << (IN_BAND_MAGAZINE_TEIL_ZW_MAG_2_UND_MAG_3));
                break;
            case 18:
            case 30:
            case 42:
                input = (1u << (IN_BAND_MAGAZINE_TEIL_VOR_WEICHE));
                break;
            case 21:
                input = (1u << (IN_BAND_MAGAZINE_TEIL_ZW_MAG_2_UND_MAG_3));
                break;
            case 35:
            case 36:
            case 37:
                input = (1u << (IN_HOEHENSENSOR_WERKSTUECK_VERDREHT));
                break;
            case 38:
            case 50:
                input = (1u << (IN_VEREINZELER_AUSGANG_TEIL_DA));
                break;
            case 39:
            case 51:
                input = (1u << (IN_VEREINZELER_AUSGANG_GESETZT));
                break;
            case 52:
                input = (1u << (IN_RUTSCHE_AUSSCHUSS_RUTSCHE_VOLL));
                break;
            default:
                input = 0u;
                break;
        }
        if (counter > 45) {
            input |= (1u << (IN_AUSWERFER_AUSSCHUSS_NACH_RECHTS_AUSGEFAHREN));
        } else {
            input |= (1u << (IN_AUSWERFER_AUSSCHUSS_IN_MITTELPOSITION));
        }
        input |= (1u << (IN_HOEHENSENSOR_MESSUNG_IN_ORDNUNG));

        rt_printk("%s%d\n", data, counter);
        usleep(250 * 1000);
    }
}

void remove_char_if_equal(int i1, char i2) {
    if (data[i1] == i2) {
        data[i1] = ' ';
    }
}

void remove_o(int pos) {
    if (data[pos] == 'o') {
        data[pos] = ' ';
    }
}

void move_o(int i) {
    if (data[i] == 'o') {
        data[i + 1] = 'o';
        data[i] = ' ';
    }
}

void timer_task_main(long id) {

}
