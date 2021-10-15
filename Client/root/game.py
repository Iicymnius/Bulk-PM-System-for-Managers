#add;

if app.ENABLE_PM_ALL_SEND_SYSTEM:
	import uiWhisperAdmin

#find;

		self.__SetQuickSlotMode()
		self.__ServerCommand_Build()

#add above;

		if app.ENABLE_PM_ALL_SEND_SYSTEM:
			self.whisperAdmin = uiWhisperAdmin.AdminWhisperManager()
			self.whisperAdmin.Close()

#find again;

		player.ClearSkillDict()

#add above;

		if app.ENABLE_PM_ALL_SEND_SYSTEM:
			if self.whisperAdmin:
				self.whisperAdmin.Close()
				self.whisperAdmin.Destroy()
				self.whisperAdmin = None

#find again;

		onPressKeyDict[app.DIK_F4]	= lambda : self.__PressQuickSlot(7)

#add below;

		if app.ENABLE_PM_ALL_SEND_SYSTEM:
			onPressKeyDict[app.DIK_F5]	= lambda : self.whisperAdmin.OpenWindow()

#find again;

	def OnShopError(self, type):

#add above;

	if app.ENABLE_PM_ALL_SEND_SYSTEM:
		def BINARY_OnRecvBulkWhisper(self, content):
			content = content.replace("$", " ")

			self.interface.RegisterGameMasterName("[SYSTEM]")
			chat.AppendWhisper(chat.WHISPER_TYPE_CHAT, "[SYSTEM]", content)

			self.interface.RecvWhisper("[SYSTEM]")

#find again;

			# PRIVATE_SHOP_PRICE_LIST
			"MyShopPriceList"		: self.__PrivateShop_PriceList,
			# END_OF_PRIVATE_SHOP_PRICE_LIST
		}

#add below;

		if app.ENABLE_PM_ALL_SEND_SYSTEM:
			serverCommandList["OpenBulkWhisperPanel"] = self.whisperAdmin.OpenWindow