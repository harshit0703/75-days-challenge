class LFUCache
{
public:
    list<pair<int, pair<int, int>>> data;
    unordered_map<int, list<pair<int, pair<int, int>>>::iterator> mp;
    // {counter, {key, value}}
    int maxSize;

    void rearrangeList(list<pair<int, pair<int, int>>> &data, list<pair<int, pair<int, int>>>::iterator it)
    {
        list<pair<int, pair<int, int>>>::iterator temp = data.begin();
        while (temp != data.end() && *temp->first > *it->first)
            temp++;
        data.insert(temp, it);
    }

    LFUCache(int capacity)
    {
        maxSize = capacity;
    }

    int get(int key)
    {
        // if the key is absent
        if (mp.find(key) == mp.end())
            return -1;

        // if the key is present we need to increment its counter and rearrange the list

        mp[key]->first += 1;
        rearrangeList(data, mp[key]);
        return mp[key]->second->first;
    }

    void put(int key, int value)
    {
        // if key already exists increase the counter, update the value and rearrange the list
        if (mp.find(key) != mp.end())
        {
            mp[key]->first += 1;
            mp[key]->second->second = value;
            rearrangeList(data, mp[key]);
            return;
        }

        // if key does not exist then make a new key add it in the list at appropriate position and check for the size
        list<pair<int, pair<int, int>>>::iterator it = data.begin();
        while (it != data.end() && *it.first > 1)
            it++;
        data.insert(it, {1, {key, value}});
        mp[key] = it;

        if (mp.size() > maxSize)
        {
            mp.erase(data.back().second.first);
            data.pop_back();
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */