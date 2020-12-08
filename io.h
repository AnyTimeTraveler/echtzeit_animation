#define MAKE_MASK_1(a) (1 << a)
#define MAKE_MASK_2(a, b) ((1u << a) | (1u << b))
#define MAKE_MASK_3(a, b, c) ((1u << a) | (1u << b) | (1u << c))
#define MAKE_MASK_4(a, b, c, d) ((1u << a) | (1u << b) | (1u << c) | (1u << d))
#define MAKE_MASK_5(a, b, c, d, e) ((1u << a) | (1u << b) | (1u << c) | (1u << d) | (1u << e))

#include <string.h>

#define __FILENAME__ (strrchr(__FILE__, '/') ? strrchr(__FILE__, '/') + 1 : __FILE__)

#define print(...) rt_printk("%s:%d: ", __FILENAME__, __LINE__); rt_printk(__VA_ARGS__)

#define FOREACH_OUT(PORT) \
    PORT(OUT_BAND_MAGAZINE_STOP, 0u, Band (Magazine): Stop) \
    PORT(OUT_BAND_MAGAZINE_GESCHWINDIGKEIT_DROSSELN, 1u, Band (Magazine): Geschwindigkeit drosseln) \
    PORT(OUT_BAND_MAGAZINE_LINKSLAUF, 2u, Band (Magazine): Linkslauf) \
    PORT(OUT_BAND_MAGAZINE_RECHTSLAUF, 3u, Band (Magazine): Rechtslauf) \
    PORT(OUT_BAND_MASSENMAGAZIN_EIN, 4u, Band (Massenmagazin): Ein) \
    PORT(OUT_BAND_ZUBRINGER_RUECKWAERTS, 5u, Band (Zubringer): Rückwärts) \
    PORT(OUT_BAND_ZUBRINGER_VORWAERTS, 6u, Band (Zubringer): Vorwärts) \
    PORT(OUT_VEREINZELER_AUSGANG_SETZEN, 7u, Vereinzeler (Ausgang): Setzen) \
    PORT(OUT_VEREINZELER_MASSENMAGAZIN_SETZEN, 8u, Vereinzeler (Massenmagazin): Setzen) \
    PORT(OUT_MAGAZIN_1_EINFAHREN, 9u, Magazin 1: Einfahren) \
    PORT(OUT_MAGAZIN_1_AUSFAHREN, 10u, Magazin 1: Ausfahren) \
    PORT(OUT_MAGAZIN_2_EINFAHREN, 11u, Magazin 2: Einfahren) \
    PORT(OUT_MAGAZIN_2_AUSFAHREN, 12u, Magazin 2: Ausfahren) \
    PORT(OUT_MAGAZIN_3_EINFAHREN, 13u, Magazin 3: Einfahren) \
    PORT(OUT_MAGAZIN_3_AUSFAHREN, 14u, Magazin 3: Ausfahren) \
    PORT(OUT_AUSWERFER_AUSSCHUSS_NACH_RECHTS_AUSFAHREN, 15u, Auswerfer (Ausschuss): Nach Rechts ausfahren) \
    PORT(OUT_AUSWERFER_AUSSCHUSS_NACH_LINKS_AUSFAHREN, 16u, Auswerfer (Ausschuss): Nach Links ausfahren) \
    PORT(OUT_AUSWERFER_AUSSCHUSS_SPERRE_AUFHEBEN, 17u, Auswerfer (Ausschuss): Sperre aufheben)
//    PORT(OUT_BAND_ZUBRINGER_GESCHWINDIGKEIT, 0u, Band (Zubringer): Geschwindigkeit)

