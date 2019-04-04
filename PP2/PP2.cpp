#include "stdafx.h"
#include "Bank.h"
#include "BankClient.h"

int main(int argc, char *argv[])
{
	int clientsNumber = (argc == 3) ? atoi(argv[1]) : 2;
	int primitive = (argc == 3) ? atoi(argv[2]) : 0;

	CBank* bank = new CBank(primitive);
	for (int i = 0; i < clientsNumber; i++) 
	{
		CBankClient* client = bank->CreateClient();
	}

	// TODO: WaitForMultipleObjects
	std::string input = "";
	std::cin >> input;
	bool exit = (input == "");

	while (std::cin && !exit)
	{
		std::cin >> input;
		exit = ((input == "quit") || (input == "exit"));
	}

	auto allClients = bank->GetAllBankClients();

	std::cout << "CLIENTS INFO" << std::endl;
	int amountBalance = 0;
	for (auto client : allClients) 
	{
		auto balance = bank->GetClientBalance(client.GetId());
		std::cout << "Id: " << client.GetId() << " Balance: " << balance << std::endl;
		amountBalance += balance;
	}


	std::cout << "Amount of clients balances: " << amountBalance << std::endl;
	std::cout << "Bank balance: " << bank->GetTotalBalance() << std::endl;

    return 0;
}
