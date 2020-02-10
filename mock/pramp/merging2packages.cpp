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
    need = limit-newArr[i].first;
    int pos = lower_bound(newArr.begin(), newArr.end(), make_pair(need,0)) - newArr.begin();

    while(pos+1 < arr.size() and newArr[pos].first == newArr[pos+1].first) pos++;

    if(pos >= 0 and pos < arr.size() and need == newArr[pos].first and i != newArr[pos].second) {
      ans.push_back(max(newArr[i].second,newArr[pos].second));
      ans.push_back(min(newArr[i].second,newArr[pos].second));
      return ans;
    }
  }

  return ans;
}

int main() {
  return 0;
}
