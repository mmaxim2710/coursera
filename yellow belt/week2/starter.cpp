#include <string>
#include <iostream>
#include <cassert>
#include <vector>
#include <map>

using namespace std;

enum class QueryType {
    NewBus,
    BusesForStop,
    StopsForBus,
    AllBuses
};

struct Query {
    QueryType type;
    string bus;
    string stop;
    vector<string> stops;
};

istream& operator >> (istream& is, Query& q) {
    string s;
    is >> s;

    if (s == "ALL_BUSES") {
        q.type = QueryType::AllBuses;
    } else if (s == "STOPS_FOR_BUS") {
        q.type = QueryType::StopsForBus;
    } else if (s == "BUSES_FOR_STOP") {
        q.type = QueryType::BusesForStop;
    } else q.type = QueryType::NewBus;

    if (q.type == QueryType::BusesForStop) {
        is >> q.stop;
    } else if (q.type == QueryType::StopsForBus) {
        is >> q.bus;
    } else if (q.type == QueryType::NewBus) {
        int c;
        string s;
        is >> q.bus >> c;
        q.stops.clear();

        for (int i = 0; i < c; ++i) {
            is >> s;
            q.stops.push_back(s);
        }
    }

    return is;
}

struct BusesForStopResponse {
    vector<string> B;
};

ostream& operator << (ostream& os, const BusesForStopResponse& r) {
    for (string i : r.B) os << i << ' ';
    return os;
}

struct StopsForBusResponse {
    vector<vector<string>> S;
};

ostream& operator << (ostream& os, const StopsForBusResponse& r) {
    for (int i = 0; i < r.S.size(); ++i) {
        for (string j : r.S[i]) {
            os << j << ' ';
        }
        os << endl;
    }

    return os;
}

struct AllBusesResponse {
    vector<vector<string>> B;
};

ostream& operator << (ostream& os, const AllBusesResponse& r) {
    for (vector<string> i : r.B) {
        for (string j : i) {
            os << j << ' ';
        }
        os << endl;
    }
    return os;
}

class BusManager {
    map<string, vector<string>> B, S;
    public:
    void AddBus(const string& bus, const vector<string>& stops) {
        S[bus] = stops;
        for (string i : stops) {
            B[i].push_back(bus);
        }
    }

    BusesForStopResponse GetBusesForStop(const string& stop) const {
        BusesForStopResponse x;

        if (B.find(stop) != B.end()) {
            x.B = get<1>(*B.find(stop));
        } else {
            x.B = {"No stop"};
        }
        return x;
    }

    StopsForBusResponse GetStopsForBus(const string& bus) const {
        StopsForBusResponse x;

        if (S.find(bus) != S.end()) {
            for (string i : get<1>(*S.find(bus))) {
                vector<string> h = get<1>(*B.find(i));
                x.S.push_back({"Stop " + i + ":"});

                if (h.size() == 1) {
                    x.S.back().push_back("no interchange");
                } else {
                    for (string j : h) {
                        if (j != bus) {
                            x.S.back().push_back(j);
                        }
                    }
                }
            }

        } else {
            x.S = {{"No bus"}};
        }
        return x;
    }

    AllBusesResponse GetAllBuses() const {
        AllBusesResponse x;

        if (S.empty()) {
            x.B = {{"No buses"}};
        } else {
            for (pair<string, vector<string>> i : S) {
                x.B.push_back({"Bus " + get<0>(i) + ":"});
                for (string j : get<1>(i)) {
                    x.B.back().push_back(j);
                }
            }
        }
        return x;
    }
};

int main() {
  int query_count;
  Query q;

  cin >> query_count;

  BusManager bm;
  for (int i = 0; i < query_count; ++i) {
    cin >> q;
    switch (q.type) {
    case QueryType::NewBus:
      bm.AddBus(q.bus, q.stops);
      break;
    case QueryType::BusesForStop:
      cout << bm.GetBusesForStop(q.stop) << endl;
      break;
    case QueryType::StopsForBus:
      cout << bm.GetStopsForBus(q.bus) << endl;
      break;
    case QueryType::AllBuses:
      cout << bm.GetAllBuses() << endl;
      break;
    }
  }

  return 0;
}