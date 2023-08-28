#pragma once
#include <forward_list>

namespace GameCore
{
	template <class T>
	class List
	{
	public:
		List();

		bool add(T item);
		bool remove(T item);

		auto begin();
		auto end();
	
	private:	
		std::forward_list<T> m_list;
	
	};



	template<class T>
	inline List<T>::List()
	{
	}

	template<class T>
	inline bool List<T>::add(T item)
	{
		//Items can be added more than once
		m_list.push_front(item);

		return true;
	}

	template<class T>
	inline bool List<T>::remove(T item)
	{
		//Does not check if item was removed
		m_list.remove(item);

		return true;
	}

	template<class T>
	inline auto List<T>::begin()
	{
		return m_list.begin();
	}

	template<class T>
	inline auto List<T>::end()
	{
		return m_list.end();
	}
}


