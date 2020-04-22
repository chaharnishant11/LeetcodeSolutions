vector<int> loadBalancing(int k, vector<int> arrival, vector<int> load){
    vector<pair<int, int>> servers(k, make_pair(0, 0));
    vector<pair<int, int>> requests;
    for(int i = 0; i < arrival.size(); ++i)
        requests.push_back({arrival[i], load[i]});
    sort(requests.begin(), requests.end());
    int index = 0;
    int maxLoad = -1;
    for(auto & it : requests)
    {
        int count = 0;
        int start = index;
        while(count <= k && it.first < servers[index].first)
        {
            index = (index + 1) % k;
            ++count;
        }
        if(count == k + 1)
        {
            index = start;
            continue;
        }
        servers[index].first = it.first + it.second - 1;
        servers[index].second += it.second;
        maxLoad = max(maxLoad, servers[index].second);
        index = (index + 1) % k;
    }
    vector<int> result;
    for(int i = 0; i < servers.size(); ++i)
        if(servers[i].second == maxLoad)
            result.push_back(i + 1);
    return result;
}