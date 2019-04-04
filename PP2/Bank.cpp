#include "Bank.h"

CBank::CBank()
{
	m_clients = std::vector<CBankClient>();
	m_totalBalance = 0;
}


CBankClient* CBank::CreateClient()
{
	unsigned clientId = unsigned(m_clients.size());
	CBankClient* client = new CBankClient(this, clientId);
	m_clients.push_back(*client);
	return client;
}

std::vector<CBankClient> CBank::GetAllBankClients()
{
	return m_clients;
}

unsigned CBank::GetTotalBalance()
{
	return m_totalBalance;
}

unsigned CBank::GetClientBalance(int id) {
	return m_clientBalance.at(id);
}

void CBank::SetClientBalance(int id, int value) {
	auto it = m_clientBalance.find(id);
	if (it != m_clientBalance.end()) 
	{
		it->second += value;
	}
	else 
	{
		m_clientBalance.emplace(id, value);
	}
}

void CBank::UpdateClientBalance(CBankClient &client, int value)
{
	int totalBalance = GetTotalBalance();
	std::cout << "Client " << client.GetId() << " initiates reading total balance. Total = " << totalBalance << "." << std::endl;
	
	SomeLongOperations();
	totalBalance += value;
	SetClientBalance(client.GetId(), value);

	std::cout
		<< "Client " << client.GetId() << " updates his balance with " << value
		<< " and initiates setting total balance to " << totalBalance
		<< ". Must be: " << GetTotalBalance() + value << "." << std::endl;

	// Check correctness of transaction through actual total balance
	if (totalBalance != GetTotalBalance() + value) {
		std::cout << "! ERROR !" << std::endl;
	}

	SetTotalBalance(totalBalance);
}

void CBank::SetTotalBalance(unsigned value)
{
	m_totalBalance = value;
}

void CBank::SomeLongOperations()
{
	// TODO
}
