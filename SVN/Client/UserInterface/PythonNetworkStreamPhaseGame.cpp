//find;

		case HEADER_GC_SPECIFIC_EFFECT:
			ret = RecvSpecificEffect();
			break;

//add below;

#ifdef ENABLE_PM_ALL_SEND_SYSTEM
		case HEADER_GC_BULK_WHISPER:
			ret = RecvBulkWhisperPacket();
			break;
#endif

//find again;

bool CPythonNetworkStream::SendChatPacket(const char* c_szChat, BYTE byType)

//add above;

#ifdef ENABLE_PM_ALL_SEND_SYSTEM
bool CPythonNetworkStream::SendBulkWhisperPacket(const char* c_szContent)
{
	if (strlen(c_szContent) == 0)
		return true;

	if (strlen(c_szContent) >= 512)
		return true;

	int iTextLen = strlen(c_szContent) + 1;
	TPacketCGBulkWhisper WhisperPacket;
	WhisperPacket.header = HEADER_CG_BULK_WHISPER;
	strncpy(WhisperPacket.szText, c_szContent, sizeof(WhisperPacket.szText) - 1);

	if (!Send(sizeof(WhisperPacket), &WhisperPacket))
		return false;

	return true;
}
#endif

//find again;

bool CPythonNetworkStream::RecvChatPacket()

//add above;

#ifdef ENABLE_PM_ALL_SEND_SYSTEM
bool CPythonNetworkStream::RecvBulkWhisperPacket()
{
	TPacketGCBulkWhisper kWhisper;
	char buf[1024 + 1];
	char line[1024 + 1];

	if (!Recv(sizeof(kWhisper), &kWhisper))
		return false;

	UINT uWhisperSize = kWhisper.size - sizeof(kWhisper);

	if (!Recv(uWhisperSize, buf))
		return false;

	buf[uWhisperSize] = '\0';

	TraceError("CPythonNetworkStream::RecvBulkWhisperPacket - %s", buf);

	PyCallClassMemberFunc(m_apoPhaseWnd[PHASE_WINDOW_GAME], "BINARY_OnRecvBulkWhisper", Py_BuildValue("(s)", buf));
	return true;
}
#endif