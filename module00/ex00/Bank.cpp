#include "Bank.hpp"

/*	Bank	*/

Bank::Bank():	_lastId(-1), _liquidity(0)	{}
Bank::Bank(int liquidity):	_lastId(-1), _liquidity(liquidity)	{}
Bank::~Bank()	{}

int	Bank::createAccount()	{
	Account	newAccount(++_lastId);
	_clientAccounts[newAccount._id] = newAccount;
	return newAccount._id;
}

int	Bank::createAccount(int value)	{
	Account	newAccount(++_lastId, value);
	_clientAccounts[newAccount._id] = newAccount;
	return newAccount._id;
}

void	Bank::deleteAccount(int accountId)	{
	_clientAccounts.erase(accountId);
}

int	Bank::addMoney(int accountId, int value)	{
	std::map<int, Account>::iterator it = _clientAccounts.find(accountId);
	int	tax = value * 0.05;
	
	if (it != _clientAccounts.end())	{
		value -= tax;
		_liquidity += tax;
		it->second._value += value;
		return it->second._value;
	}
	return -1;
}

int	Bank::removeMoney(int accountId, int value)	{
	std::map<int, Account>::iterator it = _clientAccounts.find(accountId);
	
	if (it != _clientAccounts.end())	{
		it->second._value -= value;
		return it->second._value;
	}
	return -1;
}

int	Bank::giveLoan(int accountId, int value)	{
	std::map<int, Account>::iterator it = _clientAccounts.find(accountId);
	
	if (value > _liquidity)	{
		throw NotEnoughFunds();
	}
	if (it != _clientAccounts.end())	{
		_liquidity -= value;
		it->second._value += value;
		return it->second._value;
	}

	return -1;
}
