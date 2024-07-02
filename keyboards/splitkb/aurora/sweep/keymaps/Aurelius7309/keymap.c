#include QMK_KEYBOARD_H

enum {
	TD_SPC_ENT,
	TD_ALT_CLOSE,
	TD_SYM_NUM,
	TD_DCR_NAV,
};

enum layers {
	_BASE,
	_QWERTY,
	_SYM,
	_DCR,
	_NUM_LEFT,
	_NUM_RGHT,
	_ALT_LEFT,
	_ALT_RGHT,
	_VI_LEFT,
	_VI_RGHT,
	_NAV,
	_NUM,
};

enum unicode_names {
	// DIACRITICS

	A_D,
	A_DC,
	E_D,
	E_DC,
	I_D,
	I_DC,
	O_D,
	O_DC,
	U_D,
	U_DC,

	E_A,
	E_AC,

	A_G,
	A_GC,
	E_G,
	E_GC,
	U_G,
	U_GC,

	A_C,
	A_CC,
	E_C,
	E_CC,
	I_C,
	I_CC,
	O_C,
	O_CC,
	U_C,
	U_CC,

	AE,
	AE_C,
	OE,
	OE_C,

	SZ,
	SZ_C,

	CED,
	CED_C,

	// SYMBOLS

	EUR,
	DOL

};

const uint32_t unicode_map[] PROGMEM = {
	[A_D] = 0xe4, // x 0.54% in German
	[A_DC] = 0xc4,
	[E_D] = 0xeb, // x 0.01% in French
	[E_DC] = 0xcb,
	[I_D] = 0xef, // <0.01% in French
	[I_DC] = 0xcf,
	[O_D] = 0xf6, // x 0.30% in German
	[O_DC] = 0xd6,
	[U_D] = 0xfc, // x 0.65% in German | 0.02% in French
	[U_DC] = 0xdc,

	[E_A] = 0xe9, // x 2.13% in French
	[E_AC] = 0xc9,

	[A_G] = 0xe0, // x 0.54% in French
	[A_GC] = 0xc0,
	[E_G] = 0xe8, // x 0.35% in French
	[E_GC] = 0xc8,
	[U_G] = 0xf9, // x 0.02% in French (it's just one word, duh)
	[U_GC] = 0xd9,

	[A_C] = 0xe2, // x 0.03% in French
	[A_CC] = 0xc2,
	[E_C] = 0xea, // x 0.24% in French
	[E_CC] = 0xca,
	[I_C] = 0xee, // x 0.03% in French
	[I_CC] = 0xce,
	[O_C] = 0xf4, // x 0.07% in French
	[O_CC] = 0xd4,
	[U_C] = 0xfb, // x 0.05% in French
	[U_CC] = 0xdb,

	[AE] = 0xe6, // used for Latin lean words in French
	[AE_C] = 0xc6,
	[OE] = 0x0153, // x 0.01% in French
	[OE_C] = 0x0152,

	[SZ] = 0xdf, // x 0.37% in German
	[SZ_C] = 0x1e9e,

	[CED] = 0xe7, // x <0.01% in French
	[CED_C] = 0xc7,


	[EUR] = 0x20ac,
	[DOL] = 0x24,
};

tap_dance_action_t tap_dance_actions[] = {
    [TD_SPC_ENT] = ACTION_TAP_DANCE_DOUBLE(KC_SPC, KC_ENT),
	[TD_ALT_CLOSE] = ACTION_TAP_DANCE_DOUBLE(KC_LALT, A(KC_F4)),
	#if false
	[TD_DCR_NAV] = ACTION_TAP_DANCE_DOUBLE(OSL(_DCR), TO(_NAV)),
	[TD_SYM_NUM] = ACTION_TAP_DANCE_DOUBLE(OSL(_SYM), TO(_NUM))
	#endif
};

const key_override_t dot_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_DOT, KC_QUES);
const key_override_t comm_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_COMM, KC_EXLM);
// const key_override_t mins_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_MINS, KC_EQL);

// This globally defines all key overrides to be used
const key_override_t **key_overrides = (const key_override_t *[]){
    &dot_key_override,
	&comm_key_override,
//	&mins_key_override,
    NULL // Null terminate the array of overrides!
};

