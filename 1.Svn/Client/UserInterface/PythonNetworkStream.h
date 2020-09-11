///Add
#if defined(__LOADING_TIP__)
#include <unordered_map>
#endif

//Find
		void __DirectEnterMode_Initialize();
		
///Add
#if defined(__LOADING_TIP__)
		std::unordered_map<int, std::string> m_TipVnum; // vnum id, string
		std::vector<std::pair<std::vector<long>, std::vector<int>>> m_TipList; // map index, vnum id
#endif

//Find
		DWORD EXPORT_GetBettingGuildWarValue(const char* c_szValueName);
		
///Add
#if defined(__LOADING_TIP__)
		bool LoadTipVnum(const char* FileName);
		bool LoadTipList(const char* FileName);
		const decltype(m_TipVnum)& GetTipMap() const { return m_TipVnum; };
		const decltype(m_TipList)& GetTipList() const { return m_TipList; };
#endif