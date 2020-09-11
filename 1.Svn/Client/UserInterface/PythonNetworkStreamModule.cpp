///Add
#if defined(__LOADING_TIP__)
#include "PythonBackground.h"
PyObject* netGetTipInfo(PyObject* poSelf, PyObject* poArgs)
{
	const auto& TipMap = CPythonNetworkStream::Instance().GetTipMap();
	const auto& TipList = CPythonNetworkStream::Instance().GetTipList();

	if (!TipMap.empty() && !TipList.empty()) {
		auto it = std::find_if(TipList.begin(), TipList.end(), [](const std::pair<std::vector<long>, std::vector<int>>& Tlist)
		{
			const auto& MapVec = Tlist.first;
			return std::find(MapVec.begin(), MapVec.end(), CPythonBackground::Instance().GetWarpMapIndex()) != MapVec.end();
		});

		const auto& TipVnumVec = (it != TipList.end()) ? (*it).second : TipList.front().second;
		if (!TipVnumVec.empty()) {
			const auto& idx = TipVnumVec.at(random_range(0, TipVnumVec.size() - 1));
			if (TipMap.count(idx))
				return Py_BuildValue("s", TipMap.at(idx).c_str());
		}
	}

	return Py_BuildValue("s", "");
}
#endif

//Find
		{ "GetServerInfo",						netGetServerInfo,						METH_VARARGS },
		
///Add
#if defined(__LOADING_TIP__)
		{ "GetTipInfo",							netGetTipInfo,							METH_VARARGS },
#endif
