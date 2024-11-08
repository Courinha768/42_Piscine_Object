#include "../../includes/Graph.hpp"

void	writeToPng(const Graph &graph, const std::string &filename)	{
	writeToPng(graph, filename, Graph::png_options());
}

static	std::pair<int, int>	_calculateScale(const Graph &graph)	{
	int	x_scale, y_scale;
	int	max_x = 1 , max_y = 1;

	{
		std::vector<Vector2> points = graph.getPoints();
		std::vector<Vector2>::const_iterator it = points.begin();
		while (it != points.end())	{
			if (abs(it->x) > max_x)
				max_x = abs(it->x);
			if (abs(it->y) > max_y)
				max_y = abs(it->y);
			it++;
		}
	}
	{
		std::vector<Line> lines = graph.getLines();
		std::vector<Line>::const_iterator it = lines.begin();
		while (it != lines.end())	{
			if (abs(it->point1.x) > max_x)
				max_x = abs(it->point1.x);
			if (abs(it->point1.y) > max_y)
				max_y = abs(it->point1.y);
			if (abs(it->point2.x) > max_x)
				max_x = abs(it->point2.x);
			if (abs(it->point2.y) > max_y)
				max_y = abs(it->point2.y);
			it++;
		}
	}

	// std::cout << "max_x: " << max_x << std::endl;
	// std::cout << "max_y: " << max_y << std::endl;

	// std::cout << pow(10, floor(log10(max_x))) << std::endl;
	// std::cout << pow(10, floor(log10(max_y))) << std::endl;

	x_scale = pow(10, floor(log10(max_x)));
	y_scale = pow(10, floor(log10(max_y)));

	return std::pair<int, int>(x_scale, y_scale);
}

static	void	_drawLine(cairo_t *cr, int x_start, int y_start, int x_end, int y_end)	{
	cairo_new_path(cr);

	cairo_move_to(cr, x_start, y_start);
	cairo_line_to(cr, x_end, y_end);
	cairo_stroke(cr);
}


static	void	_set_source_rgb(cairo_t *cr, int color)	{
	switch (color)	{
		case C_WHITE:
			cairo_set_source_rgb(cr, 1, 1, 1);
			break;
		case C_BLACK:
			cairo_set_source_rgb(cr, 0, 0, 0);
			break;
		case C_GREY:
			cairo_set_source_rgb(cr, 0.5, 0.5, 0.5);
			break;
		case C_RED:
			cairo_set_source_rgb(cr, 1, 0, 0);
			break;
		case C_GREEN:
			cairo_set_source_rgb(cr, 0, 1, 0);
			break;
		case C_BLUE:
			cairo_set_source_rgb(cr, 0, 0, 1);
			break;
	}
}

static	void	_drawAxis(cairo_t *cr, const Graph::png_options &options)	{
	_set_source_rgb(cr, options.c_axis);

	cairo_set_line_width(cr, AXIS_WIDTH *  options.width / 1000);
	_drawLine(cr, options.width / 2, 0, options.width / 2, options.height);

	cairo_set_line_width(cr, AXIS_WIDTH *  options.height / 1000);
	_drawLine(cr, 0, options.height / 2, options.width, options.height / 2);
}

static	void	_drawGrid(cairo_t *cr, const Graph::png_options &options)	{
	_set_source_rgb(cr, options.c_grid);


	cairo_set_line_width(cr, ceil(options.width / 1000) * GRID_WIDTH);
	for (int i = -9; i < 10; i++)	{
		_drawLine(cr, i * options.width / 20 + options.height / 2, 0, i * options.width / 20 + options.height / 2, options.height);
	}

	cairo_set_line_width(cr, ceil(options.height / 1000) * GRID_WIDTH);
	for (int i = -9; i < 10; i++)	{
		_drawLine(cr, 0, i * options.height / 20 + options.height / 2, options.width, i * options.height / 20 + options.height / 2);
	}
}

static	std::string _int2str(int number) {
	std::ostringstream ss;
	ss << number;
	return ss.str();
}

static	void	_drawNumber(cairo_t *cr, int number, int x, int y)	{
	cairo_new_path(cr);

	cairo_move_to(cr, x, y);
	cairo_show_text(cr, _int2str(number).c_str());
	cairo_stroke(cr);
}

