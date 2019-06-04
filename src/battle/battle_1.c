#include "global.h"
#include "data2.h"
#include "battle_setup.h"
#include "battle.h"
#include "trainer.h"
#include "graphics.h"
#include "gba/types.h"
#include "constants/species.h"
#include "constants/moves.h"
#include "constants/items.h"
#include "constants/opponents.h"

const struct MonCoords gTrainerBackPicCoords[] = {
    {8, 4},
    {8, 4},
    {8, 4},
};

extern const u8 gTrainerBackPic_Brendan[];
extern const u8 gTrainerBackPic_May[];
extern const u8 gTrainerBackPic_Wally[];

const struct CompressedSpriteSheet gTrainerBackPicTable[] = {
    {gTrainerBackPic_Brendan, 0x2000, 0},
    {gTrainerBackPic_May, 0x2000, 1},
    {gTrainerBackPic_Wally, 0x2000, 2}
};

extern const u8 gTrainerPalette_Brendan[];
extern const u8 gTrainerPalette_May[];
extern const u8 gTrainerPalette_Wally[];

const struct CompressedSpritePalette gTrainerBackPicPaletteTable[] = {
    {gTrainerPalette_Brendan, 0},
    {gTrainerPalette_May, 1},
    {gTrainerPalette_Wally, 2}
};

// This determines how much higher above the usual position the enemy Pokémon
// is during battle. Species that float or fly have nonzero values.
const u8 gEnemyMonElevation[NUM_SPECIES] =
{
    [SPECIES_BUTTERFREE] = 10,
    [SPECIES_BEEDRILL] = 9,
    [SPECIES_PIDGEOT] = 5,
    [SPECIES_FEAROW] = 6,
    [SPECIES_ZUBAT] = 16,
    [SPECIES_GOLBAT] = 10,
    [SPECIES_VENOMOTH] = 16,
    [SPECIES_GEODUDE] = 16,
    [SPECIES_MAGNEMITE] = 17,
    [SPECIES_MAGNETON] = 9,
    [SPECIES_GASTLY] = 10,
    [SPECIES_HAUNTER] = 11,
    [SPECIES_VOLTORB] = 11,
    [SPECIES_ELECTRODE] = 12,
    [SPECIES_KOFFING] = 14,
    [SPECIES_WEEZING] = 6,
    [SPECIES_AERODACTYL] = 9,
    [SPECIES_ZAPDOS] = 8,
    [SPECIES_MEW] = 11,
    [SPECIES_LEDIAN] = 10,
    [SPECIES_CROBAT] = 9,
    [SPECIES_HOPPIP] = 15,
    [SPECIES_SKIPLOOM] = 15,
    [SPECIES_JUMPLUFF] = 9,
    [SPECIES_YANMA] = 13,
    [SPECIES_MURKROW] = 12,
    [SPECIES_MISDREAVUS] = 12,
    [SPECIES_UNOWN] = 8,
    [SPECIES_GLIGAR] = 8,
    [SPECIES_LUGIA] = 6,
    [SPECIES_HO_OH] = 6,
    [SPECIES_CELEBI] = 15,
    [SPECIES_BEAUTIFLY] = 10,
    [SPECIES_DUSTOX] = 12,
    [SPECIES_NINJASK] = 10,
    [SPECIES_SHEDINJA] = 8,
    [SPECIES_WINGULL] = 15,
    [SPECIES_PELIPPER] = 8,
    [SPECIES_MASQUERAIN] = 10,
    [SPECIES_BALTOY] = 1,
    [SPECIES_CLAYDOL] = 10,
    [SPECIES_FLYGON] = 7,
    [SPECIES_GLALIE] = 12,
    [SPECIES_LUNATONE] = 13,
    [SPECIES_SOLROCK] = 4,
    [SPECIES_SWABLU] = 12,
    [SPECIES_ALTARIA] = 8,
    [SPECIES_DUSKULL] = 13,
    [SPECIES_SHUPPET] = 14,
    [SPECIES_BANETTE] = 8,
    [SPECIES_CASTFORM] = 16,
    [SPECIES_BELDUM] = 8,
    [SPECIES_RAYQUAZA] = 6,
    [SPECIES_LATIAS] = 12,
    [SPECIES_LATIOS] = 6,
    [SPECIES_JIRACHI] = 14,
    [SPECIES_CHIMECHO] = 16,
    [SPECIES_MOTHIM] = 10,
    [SPECIES_COMBEE] = 8,
    [SPECIES_VESPIQUEN] = 4,
    [SPECIES_DRIFLOON] = 5,
    [SPECIES_DRIFBLIM] = 7,
    [SPECIES_MISMAGIUS] = 3,
    [SPECIES_BRONZONG] = 4,
    [SPECIES_MAGNEZONE] = 4,
    [SPECIES_TOGEKISS] = 14,
    [SPECIES_YANMEGA] = 6,
    [SPECIES_GLISCOR] = 6,
    [SPECIES_ROTOM] = 10,
    [SPECIES_UXIE] = 6,
    [SPECIES_MESPRIT] = 6,
    [SPECIES_AZELF] = 6,
    [SPECIES_CRESSELIA] = 3,
    [SPECIES_DARKRAI] = 4,
    [SPECIES_WOOBAT] = 19,
    [SPECIES_SWOOBAT] = 12,
    [SPECIES_PETILIL] = 7,
    [SPECIES_SIGILYPH] = 7,
    [SPECIES_YAMASK] = 10,
    [SPECIES_ARCHEOPS] = 8,
    [SPECIES_SOLOSIS] = 14,
    [SPECIES_DUOSION] = 7,
    [SPECIES_REUNICLUS] = 3,
    [SPECIES_EMOLGA] = 19,
    [SPECIES_TYNAMO] = 16,
    [SPECIES_EELEKTRIK] = 8,
    [SPECIES_EELEKTROSS] = 8,
    [SPECIES_BRAVIARY] = 8,
    [SPECIES_HYDREIGON] = 3,
    [SPECIES_TORNADUS] = 7,
    [SPECIES_THUNDURUS] = 7,
    [SPECIES_LANDORUS] = 7,
    // Gens 6 & 7
    [SPECIES_FLETCHINDER] = 9,
    [SPECIES_TALONFLAME] = 7,
    [SPECIES_VIVILLON] = 9,
    [SPECIES_NOIBAT] = 8,
    [SPECIES_HOOPA] = 13,
    [SPECIES_VIKAVOLT] = 8,
    [SPECIES_CUTIEFLY] = 10,
    [SPECIES_MINIOR] = 17,
};

#include "../data/trainer_parties.h"

#if ENGLISH
#include "../data/text/trainer_class_names_en.h"
#include "../data/trainers_en.h"
#include "../data/text/species_names_en.h"
#include "../data/text/move_names_en.h"
#elif GERMAN
#include "../data/text/trainer_class_names_de.h"
#include "../data/trainers_de.h"
#include "../data/text/species_names_de.h"
#include "../data/text/move_names_de.h"
#endif

const u32 gUnknown_81F9528 = 0x101;
