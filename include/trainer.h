#ifndef GUARD_TRAINER_H
#define GUARD_TRAINER_H

#define TRAINER_ENCOUNTER_MUSIC_MALE         0 // standard male encounter music
#define TRAINER_ENCOUNTER_MUSIC_FEMALE       1 // standard female encounter music
#define TRAINER_ENCOUNTER_MUSIC_GIRL         2 // used for male Tubers and Young Couples too
#define TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS   3
#define TRAINER_ENCOUNTER_MUSIC_INTENSE      4
#define TRAINER_ENCOUNTER_MUSIC_COOL         5
#define TRAINER_ENCOUNTER_MUSIC_AQUA         6
#define TRAINER_ENCOUNTER_MUSIC_MAGMA        7
#define TRAINER_ENCOUNTER_MUSIC_SWIMMER      8
#define TRAINER_ENCOUNTER_MUSIC_TWINS        9 // used for other trainer classes too
#define TRAINER_ENCOUNTER_MUSIC_ELITE_FOUR  10
#define TRAINER_ENCOUNTER_MUSIC_HIKER       11 // used for other trainer classes too
#define TRAINER_ENCOUNTER_MUSIC_INTERVIEWER 12
#define TRAINER_ENCOUNTER_MUSIC_RICH        13 // Rich Boys and Gentlemen

#define F_TRAINER_FEMALE 1 << 7

// All trainer parties specify the IV, level, and species for each Pokémon in
// the  party. Some trainer parties also specify held items and custom moves
// for each Pokémon.
#define F_TRAINER_PARTY_CUSTOM_MOVESET 1 << 0
#define F_TRAINER_PARTY_HELD_ITEM 1 << 1
#define F_TRAINER_PARTY_FULL_CONTROL 1 << 2

enum {
    FACILITY_CLASS_AQUA_LEADER,
    FACILITY_CLASS_TEAM_AQUA_M,
    FACILITY_CLASS_TEAM_AQUA_F,
    FACILITY_CLASS_AROMA_LADY,
    FACILITY_CLASS_RUIN_MANIAC,
    FACILITY_CLASS_INTERVIEWER,
    FACILITY_CLASS_TUBER_F,
    FACILITY_CLASS_TUBER_M,
    FACILITY_CLASS_COOL_TRAINER_M,
    FACILITY_CLASS_COOL_TRAINER_F,
    FACILITY_CLASS_HEX_MANIAC,
    FACILITY_CLASS_LADY,
    FACILITY_CLASS_BEAUTY,
    FACILITY_CLASS_RICH_BOY,
    FACILITY_CLASS_POKEMANIAC,
    FACILITY_CLASS_SWIMMER_M,
    FACILITY_CLASS_BLACK_BELT,
    FACILITY_CLASS_GUITARIST,
    FACILITY_CLASS_KINDLER,
    FACILITY_CLASS_CAMPER,
    FACILITY_CLASS_BUG_MANIAC,
    FACILITY_CLASS_PSYCHIC_M,
    FACILITY_CLASS_PSYCHIC_F,
    FACILITY_CLASS_GENTLEMAN,
    FACILITY_CLASS_ELITE_FOUR_M,
    FACILITY_CLASS_ELITE_FOUR_F,
    FACILITY_CLASS_LEADER_F,
    FACILITY_CLASS_LEADER_M,
    FACILITY_CLASS_LEADER_MF,
    FACILITY_CLASS_SCHOOL_KID_M,
    FACILITY_CLASS_SCHOOL_KID_F,
    FACILITY_CLASS_SR_AND_JR,
    FACILITY_CLASS_POKEFAN_M,
    FACILITY_CLASS_POKEFAN_F,
    FACILITY_CLASS_EXPERT_M,
    FACILITY_CLASS_EXPERT_F,
    FACILITY_CLASS_YOUNGSTER,
    FACILITY_CLASS_CHAMPION,
    FACILITY_CLASS_FISHERMAN,
    FACILITY_CLASS_CYCLING_TRIATHLETE_M,
    FACILITY_CLASS_CYCLING_TRIATHLETE_F,
    FACILITY_CLASS_RUNNING_TRIATHLETE_M,
    FACILITY_CLASS_RUNNING_TRIATHLETE_F,
    FACILITY_CLASS_SWIMMING_TRIATHLETE_M,
    FACILITY_CLASS_SWIMMING_TRIATHLETE_F,
    FACILITY_CLASS_DRAGON_TAMER,
    FACILITY_CLASS_BIRD_KEEPER,
    FACILITY_CLASS_NINJA_BOY,
    FACILITY_CLASS_BATTLE_GIRL,
    FACILITY_CLASS_PARASOL_LADY,
    FACILITY_CLASS_SWIMMER_F,
    FACILITY_CLASS_PICNICKER,
    FACILITY_CLASS_TWINS,
    FACILITY_CLASS_SAILOR,
    FACILITY_CLASS_BOARDER_1,
    FACILITY_CLASS_BOARDER_2,
    FACILITY_CLASS_COLLECTOR,
    FACILITY_CLASS_WALLY,
    FACILITY_CLASS_BRENDAN_1,
    FACILITY_CLASS_BRENDAN_2,
    FACILITY_CLASS_BRENDAN_3,
    FACILITY_CLASS_MAY_1,
    FACILITY_CLASS_MAY_2,
    FACILITY_CLASS_MAY_3,
    FACILITY_CLASS_POKEMON_BREEDER_M,
    FACILITY_CLASS_POKEMON_BREEDER_F,
    FACILITY_CLASS_POKEMON_RANGER_M,
    FACILITY_CLASS_POKEMON_RANGER_F,
    FACILITY_CLASS_MAGMA_LEADER,
    FACILITY_CLASS_TEAM_MAGMA_M,
    FACILITY_CLASS_TEAM_MAGMA_F,
    FACILITY_CLASS_LASS,
    FACILITY_CLASS_BUG_CATCHER,
    FACILITY_CLASS_HIKER,
    FACILITY_CLASS_YOUNG_COUPLE,
    FACILITY_CLASS_OLD_COUPLE,
    FACILITY_CLASS_SIS_AND_BRO
};

