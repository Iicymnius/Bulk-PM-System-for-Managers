//find;

void LoginFailure(LPDESC d, const char* c_pszStatus)

//add above;

#ifdef ENABLE_PM_ALL_SEND_SYSTEM
struct SWhisperPacketFunc
{
	const char* c_pszText;

	SWhisperPacketFunc(const char* text) :
		c_pszText(text)
	{
	}

	void operator () (LPDESC d)
	{
		if (!d || !d->GetCharacter())
			return;

		struct packet_bulk_whisper bulk_whisper_pack;
		bulk_whisper_pack.header = HEADER_GC_BULK_WHISPER;
		bulk_whisper_pack.size = sizeof(struct packet_bulk_whisper) + strlen(c_pszText);

		TEMP_BUFFER buf;
		buf.write(&bulk_whisper_pack, sizeof(struct packet_bulk_whisper));
		buf.write(c_pszText, strlen(c_pszText));

		d->Packet(buf.read_peek(), buf.size());
	}
};

void CInputProcessor::SendBulkWhisper(const char* c_pszText)
{
	const DESC_MANAGER::DESC_SET& f = DESC_MANAGER::instance().GetClientSet();
	std::for_each(f.begin(), f.end(), SWhisperPacketFunc(c_pszText));
}
#endif