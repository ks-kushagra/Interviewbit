

Design and implement a data structure for LRU (Least Recently Used) cache. It should support the following operations: get and set.

    get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
    set(key, value) - Set or insert the value if the key is not already present. When the cache reaches its capacity, it should invalidate the least recently used item before inserting the new item.

The LRU Cache will be initialized with an integer corresponding to its capacity. Capacity indicates the maximum number of unique keys it can hold at a time.

Definition of “least recently used” : An access to an item is defined as a get or a set operation of the item. “Least recently used” item is the one with the oldest access time.

    NOTE: If you are using any global variables, make sure to clear them in the constructor. 

Example :

Input : 
         capacity = 2
         set(1, 10)
         set(5, 12)
         get(5)        returns 12
         get(1)        returns 10
         get(10)       returns -1
         set(6, 14)    this pushes out key = 5 as LRU is full. 
         get(5)        returns -1 


___________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________


vector <pair<int,int> >v;
int k=0;

int Find(int key)
{
    for(int i=0;i<v.size();i++)
    {
        if(v[i].first == key)
         return i;
    }
    
    return -1;
}

LRUCache::LRUCache(int capacity) {
v = vector <pair<int,int> >();
k=capacity;
}

int LRUCache::get(int key) {

int index = Find(key);
if(index != -1)
   {
      auto p = v[index];
      v.erase(v.begin()+index);
      v.push_back(p);
     return p.second;
   }
 
 return -1;
}


void LRUCache::set(int key, int value) {
  
  int index = Find(key);
  if(index != -1)
  {
      v[index].second=value;
      auto p = v[index];
      v.erase(v.begin()+index);
      v.push_back(p);
      return;
  }
  
  if(v.size() == k)
    v.erase(v.begin());

  
  v.push_back({key,value});
  
}
_____________________________________________________________________________________________________________________________________________________________________________________________________________



list<pair<int,int>> dq;
unordered_map<int,list<pair<int,int>>::iterator> ma;
int csize;
LRUCache::LRUCache(int capacity) {
dq.clear();
ma.clear();
csize=capacity;
}

int LRUCache::get(int key) {
if(ma.find(key)==ma.end())
    return -1;
else
{
    pair<int,int> v=*ma[key];
    dq.erase(ma[key]);
    dq.push_front(v);
    ma[key]=dq.begin();
    return dq.begin()->second;
}
}

void LRUCache::set(int key, int value) {
if(ma.find(key)!=ma.end())
{
    dq.erase(ma[key]);
    dq.push_front({key,value});
    ma[key]=dq.begin();
}
else
{
    if(dq.size()==csize)
    {
        pair<int,int> v=dq.back();
        dq.pop_back();
        ma.erase(v.first);
        dq.push_front({key,value});
        ma[key]=dq.begin();
    }
    else
    {
        dq.push_front({key,value});
        ma[key]=dq.begin();
    }
}
}
