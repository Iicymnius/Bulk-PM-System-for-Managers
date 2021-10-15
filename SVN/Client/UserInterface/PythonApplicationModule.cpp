//find;

#ifdef ENABLE_COSTUME_SYSTEM
	PyModule_AddIntConstant(poModule, "ENABLE_COSTUME_SYSTEM", 1);
#else
	PyModule_AddIntConstant(poModule, "ENABLE_COSTUME_SYSTEM", 0);
#endif

//add below;

#ifdef ENABLE_PM_ALL_SEND_SYSTEM
	PyModule_AddIntConstant(poModule, "ENABLE_PM_ALL_SEND_SYSTEM", 1);
#else
	PyModule_AddIntConstant(poModule, "ENABLE_PM_ALL_SEND_SYSTEM", 0);
#endif