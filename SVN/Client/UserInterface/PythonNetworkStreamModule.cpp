//find;

void initnet()

//add above;

#ifdef ENABLE_PM_ALL_SEND_SYSTEM
PyObject* netSendBulkWhisperPacket(PyObject* poSelf, PyObject* poArgs)
{
	char* szContent;
	if (!PyTuple_GetString(poArgs, 0, &szContent))
		return Py_BuildException();

	CPythonNetworkStream& rkNetStream = CPythonNetworkStream::Instance();
	rkNetStream.SendBulkWhisperPacket(szContent);

	return Py_BuildNone();
}
#endif

//find again;

		{ "RegisterErrorLog",						netRegisterErrorLog,						METH_VARARGS },

//add below;

#ifdef ENABLE_PM_ALL_SEND_SYSTEM
		{ "SendBulkWhisperPacket",					netSendBulkWhisperPacket,					METH_VARARGS },
#endif