enum my_keycodes {
	SS_CHAP = SAFE_RANGE,
	SS_SECT,
	SS_SSEC,
	SS_PARA,
	SS_SPAR,
	SS_CHAS,
	SS_SECS,
	SS_SSTS,
	SS_PARS,
	SS_SPRS,
	SS_TEN,
	SS_HUND,
	SS_THOU,
	SS_MILL,
	SS_HUNDS,
	SS_THOUS,
	SS_MILLS,
	SS_SCNT,
	A_QU,
	A_AA,
	A_ZZ,
	A_WR,
	A_FF,
	A_SC,
	ALT_CC,
	A_PP,
	A_DT,
	A_DD,
	A_BB,
	A_GG,
	A_BV,
	A_MM,
	A_KK,
	A_LL,
	A_HN,
	A_HNL,
	A_UE,
	A_EU,
	A_YOU,
	A_IY,
	A_OO,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[_BASE] = LAYOUT(
		KC_Q 				, KC_W 			, KC_F  		, LT(_VI_RGHT, KC_P)		, KC_B          , /*******/ KC_J    		, LT(_VI_LEFT, KC_L)	, KC_U         	, KC_Y   		, KC_MINS ,
       	LT(_ALT_RGHT, KC_A) , LCTL_T(KC_R) 	, LALT_T(KC_S)  , LGUI_T(KC_T)  			, KC_G          , /*******/ KC_M    		, LGUI_T(KC_N) 			, LALT_T(KC_E) 	, LCTL_T(KC_I) 	, LT(_ALT_LEFT, KC_O) ,
		KC_Z 				, KC_X 			, KC_C  	    , LT(_NUM_RGHT, KC_D)		, KC_V          , /*******/ KC_K    		, LT(_NUM_LEFT, KC_H)	, KC_COMM		, KC_DOT	 	, KC_QUOT ,
											OSL(_SYM)					, OSM(MOD_LSFT)	, /*******/ TD(TD_SPC_ENT)	, OSL(_DCR)
		),
	[_QWERTY] = LAYOUT(
		KC_Q , KC_W , KC_E , KC_R , KC_T , /********/ KC_Y , KC_U , KC_I 	, KC_O 				, KC_P ,
		KC_A , KC_S , KC_D , KC_F , KC_G , /********/ KC_H , KC_J , KC_K 	, KC_L 				, KC_ENT,
		KC_Z , KC_X , KC_C , KC_V , KC_B , /********/ KC_N , KC_M , KC_LGUI	, TD(TD_ALT_CLOSE)	, A(KC_TAB),
				TO(_BASE) , OSM(MOD_LSFT), /********/ KC_SPC, KC_LCTL
	),
     [_SYM] = LAYOUT(
        KC_ESC  , KC_LBRC 		, KC_RBRC 		, KC_COLN 	, KC_HASH , /*******/ KC_PIPE , KC_PERC , KC_RABK , KC_LABK , KC_BSPC ,
        KC_TAB  , KC_LPRN 		, KC_RPRN 		, KC_SCLN 	, KC_CIRC , /*******/ KC_AT   , KC_BSLS , KC_PLUS , KC_SLSH , KC_MINS ,
        TO(_NUM), S(KC_LBRC) 	, S(KC_RBRC) 	, KC_DLR  	, X(EUR)  , /*******/ KC_AMPR , KC_EQL  , KC_EXLM , KC_ASTR , TO(_NAV),
                                  				  XXXXXXX 	, _______ , /*******/ _______ , XXXXXXX
        ),
	[_DCR] = LAYOUT(
		KC_ESC  		, XP(OE, OE_C)  , XP(I_D, I_DC)		, TO(_QWERTY) 	, XXXXXXX , /*******/ XXXXXXX , XP(U_G, U_GC)	, XP(E_G, E_GC)	, XP(U_D, U_DC) , C(KC_BSPC) ,
        XP(A_G, A_GC)   , XP(E_A, E_AC) , XP(SZ, SZ_C)		, XP(E_D, E_DC) , XXXXXXX , /*******/ XXXXXXX , XP(E_C, E_CC)	, XP(O_D, O_DC)	, XP(A_D, A_DC) , XP(U_C, U_CC) ,
        TO(_NUM)		, XP(I_C, I_CC) , XP(CED, CED_C)	, UC_NEXT 		, XXXXXXX , /*******/ XXXXXXX , XP(AE, AE_C)	, XP(O_C, O_CC)	, XP(A_C, A_CC) , TO(_NAV) ,
															  XXXXXXX		, _______ , /*******/ _______ , XXXXXXX
	),
	[_NUM_LEFT] = LAYOUT(
		SS_MILL	, SS_THOU  , SS_HUND 	, SS_TEN  	, XXXXXXX 	, /*******/ XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , 
		KC_4 	, KC_3     , KC_2  		, KC_1    	, KC_5		, /*******/	KC_9 	, KC_0	  , KC_6	, KC_7	  , KC_8    ,
		SS_SCNT	, SS_MILLS , SS_THOUS 	, SS_HUNDS 	, XXXXXXX 	, /*******/ XXXXXXX , _______ , XXXXXXX , XXXXXXX , XXXXXXX , 
									  	  XXXXXXX 	, KC_LGUI 	, /*******/ KC_LCTL , XXXXXXX
	),
	[_NUM_RGHT] = LAYOUT(
		SS_MILL	, SS_THOU  , SS_HUND 	, SS_TEN	, XXXXXXX 	, /*******/ SS_CHAS , SS_SECS , SS_SSTS , SS_PARS , SS_SPRS , 
		KC_4	, KC_3		, KC_2		, KC_1		, KC_5 		, /*******/	KC_9 	, KC_0	  , KC_6	, KC_7	  , KC_8    ,
		SS_SCNT	, SS_MILLS , SS_THOUS 	, _______ 	, XXXXXXX 	, /*******/ SS_CHAP , SS_SECT , SS_SSEC , SS_PARA , SS_SPAR , 
									  		XXXXXXX , KC_LGUI 	, /*******/ KC_LCTL , XXXXXXX
	),
	[_ALT_LEFT] = LAYOUT(
		A_QU , _______ , A_FF 	, A_PP , A_BB , /*******/ _______ , A_LL  , A_UE     , A_YOU   	, _______ ,
       	A_AA , A_WR	   , A_SC 	, A_DT , A_GG , /*******/ A_MM 	, A_HN  , A_EU  	, A_IY 		, _______ ,
		A_ZZ , _______ , ALT_CC , A_DD , A_BV , /*******/ A_KK 	, A_HNL , _______  , _______ 	, _______ ,
					_______ , _______	 , /*******/ _______ , _______
	),
	[_ALT_RGHT] = LAYOUT(
		_______ , _______ , A_FF 	, A_PP , A_BB , /*******/ _______  , A_LL  , A_UE    , A_YOU  , _______ ,
       	_______ , A_WR 	  , A_SC 	, A_DT , A_GG , /*******/ A_MM 	, A_HN  , A_EU	  , A_IY 	, A_OO    ,
		_______ , _______ , ALT_CC 	, A_DD , A_BV , /*******/ A_KK 	, A_HNL , _______ , _______ , _______ ,
							_______ , _______  , /*******/ _______ , _______
	),
	[_VI_LEFT] = LAYOUT(
		KC_A	, KC_S 	  , KC_W 	, KC_D	  , XXXXXXX , /*******/ XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,
		KC_LEFT , KC_DOWN , KC_UP	, KC_RGHT , XXXXXXX , /*******/ XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,
		KC_H	, KC_J    , KC_K	, KC_L 	  , XXXXXXX , /*******/ XXXXXXX , XXXXXXX , _______ , XXXXXXX , XXXXXXX ,
									  _______ , _______ , /*******/ _______ , _______
	),
	[_VI_RGHT] = LAYOUT(
		XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , /*******/ XXXXXXX , KC_A	  , KC_S 	, KC_W 	  , KC_D    ,
		XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , /*******/ XXXXXXX , KC_H 	  , KC_J  	, KC_K	  , KC_L    ,
		XXXXXXX , XXXXXXX , _______ , XXXXXXX , XXXXXXX , /*******/ XXXXXXX , KC_LEFT , KC_DOWN , KC_UP	  , KC_RGHT ,
									  _______ , _______ , /*******/ _______ , _______
	),
	[_NAV] = LAYOUT(
		KC_ESC  , KC_WH_L , KC_MS_U , KC_WH_R   , XXXXXXX 		, /*******/ KC_PSLS 	  , KC_PAST , KC_PPLS 	, KC_PMNS 	, KC_BSPC  ,
		KC_TAB  , KC_MS_L , KC_MS_D , KC_MS_R   , KC_DEL  		, /*******/ KC_LEFT 	  , KC_DOWN , KC_UP 	, KC_RGHT 	, KC_ENT ,
		TO(_NUM), KC_BTN2 , KC_WH_U , KC_WH_D   , XXXXXXX 		, /*******/ KC_BTN1 	  , KC_ACL0 , KC_ACL1 	, KC_ACL2 	, XXXXXXX ,
									  TO(_BASE) , OSM(MOD_LCTL) , /*******/ OSM(MOD_LALT) , TO(_BASE)
	),
	[_NUM] = LAYOUT(
		KC_ESC  , KC_F7 , KC_F8 , KC_F9     , KC_F12 		, /*******/ KC_COMM , KC_7 , KC_8 , KC_9 , KC_BSPC  ,
		KC_TAB  , KC_F4 , KC_F5 , KC_F6     , KC_F11 		, /*******/ KC_DOT  , KC_4 , KC_5 , KC_6 , KC_ENT ,
		XXXXXXX , KC_F1 , KC_F2 , KC_F3     , KC_F10 		, /*******/ KC_0    , KC_1 , KC_2 , KC_3 , TO(_NAV) ,
								  TO(_BASE) , OSM(MOD_LSFT) , /*******/ KC_LALT , TO(_BASE)
	)
}; 

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  	switch (keycode) {
    	case SS_CHAP:
			if (record->event.pressed) {
				SEND_STRING("\\chapter{");
			}
			return false;
		case SS_SECT:
			if (record->event.pressed) {
				SEND_STRING("\\section{");
			}
			return false;
		case SS_SSEC:
			if (record->event.pressed) {
				SEND_STRING("\\subsection{");
			}
			return false;
		case SS_PARA:
			if (record->event.pressed) {
				SEND_STRING("\\paragraph{");
			}
			return false;
		case SS_SPAR:
			if (record->event.pressed) {
				SEND_STRING("\\subparagraph{");
			}
			return false;
		case SS_CHAS:
			if (record->event.pressed) {
				SEND_STRING("\\chapter*{");
			}
			return false;
		case SS_SECS:
			if (record->event.pressed) {
				SEND_STRING("\\section*{");
			}
			return false;
		case SS_SSTS:
			if (record->event.pressed) {
				SEND_STRING("\\subsection*{");
			}
			return false;
		case SS_PARS:
			if (record->event.pressed) {
				SEND_STRING("\\paragraph*{");
			}
			return false;
		case SS_SPRS:
			if (record->event.pressed) {
				SEND_STRING("\\subparagraph*{");
			}
			return false;
		case SS_TEN:
			if (record->event.pressed) {
				SEND_STRING("10");
			}
			return false;
		case SS_HUND:
			if (record->event.pressed) {
				SEND_STRING("100");
			}
			return false;
		case SS_THOU:
			if (record->event.pressed) {
				SEND_STRING("1000");
			}
			return false;
		case SS_MILL:
			if (record->event.pressed) {
				SEND_STRING("1 000 000");
			}
			return false;
		case SS_HUNDS:
			if (record->event.pressed) {
				SEND_STRING("00");
			}
			return false;
		case SS_THOUS:
			if (record->event.pressed) {
				SEND_STRING("000");
			}
			return false;
		case SS_MILLS:
			if (record->event.pressed) {
				SEND_STRING(" 000 000");
			}
			return false;
		case SS_SCNT:
			if (record->event.pressed) {
				SEND_STRING("*10^{");
			}
			return false;
		case A_QU:
			if (record->event.pressed) {
				SEND_STRING("qu");
			}
			return false;
		case A_AA:
			if (record->event.pressed) {
				SEND_STRING("aa");
			}
			return false;
		case A_ZZ:
			if (record->event.pressed) {
				SEND_STRING("zz");
			}
			return false;
		case A_WR:
			if (record->event.pressed) {
				SEND_STRING("wr");
			}
			return false;
		case A_FF:
			if (record->event.pressed) {
				SEND_STRING("ff");
			}
			return false;
		case A_SC:
			if (record->event.pressed) {
				SEND_STRING("sc");
			}
			return false;
		case ALT_CC:
			if (record->event.pressed) {
				SEND_STRING("cc");
			}
			return false;
		case A_PP:
			if (record->event.pressed) {
				SEND_STRING("pp");
			}
			return false;
		case A_DT:
			if (record->event.pressed) {
				SEND_STRING("dt");
			}
			return false;
		case A_DD:
			if (record->event.pressed) {
				SEND_STRING("dd");
			}
			return false;
		case A_BB:
			if (record->event.pressed) {
				SEND_STRING("bb");
			}
			return false;
		case A_GG:
			if (record->event.pressed) {
				SEND_STRING("gg");
			}
			return false;
		case A_BV:
			if (record->event.pressed) {
				SEND_STRING("bv");
			}
			return false;
		case A_MM:
			if (record->event.pressed) {
				SEND_STRING("mm");
			}
			return false;
		case A_KK:
			if (record->event.pressed) {
				SEND_STRING("kk");
			}
			return false;
		case A_LL:
			if (record->event.pressed) {
				SEND_STRING("ll");
			}
			return false;
		case A_HN:
			if (record->event.pressed) {
				SEND_STRING("hn");
			}
			return false;
		case A_HNL:
			if (record->event.pressed) {
				SEND_STRING("hnl");
			}
			return false;
		case A_UE:
			if (record->event.pressed) {
				SEND_STRING("ue");
			}
			return false;
		case A_EU:
			if (record->event.pressed) {
				SEND_STRING("eu");
			}
			return false;
		case A_YOU:
			if (record->event.pressed) {
				SEND_STRING("you");
			}
			return false;
		case A_IY:
			if (record->event.pressed) {
				SEND_STRING("iy");
			}
			return false;
		case A_OO:
			if (record->event.pressed) {
				SEND_STRING("oo");
			}
			return false;
    default:
      return true; // Process all other keycodes normally
  }
}

