#include "../includes/Tool.hpp"

Tool::Tool(): _worker(NULL), _numberOfUses(0)	{
	std::cout << "Tool constructer called" << std::endl;
}

Tool::~Tool()	{
	std::cout << "Tool destructer called" << std::endl;
}

void	Tool::assignWorker(Worker *worker)	{
	if (_worker)	{
		_worker->removeTool(this);
	}

	_worker = worker;
}

void	Tool::removeWorker()	{
	_worker = NULL;
}

int	Tool::getNumberOfUses() const	{
	return (_numberOfUses);
}

int	Tool::operator++(int)	{
	_numberOfUses += 1;
	return this->_numberOfUses;
}

int	Tool::operator++()	{
	_numberOfUses += 1;
	return this->_numberOfUses;
}
