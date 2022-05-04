#include<bits/stdc++.h>
using namespace std;
struct trees{
    //trees(int num, int times) : num(num), times(times) {}
    int num;
    trees *lefttree;
    trees *righttree;
    int times;
    int size;
};
void insert (int num, trees *tree){
    if(tree->num==num) tree->times++;
    if(tree->num>num)
    {
        if(tree->righttree == nullptr){
            trees *t=new trees;
            t->num=num;
            t->times=1;
            t->lefttree=nullptr;
            t->righttree=nullptr;
            t->size=0
            tree->righttree=t;
        }
        else{
            insert(num,tree->righttree);
        }
    }
    if(tree->num<num)
    {
        if(tree->lefttree == nullptr){
            trees *t=new trees;
            t->num=num;
            t->times=1;
            t->lefttree=nullptr;
            t->righttree=nullptr;
            t->size=0
            tree->lefttree=t;
        }
        else{
            insert(num,tree->lefttree);
            tree->size++;
        }
    }
}
int ranked(int num , trees *tree )
{
    if(num ==tree->num) return tree->times+ranked(num,tree->lefttree);
    if(num < tree->num) return ranked(num,tree->lefttree);
    if(num > tree->num) 
}
int main()
{
    int q;
    cin>>q;

}