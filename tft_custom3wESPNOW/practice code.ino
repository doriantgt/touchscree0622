/* 

updating text box with matching ptr

#include <stdio.h>
#include <iostream>
using namespace  std;

int datas = 2;
int otherData =5;

class withPtr{
    public:
  int *ptr;  
};
int main()
{
    
    
    withPtr testerA;
    withPtr testerB;
    withPtr testerC;
    
    testerA.ptr = &datas;
        testerB.ptr = &otherData;

    testerC.ptr = &datas;
    
    cout << testerA.ptr << endl;
    cout << testerB.ptr << endl;
    cout << testerC.ptr << endl;

if(testerA.ptr == testerC.ptr){
    printf("matching address");}

    return 0;
}
*/