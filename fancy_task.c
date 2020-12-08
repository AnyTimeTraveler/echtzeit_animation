#include <stdlib.h>
#include <stdbool.h>

#define ROWS 32
#define COLS 90
#define INIT_COLS 85

char *data;

char initial_frame[] =
        "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\n"
        "X                                                                                        X\n"
        "X                                                                                        X\n"
        "X                                                                                        X\n"
        "X                                                                               | o |    X\n"
        "X                                                                               | o |    X\n"
        "X                                                                               | o |    X\n"
        "X                                                                               | o |    X\n"
        "X                                                                               | o |    X\n"
        "X                                                                               | o |    X\n"
        "X         | |         | |         | |                                           | o |    X\n"
        "X         | |         | |         | |   [X ]                                    | o |    X\n"
        "X         |o|         |o|         |o|     ||                                    | o |    X\n"
        "X         / /         / /         / /     ||            [/\\]                    | o |    X\n"
        "X    --|-/ /----|----/ /----|----/ /-------------|------//\\\\---------|----------    |    X\n"
        "X              >         >         >         >         //  \\\\      >  \\             |    X\n"
        "X    --|--------|-----------|--------------------|------\\   \\--------|--------------     X\n"
        "X                                                        +   +                           X\n"
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
        "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX";

#define is_changed_and_set(bit) (is_set(diff, bit) && is_set(input, bit))
#define is_changed_and_clear(bit) (is_set(diff, bit) && !is_set(input, bit))

int rutsche[] = {

};

void fancy_task_main(long id) {
    int i, ticks = 0, finished = 0, dropped = 0;
    unsigned int input= ~0, old_input = 0, diff;
    data = (char *) malloc(INIT_COLS + ROWS * COLS + 1);

    for (i = 0; i < INIT_COLS + ROWS * COLS; i++) {
        data[i] = initial_frame[i];
    }
    data[INIT_COLS + ROWS * COLS] = 0;


    rt_printk("%s\n", data);

    while (true) {
//        rt_mbx_receive(&tasks[id].input_mbx, &input, sizeof(unsigned int));
        diff = old_input ^ input;
        if (input == 0u) {
            // timer

            for (i = 1375; i >= 1367; i--) {

            }
        } else {

            // io event
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
            if (is_changed_and_set(IN_BAND_MASSENMAGAZIN_TEIL_AM_BANDENDE)) {
                data[1419] = 'o';
            }

            data[1315] = (is_set(input, IN_AUSWERFER_AUSSCHUSS_NACH_LINKS_AUSGEFAHREN) ||
                          is_set(input, IN_AUSWERFER_AUSSCHUSS_IN_MITTELPOSITION)) ? '/' : ' ';
            data[1316] = (is_set(input, IN_AUSWERFER_AUSSCHUSS_NACH_LINKS_AUSGEFAHREN) ||
                          is_set(input, IN_AUSWERFER_AUSSCHUSS_IN_MITTELPOSITION)) ? '/' : ' ';
            data[1317] = (is_set(input, IN_AUSWERFER_AUSSCHUSS_NACH_RECHTS_AUSGEFAHREN) ||
                          is_set(input, IN_AUSWERFER_AUSSCHUSS_IN_MITTELPOSITION)) ? '/' : ' ';
            data[1318] = (is_set(input, IN_AUSWERFER_AUSSCHUSS_NACH_RECHTS_AUSGEFAHREN) ||
                          is_set(input, IN_AUSWERFER_AUSSCHUSS_IN_MITTELPOSITION)) ? '/' : ' ';

            data[1405] = is_set(input, IN_AUSWERFER_AUSSCHUSS_NACH_LINKS_AUSGEFAHREN) ? '/' : ' ';
            data[1406] = is_set(input, IN_AUSWERFER_AUSSCHUSS_NACH_LINKS_AUSGEFAHREN) ? '/' : ' ';

            data[1409] = is_set(input, IN_AUSWERFER_AUSSCHUSS_NACH_RECHTS_AUSGEFAHREN) ? '\\' : ' ';
            data[1410] = is_set(input, IN_AUSWERFER_AUSSCHUSS_NACH_RECHTS_AUSGEFAHREN) ? '\\' : ' ';

            data[1591] = is_set(input, IN_RUTSCHE_AUSSCHUSS_RUTSCHE_VOLL) ? 'o' : ' ';
            data[1391] = (is_set(input, IN_HOEHENSENSOR_WERKSTUECK_VERDREHT) ||
                          is_set(input, IN_HOEHENSENSOR_MESSUNG_IN_ORDNUNG)) ? 'o' : ' ';

            if (is_set(input, IN_BAND_MASSENMAGAZIN_TEIL_AM_BANDENDE)) {
                dropped = 0;
                finished = 0;
            }

            if (is_set(diff, IN_RUTSCHE_AUSSCHUSS_RUTSCHE_VOLL) && is_set(input, IN_RUTSCHE_AUSSCHUSS_RUTSCHE_VOLL)) {
                dropped++;
            }
            if (is_set(diff, IN_BAND_MAGAZINE_TEIL_VOR_WEICHE) && !is_set(input, IN_BAND_MAGAZINE_TEIL_VOR_WEICHE)) {
                finished++;
            }
        }

        rt_printk("%s\n", data);
        old_input = input;
        break;
    }
}

void timer_task_main(long id){

}