static	void	_drawGridNumbers(cairo_t *cr, const Graph::png_options &options, const std::pair<int, int> &scales)	{

	_set_source_rgb(cr, options.c_grid);

	cairo_select_font_face(cr, "Sans", CAIRO_FONT_SLANT_NORMAL, CAIRO_FONT_WEIGHT_NORMAL);
	
	//!Check this font size
	cairo_set_font_size(cr, 15 * options.height / 1000);

	for (int i = -9; i < 10; i++)	{
		_drawNumber(cr,
			i * scales.first,
			i * options.width / 20 + options.width / 2 + (15 * options.height / 1000) * 0.3,
			options.height / 2 + (15 * options.height / 1000) * 1.3
		);
	}

	for (int i = -9; i < 10; i++)	{
		if (i * scales.second != 0)	{
			_drawNumber(cr,
				-1 * i * scales.second,
				options.width / 2 - (15 * options.height / 1000) * 1.8,
				i * options.height / 20 + options.height / 2 + (15 * options.height / 1000) * 1.3
			);
		}
	}
}

static	void	_drawPoints(cairo_t *cr, const Graph &graph, const Graph::png_options &options, const std::pair<int, int> &scales)	{

	_set_source_rgb(cr, options.c_points);
	std::vector<Vector2> points = graph.getPoints();
	std::vector<Vector2>::const_iterator it = points.begin();
	while (it != points.end())	{
		cairo_new_path(cr);

		// std::cout << "it->x: " << it->x << std::endl;
		// std::cout << "it->y: " << it->y << std::endl;

		// std::cout << "x: " << options.width / 2 + (it->x * options.width / 20) / scales.first << std::endl;
		// std::cout << "y: " << options.height / 2 - (it->y * options.height / 20) / scales.second << std::endl;

		cairo_arc(cr,
			options.width / 2 + (it->x * options.width / 20) / scales.first,
			options.height / 2 - (it->y * options.height / 20) / scales.second,
			options.height / 200,
			0,
			2 * M_PI
		);
		cairo_fill(cr);
		cairo_stroke(cr);

		it++;
	}

}

static	void	_drawLines(cairo_t *cr, const Graph &graph, const Graph::png_options &options, const std::pair<int, int> &scales) {
	_set_source_rgb(cr, options.c_lines);
	cairo_set_line_width(cr, AXIS_WIDTH *  options.height * options.width / 1000000);

	std::vector<Line> lines = graph.getLines();
	std::vector<Line>::const_iterator it = lines.begin();
	while (it != lines.end())	{
		cairo_new_path(cr);

		cairo_move_to(cr,
			options.width / 2 + (it->point1.x * options.width / 20) / scales.first,
			options.height / 2 - (it->point1.y * options.height / 20) / scales.second
		);
		cairo_line_to(cr,
			options.width / 2 + (it->point2.x * options.width / 20) / scales.first,
			options.height / 2 - (it->point2.y * options.height / 20) / scales.second
		);
		cairo_stroke(cr);
		it++;
	}
}

void	writeToPng(const Graph &graph, const std::string &filename, const Graph::png_options &options)	{

	//todo: if it doesnt have the extension add it

	//todo: check settings, height and width divided by 1000 cant be smaller than AXIS_WIDTH or GRID_WIDTH

	std::pair<int, int>	scales = _calculateScale(graph);

	// std::cout << "scales.first: " << scales.first << std::endl;
	// std::cout << "scales.second: " << scales.second << std::endl;

	cairo_surface_t *surface = cairo_image_surface_create(CAIRO_FORMAT_ARGB32, options.width, options.height);
	cairo_t			*cr = cairo_create(surface);

	_set_source_rgb(cr, options.c_background);
	cairo_paint(cr);

	if (options.axis)
		_drawAxis(cr, options);
	if (options.grid)
		_drawGrid(cr, options);
	if (options.numbers)
		_drawGridNumbers(cr, options, scales);

	_drawPoints(cr, graph, options, scales);
	_drawLines(cr, graph, options, scales);

	cairo_surface_write_to_png(surface, filename.c_str());

	cairo_destroy(cr);
	cairo_surface_destroy(surface);
	
}
