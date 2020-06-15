There are A islands and there are M bridges connecting them. Each bridge has some cost attached to it.

We need to find bridges with minimal cost such that all islands are connected.

It is guaranteed that input data will contain at least one possible scenario in which all islands are connected with each other.

Input Format:

The first argument contains an integer, A, representing the number of islands.
The second argument contains an 2-d integer matrix, B, of size M x 3:
    => Island B[i][0] and B[i][1] are connected using a bridge of cost B[i][2].

Output Format:

Return an integer representing the minimal cost required.

Constraints:

1 <= A, M <= 6e4
1 <= B[i][0], B[i][1] <= A
1 <= B[i][2] <= 1e3

Examples:

Input 1:
    A = 4
    B = [   [1, 2, 1]
            [2, 3, 4]
            [1, 4, 3]
            [4, 3, 2]
            [1, 3, 10]  ]

Output 1:
    6

Explanation 1:
    We can choose bridges (1, 2, 1), (1, 4, 3) and (4, 3, 2), where the total cost incurred will be (1 + 3 + 2) = 6.

Input 2:
    A = 4
    B = [   [1, 2, 1]
            [2, 3, 2]
            [3, 4, 4]
            [1, 4, 3]   ]

Output 2:
    6

Explanation 2:
    We can choose bridges (1, 2, 1), (2, 3, 2) and (1, 4, 3), where the total cost incurred w
    _____________________________________________________________________________________________________________________________________________________________________________________________________________
    
    
    
    //Krushkal's Algorithm for minimum stpanning tree
/*bool compare(const vector<int> &A , const vector <int> &B)
{
    return A[2]<B[2];
}

int find(int u , vector <int> parent)
{
    while(u != parent[u])
        u= parent[u];
        
    return u;
}

void merge(int u , int v , vector <int> &parent)
{
    parent[find(v,parent)] = parent[find(u,parent)];
}

int krushkals(int n , vector <vector <int> > edges)
{

    vector <int> parent(n+1);
    for(int i=1;i<=n;i++)
     parent[i]=i;
     
     int ans=0;
     int edge=0;
     
    for(int e = 0;e<edges.size();e++)
    {
        if(find(edges[e][0] ,parent) != find(edges[e][1] , parent))
        {
          
            ans += edges[e][2];
            edge++;
            merge(edges[e][0],edges[e][1] , parent); // merge them
        }
        
        if(edge == n-1)
        break;
    }
    
    return ans;
}
int Solution::solve(int A, vector<vector<int> > &B) {
    sort(B.begin(),B.end(),compare);
    return krushkals(A , B);
}
*/

int find(int parent[], int i) {
    if(parent[i]==-1)
        return i;
    return find(parent, parent[i]);
}
void Union(int parent[], int x, int y) {
    int xp = find(parent, x);
    int yp = find(parent, y);
    parent[xp] = yp;
}
bool comp(vector<int> a, vector<int> b) {
    return a[2] < b[2];
}
int Solution::solve(int A, vector<vector<int> > &B) {
    
    sort(B.begin(), B.end(), comp);
    
    int parent[A];
    fill_n(parent, A, -1);
    
    int ans = 0;
    
    for(int i=0;i<B.size();i++) {
        int up = find(parent, B[i][0]-1);
        int vp = find(parent, B[i][1]-1);
        
        if(up!=vp) {
            Union(parent, up, vp);
            ans += B[i][2];
        }
    }

    return ans;
}

