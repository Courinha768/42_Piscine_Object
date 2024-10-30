#include <iostream>
#include <map>

struct Bank	{

	private:

		struct Account {
			int			_id;
			int			_value;

			Account():	_id(-1),	_value(0)	{};
			Account(int id): _id(id), _value(0) {}
			Account(int id, int value): _id(id), _value(value) {}
			~Account() {};
		};


		std::map<int, Account>	_clientAccounts;
		int						_lastId;
		int						_liquidity;


	public:

		Bank();
		Bank(int liquidity);
		~Bank();

		int	createAccount();
		int	createAccount(int value);

		void	deleteAccount(int accountId);

		int	addMoney(int accountId, int value);
		int	removeMoney(int accountId, int value);
		int	giveLoan(int accountId, int value);

		class NotEnoughFunds: public std::exception
		{
			public:
				virtual const char* what() const throw()	{
					return ("The bank doens't have anough funds to perform this action");};
		};

		friend std::ostream& operator << (std::ostream& os, const Bank& bank)	{

			os << "Bank informations : " << std::endl;
			os << "Liquidity : " << bank._liquidity << std::endl;

			std::map<int, Account>::const_iterator it = bank._clientAccounts.begin();
			while (it != bank._clientAccounts.end())	{
				os << "[" << it->first << "] - [" << it->second._value << "]" << std::endl;
				it++;
			}
			return (os);

		}
};


