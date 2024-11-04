#ifndef WORKER_HPP
# define WORKER_HPP

# include <iostream>
# include <set>

# include "Statistic.hpp"
# include "Position.hpp"
# include "Shovel.hpp"
# include "Tool.hpp"

class Worker	{

	Position		_coordonnee;
	Statistic		_stat;
	std::set<Tool*>	_tools;
	

	public:
		Worker();
		~Worker();

		Position		getPosition() const;
		Statistic		getStats() const;
		std::set<Tool*>	getTools() const;

		Position	changePosition(int x, int y);
		Position	changePosition(int x, int y, int z);

		Statistic	addXP(int xp);
		Statistic	removeXP(int xp);
		Statistic	changeXP(int xp);

		Statistic	addLevels(int level);
		Statistic	removeLevels(int level);
		Statistic	changeLevels(int level);

		void		assignTool(Tool* tool);
		void		removeTool(Tool* tool);

};

#endif