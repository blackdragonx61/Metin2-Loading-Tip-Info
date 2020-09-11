//Find
	if (!rkItemMgr.LoadItemList(szItemList))
	{
		TraceError("LoadLocaleData - LoadItemList(%s) Error", szItemList);
	}
	
///Add
#if defined(__LOADING_TIP__)
	char szTip[256];
	snprintf(szTip, sizeof(szTip), "%s/loading_tip_vnum.txt", localePath);
	if (!rkNetStream.LoadTipVnum(szTip)) {
		TraceError("LoadLocaleData - LoadTipVnum(%s) Error", szTip);
		return false;
	}
	snprintf(szTip, sizeof(szTip), "%s/loading_tip_list.txt", localePath);
	if (!rkNetStream.LoadTipList(szTip)) {
		TraceError("LoadLocaleData - LoadTipList(%s) Error", szTip);
		return false;
	}
#endif