class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        // make a duplicate matrix: visited (same size as grid)
        //vector<vector<bool> > visited;
        // use a queue/deque to explore all the locations of the grid
        //visited.resize(grid.size(), vector<bool>(grid[0].size(), false));
        // iterate through rows and columns of vector
        queue<std::pair<size_t, size_t> > locations;
        // keep count of number of islands
        uint32_t num_islands = 0;
        for (size_t r = 0; r < grid.size(); ++r) {
            for (size_t c = 0; c < grid[0].size(); ++c) {
                //skip over if the position is 0
                if (grid[r][c] == '0') continue;
                //if (visited[r][c] == true) continue;
                //if it's = 1:
                // add this position to queue, mark as visited
                grid[r][c] = '0';
                locations.push(make_pair(r, c));
                //while queue is not empty
                while (!locations.empty()) {
                    // pop first pair off of queue
                    pair<size_t, size_t> &p = locations.front();
                    size_t ro = p.first;
                    size_t co = p.second;
                    locations.pop();
                    // travel north if possible
                    // add to queue and mark visited
                    if (ro != 0 && grid[ro-1][co] == '1') {
                        grid[ro-1][co] = '0';
                        locations.push(make_pair(ro-1, co));
                    }
                    //same for other directions
                    //travel south
                    if (ro < grid.size() - 1 && grid[ro+1][co] == '1') {
                        grid[ro+1][co] = '0';
                        locations.push(make_pair(ro+1, co));
                    }
                    // travel west
                    if (co != 0 && grid[ro][co-1] == '1') {
                        grid[ro][co-1] = '0';
                        locations.push(make_pair(ro, co-1));
                    }
                    //travel east
                    if (co < grid[0].size() - 1 && grid[ro][co+1] == '1') {
                       grid[ro][co+1] = '0';
                        locations.push(make_pair(ro, co+1));
                    }
                } //while queue isn't empty
                //increment island count by 1
                ++num_islands;
            } //for c
        } //for r
        return num_islands;
    } //numIslands
}; //Solution
