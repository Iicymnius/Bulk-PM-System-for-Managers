//find;

ACMD(do_clear_affect);

//add below;

#ifdef ENABLE_PM_ALL_SEND_SYSTEM
ACMD(do_pm_all_send);
#endif

//find again;

			{ "do_clear_affect",		do_clear_affect,		0,			POS_DEAD,	GM_LOW_WIZARD},

//add below;

#ifdef ENABLE_PM_ALL_SEND_SYSTEM
			{ "pm_all_send",			do_pm_all_send,			0,			POS_DEAD,	GM_IMPLEMENTOR},
#endif
