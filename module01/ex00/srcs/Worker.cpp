#include "../includes/Worker.hpp"

Worker::Worker()	{
	std::cout << "Worker constructer called" << std::endl;
}

Worker::~Worker()	{
	std::cout << "Worker destructer called" << std::endl;
}

Position	Worker::getPosition() const {
	return (_coordonnee);
}

Statistic	Worker::getStats() const {
	return (_stat);
}

std::set<Tool*>	Worker::getTools() const {
	return (_tools);
}

Position	Worker::changePosition(int x, int y)	{
	_coordonnee.x = x;
	_coordonnee.y = y;
}

Position	Worker::changePosition(int x, int y, int z)	{
	_coordonnee.x = x;
	_coordonnee.y = y;
	_coordonnee.z = z;
}

Statistic	Worker::addXP(int xp)	{
	_stat.xp += xp;
}

Statistic	Worker::removeXP(int xp)	{
	_stat.xp -= xp;
}

Statistic	Worker::changeXP(int xp)	{
	_stat.xp = xp;
}

Statistic	Worker::addLevels(int level)	{
	_stat.level += level;
}

Statistic	Worker::removeLevels(int level)	{
	_stat.level -= level;
}

Statistic	Worker::changeLevels(int level)	{
	_stat.level = level;
}

void	Worker::assignTool(Tool* tool)	{
	if (_tools.find(tool) != _tools.end())	{
		_tools.insert(tool);
		tool->assignWorker(this);
	}
}

void	Worker::removeTool(Tool* tool)	{
	if (_tools.find(tool) == _tools.end())	{
		return ;
	}
	tool->removeWorker();
	_tools.erase(tool);
}
