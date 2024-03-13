// Libraries Used In this Code
#include<iostream>
#include <cstdlib>
#include <ctime>
#include<cstring>
using namespace std;
// Creating Struct a User defined Data Type & storring Values in it
struct Product{
    char name[50];
    int stockLevel;
    int sales;
};
// Functions Made
void generate(Product* inventory,int size);
// Claculating Stock Level
float calAvgStockLevel(Product *inventory,int size);
// Critical points function
int countCriticalPoints(Product *inventory,int size,float avgStockLevel);
// so on
void findTopSellingProduct(Product* inventory, int size);
Product* findSecondBestSellingProduct(Product* inventory,int size);
void sortByPopularity(Product* inventory,int size);

int main(){
    // Declaring Variable of datatype int
    int size;
    // Taking Values from User
    cout<<"Enter the size : "<<endl;
    cin>>size;
    // Dynamic Mmeory Allocation
    Product* inventory=new Product[size];
    generate(inventory,size);
    float averageStockLevel=calAvgStockLevel(inventory,size);
    cout<<"Average Stock Level: "<<averageStockLevel<<endl<<endl;
    cout<<"Number of Critical Products: "
        <<countCriticalPoints(inventory,size,averageStockLevel)<<endl<<endl;
    findTopSellingProduct(inventory, size);
    cout<<endl;
    Product* secondBest=findSecondBestSellingProduct(inventory,size);
    if(secondBest!=NULL){
        cout<<"Second Best Selling Product: "<<secondBest->name<<endl<<endl;
    }
    sortByPopularity(inventory, size);
    cout<<"Products sorted by popularity are : "<<endl;
    for(int i=0;i<size;i++){
        cout<<inventory[i].name<<" - Sales : "<<inventory[i].sales<<endl;
    }
    delete[] inventory;
}

void generate(Product* inventory,int size){

    char names[][50]={"Product-01","Product-02","Product-03","Product-04","Product-05"};

    for(int i=0;i<size;i++){
        strcpy(inventory[i].name,names[i%5]);
        inventory[i].stockLevel=rand()%100;
        inventory[i].sales=rand()%1000;
    }
}

float calAvgStockLevel(Product *inventory,int size){
    int total=0;
    for(int i=0;i<size;i++){
        total+=inventory[i].stockLevel;
    }
    return (float)total/size;
}

int countCriticalPoints(Product *inventory,int size,float avgStockLevel){
    int count=0;
    for(int i=0;i<size;i++){
        if(inventory[i].stockLevel<avgStockLevel){
            count++;
        }
    }
    return count;
}

void findTopSellingProduct(Product* inventory, int size){
    int maxSalesVolume=0;
    Product* topSellingProduct=NULL;
    for(int i=0;i<size;i++){
        if (inventory[i].sales>maxSalesVolume){
            maxSalesVolume=inventory[i].sales;
            topSellingProduct=&inventory[i];
        }
    }
    cout<<"Top Selling Product: "<<topSellingProduct->name<<endl;
}

Product* findSecondBestSellingProduct(Product* inventory,int size) {
    int max=0;
    Product* bestSellingProduct =NULL;
    Product* second=NULL;
    for(int i=0;i<size;i++){
        if(inventory[i].sales>max){
            max=inventory[i].sales;
            second=bestSellingProduct;
            bestSellingProduct=&inventory[i];
        }
    }
    return second;
}

void sortByPopularity(Product* inventory,int size){
    for (int i=0;i<size-1;i++){
        for (int j=0;j<size-i-1;j++){
            if (inventory[j].sales<inventory[j+1].sales){
                Product temp=inventory[j];
                inventory[j]=inventory[j+1];
                inventory[j+1]=temp;
            }
        }
    }
}