#define FOREACH_IN(PORT) \
    PORT(IN_BAND_MASSENMAGAZIN_TEIL_AM_BANDENDE, 0u, Band (Massenmagazin): Teil am Bandende) \
    PORT(IN_BAND_ZUBRINGER_TEIL_AM_BANDANFANG, 1u, Band (Zubringer): Teil am Bandanfang) \
    PORT(IN_BAND_MAGAZINE_TEIL_AM_BANDANFANG, 2u, Band (Magazine): Teil am Bandanfang) \
    PORT(IN_BAND_MAGAZINE_TEIL_ZW_MAG_1_UND_MAG_2, 3u, Band (Magazine): Teil zw. Mag 1 und Mag 2) \
    PORT(IN_BAND_MAGAZINE_TEIL_ZW_MAG_2_UND_MAG_3, 4u, Band (Magazine): Teil zw. Mag 2 und Mag 3) \
    PORT(IN_BAND_MAGAZINE_TEIL_VOR_WEICHE, 5u, Band (Magazine): Teil vor Weiche) \
    PORT(IN_VEREINZELER_AUSGANG_GESETZT, 6u, Vereinzeler (Ausgang): Gesetzt) \
    PORT(IN_VEREINZELER_AUSGANG_TEIL_DA, 7u, Vereinzeler (Ausgang): Teil da) \
    PORT(IN_VEREINZELER_MASSENMAGAZIN_GESETZT, 8u, Vereinzeler (Massenmagazin): Gesetzt) \
    PORT(IN_VEREINZELER_MASSENMAGAZIN_TEIL_DA, 9u, Vereinzeler (Massenmagazin): Teil da) \
    PORT(IN_MAGAZIN_1_EINGEFAHREN, 10u, Magazin 1: Eingefahren) \
    PORT(IN_MAGAZIN_1_AUSGEFAHREN, 11u, Magazin 1: Ausgefahren) \
    PORT(IN_MAGAZIN_1_TEIL_DA, 12u, Magazin 1: Teil da) \
    PORT(IN_MAGAZIN_2_EINGEFAHREN, 13u, Magazin 2: Eingefahren) \
    PORT(IN_MAGAZIN_2_AUSGEFAHREN, 14u, Magazin 2: Ausgefahren) \
    PORT(IN_MAGAZIN_2_TEIL_DA, 15u, Magazin 2: Teil da) \
    PORT(IN_MAGAZIN_3_EINGEFAHREN, 16u, Magazin 3: Eingefahren) \
    PORT(IN_MAGAZIN_3_AUSGEFAHREN, 17u, Magazin 3: Ausgefahren) \
    PORT(IN_MAGAZIN_3_TEIL_DA, 18u, Magazin 3: Teil da) \
    PORT(IN_AUSWERFER_AUSSCHUSS_NACH_RECHTS_AUSGEFAHREN, 19u, Auswerfer (Ausschuss): Nach rechts ausgefahren) \
    PORT(IN_AUSWERFER_AUSSCHUSS_NACH_LINKS_AUSGEFAHREN, 20u, Auswerfer (Ausschuss): Nach links ausgefahren) \
    PORT(IN_AUSWERFER_AUSSCHUSS_IN_MITTELPOSITION, 21u, Auswerfer (Ausschuss): In Mittelposition) \
    PORT(IN_AUSWERFER_AUSSCHUSS_SPERRE_GESETZT, 22u, Auswerfer (Ausschuss): Sperre gesetzt) \
    PORT(IN_RUTSCHE_AUSSCHUSS_RUTSCHE_VOLL, 23u, Rutsche (Ausschuss): Rutsche voll) \
    PORT(IN_HOEHENSENSOR_WERKSTUECK_VERDREHT, 24u, Hoehensensor: Werkstueck verdreht) \
    PORT(IN_HOEHENSENSOR_MESSUNG_IN_ORDNUNG, 25u, Hoehensensor: Messung in Ordnung)
//    PORT(IN_HOEHENSENSOR_ANALOGER_MESSWERT_HOEHE, 10u, Höhensensor: Analoger Messwert Höhe)

#define GENERATE_ENUM(NAME, PORT, STRING) NAME = PORT,
#define GENERATE_STRING(NAME, PORT, STRING) #STRING,

enum IO {
    FOREACH_IN(GENERATE_ENUM) FOREACH_OUT(GENERATE_ENUM)
};

const char *IN_STRINGS[] = {FOREACH_IN(GENERATE_STRING)};

const char *OUT_STRINGS[] = {FOREACH_OUT(GENERATE_STRING)};

void print_changes(const char **strings, unsigned int old_input,
                   unsigned int new_input) {
    unsigned int diff = old_input ^new_input;
    unsigned int i = 0;

    if (!IO_PRINT) return;
    for (; i < 32; ++i) {
        // if i'th bit changed:
        if (((diff >> i) & 1u) == 1u) {
            print("%s: %d -> %d\n", strings[i],
                  (old_input >> i) & 1u,
                  (new_input >> i) & 1u);
        }
    }
}

#define is_set(value, bit) ((1u << (bit)) & (value))
#define do_set(value, bit) ((1u << (bit)) | (value))

#define set(bit) bit | 128u
#define clear(bit) bit

#define ENABLE(bit)    output = set(bit);\
    rt_mbx_send(&output_task->input_mbx, &output, sizeof(unsigned char));
#define DISABLE(bit)    output = clear(bit);\
    rt_mbx_send(&output_task->input_mbx, &output, sizeof(unsigned char));

#define WAIT_FOR_ENABLE(bit)    while(!is_set(input, bit)) { rt_mbx_receive(&tasks[id].input_mbx, &input, sizeof(unsigned int)); }

#define WAIT_FOR_DISABLE(bit)    while(is_set(input, bit)) { rt_mbx_receive(&tasks[id].input_mbx, &input, sizeof(unsigned int)); }
