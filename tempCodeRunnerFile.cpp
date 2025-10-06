#include<iostream>
using namespace std;

class box{
    double l,w,h;
    public:
        box& setl(double l){
            this->l = l;
            return *this;
        }
        box& setw(double w){
            this->w = w;
            return *this;
        }
        box& seth(double h){
            this->h = h;
            return *this;
        }
        void get_data(){
            cout<<l<<endl<<w<<endl<<h<<endl;
        }
};
int main(){
    box a,b,c;
    a.setl(2).setw(3).seth(5);
    a.get_data();
    return 0;
}