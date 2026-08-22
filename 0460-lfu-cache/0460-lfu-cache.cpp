class LFUCache {
public:

    // Watch this video for explaination:- https://www.youtube.com/watch?v=-Vch0tHAsOM
    
    unordered_map<int, list<vector<int>> :: iterator>mp;  // int -> Address
    map<int,list<vector<int>>>freq;   //  cnt -> list of dll { key, value, couter }
    int size,cap;

    LFUCache(int capacity) {
        cap=capacity;
        size=0;
    }


    void Increaseitscounter(int key){
        auto &vec= *mp[key];
        int f=vec[2];
        int value=vec[1];

        //erase from freq map
        freq[f].erase(mp[key]);
        if(freq[f].empty()){
            freq.erase(f);
        }

        //increase its counter and add it into freq map
        f++;
        freq[f].push_front({key,value,f});

        //since new node is added in freq map,we have to update address map as well 

        mp.erase(key);
        mp[key]=freq[f].begin();
    }
    
    int get(int key) {

        //if element does not exists
        if(mp.find(key)==mp.end()) {
            return -1;
        }
        
        auto &vec=*mp[key];
        int x=vec[1];
        Increaseitscounter(key);
        return x;
        
    }
    
    void put(int key, int value) {
        // key exists
        if(mp.find(key)!=mp.end()){
            auto &vec=*mp[key];
            vec[1]=value;
            Increaseitscounter(key);
        }else if(size<cap){
            size++;
            freq[1].push_front({key,value,1});
            mp[key]=freq[1].begin();
        }
        else{
            // we have to delete the end of the least freq ,
            auto &list=freq.begin()->second;
            int key_to_delete= list.back()[0];
            list.pop_back();
            if(list.empty()){
                freq.erase(freq.begin()->first);
            }
            freq[1].push_front({key,value,1});
            mp.erase(key_to_delete);
            mp[key]=freq[1].begin();
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */