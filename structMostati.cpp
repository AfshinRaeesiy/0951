#include <iostream>

using namespace std;
struct rectangle{
    int x,y,area,mohit;


}A;
int main()
{
    cout <<" the x and y"<< endl;
    cin >>A.x>>A.y;
    A.mohit=(A.x+A.y)*2;
    A.area=A.x*A.y;

    for(int i=0;i<=A.x;i++){
        cout <<"_\t";
    }
        for(int j=0;j<=A.y;j++) {
            cout <<"\n|";
            for(int g=0;g<A.x;g++){
                cout <<"\t";
            }cout<< "|"<<endl;
        }
    for(int i=0;i<=A.x;i++){
        cout <<"_\t";
    }




    for(int i=0;i<=A.y;i++){

        }

    return 0;
}
