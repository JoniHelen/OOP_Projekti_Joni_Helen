#pragma once
#include <list>
#include <functional>

template <typename TKey, typename TValue>
class Dictionary {
private:
	TKey Key;
	TValue Value;

	std::list<std::pair<TKey, TValue>> Collection;
public:
	Dictionary();

	// Adds a pair to the collection.
	void Add(const TKey& key, const TValue& value);

	// Removes a pair with the specified Key.
	void Remove(TKey key);

	// Checks if the collection contains any Value.
	bool Any(TValue value);

	// Returns Value at Key if found, otherwise false.
	TValue* TryGetValue(TKey key);

	// Executes a function for each element in the collection.
	void ForEach(std::function<void(std::pair<TKey, TValue>&)> func);
};

template<typename TKey, typename TValue>
inline Dictionary<TKey, TValue>::Dictionary() { }

template<typename TKey, typename TValue>
inline void Dictionary<TKey, TValue>::Add(const TKey& key, const TValue& value) 
{ 
	Collection.push_back(std::pair<TKey, TValue>(key, value));
}

template<typename TKey, typename TValue>
inline void Dictionary<TKey, TValue>::Remove(TKey key)
{
	Collection.remove_if([](const std::pair<TKey, TValue> kvp) { return kvp.first == key; });
}

template<typename TKey, typename TValue>
inline bool Dictionary<TKey, TValue>::Any(TValue value)
{
	for (std::pair<TKey, TValue>& item : Collection) {
		if (item.second == value) return true;
	}
	return false;
}

template<typename TKey, typename TValue>
inline TValue* Dictionary<TKey, TValue>::TryGetValue(TKey key)
{
	for (std::pair<TKey, TValue>& item : Collection) {
		if (item.first == key) return &item.second;
	}
	return nullptr;
}

template<typename TKey, typename TValue>
inline void Dictionary<TKey, TValue>::ForEach(std::function<void(std::pair<TKey, TValue>&)> func)
{
	for (std::pair<TKey, TValue>& item : Collection) {
		func(item);
	}
}
