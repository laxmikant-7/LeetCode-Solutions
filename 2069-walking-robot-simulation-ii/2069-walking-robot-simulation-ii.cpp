class Robot {
public:
    vector<vector<int>> temp;
    int w;
    int h;
    int i=0;
    bool moved=false;
    Robot(int width, int height) {
        this->w=width;
        this->h=height;
        for(int x=0;x<w;x++){
            temp.push_back({x,0,0});
        }
        for(int y=1;y<h;y++){
            temp.push_back({w-1,y,1});
        }
        for(int x=w-2;x>=0;x--){
            temp.push_back({x,h-1,2});
        }
        for(int y=h-2;y>0;y--){
            temp.push_back({0,y,3});
        }
        temp[0][2]=3;
    }
    
    void step(int num) {
        moved=true;
        i=(i+num)%temp.size();
    }
    
    vector<int> getPos() {
        return {temp[i][0],temp[i][1]};
    }
    
    string getDir() {
        if(!moved){
            return "East";
        }
        if(temp[i][2]==0) return "East";
        if(temp[i][2]==1) return "North";
        if(temp[i][2]==2) return "West";
        return "South";  
    }
};

/**
 * Your Robot object will be instantiated and called as such:
 * Robot* obj = new Robot(width, height);
 * obj->step(num);
 * vector<int> param_2 = obj->getPos();
 * string param_3 = obj->getDir();
 */