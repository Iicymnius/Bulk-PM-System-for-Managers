//find;

int CInputP2P::Notice(LPDESC d, const char* c_pData, size_t uiBytes)

//add above;

#ifdef ENABLE_PM_ALL_SEND_SYSTEM
int CInputP2P::BulkWhisperSend(LPDESC d, const char* c_pData, size_t uiBytes)
{
	TPacketGGBulkWhisper* p = (TPacketGGBulkWhisper*)c_pData;

	if (uiBytes < sizeof(TPacketGGBulkWhisper) + p->lSize)
		return -1;

	if (p->lSize < 0)
	{
		sys_err("invalid packet length %d", p->lSize);
		d->SetPhase(PHASE_CLOSE);
		return -1;
	}

	char szBuf[CHAT_MAX_LEN + 1];
	strlcpy(szBuf, c_pData + sizeof(TPacketGGBulkWhisper), MIN(p->lSize + 1, sizeof(szBuf)));
	SendBulkWhisper(szBuf);

	return (p->lSize);
}
#endif

//find again;

	case HEADER_GG_CHECK_AWAKENESS:
		IamAwake(d, c_pData);
		break;

//add below;

#ifdef ENABLE_PM_ALL_SEND_SYSTEM
	case HEADER_GG_BULK_WHISPER:
		if ((iExtraLen = BulkWhisperSend(d, c_pData, m_iBufferLeft)) < 0)
			return -1;
		break;
#endif