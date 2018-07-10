
//{{BLOCK(Logo)

//======================================================================
//
//	Logo, 240x24@2, 
//	+ 63 tiles (t|f reduced) not compressed
//	+ regular map (flat), not compressed, 30x3 
//	Total size: 1008 + 180 = 1188
//
//	Exported by Cearn's GBA Image Transmogrifier, v0.8.6
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

const unsigned int LogoTiles[252] __attribute__((aligned(4)))=
{
	0x00000000,0x00000000,0x00000000,0x00000000,0x0FF00000,0xFFF03FF0,0xFFF0FFF0,0xFFF0FFF0,
	0xFF000000,0xFFF0FFC0,0xFFFFFFFF,0xFFFFFFFF,0x0FF00000,0x0FF00FF0,0x0FF00FF0,0x0FF00FF0,
	0xFF000000,0xFF00FF00,0xFF00FF00,0xFF00FF00,0xFFFF0000,0xFF00FFFF,0xFF2AFF00,0xFF00FF2A,
	0xF0FF0000,0x0000F0FF,0xA0A80000,0x0000A0A8,0xFFFF0000,0x0FF0FFFF,0x8FF20FF0,0x0FF08FF2,
	0x000F0000,0x0000000F,0x000A0000,0x0000000A,0xFF000000,0x0FF0FFC0,0xA8FF03FC,0x08FFA8FF,
	0x00FF0000,0x0FF003FF,0x002A0FC0,0x0AA002AA,0xFFF00000,0x00FFFFFC,0xA8FF00FF,0x00FFA8FF,
	0x00FF0000,0x0FF003FF,0x0FF20FF0,0x0FF00FF2,0x00000000,0xF000C000,0xF000F000,0xF000F000,
	0xFFFF0000,0x000FFFFF,0x2A8F000F,0x000F2A8F,0xF00F0000,0xF0FFF03F,0xF0FFF0FF,0xF0FFF0FF,

	0xFFFF0000,0xC00FFFFF,0x2A8F000F,0xC00F2A8F,0x000F0000,0x00FF003F,0x00FF00FF,0x00FF00FF,
	0xFFF00000,0x0FF0FFF0,0x8FF00FF0,0x0FF08FF0,0xFFF00000,0x0FF0FFF0,0x8FF00FF0,0xFFF00FF0,
	0x0FFF0000,0x00000FFF,0x0AAA0000,0x00FF0A00,0xCFF0FFF0,0x8FF00FF0,0x8FF08FF0,0x40004FF0,
	0xFF3FFFFF,0xFF20FF0F,0xFF2AFF2A,0x0015FF1A,0x0FF00FF0,0x0FF00FF0,0xFFC00FF0,0x00A0FF20,
	0xFF00FF00,0xFF00FF00,0x3FFFFF00,0xA0008FFF,0x0FF00FF0,0x0FF00FF0,0xFFF00FF0,0x0000FFF0,
	0x00000000,0x00000000,0x0FFF0000,0x00000FFF,0xFF15FF00,0xFF00FF15,0xFF00FF00,0x0000FF00,
	0x50540000,0x00005054,0xF0000000,0x0000F000,0x4FF10FF0,0x0FF04FF1,0xFFFF0FF0,0x0000FFFF,
	0x00050000,0x00000005,0x000F0000,0x0000000F,0x54FF00FF,0x03FC54FF,0xFFCA0FF2,0x00A9FF2A,

	0x00550A80,0x0FC00015,0x03FF0FF0,0x0A0000FF,0x54FF00FF,0x00FF54FF,0xFFFC00FF,0x000AFFF2,
	0x0FF10FF0,0x0FF00FF1,0x03FF0FF0,0x0A0008FF,0x00FF00FF,0x00FF00FF,0xFFFF00FF,0x0000FFFF,
	0xF000F000,0xF000F000,0xC0FFF000,0xA00020FF,0x154F000F,0x000F154F,0xFFFF000F,0x0000FFFF,
	0xF0FFF0FF,0xF0FFF0FF,0xF03FF0FF,0x00A0F08F,0xFFFFF00F,0xFF0FFFFF,0xF28FFC0F,0x2A00CA8F,
	0x008F003F,0x008F00A3,0x00FF003F,0x000000FF,0x4FF00FF0,0x0FF04FF0,0xFFF00FF0,0x0000FFF0,
	0x0FF0FFF0,0x8FF04FF0,0xFFF00FF0,0x0000FFF0,0x050000FF,0x00AA0555,0x0FFF0000,0x00000FFF,
	0x4AA05AA0,0x05500AA0,0x05500550,0x00000550,0xAA15AA55,0x5500AA05,0x55005500,0x00005500,
	0xAA900AA0,0x0550AA50,0x55400550,0x00005500,0x6AAAAA00,0x55005AAA,0x15555500,0x00000555,

	0xAAA00AA0,0x0550AAA0,0x55500550,0x00005550,0x0AAA0000,0x00000AAA,0x05550000,0x00000555,
	0xAA00AA00,0x5500AA00,0x55005500,0x00005500,0xA0000000,0x0000A000,0x50000000,0x00005000,
	0xAAAA0AA0,0x0550AAAA,0x55550550,0x00005555,0xAA950AA5,0x0154AA55,0x55400550,0x00005500,
	0x02AA0AA0,0x054000AA,0x01550550,0x00000055,0xAAAA00AA,0x0055AAAA,0x55550055,0x00005555,
	0x90AAA000,0x500050AA,0x40555000,0x00000055,0xAAAA000A,0x0005AAAA,0x55550005,0x00005555,
	0xA06AA0AA,0x5055A05A,0x50155055,0x00005005,0xA55AA80A,0x5505955A,0x50055405,0x00004005,
	0x00AA002A,0x000500AA,0x00550015,0x00000055,0xAAA05AA0,0x0550AAA0,0x55500550,0x00005550,
	0x0AAA0055,0x00000AAA,0x05550000,0x00000555,
};

const unsigned short LogoMap[90] __attribute__((aligned(4)))=
{
	0x0001,0x0002,0x0003,0x0004,0x0003,0x0000,0x0005,0x0006,
	0x0007,0x0008,0x0000,0x0009,0x000A,0x000B,0x000C,0x2004,
	0x000D,0x000E,0x000F,0x0010,0x0011,0x0000,0x0012,0x2009,
	0x0013,0x0014,0x2002,0x2001,0x000B,0x000C,0x0015,0x0016,
	0x0017,0x0018,0x0019,0x001A,0x001B,0x001C,0x001D,0x001E,
	0x0000,0x001F,0x0020,0x0021,0x0022,0x0023,0x0024,0x0025,
	0x0026,0x0027,0x0028,0x0000,0x0029,0x201F,0x002A,0x002B,
	0x2016,0x2015,0x0021,0x0022,0x002C,0x002D,0x002E,0x002F,

	0x0030,0x0031,0x0032,0x0033,0x0034,0x2033,0x0000,0x0035,
	0x0036,0x202F,0x202E,0x0037,0x0038,0x0039,0x003A,0x003B,
	0x003C,0x0000,0x0030,0x2035,0x003D,0x003E,0x202D,0x202C,
	0x202F,0x202E,
};

//}}BLOCK(Logo)
