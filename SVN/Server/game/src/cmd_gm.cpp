//find;

ACMD(do_clear_affect)
{
	ch->ClearAffect(true);
}

//add below;

#ifdef ENABLE_PM_ALL_SEND_SYSTEM
ACMD(do_pm_all_send)
{
	if (ch && ch->GetDesc() && ch->IsGM())
		ch->ChatPacket(CHAT_TYPE_COMMAND, "OpenBulkWhisperPanel");
}
#endif