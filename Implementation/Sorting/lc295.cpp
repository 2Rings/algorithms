class MedianFinder {
public:
    /** initialize your data structure here. */
    vector<int> vec;
    int length = 0;
    MedianFinder() {
    }

    void addNum(int num) {
        vec.push_back(num);
        length++;
        return;
    }

    int partition(vector<int> v, int lo, int hi){
        int i = lo, j = hi+1;
        while(true){
            while(v[++i]<v[lo]){
                if(i == hi) break;
            }

            while(v[lo] < v[--j]){
                if(j == lo) break;
            }

            //check cross
            if(i >= j) break;

            swap(v[i], v[j]);
        }
        swap(v[lo], v[j]);
        return j;
    }

    int select(vector<int> v, int k){
        int lo = 0;
        int hi = v.size()-1;
        if(lo<hi){
            int j = partition(v, lo, hi);
            if(j<k) lo = j+1;
            else if(j>k) hi = j-1;
            else return v[k];
        }
        return v[k];
    }

    double findMedian() {
        if(length%2 == 1){
            int mid = (length-1)>>1;
            return (double)select(vec, mid);
        }
        else{
            int mid = (length-1)>>1;
            int a = select(vec, mid);
            int b = select(vec, mid+1);
            return ((double)a+(double)b)/2;
        }
    }
};
