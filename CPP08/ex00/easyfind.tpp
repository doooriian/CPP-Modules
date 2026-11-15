template<typename T>
typename T::const_iterator	easyfind(const T &container, int valueToFind)
{
	typename T::const_iterator	it_return;

	it_return = std::find(container.begin(), container.end(), valueToFind);
	if (it_return == container.end())
		throw std::out_of_range("value not found");
	return (it_return);
}
