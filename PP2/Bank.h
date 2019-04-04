#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

#include "BankClient.h"

class CBank
{
public:
	CBank();
	CBankClient* CreateClient();
	void UpdateClientBalance(CBankClient& client, int value);
	std::vector<CBankClient> GetAllBankClients();
	unsigned GetTotalBalance();
	unsigned GetClientBalance(int clientId);
	void SetClientBalance(int clientId, int value);

private:
	std::vector<CBankClient> m_clients;
	unsigned m_totalBalance;
	std::map<unsigned, unsigned> m_clientBalance;

	void SetTotalBalance(unsigned value);
	void SomeLongOperations();
};
