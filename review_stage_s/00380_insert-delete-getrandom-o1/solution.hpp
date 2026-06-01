#include <random>
#include <vector>
#include <unordered_map>

using namespace std;

class RandomizedSet {
public:
    RandomizedSet() : gen(random_device{}()){
        
    }
    
    bool insert(int val) {
        auto it = umap.find(val);
        if (it != umap.end()) return false;
        nums.emplace_back(val);
        umap.insert({val, nums.size()-1});
        return true;
    }
    
    bool remove(int val) {
        auto it = umap.find(val);
        if (it == umap.end()) return false;
        int index = it->second;
        umap.erase(it);
        int lastVal = nums.back();
        swap(nums.at(index), nums.back());
        nums.pop_back();
        if (lastVal != val) umap[lastVal] = index;  // 防止删除的就是最后一个元素导致重新添加
        return true;
    }
    
    int getRandom() {
        return nums.at(uniform_int_distribution<>(0, nums.size()-1)(gen));
    }

private:
    mt19937 gen;
    vector<int> nums;
    unordered_map<int, int> umap;
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
