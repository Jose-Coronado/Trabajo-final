#pragma once
template <class Class>
class vector
{
private:
	Class* array;
	int n;
public:
	vector()
	{
		array = nullptr;
		n = 0;
	}
	~vector()
	{
		delete[] array;
	}

	void push_back(Class new_value)
	{
		Class* aux = new Class[n + 1];
		
		for (int i = 0; i < n; i++)
			aux[i] = array[i];

		aux[n] = new_value;

		delete[] array;
		array = aux;
		n++;
	}
	void push_front(Class new_value)
	{
		Class* aux = new Class[n + 1];

		aux[0] = new_value;

		for (int i = 1; i < n + 1; i++)
			aux[i] = array[i - 1];

		delete[] array;
		array = aux;
		n++;
	}
	bool insert(Class new_value, int position)
	{
		if (!(position >= 0 && position < n))
			return false;

		Class* aux = new Class[n + 1];

		for (int i = 0; i < position; i++)
			aux[i] = array[i];

		aux[position] = new_value;

		for (int i = position + 1; i < n + 1; i++)
			aux[i] = array[i - 1];

		delete[] array;
		array = aux;
		n++;

		return true;
	}

	Class pop_back()
	{
		Class* aux = new Class[n - 1];

		for (int i = 0; i < n - 1; i++)
			aux[i] = array[i];

		Class eliminado = array[n - 1];

		delete[] array;
		array = aux;
		n--;

		return eliminado;
	}
	Class pop_front()
	{
		Class* aux = new Class[n - 1];

		for (int i = 0; i < n - 1; i++)
			aux[i] = array[i + 1];

		Class eliminado = array[0];

		delete[] array;
		array = aux;
		n--;

		return eliminado;
	}
	Class erase(int position)
	{
		Class* aux = new Class[n - 1];

		for (int i = 0; i < position; i++)
			aux[i] = array[i];

		for (int i = position; i < n - 1; i++)
			aux[i] = array[i + 1];

		Class eliminado = array[position];

		delete[] array;
		array = aux;
		n--;

		return eliminado;
	}

	bool remove_first(Class value)
	{
		for (int i = 0; i < n; i++)
			if (array[i] == value)
			{
				erase(i);
				return true;
			}

		return false;
	}
	bool remove_last(Class value)
	{
		for (int i = n - 1; i >= 0; i--)
			if (array[i] == value)
			{
				erase(i);
				return true;
			}

		return false;
	}
	int remove_all(Class value)
	{
		int result = 0;
		for (int i = 0; i < n; i++)
			if (array[i] == value)
			{
				erase(i);
				i--;
				result++;
			}

		return result;
	}

	Class assing(Class new_value, int position)
	{
		if (!(position >= 0 && position < n))
			return nullptr;

		Class old = array[position];
		array[position] = new_value;
		return old;
	}

	int size()
	{
		return n;
	}
	void clear()
	{
		delete[] array;
		array = nullptr;
		n = 0;
	}
	bool swap(int first, int second)
	{
		if (!(first >= 0 && first < n && second >= 0 && second < n))
			return false;

		Class temp = array[first];
		array[first] = array[second];
		array[second] = temp;

		return true;
	}

	Class front()
	{
		return array[0];
	}
	Class back()
	{
		return array[n - 1];
	}
	Class at(int position)
	{
		return array[position];
	}
	Class* data()
	{
		return array;
	}
};