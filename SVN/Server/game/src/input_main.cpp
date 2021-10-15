//find;

void CInputMain::Refine(LPCHARACTER ch, const char* c_pData)

//add above;

#ifdef ENABLE_PM_ALL_SEND_SYSTEM
void CInputMain::BulkWhisperManager(LPCHARACTER ch, const char* c_pData)
{
	TPacketCGBulkWhisper* f = (TPacketCGBulkWhisper*)c_pData;

	if (!ch)
		return;

	if (ch->GetGMLevel() != GM_IMPLEMENTOR)
	{
		ch->ChatPacket(CHAT_TYPE_INFO, "[SYSTEM] GM degilsin.");
		return;
	}

	TPacketGGBulkWhisper p;
	p.bHeader = HEADER_GG_BULK_WHISPER;
	p.lSize = strlen(f->szText) + 1;

	TEMP_BUFFER tmpbuf;
	tmpbuf.write(&p, sizeof(p));
	tmpbuf.write(f->szText, p.lSize);

	char szEscaped[CHAT_MAX_LEN * 2 + 1];
	DBManager::instance().EscapeString(szEscaped, sizeof(szEscaped), f->szText, strlen(f->szText));
	SendBulkWhisper(f->szText);
	P2P_MANAGER::instance().Send(tmpbuf.read_peek(), tmpbuf.size());
}
#endif

//find again;

	case HEADER_CG_CLIENT_VERSION:
		Version(ch, c_pData);
		break;

//add below;

#ifdef ENABLE_PM_ALL_SEND_SYSTEM
	case HEADER_CG_BULK_WHISPER:
		BulkWhisperManager(ch, c_pData);
		break;
#endif