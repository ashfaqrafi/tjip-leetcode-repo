class DetectSquares {
public:
    unordered_map<int, int> points;
    static const int BASE = 1001;
    
    inline int getSerializedValue(int x, int y) {
        return (x * BASE) + y;
    }
    
    DetectSquares() {
        points.clear();
    }
    
    void add(vector<int> point) {
        int x = point[0];
        int y = point[1];
        points[getSerializedValue(x, y)]++;
    }
    
    int count(vector<int> qpoint) {
        int tot_sqr = 0;
        int x2 = qpoint[0];
        int y2 = qpoint[1];
        
        for (auto &point : points) {
            /**
            (x4y2) -------- q(x2y2)
            |
            |
            |
            |
            |
            |
            (x4y4) --------- (x2y4)
            **/
            int x4 = point.first / BASE;
            int y4 = point.first % BASE;
            
            if ((x2 == x4) || (abs(x2 - x4) != abs(y2 - y4))) continue;
            
            if (points.count(getSerializedValue(x2, y4)) && points.count(getSerializedValue(x4, y2))) {
                tot_sqr += 
                      points[getSerializedValue(x2, y4)]
                    * points[getSerializedValue(x4, y2)]
                    * points[getSerializedValue(x4, y4)];
            }
        }
        
        return tot_sqr;
    }
};

/**
 * Your DetectSquares object will be instantiated and called as such:
 * DetectSquares* obj = new DetectSquares();
 * obj->add(point);
 * int param_2 = obj->count(point);
 */