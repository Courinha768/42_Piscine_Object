#include "Bank.hpp"

#define RESET "\e[0m"
#define BIBLUE "\e[0;104m"
#define BIBLACK "\e[1;90m"
#define GREEN "\e[0;32m"

int	main(void)	{



	std::cout << BIBLUE << "#1: Creating multiple accounts:                " << RESET << std::endl << std::endl;
	{
		Bank bank;

		std::cout << GREEN << "Creating an account:" << RESET << std::endl;
		bank.createAccount();
		std::cout << bank << std::endl;

		std::cout << GREEN << "Creating 2 more accounts:" << RESET << std::endl;
		bank.createAccount();
		bank.createAccount();
		std::cout << bank << std::endl;

	}
	std::cout << BIBLUE << "#2: Creating and deleting an account:          " << RESET << std::endl << std::endl;
	{
		Bank bank;

		std::cout << GREEN << "Creating an account:" << RESET << std::endl;
		int	accountId = bank.createAccount();
		std::cout << bank << std::endl;

		std::cout << GREEN << "Deleting an account:" << RESET << std::endl;
		bank.deleteAccount(accountId);
		std::cout << bank << std::endl;

	}
	std::cout << BIBLUE << "#3: Adding and removing money from an account: " << RESET << std::endl << std::endl;
	{
		Bank bank;

		std::cout << GREEN << "Creating an account with 500$:" << RESET << std::endl;
		int	accountId = bank.createAccount(500);
		std::cout << bank << std::endl;

		std::cout << GREEN << "Adding 200$:" << RESET << std::endl;
		bank.addMoney(accountId, 200);
		std::cout << bank << std::endl;

		std::cout << GREEN << "Removing 300$:" << RESET << std::endl;
		bank.removeMoney(accountId, 300);
		std::cout << bank << std::endl;

	}
	std::cout << BIBLUE << "#4: Giving Loans:                              " << RESET << std::endl << std::endl;
	{
		Bank bank(1000);
		int	accountId = bank.createAccount();
		std::cout << bank << std::endl;
		
		std::cout << GREEN << "Giving a 500$ loan:" << RESET << std::endl;
		bank.giveLoan(accountId, 500);
		std::cout << bank << std::endl;

	}
}