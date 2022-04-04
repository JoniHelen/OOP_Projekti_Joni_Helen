#pragma once
#include <list>
#include <functional>
#include <stdexcept>

template <typename TKey, typename TValue>
class Dictionary { // Tein itse ja s‰‰stin.
private:
	std::list<std::unique_ptr<std::pair<TKey, std::unique_ptr<TValue>>>> Collection;
public:
	Dictionary();

	// Adds a pair to the collection.
	void Add(TKey& key, TValue&& value);

	// Adds a pair to the collection.
	void Add(TKey&& key, TValue&& value);

	// Removes a pair with the specified Key.
	void Remove(TKey key);

	// Checks if the collection contains any Value.
	bool Any(TValue&& value);

	// Checks if the dictionary contains a specific key.
	bool ContainsKey(TKey& key);

	// Checks if the dictionary contains a specific key.
	bool ContainsKey(TKey&& key);

	// Sets Value at Key if found.
	void TrySetValue(TKey&& key, TValue* value);

	// Sets Value at Key if found.
	void TrySetValue(TKey& key, TValue* value);

	// Sets Value at Key if found.
	void TrySwapValues(TKey&& key_first, TKey&& key_second);

	// Sets Value at Key if found.
	void TrySwapValues(TKey& key_first, TKey&& key_second);

	// Sets Value at Key if found.
	void TrySwapValues(TKey&& key_first, TKey& key_second);

	// Sets Value at Key if found.
	void TrySwapValues(TKey& key_first, TKey& key_second);

	// Gets a reference to a value at the given Key if found.
	std::unique_ptr<TValue>& ValueAt(TKey& key);

	// Gets a reference to a value at the given Key if found.
	std::unique_ptr<TValue>& ValueAt(TKey&& key);

	// Executes a function for each element in the collection.
	void ForEach(std::function<void(std::unique_ptr<std::pair<TKey, std::unique_ptr<TValue>>>&)> func);
};

template<typename TKey, typename TValue>
inline Dictionary<TKey, TValue>::Dictionary() { }

template<typename TKey, typename TValue>
inline void Dictionary<TKey, TValue>::Add(TKey& key, TValue&& value)
{
	if (!ContainsKey(key))
		Collection.push_back(std::make_unique<std::pair<TKey, std::unique_ptr<TValue>>>(key, std::make_unique<TValue>(value)));
	else
		throw std::invalid_argument("The given key already exists in the Dictionary.");
}

template<typename TKey, typename TValue>
inline void Dictionary<TKey, TValue>::Add(TKey&& key, TValue&& value)
{
	if (!ContainsKey(key))
		Collection.push_back(std::make_unique<std::pair<TKey, std::unique_ptr<TValue>>>(key, std::make_unique<TValue>(value)));
	else
		throw std::invalid_argument("The given key already exists in the Dictionary.");
}

template<typename TKey, typename TValue>
inline void Dictionary<TKey, TValue>::Remove(TKey key)
{
	int size = Collection.size();
	Collection.remove_if([key](const std::pair<TKey, std::unique_ptr<TValue>>& kvp) { return kvp.first == key; });
	if (size = Collection.size()) throw std::out_of_range("The given Key was not in the Dictionary.");
}

template<typename TKey, typename TValue>
inline bool Dictionary<TKey, TValue>::Any(TValue&& value)
{
	for (auto& item : Collection) {
		if (*(item->second.get()) == value) return true;
	}
	return false;
}

template<typename TKey, typename TValue>
inline bool Dictionary<TKey, TValue>::ContainsKey(TKey& key)
{
	for (auto& item : Collection) {
		if (item->first == key) return true;
	}
	return false;
}

template<typename TKey, typename TValue>
inline bool Dictionary<TKey, TValue>::ContainsKey(TKey&& key)
{
	for (auto& item : Collection) {
		if (item->first == key) return true;
	}
	return false;
}

template<typename TKey, typename TValue>
inline void Dictionary<TKey, TValue>::TrySetValue(TKey&& key, TValue* value)
{
	for (auto& item : Collection) {
		if (item->first == key) {
			item->second = std::unique_ptr<TValue>(value);
			return;
		}
	}
	throw std::out_of_range("The given Key was not in the Dictionary.");
}

template<typename TKey, typename TValue>
inline void Dictionary<TKey, TValue>::TrySetValue(TKey& key, TValue* value)
{
	for (auto& item : Collection) {
		if (item->first == key) {
			item->second = std::unique_ptr<TValue>(value);
			return;
		}	
	}
	throw std::out_of_range("The given Key was not in the Dictionary.");
}

template<typename TKey, typename TValue>
inline void Dictionary<TKey, TValue>::TrySwapValues(TKey&& key_first, TKey&& key_second)
{
	ValueAt(key_first).swap(ValueAt(key_second));
}

template<typename TKey, typename TValue>
inline void Dictionary<TKey, TValue>::TrySwapValues(TKey& key_first, TKey&& key_second)
{
	ValueAt(key_first).swap(ValueAt(key_second));
}

template<typename TKey, typename TValue>
inline void Dictionary<TKey, TValue>::TrySwapValues(TKey&& key_first, TKey& key_second)
{
	ValueAt(key_first).swap(ValueAt(key_second));
}

template<typename TKey, typename TValue>
inline void Dictionary<TKey, TValue>::TrySwapValues(TKey& key_first, TKey& key_second)
{
	ValueAt(key_first).swap(ValueAt(key_second));
}

template<typename TKey, typename TValue>
inline std::unique_ptr<TValue>& Dictionary<TKey, TValue>::ValueAt(TKey& key)
{
	for (auto& item : Collection) {
		if (item->first == key) return item->second;
	}
	throw std::out_of_range("The given Key was not in the Dictionary.");
}

template<typename TKey, typename TValue>
inline std::unique_ptr<TValue>& Dictionary<TKey, TValue>::ValueAt(TKey&& key)
{
	for (auto& item : Collection) {
		if (item->first == key) return item->second;
	}
	throw std::out_of_range("The given Key was not in the Dictionary.");
}

template<typename TKey, typename TValue>
inline void Dictionary<TKey, TValue>::ForEach(std::function<void(std::unique_ptr<std::pair<TKey, std::unique_ptr<TValue>>>&)> func)
{
	for (auto& item : Collection) func(item);
}