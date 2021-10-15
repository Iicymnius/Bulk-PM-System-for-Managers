//find;

	Set(HEADER_CG_STATE_CHECKER, sizeof(BYTE), "ServerStateCheck", false);

//add below;

#ifdef ENABLE_PM_ALL_SEND_SYSTEM
	Set(HEADER_CG_BULK_WHISPER, sizeof(TPacketCGBulkWhisper), "TPacketCGBulkWhisper", false);
#endif

//find again;

	Set(HEADER_GG_CHECK_AWAKENESS, sizeof(TPacketGGCheckAwakeness), "CheckAwakeness", false);

//add below;

#ifdef ENABLE_PM_ALL_SEND_SYSTEM
	Set(HEADER_GG_BULK_WHISPER, sizeof(TPacketGGBulkWhisper), "TPacketGGBulkWhisper", false);
#endif