#include "Point.hpp"

bool	bsp(Point const a, Point const b, Point const c, Point const point)
{
	int	det1 = (a.getX() - point.getX()) * (b.getY() - point.getY()) \
	- (a.getY() - point.getY()) * (b.getX() - point.getX());
	
	int	det2 = (c.getX() - point.getX()) * (a.getY() - point.getY()) \
	- (c.getY() - point.getY()) * (a.getX() - point.getX());
	
	int	det3 = (b.getX() - point.getX()) * (c.getY() - point.getY()) \
	- (b.getY() - point.getY()) * (c.getX() - point.getX());

	if ((det1 > 0 && det2 > 0 && det3 > 0) || (det1 < 0 && det2 < 0 && det3 < 0))
		return (true);
	return (false);
}