/*The Postmaster wants to write a program to answer the queries regarding letter collection in a city. A city is represented as a matrix mat of size n*m. Each cell represents a house and contains letters which are denoted by a number in the cell. The program should answer q queries which are of following types:
1 i j : To sum all the letters which are at a 1-hop distance from the cell (i,j) in any direction
2 i j : To sum all the letters which are at a 2-hop distance from the cell (i,j) in any direction 
The queries are given in a 2D matrix queries[][].
In one hop distance postmaster can go to any of [(i-1,j-1), (i-1,j), (i-1,j+1), (i,j-1), (i,j+1), (i+1,j-1), (i+1,j), (i+1,j+1)] from (i,j). 
*/
//----------------------------------------------------------
//my idea is first to figure out the hops and sum all the cell that satisfy the condition
//but I add all the cell value one by one, this is not efficient
//the provided answer used the loops to solve this problem, and I should really learn from it


 vector<int> matrixSum(int n, int m, vector<vector<int>> mat, int q, vector<int> queries[])
{
	// code here
	vector<int> res;

	for (unsigned int k = 0; k < q; k++) {
		vector<int> currQ = queries[k];
		int hops = currQ[0];
		int iPos = currQ[1];
		int jPos = currQ[2];

		int sum = 0;
		for (int i = iPos - hops; i <= iPos + hops; i++) {
			if (i < 0 || i >= n) {
				continue;
			}
			for (int j = jPos - hops; j <= jPos + hops; j++) {
				if (j < 0 || j >= m) {
					continue;
				}
				if (i == iPos && j == jPos) {
					continue;
				}

				bool compute = false;

				if (i == iPos - hops) {
					compute = true;
				}
				if (i == iPos + hops) {
					compute = true;
				}
				if (j == jPos - hops) {
					compute = true;
				}
				if (j == jPos + hops) {
					compute = true;
				}

				if (compute) {
					sum += mat[i][j];
				}
			}
		}

		res.push_back(sum);
	}

	return res;
}