class MovieRentingSystem {
public:
    map<pair<int, int>, int> priceMap;
    unordered_map<int, set<pair<int, int>>> moviesToShops;

    set<tuple<int, int, int>> rented;

    MovieRentingSystem(int n, vector<vector<int>>& entries) {
        for (auto& e : entries) {
            int shop = e[0], movie = e[1], price = e[2];
            priceMap[{shop, movie}] = price;
            moviesToShops[movie].insert({price, shop});
        }
    }

    vector<int> search(int movie) {
        vector<int> res;
        if (moviesToShops.count(movie) == 0)
            return res;

        for (auto it = moviesToShops[movie].begin();
             it != moviesToShops[movie].end() && res.size() < 5; ++it) {
            res.push_back(it->second);
        }

        return res;
    }

    void rent(int shop, int movie) {
        int price = priceMap[{shop, movie}];
        moviesToShops[movie].erase({price, shop});
        rented.insert({price, shop, movie});
    }

    void drop(int shop, int movie) {
        int price = priceMap[{shop, movie}];
        rented.erase({price, shop, movie});
        moviesToShops[movie].insert({price, shop});
    }

    vector<vector<int>> report() {
        vector<vector<int>> res;

        for (auto it = rented.begin(); it != rented.end() && res.size() < 5;
             ++it) {
            auto [price, shop, movie] = *it;
            res.push_back({shop, movie});
        }

        return res;
    }
};
