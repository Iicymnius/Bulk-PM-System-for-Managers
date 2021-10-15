#add;

if app.ENABLE_PM_ALL_SEND_SYSTEM:
	import uiWhisperAdmin

#find;

		if net.IsChatInsultIn(text):

#add above;

		if app.ENABLE_PM_ALL_SEND_SYSTEM:
			if str(text) == "/pm_all_send":
				self.whisperadmin = uiWhisperAdmin.AdminWhisperManager()
				self.whisperadmin.OpenWindow()
				return