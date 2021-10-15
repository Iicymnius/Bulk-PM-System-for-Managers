//find;

protected:
	virtual int	Analyze(LPDESC d, BYTE bHeader, const char* c_pData) = 0;

//add above;

#ifdef ENABLE_PM_ALL_SEND_SYSTEM
	void SendBulkWhisper(const char* c_pszText);
#endif

//find again;

	void		Refine(LPCHARACTER ch, const char* c_pData);

//add below;

#ifdef ENABLE_PM_ALL_SEND_SYSTEM
	void		BulkWhisperManager(LPCHARACTER ch, const char* c_pData);
#endif

//find again;

	int			Relay(LPDESC d, const char* c_pData, size_t uiBytes);

//add below;

#ifdef ENABLE_PM_ALL_SEND_SYSTEM
	int			BulkWhisperSend(LPDESC d, const char* c_pData, size_t uiBytes);
#endif