enum {
    TRAINER_PIC_BRENDAN,
    TRAINER_PIC_MAY,
    TRAINER_PIC_LASS,
    TRAINER_PIC_YOUNGSTER,
    TRAINER_PIC_HIKER,
    TRAINER_PIC_BEAUTY,
    TRAINER_PIC_FISHERMAN,
    TRAINER_PIC_LADY,
    TRAINER_PIC_CYCLING_TRIATHLETE_M,
    TRAINER_PIC_AQUA_GRUNT_M,
    TRAINER_PIC_TWINS,
    TRAINER_PIC_SWIMMER_F,
    TRAINER_PIC_BUG_CATCHER,
    TRAINER_PIC_SCHOOL_KID_M,
    TRAINER_PIC_RICH_BOY,
    TRAINER_PIC_SR_AND_JR,
    TRAINER_PIC_BLACK_BELT,
    TRAINER_PIC_WALLY,
    TRAINER_PIC_AQUA_GRUNT_F,
    TRAINER_PIC_TUBER_F,
    TRAINER_PIC_HEX_MANIAC,
    TRAINER_PIC_POKEMON_BREEDER_F,
    TRAINER_PIC_MAGMA_GRUNT_M,
    TRAINER_PIC_MAGMA_GRUNT_F,
    TRAINER_PIC_INTERVIEWER,
    TRAINER_PIC_TUBER_M,
    TRAINER_PIC_YOUNG_COUPLE,
    TRAINER_PIC_GUITARIST,
    TRAINER_PIC_GENTLEMAN,
    TRAINER_PIC_STEVEN,
    TRAINER_PIC_MAXIE,
    TRAINER_PIC_RUNNING_TRIATHLETE_F,
    TRAINER_PIC_RUNNING_TRIATHLETE_M,
    TRAINER_PIC_BATTLE_GIRL,
    TRAINER_PIC_CYCLING_TRIATHLETE_F,
    TRAINER_PIC_SWIMMER_M,
    TRAINER_PIC_POKEFAN_F,
    TRAINER_PIC_EXPERT_M,
    TRAINER_PIC_EXPERT_F,
    TRAINER_PIC_SWIMMING_TRIATHLETE_M,
    TRAINER_PIC_SWIMMING_TRIATHLETE_F,
    TRAINER_PIC_DRAGON_TAMER,
    TRAINER_PIC_BIRD_KEEPER,
    TRAINER_PIC_NINJA_BOY,
    TRAINER_PIC_PARASOL_LADY,
    TRAINER_PIC_BUG_MANIAC,
    TRAINER_PIC_SAILOR,
    TRAINER_PIC_COLLECTOR,
    TRAINER_PIC_POKEMON_BREEDER_M,
    TRAINER_PIC_POKEMON_RANGER_M,
    TRAINER_PIC_POKEMON_RANGER_F,
    TRAINER_PIC_MAGMA_ADMIN_M,
    TRAINER_PIC_MAGMA_ADMIN_F,
    TRAINER_PIC_AROMA_LADY,
    TRAINER_PIC_RUIN_MANIAC,
    TRAINER_PIC_COOL_TRAINER_M,
    TRAINER_PIC_COOL_TRAINER_F,
    TRAINER_PIC_POKEMANIAC,
    TRAINER_PIC_KINDLER,
    TRAINER_PIC_CAMPER,
    TRAINER_PIC_PICNICKER,
    TRAINER_PIC_PSYCHIC_M,
    TRAINER_PIC_PSYCHIC_F,
    TRAINER_PIC_SCHOOL_KID_F,
    TRAINER_PIC_POKEFAN_M,
    TRAINER_PIC_SIS_AND_BRO,
    TRAINER_PIC_OLD_COUPLE,
    TRAINER_PIC_AQUA_ADMIN_M,
    TRAINER_PIC_AQUA_ADMIN_F,
    TRAINER_PIC_UNUSED_AQUA,
    TRAINER_PIC_ARCHIE,
    TRAINER_PIC_ROXANNE,
    TRAINER_PIC_BRAWLY,
    TRAINER_PIC_WATTSON,
    TRAINER_PIC_FLANNERY,
    TRAINER_PIC_NORMAN,
    TRAINER_PIC_WINONA,
    TRAINER_PIC_TATE_AND_LIZA,
    TRAINER_PIC_WALLACE,
    TRAINER_PIC_SIDNEY,
    TRAINER_PIC_PHOEBE,
    TRAINER_PIC_GLACIA,
    TRAINER_PIC_DRAKE,
};

