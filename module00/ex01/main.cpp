#include "includes/Graph.hpp"

#define RESET "\e[0m"
#define BIBLUE "\e[0;104m"
#define BIBLACK "\e[1;90m"
#define GREEN "\e[0;32m"
#define RED "\e[0;31m"
#define BIGREEN "\e[0;102m"

int	main(void)	{

	std::cout << BIBLUE << "#1: Adding positive points                            " << RESET << std::endl << std::endl;
	{
		Graph graph;

		graph.add(1, 1);
		graph.add(3, 2);
		graph.add(2, 5);

		std::cout << GREEN << "Points added:" << RESET << std::endl;
		std::cout << "(1, 1)\n(3, 2)\n(2, 5)" << std::endl;

		std::cout << GREEN << "\nGraph:" << RESET << std::endl;
		std::cout << graph << std::endl;
	}
	std::cout << BIBLUE << "#2: Adding negative x points                          " << RESET << std::endl << std::endl;
	{
		Graph graph;

		graph.add(-4, 4);

		std::cout << GREEN << "Points added:" << RESET << std::endl;
		std::cout << "(-4, 4)" << std::endl;

		std::cout << GREEN << "\nGraph:" << RESET << std::endl;
		std::cout << graph << std::endl;
	}
	std::cout << BIBLUE << "#3: Adding negative y points                          " << RESET << std::endl << std::endl;
	{
		Graph graph;

		graph.add(4, -4);

		std::cout << GREEN << "Points added:" << RESET << std::endl;
		std::cout << "(4, -4)" << std::endl;

		std::cout << GREEN << "\nGraph:" << RESET << std::endl;
		std::cout << graph << std::endl;
	}
	std::cout << BIBLUE << "#4: Adding negative x and y points                    " << RESET << std::endl << std::endl;
	{
		Graph graph;

		graph.add(-4, -4);

		std::cout << GREEN << "Points added:" << RESET << std::endl;
		std::cout << "(-4, -4)" << std::endl;

		std::cout << GREEN << "\nGraph:" << RESET << std::endl;
		std::cout << graph << std::endl;
	}
	std::cout << BIBLUE << "#5: Adding a lot of points                            " << RESET << std::endl << std::endl;
	{
		Graph graph;

		graph.add(4, 4);
		graph.add(-4, 4);
		graph.add(4, -4);
		graph.add(-4, -4);

		std::cout << GREEN << "Points added:" << RESET << std::endl;
		std::cout << "(4, 4)\n(-4, 4)\n(4, -4)\n(-4, -4)\n" << std::endl;

		std::cout << GREEN << "\nGraph:" << RESET << std::endl;
		std::cout << graph << std::endl;
	}
	std::cout << BIBLUE << "#5: Trying to add a point that already exists         "<< RESET << std::endl << std::endl;
	{
		Graph graph;

		graph.add(4, 4);

		try	{
			graph.add(4, 4);
		}
		catch (std::exception &e)	{
			std::cout << RED << e.what() << RESET << std::endl << std::endl;
		}

	}
	std::cout << BIBLUE << "#6: Trying to remove a point that is not in the graph "<< RESET << std::endl << std::endl;
	{
		Graph graph;

		try	{
			graph.remove(4, 4);
		}
		catch (std::exception &e)	{
			std::cout << RED << e.what() << RESET << std::endl << std::endl;
		}

	}
	std::cout << BIGREEN << "Big final graph just because                          "<< RESET << std::endl << std::endl;
	{
		Graph graph;

		graph.add(3, 2);
		graph.add(12, 1);
		graph.add(2, 10);
		graph.add(-2, 5);
		graph.add(7, -10);
		graph.add(-8, -12);
		graph.add(-3, -6);

		std::cout << graph << std::endl;
	}
	/*	BONUS	*/
	// {
	// 	Graph graph;

	// 	graph.add(40, 20);
	// 	graph.add(30, 40);
	// 	graph.add(-110, 40);

	// 	graph.add(-400, -600, 300, 100);
	// 	graph.add(-800, 600, 300, 600);
	// 	graph.add(100, -600, 100, 400);

	// 	Graph::png_options	options;

	// 	options.height = 3000;
	// 	options.width = 3000;

	// 	writeToPng(graph, "test.png", options);
	// 	// writeToPng(graph, "test1.png");
	// }
	
}