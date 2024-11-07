#include "Graph.hpp"

void	Graph::addPoint(Vector2 newVector2)	{

	std::vector<Vector2>::const_iterator it = _points.begin();

	while (it != _points.end())	{
		if (*it == newVector2)
			throw PointAlreadyInGraph();
		it++;
	}

	_points.push_back(newVector2);
}

void	Graph::addPoint(float x, float y)	{

	Vector2 newVector2(x, y);
	std::vector<Vector2>::const_iterator it = _points.begin();

	while (it != _points.end())	{
		if (*it == newVector2)
			throw PointAlreadyInGraph();
		it++;
	}

	_points.push_back(newVector2);

}

void	Graph::removePoint(Vector2 vector2)	{

	std::vector<Vector2>::iterator it = _points.begin();

	while (it != _points.end())	{
		if (*it == vector2)	{
			_points.erase(it);
			return ;
		}
		it++;
	}
	throw PointNotInGraph();
}

void	Graph::removePoint(float x, float y)	{

	Vector2 newVector2(x, y);
	std::vector<Vector2>::iterator it = _points.begin();

	while (it != _points.end())	{
		if (*it == newVector2)	{
			_points.erase(it);
			return ;
		}
		it++;
	}
	throw PointNotInGraph();

}

bool	Graph::linesAreEqual(std::vector<Vector2> line1, std::vector<Vector2> line2)	{
	std::vector<Vector2>::iterator it1 = line1.begin();
	std::vector<Vector2>::iterator it2 = line2.begin();

	while (it1 != line1.end() && it2 != line2.end())	{
		if (!(*it1 == *it2))
			return (false);
	}
	return true;
}

void	Graph::addLine(std::vector<Vector2> newLine)	{
	std::vector<std::vector<Vector2> >::iterator line_it = _lines.begin();

	while (line_it != _lines.end())	{
		if (linesAreEqual(*line_it, newLine))
			throw LineAlreadyInGraph();
	}

	_lines.push_back(newLine);
}

void	Graph::removeLine(std::vector<Vector2> line)	{
	std::vector<std::vector<Vector2> >::iterator line_it = _lines.begin();

	while (line_it != _lines.end())	{
		if (linesAreEqual(*line_it, line))
			_lines.erase(line_it);
	}

	throw LineNotInGraph();
}

void	_drawFilledCircle(cairo_t *cr, int x, int y, int radius)	{
	cairo_new_path(cr);

	cairo_arc(cr, x, y, radius, 0, 2 * M_PI);
	cairo_fill(cr);
	cairo_stroke(cr);
}

void	_drawLine(cairo_t *cr, int x_start, int y_start, int x_end, int y_end)	{
	cairo_new_path(cr);

	cairo_move_to(cr, x_start, y_start);
	cairo_line_to(cr, x_end, y_end);
	cairo_stroke(cr);
}

void	_drawText(cairo_t *cr, std::string text, int x, int y) {
	cairo_new_path(cr);


	cairo_move_to(cr, x, y);
	cairo_show_text(cr, text.c_str());
	cairo_stroke(cr);
}

std::string _int2str(int number) {
	std::ostringstream ss;
	ss << number;
	return ss.str();
}

void	_drawAxes(cairo_t *cr, int width, int height)	{
	cairo_new_path(cr);

	cairo_set_source_rgb(cr, 0, 0, 0);
	cairo_set_line_width(cr, width / 800);
	cairo_select_font_face(cr, "Sans", CAIRO_FONT_SLANT_NORMAL, CAIRO_FONT_WEIGHT_NORMAL);
	cairo_set_font_size(cr, width / 100);

	int ratio = width / 20;

	std::cout << "width: " << width << std::endl;
	std::cout << "height: " << height << std::endl;
	std::cout << "ratio: " << ratio << std::endl;

	_drawLine(cr, width / 2, 0, width / 2, height);
	_drawLine(cr, 0, height / 2, width, height / 2);

	cairo_set_line_width(cr, width / 1000);
	cairo_set_source_rgb(cr, 0.5, 0.5, 0.5);


	for (float i = ratio + width % ratio; i < width; i += ratio)	{
		std::cout << i << std::endl;
		if ((i - width / 2) / 10 != 0 && (i - width / 2) / 10 == round(i - width / 2) / 10)	{
			_drawLine(cr, i, 0, i, height);
			_drawText(cr, _int2str((i - width / 2) / 10), i - ratio / 2.5, height / 2 + (height / 20) / 4);
		}
	}
	for (float i = ratio + height % ratio; i < height; i += ratio)	{
		if ((i - height / 2) / 10 != 0 && (i - height / 2) / 10 == round((i - height / 2) / 10))	{
			_drawLine(cr, 0, i, width, i);
			_drawText(cr, _int2str(-1 * (i - height / 2) / 10), width / 2 - (width / 20) / 3, i + (height / 20) / 4);
		}
	}
}

