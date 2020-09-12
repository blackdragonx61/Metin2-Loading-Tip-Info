//Find
bool CPythonNetworkStream::IsInsultIn(const char* c_szMsg)
{
	return m_kInsultChecker.IsInsultIn(c_szMsg, strlen(c_szMsg));
}

///Add
#if defined(__LOADING_TIP__)
bool CPythonNetworkStream::LoadTipVnum(const char* FileName)
{
	const VOID* pvData;
	CMappedFile kFile;
	if (!CEterPackManager::Instance().Get(kFile, FileName, &pvData))
		return false;

	m_TipVnum.clear();
	CMemoryTextFileLoader kTextFileLoader;
	kTextFileLoader.Bind(kFile.Size(), pvData);
	CTokenVector kTokenVector;

	for (DWORD i = 0; i < kTextFileLoader.GetLineCount(); ++i)
		if (kTextFileLoader.SplitLineByTab(i, &kTokenVector))
			m_TipVnum.emplace(std::stoi(kTokenVector.at(0)), kTokenVector.at(1));
	return true;
}

bool CPythonNetworkStream::LoadTipList(const char* FileName)
{
	m_TipList.clear();

	CTextFileLoader* pkTextFileLoader = CTextFileLoader::Cache(FileName);
	
	if (!pkTextFileLoader)
		return false;

	if (pkTextFileLoader->IsEmpty())
		return false;

	pkTextFileLoader->SetTop();

	for (DWORD i = 0; i < pkTextFileLoader->GetChildNodeCount(); ++i) {
		
		CTextFileLoader::CGotoChild GotoChild(pkTextFileLoader, i);

		CTokenVector* tv;
		std::vector<long> mapindex;
		if (pkTextFileLoader->GetTokenVector("map_index", &tv))
			for (auto it = tv->begin(); it != tv->end(); ++it)
				mapindex.emplace_back(std::stol(*it));

		std::vector<int> tipindex;
		if (pkTextFileLoader->GetTokenVector("tip_vnum", &tv))
			for (auto it = tv->begin(); it != tv->end(); ++it)
				tipindex.emplace_back(std::stoi(*it));

		m_TipList.emplace_back(std::move(mapindex), std::move(tipindex));
	}

	return true;
}
#endif