#pragma once
#include <string>

class	Brain
{
	public:

		Brain();
		Brain(const Brain &other);
		Brain	&operator=(const Brain &other);
		~Brain();

		const std::string	getIdea(size_t index) const;
		void				setIdea(size_t index, const std::string &idea);

	private:

		std::string	_ideas[100];
};