#if defined(ENCODER_ENABLE) && defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {

};
#endif // defined(ENCODER_ENABLE) && defined(ENCODER_MAP_ENABLE)

/* 
MANUALLY OPTIMIZED FOR SFBs/REDIRECTS
- œ ï - -   - ù è ü -
à é ß ë -   - ê ö ä û
- î ç - -   - æ ô â -
      _ _   _ _
UNOPTIMIZED DIACRITICS LAYER
	[_DCR] = LAYOUT(
			KC_ESC  , XP(O_C, O_CC) , XP(A_C, A_CC) 	, XP(U_C, U_CC) , XXXXXXX ,   XXXXXXX , XP(E_C, E_CC) , XP(E_G, E_GC) , XP(I_C, I_CC) , KC_BSPC ,
            KC_TAB  , XP(O_D, O_DC) , XP(A_D, A_DC) 	, XP(U_D, U_DC) , XXXXXXX ,   XXXXXXX , XP(SZ, SZ_C)  , XP(E_A, E_AC) , XP(A_G, A_GC) , KC_ENT ,
            TO(_NUM), XP(AE, AE_C)  , XP(CED, CED_C)	, XP(U_G, U_GC) , XXXXXXX ,   XXXXXXX , XP(OE, OE_C)  , XP(E_D, E_DC) , XP(I_D, I_DC) , TO(_NAV) ,
                                          	   		      TO(_BASE)		, KC_LSFT ,   A(KC_SPC) , TO(_BASE)
	),

UNOPTIMIZED SYMBOL LAYER
[_SYM] = LAYOUT(
            KC_ESC  , KC_AT   , KC_HASH , XP(EUR, DOL) 	, KC_PERC ,   KC_CIRC   , KC_AMPR    , KC_ASTR    , KC_SCLN, C(KC_BSPC) ,
            KC_TAB  , KC_EQL  , KC_GRV  , KC_QUOT	  	, KC_EXLM ,   KC_PIPE   , S(KC_LBRC) , S(KC_RBRC) , KC_BSLS , KC_ENT  ,
            TO(_NUM), KC_PLUS , KC_TILD , KC_DQUO   	, KC_QUES ,   KC_LBRC   , KC_LPRN    , KC_RPRN    , KC_RBRC , TO(_NAV),
                                          TO(_BASE) 	, KC_LSFT ,   A(KC_SPC) , TO(_BASE)
        ),
*/