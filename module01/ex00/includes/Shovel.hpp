#ifndef SHOVEL_HPP
# define SHOVEL_HPP

# include <iostream>
# include "Tool.hpp"

class Shovel: public Tool{

	public:

		Shovel();
		~Shovel();

		void use();

};

#endif