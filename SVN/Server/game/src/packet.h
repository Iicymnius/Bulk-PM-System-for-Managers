//find;

	HEADER_CG_ITEM_GIVE = 83,

//add below;

#ifdef ENABLE_PM_ALL_SEND_SYSTEM
	HEADER_CG_BULK_WHISPER = 84,//You may need to change the number 84 here.
#endif

//find again;

		HEADER_GC_MAIN_CHARACTER4_BGM_VOL = 138,

//add below;

#ifdef ENABLE_PM_ALL_SEND_SYSTEM
		HEADER_GC_BULK_WHISPER = 139,//You may need to change the number 139 here.
#endif

//find again;

		HEADER_GG_CHECK_AWAKENESS = 29,

//add below;

#ifdef ENABLE_PM_ALL_SEND_SYSTEM
		HEADER_GG_BULK_WHISPER = 30,//You may need to change the number 30 here.
#endif

//find again;

#pragma pack()
#endif

//add above;

#ifdef ENABLE_PM_ALL_SEND_SYSTEM
typedef struct SPacketCGBulkWhisper
{
	BYTE	header;
	char	szText[512 + 1];
} TPacketCGBulkWhisper;

typedef struct packet_bulk_whisper
{
	BYTE	header;
	WORD	size;
} TPacketGCBulkWhisper;

typedef struct SPacketGGBulkWhisper
{
	BYTE	bHeader;
	long	lSize;
} TPacketGGBulkWhisper;
#endif
