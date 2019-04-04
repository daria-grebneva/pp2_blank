#include "stdafx.h"
#include "Bank.h"
#include "BankClient.h"

int main(int argc, char *argv[])
{
	CBank* bank = new CBank();

	int clientsNumber = (argc == 2) ? atoi(argv[1]) : 2;

	for (int i = 0; i < clientsNumber; i++) {
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

    return 0;
}
