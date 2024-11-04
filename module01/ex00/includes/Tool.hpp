#ifndef TOOL_HPP
# define TOOL_HPP

# include <iostream>
# include "Worker.hpp"

class Tool	{

	Worker*	_worker;
	int		_numberOfUses;

	public:

		Tool();
		~Tool();
		
		virtual void	use() = 0;

		void	assignWorker(Worker *worker);
		void	removeWorker();

		int	getNumberOfUses() const;

		int	operator++(int);
		int	operator++();


};

#endif