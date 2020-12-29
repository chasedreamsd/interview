/*
LI 589 Connecting Graph
Description: Given n nodes in a graph labeled from 1 to n. There is no edges in the graph at beginning.
support the following method:
1. connect(a, b), add an edge to connect node a and node b.
2. query(a, b), check if two nodes are connected
Example
5 // n = 5
query(1, 2) return false
connect(1, 2)
query(1, 3) return false
connect(2, 4)
query(1, 4) return true
*/
class ConnectingGraph1 {
public:
	ConnectingGraph1(int n ): d_parent(n+1) {
		iota(d_parent.begin(), d_parent.end(), 0);
	}

	bool query(int a, int b) {
		return find(a) == find(b);
	}

	void connect(int a, int b) {
		int pa = find(a), pb = find(b);
		if (pa != pb) {
			d_parent[pa] = pb;
		}
	}

	int find(int a) {
		if (d_parent[a] == a) {
			return a;
		}
		return d_parent[a] = find(d_parent[a]);
	}

private:
	vector<int> d_parent;
};

/*
LI 590 Connecting Graph II
Description: Given n nodes in a graph labeled from 1 to n. There is no edges in the graph at beginning.
support the following method:
1. connect(a, b), add an edge to connect node a and node b.
2. query(a), Returns the number of connected component nodes which include node a.

Example
5 // n = 5
query(1) return 1
connect(1, 2)
query(1) return 2
connect(2, 4)
query(1) return 3
connect(1, 4)
query(1) return 3
*/
class ConnectingGraph2 {
public:
	ConnectingGraph2(int n) : d_parent(n + 1), d_size(n + 1, 1) {
		iota(d_parent.begin(), d_parent.end(), 0);
	}

	int query(int a) {
		return d_size[find(a)];
	}

	void connect(int a, int b) {
		int pa = find(a), pb = find(b);
		if (pa != pb) {
			d_parent[pa] = pb;
			d_size[pb] += d_size[pa];
		}
	}

	int find(int a) {
		if (d_parent[a] == a) {
			return a;
		}
		return d_parent[a] = find(d_parent[a]);
	}

private:
	vector<int> d_parent;
	vector<int> d_size;
};


/*
LI 591 Connecting Graph III 
Description Given n nodes in a graph labeled from 1 to n. There is no edges in the graph at beginning.
support the following method:
1. connect(a, b), add an edge to connect node a and node b.
2. query(), Returns the number of connected component in the graph

Example
5 // n = 5
query() return 5
connect(1, 2)
query() return 4
connect(2, 4)
query() return 3
connect(1, 4)
query() return 3
*/
class ConnectingGraph3 {
public:
     ConnectingGraph3(int n): d_parent(n+1), d_size(n) {
        // initialize your data structure here.
        iota(d_parent.begin(), d_parent.end(), 0);
    }
    void connect(int a, int b) {
        int pa = find(a), pb = find(b);
        if(pa != pb){
            d_parent[pa] = pb;
            --d_size;
        }
    }
    
    int find(int a){
        if(d_parent[a] == a){
            return a;
        }
        return d_parent[a] = find(d_parent[a]);
    }
    
    int query() {
        return d_size;
    }
private:
    vector<int> d_parent;
    int d_size;
};
