#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> getIndicesOfItemWeights( const vector<int>& arr, int limit)
{
  vector<int> ans;
  vector<pair<int,int>> newArr;
  int need;

  for(int i = 0; i < arr.size(); i++)
    newArr.push_back(make_pair(arr[i],i));

  sort(newArr.begin(), newArr.end());

  for(int i = 0; i < newArr.size(); i++) {
    need = limit-arr[i];
    int pos = lower_bound(newArr.begin(), newArr.end(), need) - newArr.begin();
    if(pos >= 0 and pos < arr.size() and need == newArr[pos].first and i != newArr[pos].second) {
      ans.push_back(min(i,newArr[pos].second));
      ans.push_back(max(i,newArr[pos].second));
      return ans;
    }
  }

  return ans;
}

int main() {
  return 0;
}
