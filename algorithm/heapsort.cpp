#include<iostream>
#include<fstream>
#include<vector>
using namespace std;
//堆排序的程序实现
class sort{
public:
    vector<int> data;
    void push(int p);
    int heapsort(int p,int r);
    int print(void);
    void xchg(int p,int r);
private:
    void buildMaxHeap(int base,int r);
    void heapsortIteration(int p, int r);
    void maxHeapify(int base,int p,int r);
};
void sort::push(int p)
{
    data.push_back(p);
}
void sort::xchg(int p,int r)
{
    data[r]=data[p]-data[r];
    data[p]=data[p]-data[r];
    data[r]=data[p]+data[r];
}
int sort::print(void)
{
    if(data.size()==0)
    {
        cout<<"无数据"<<endl;
        return 0;
    }
    else{
    for(int i=0;i<data.size();i++)
        cout<<data[i]<<' ';
    cout<<endl;
    return 1;//不知为何，这个函数必须要返回个值，否则结束会输出个‘%’
    }
}
void sort::maxHeapify(int base,int p,int r)
{
    int largest=p;
    if(2*p+1<=r&&data[base+p]<data[base+2*p+1])
        largest=2*p+1;
    if(2*p+2<=r&&data[base+largest]<data[base+2*p+2])
        largest=2*p+2;
    if(largest!=p)
    {
        xchg(base+largest,base+p);
        maxHeapify(base,largest,r);
    }
}
void sort::buildMaxHeap(int base, int r)
{
    int len=r-base+1;
    for(int i=len/2-1;i>=0;i--)
    {
        maxHeapify(base,i,r);
    }
}
void sort::heapsortIteration(int p,int r)
{
    for(;r>=0;r--)
    {
        maxHeapify(p,0,r);
        xchg(p,r);
    }
}
int sort::heapsort(int p,int r)
{
    if(p<0||p>=r)
    {
        cout<<"输入非法！"<<endl;
        return 0;
    }
    else {
        buildMaxHeap(p,r);
        heapsortIteration(p,r);
    }
    return 1;
}

int main()
{
    sort d;
    string datum;
    string name;
    cout<<"请输入文件名："<<endl;
    cin>>name;
    ifstream ist(name.c_str());
    while(ist>>datum)
    {
        d.push(stoi(datum.c_str()));
    }
    d.heapsort(0,d.data.size()-1);
    d.print();
    return 0;
}
