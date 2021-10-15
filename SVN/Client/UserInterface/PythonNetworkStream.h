//find;

	bool SendChatPacket(const char* c_szChat, BYTE byType = CHAT_TYPE_TALKING);

//add below;

#ifdef ENABLE_PM_ALL_SEND_SYSTEM
	bool SendBulkWhisperPacket(const char* c_szContent);
#endif

//find again;

	bool RecvChatPacket();

//add below;

#ifdef ENABLE_PM_ALL_SEND_SYSTEM
	bool RecvBulkWhisperPacket();
#endif