#pragma once
#include <iostream>

class	Fixed
{
	public:
		Fixed();
		Fixed(const Fixed &other);
		Fixed &operator=(const Fixed &other);
		~Fixed();

		Fixed(const int value);
		Fixed(const float value);

		int		toInt() const;
		float	toFloat() const;
		
		int		getRawBits() const;
		void	setRawBits(int const raw);
	
	private:
		int					_value;
		static const int	_fractionalBits = 8;
};

std::ostream	&operator<<(std::ostream &out, const Fixed &fixed);