enum {
    TRAINER_CLASS_POKEMON_TRAINER_1,
    TRAINER_CLASS_POKEMON_TRAINER_2,
    TRAINER_CLASS_AQUA_LEADER,
    TRAINER_CLASS_TEAM_AQUA,
    TRAINER_CLASS_AQUA_ADMIN,
    TRAINER_CLASS_AROMA_LADY,
    TRAINER_CLASS_RUIN_MANIAC,
    TRAINER_CLASS_INTERVIEWER,
    TRAINER_CLASS_TUBER_F,
    TRAINER_CLASS_TUBER_M,
    TRAINER_CLASS_COOL_TRAINER,
    TRAINER_CLASS_HEX_MANIAC,
    TRAINER_CLASS_LADY,
    TRAINER_CLASS_BEAUTY,
    TRAINER_CLASS_RICH_BOY,
    TRAINER_CLASS_POKEMANIAC,
    TRAINER_CLASS_SWIMMER_M,
    TRAINER_CLASS_BLACK_BELT,
    TRAINER_CLASS_GUITARIST,
    TRAINER_CLASS_KINDLER,
    TRAINER_CLASS_CAMPER,
    TRAINER_CLASS_BUG_MANIAC,
    TRAINER_CLASS_PSYCHIC,
    TRAINER_CLASS_GENTLEMAN,
    TRAINER_CLASS_ELITE_FOUR,
    TRAINER_CLASS_LEADER,
    TRAINER_CLASS_SCHOOL_KID,
    TRAINER_CLASS_SR_AND_JR,
    TRAINER_CLASS_WINSTRATE,
    TRAINER_CLASS_POKEFAN,
    TRAINER_CLASS_EXPERT,
    TRAINER_CLASS_YOUNGSTER,
    TRAINER_CLASS_CHAMPION,
    TRAINER_CLASS_FISHERMAN,
    TRAINER_CLASS_TRIATHLETE,
    TRAINER_CLASS_DRAGON_TAMER,
    TRAINER_CLASS_BIRD_KEEPER,
    TRAINER_CLASS_NINJA_BOY,
    TRAINER_CLASS_BATTLE_GIRL,
    TRAINER_CLASS_PARASOL_LADY,
    TRAINER_CLASS_SWIMMER_F,
    TRAINER_CLASS_PICNICKER,
    TRAINER_CLASS_TWINS,
    TRAINER_CLASS_SAILOR,
    TRAINER_CLASS_BOARDER,
    TRAINER_CLASS_COLLECTOR,
    TRAINER_CLASS_POKEMON_TRAINER_3,
    TRAINER_CLASS_POKEMON_BREEDER,
    TRAINER_CLASS_POKEMON_RANGER,
    TRAINER_CLASS_MAGMA_LEADER,
    TRAINER_CLASS_TEAM_MAGMA,
    TRAINER_CLASS_MAGMA_ADMIN,
    TRAINER_CLASS_LASS,
    TRAINER_CLASS_BUG_CATCHER,
    TRAINER_CLASS_HIKER,
    TRAINER_CLASS_YOUNG_COUPLE,
    TRAINER_CLASS_OLD_COUPLE,
    TRAINER_CLASS_SIS_AND_BRO
};

#endif // GUARD_TRAINER_H
