class LRUCache
{
public:
    list<pair<int, int>> data;
    unordered_map<int, list<pair<int, int>>::iterator> mp;
    // using iterator to use the splice function to manipulate the positions
    int max_size;

    LRUCache(int capacity)
    {
        max_size = capacity;
        mp.clear();
    }

    int get(int key)
    {

        // if absent return -1;
        if (mp.find(key) == mp.end())
            return -1;

        // if present make it the recently used key by bringing to the front

        data.splice(data.begin(), data, mp[key]);
        return mp[key]->second;
    }

    void put(int key, int value)
    {

        // if present simply update the value make it the recent and return

        if (mp.find(key) != mp.end())
        {
            mp[key]->second = value;
            data.splice(data.begin(), data, mp[key]);
            return;
        }

        // else we need to make a new key as the recent key and check for the size

        data.push_front({key, value});
        mp.insert({key, data.begin()});

        if (mp.size() > max_size)
        {
            mp.erase(data.back().first);
            data.pop_back();
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */