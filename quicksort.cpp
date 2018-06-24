#include<fstream>
#include<iostream>
#include<vector>

using namespace std;
class sort{
public:
    vector<int> data;
    void quicksort(int q,int r);
    void push(int i);
    void xchg(int p,int r);
    int print(void);
private:
    int partition(int q,int r);
    void sortIteration(int p,int r); 
    
};
void sort::xchg(int p,int r)
{
    if(p!=r){
        data[r]=data[p]-data[r];
        data[p]=data[p]-data[r];
        data[r]=data[p]+data[r];        
    }
}
int sort::print(void)
{
    if(data.size()==0)
    {
        cout<<"无数据"<<endl;
        return 0;
    }
    else for(int i=0;i<data.size();i++)
        cout<<data[i]<<' ';
    cout<<endl;
    return 0;
}
void sort::quicksort(int q,int r)
{
    if(q<r&&q>=0)
        sortIteration(q,r);
    else cout<<"输入非法范围！";
}

void sort::sortIteration(int p,int r)
{
    if(p<r)
    {
        int q = partition(p,r);
        sortIteration(p,q-1);
        sortIteration(q+1,r);
    }
}
int sort::partition(int p,int r)
{
    int base=data[p];
    int i=p,j=r;
    while(i<j)
    {
        while(data[j]>=base)
        {
            if(i==j)
                break;
            j--;
        }
        while(data[i]<=base)//结束了看一看这里加不加等号会不会影响稳定性   
        {   
            if(i==j)
                break;
            i++;
        }
        xchg(i,j);
    }
    xchg(p,i);
    return i;
}
void sort::push(int p)
{
    data.push_back(p);
}

int main(){
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
    d.quicksort(0,d.data.size()-1);
    d.print();
    return 0;
}