void	Graph::saveToPNG(const std::string &filename)	{
	int	max_height	= 0;
	int	min_height	= 0;
	int	max_width	= 0;
	int	min_width	= 0;

	std::vector<Vector2>::iterator it3 = _points.begin();

	while (it3 != _points.end())	{
		if (max_height < it3->y)
			max_height = it3->y;
		if (min_height > it3->y)
			min_height = it3->y;
		if (max_width < it3->x)
			max_width = it3->x;
		if (min_width > it3->x)
			min_width = it3->x;
		it3++;
	}
	max_height++;
	min_height--;
	max_width++;
	min_width--;

	int	height, width;

	if (max_height > -min_height)
		height = (max_height + 1) * 20;
	else
		height = (min_height + 1) * 20;
	if (max_width > -min_width)
		width = (max_width + 1) * 20;
	else
		width = (min_width + 1) * 20;


	height = ceil(height / pow(10, _int2str(height).size())) * pow(10, _int2str(height).size() - 1) * 2;
	width = ceil(width / pow(10, _int2str(width).size())) * pow(10, _int2str(width).size() - 1) * 2;
	
	if (height < 2000)
		height = 2000;
	if (width < 2000)
		width = 2000;

	cairo_surface_t *surface = cairo_image_surface_create(CAIRO_FORMAT_ARGB32, width, height);
	cairo_t *cr = cairo_create(surface);

	std::string	filename_with_extension = filename + ".png";

	cairo_set_source_rgb(cr, 1, 1, 1);
	cairo_paint(cr);

	_drawAxes(cr, width, height);


	cairo_set_source_rgb(cr, 1, 0, 0);

	std::vector<Vector2>::iterator it = _points.begin();
	while (it != _points.end())	{
		cairo_new_path(cr);
		_drawFilledCircle(cr, it->x * 10 + width / 2, -1 * it->y * 10 + height / 2, width / 200);
		it++;
	}

	cairo_set_source_rgb(cr, 0, 0, 1);
	cairo_set_line_width(cr, width / 80);
	std::vector<std::vector<Vector2> >::const_iterator it1 = _lines.begin();
	while (it1 != _lines.end())	{
		cairo_new_path(cr);
		std::vector<Vector2>::const_iterator it2 = it1->begin();
		cairo_move_to(cr, it2->x * 10 + width / 2, -1 * it2->y * 10 + height / 2);
		while (it2 != it1->end())	{
			cairo_line_to(cr, it2->x * 10 + width / 2,  -1 * it2->y * 10 + height / 2);
			it2++;
		}
		cairo_stroke(cr);
		it1++;
	}

	cairo_surface_write_to_png(surface, filename_with_extension.c_str());


	cairo_destroy(cr);
	cairo_surface_destroy(surface);
}

std::ostream& operator << (std::ostream& os, const Graph& graph)	{

	// std::cout << "Iterator address: " << &(*(graph.getPoints().begin())) << std::endl;
	// os << "+" << *(graph.getPoints().begin()) << std::endl;

	// std::vector<Vector2>::iterator it = graph.getPoints().begin();
	// std::cout << "Iterator address: " << &(*it) << std::endl;
	// os << "-" << *it << std::endl;

	// std::cout << "Iterator address: " << &(*(graph.getPoints().begin())) << std::endl;
	// os << "+" << *(graph.getPoints().begin()) << std::endl;


	// while (it != graph.getPoints().end())	{
	// 	os << *it << std::endl;
	// 	it++;
	// }

	int	max_height	= 0;
	int	min_height	= 0;
	int	max_width	= 0;
	int	min_width	= 0;

	std::vector<Vector2>::iterator it = graph.getPoints().begin();

	while (it != graph.getPoints().end())	{
		if (max_height < it->y)
			max_height = it->y;
		if (min_height > it->y)
			min_height = it->y;
		if (max_width < it->x)
			max_width = it->x;
		if (min_width > it->x)
			min_width = it->x;
		it++;
	}
	max_height++;
	min_height--;
	max_width++;
	min_width--;

	os << max_height << std::endl;
	os << min_height << std::endl;
	os << max_width << std::endl;
	os << min_width << std::endl;

	int	height = max_height - min_height + 1;
	int	width = max_width - min_width + 1;

	char	ASCIImap[height][width];

	// os << height << std::endl;
	// os << width << std::endl;

	for (int i = 0; i < height; i++)	{
		for (int j = 0; j < width; j++)	{
			if (i == height - abs(min_height) - 1 && j == abs(min_width))
				ASCIImap[i][j] = '+';
			else if (i == height - abs(min_height) - 1)
				ASCIImap[i][j] = '-';
			else if (j == abs(min_width))
				ASCIImap[i][j] = '|';
			else
				ASCIImap[i][j] = ' ';
		}
	}

	it = graph.getPoints().begin();
	while (it != graph.getPoints().end())	{
		// os << (int)round(it->x) << std::endl;
		ASCIImap[height - (int)round(it->y) + min_height - 1][(int)round(it->x) + abs(min_width)] = 'X';
		it++;
	}

	for (int i = 0; i < height; i++)	{
		if ((height - i - 1 - abs(min_height)) % 10 >= 0)
			os << " ";
		os << (height - i - 1 - abs(min_height)) % 10;
		for (int j = 0; j < width; j++)	{
			os << ASCIImap[i][j];
		}
		os << std::endl;
	}
	os << "  ";
	for (int j = 0; j < width; j++)	{
		os << abs((j + min_width) % 10);
	}
	os << std::endl;

	return os;
}