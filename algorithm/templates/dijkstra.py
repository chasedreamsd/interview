import heapq
import collections

def dijk(weightArray, n, st):
    '''
    input:
        weightArray = [[sourceNode, targetNode, weight]]
        n = number of node from 0 to n-1
        st = start node
    output:
        parent = parent array
        dist = shortest distance from start point to current point
    '''
    graph = collections.defaultdict(list)
    for s, t, d in weightArray:
        graph[s].append((t, d))

    pq = [(0, st)]
    dist = {st: 0}
    parent = {st: None}
    visted = set()

    while pq:
        curr_dist, curr_node = heapq.heappop(pq)
        visted.add(curr_node)
        for neighbor, neighbor_dist in graph[curr_node]:
            if neighbor in visted: continue
            if neighbor not in dist or curr_dist + neighbor_dist < dist[neighbor]:
                heapq.heappush(pq, (curr_dist + neighbor_dist, neighbor))
                parent[neighbor] = curr_node
                dist[neighbor] = curr_dist + neighbor_dist
    return dist, parent

if __name__ == '__main__':
    # leetcode 743
    # direct graph
    dg = [[2,1,1],[2,3,1],[3,4,1]]
    d, p = dijk(dg, 4, 2)
    print(d == {2: 0, 1: 1, 3: 1, 4: 2})
    print(p == {2: None, 1: 2, 3: 2, 4: 3})

    # huanghaojie youtube
    #      B---1---D
    #  5 / |     / | \ 6
    #   /  |    /  |  \
    # A    |2  4   3   F
    #   \  |  /    |    
    #  1 \ | /     |
    #      C---8---E
    ug = [["A","B",5], ["A","C",1],
          ["B","A",5], ["B","C",2], ["B","D",1], 
          ["C","A",1], ["C","B",2], ["C","D",4], ["C","E",8],
          ["D","B",1], ["D","C",4], ["D","E",3], ["D","F",6],
          ["E","C",8], ["E","D",3],
          ["F","D",6]]
    d, p = dijk(ug, 6, "A")
    print({'A': 0, 'B': 3, 'C': 1, 'D': 4, 'E': 7, 'F': 10} == d)
    print({'A': None, 'B': 'C', 'C': 'A', 'D': 'B', 'E': 'D', 'F': 'D'} == p)
