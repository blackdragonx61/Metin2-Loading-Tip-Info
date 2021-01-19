//Find in void CClientManager::RESULT_LOGIN_BY_KEY(CPeer * peer, SQLMsg * msg)
			"SELECT id, name, job, level, playtime, st, ht, dx, iq, part_main, part_hair, x, y, skill_group, change_name FROM player%s WHERE account_id=%u",
			
///Change
#if defined(__LOADING_TIP__)
			"SELECT id, name, job, level, playtime, st, ht, dx, iq, part_main, part_hair, x, y, skill_group, change_name, map_index FROM player%s WHERE account_id=%u",
#else
			"SELECT id, name, job, level, playtime, st, ht, dx, iq, part_main, part_hair, x, y, skill_group, change_name FROM player%s WHERE account_id=%u",
#endif

//Find in void CreateAccountPlayerDataFromRes(MYSQL_RES * pRes, TAccountTable * pkTab)
					pkTab->players[j].skill_group		= pt->skill_group;
					
///Add
#if defined(__LOADING_TIP__)
					pkTab->players[j].lMapIndex =	pt->lMapIndex;
#endif

//Find
					str_to_number(pkTab->players[j].bChangeName, row[col++]);
					
///Add
#if defined(__LOADING_TIP__)
					str_to_number(pkTab->players[j].lMapIndex, row[col++]);
#endif

//Find in void CClientManager::RESULT_LOGIN(CPeer * peer, SQLMsg * msg)
					"SELECT id, name, job, level, playtime, st, ht, dx, iq, part_main, part_hair, x, y, skill_group, change_name FROM player%s WHERE account_id=%u",
					
///Change
#if defined(__LOADING_TIP__)
					"SELECT id, name, job, level, playtime, st, ht, dx, iq, part_main, part_hair, x, y, skill_group, change_name, map_index FROM player%s WHERE account_id=%u",
#else
					"SELECT id, name, job, level, playtime, st, ht, dx, iq, part_main, part_hair, x, y, skill_group, change_name FROM player%s WHERE account_id=%u",
#endif