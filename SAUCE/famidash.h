
// game states
#define MENU 0x01
#define GAME 0x02

// uhh something i can get rid of later
#define MAX_UP 0x6000
#define MAX_DOWN 0x7000
#define MIN_SCROLL 1

// physics defines
#define PAD_HEIGHT_YELLOW -0x760

#define CUBE_WIDTH 0x0F
#define CUBE_HEIGHT 0x0F

#define CUBE_SPEED_X1 0x2C4
#define CUBE_MAX_FALLSPEED 0x600
#define CUBE_GRAVITY 0x6C
#define SHIP_MAX_FALLSPEED 0x300


#pragma bss-name(push, "ZEROPAGE")
// zero-page variables go here

unsigned char tmp1;
unsigned char tmp2;
unsigned char tmp3;
unsigned char tmp4;
unsigned short tmp5;
unsigned short tmp6;

unsigned char pad;
unsigned char pad_new;

unsigned char gamemode;
unsigned char cube_data;
signed short cube_rotate;

unsigned char coordinates;
unsigned char collision;
unsigned char collision_L;
unsigned char collision_R;
unsigned char collision_U;
unsigned char collision_D;
unsigned char coordinates;

unsigned short old_x;
unsigned short old_y;

unsigned char gravity;
unsigned char eject_L; // from the left
unsigned char eject_R; // remember these from the collision sub routine
unsigned char eject_D; // from below
unsigned char eject_U; // from up

unsigned short address;
unsigned char x; // room loader code
unsigned char y;
unsigned short index;
unsigned short index2;
unsigned char temp_x;
unsigned char temp_y;
unsigned char temp_room;

#pragma bss-name(pop)
// other variables go here

unsigned char collisionMap0[240];   // collision map, for a 16*27 tile area
unsigned char collisionMap1[192];
unsigned char columnBuffer[27];     // column buffer, to be pushed to the collision map

unsigned char rld_column;

unsigned char level;

unsigned char gameState;

unsigned short pseudo_scroll_x;
unsigned char scroll_x;
unsigned short scroll_y;
unsigned char scroll_count;

long unsigned int test;



const unsigned char * const active_level[] = {collisionMap0,collisionMap1};

struct player {
	unsigned short x; // low byte is sub-pixel
	unsigned short y;
	signed short vel_x; // speed, signed, low byte is sub-pixel
	signed short vel_y;
};

struct player player = {0x0000,0x01d000};

struct Base {
	unsigned char x;
	unsigned char y;
	unsigned char width;
	unsigned char height;
};

struct Base Generic;
struct Base Generic2;

const unsigned char paletteDefault[] = {
    0x11,0x0c,0x0f,0x30,	// palette 0, used for level tiles
	0x00,0x01,0x11,0x30,	// palette 1, used for ground
	0x00,0x28,0x14,0x30,	// palette 2, UNUSED
	0x00,0x0f,0x00,0x30 	// palette 3, used for text
};

const unsigned char paletteDefaultSP[]={
	0x00,0x0f,0x2a,0x21,
	0x00,0x0f,0x24,0x28,
	0x00,0x0f,0x0f,0x0f,
	0x00,0x14,0x24,0x34
};

