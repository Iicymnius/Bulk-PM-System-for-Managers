//find;

		Set(HEADER_GC_DRAGON_SOUL_REFINE, CNetworkPacketHeaderMap::TPacketType(sizeof(TPacketGCDragonSoulRefine), STATIC_SIZE_PACKET));

//add below;

#ifdef ENABLE_PM_ALL_SEND_SYSTEM
		Set(HEADER_GC_BULK_WHISPER, CNetworkPacketHeaderMap::TPacketType(sizeof(TPacketGCBulkWhisper), DYNAMIC_SIZE_PACKET));
#endif