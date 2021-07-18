//
//  main.cpp
//  Trivial
//
//  Created by PavanKumar on 25/10/2020.
//  Copyright © 2020 PavanKumar. All rights reserved.
//

#include <iostream>
#include <sstream>
#include <fstream>



using std::cout;
using std::cin;
using std::endl;


class destruct{
private:
    int s, d;
public:
    destruct(int& s, int& d){
        this->s = s;
        this->d = d;
    }
    ~destruct(){
        cout<< "S : "<< s << "D : "<< d << endl;
    }
};


class construct{
private:
    int l, m;
public:
    construct(){
        l = 34;
        m = 45;
    }
    construct(int& p, int& q){
        l = p;
        m = q;
    }
    void get(){
        cout<< l << " " << m << endl;
    }
    void update(int l, int m){
//        (*this).l = l;
//        (*this).m = m;
        this->m = m;
        this->l = l;
    }
};

class arrayOfObjects{
private:
    int id, subjects;
    int* subjarray;
    char name[8];
public:
    void inputStudent();
    void getStudentData();
};

void arrayOfObjects::inputStudent(){
    cout<<"Enter Student id : "<<endl;
    cin>> this->id;
    cout<<"Enter Student "<< this->id << " name" <<endl;
    cin>> this->name;
    cout<< "Enter no.of subjects : \n";
    cin>> this->subjects;
    
    this->subjarray = new int[this->subjects];
    for(int i = 0; i< this->subjects; i++){
        cout << "Enter a numeric grade between 0 - 100" << endl;
        cin>> this->subjarray[i];
    }
}
void arrayOfObjects::getStudentData(){
    cout<<this->id<<"\t"<< this->name <<"\t";
    for(int i = 0; i< this->subjects; i++){
        cout<<"\t\t" << this->subjarray[i] << std::ends;
    }
    cout<<"\n";
}

class returnObjType{
private:
    int a, b;
public:
    void inputData(){
        cout<<"Enter a, b values : "<< endl;
        cin>> a >> b;
    }
    void showData(){
        cout<<"a, b values are : "<< a << " and " << b <<endl;
    }
    returnObjType sum(returnObjType obj);
};

returnObjType returnObjType::sum(returnObjType obj){
    returnObjType rtn3;
    rtn3.a = this->a + obj.a;
    rtn3.b = this->b + obj.b;
    return rtn3;
}

class thisPointer{
private:
    int a{10};
    float b{45.0};
    void put(){
        cout<< "HelloPAvan"<< endl;
    }
public:
    void get(){
        cout<<"Current Objects address is : "<< this << endl;
        cout<< "a is : "<< this->a << endl;
        cout<< "b is : "<< (*this).b << endl;
    }
};
 

void swapByAddress(int* a, int* b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
void swapByReference(int& a, int& b){
    int tmp = a;
    a = b;
    b = tmp;
}




int main(int argc, char **argv)
{
    int p = 100;
    int& q = p;
    int& r = q;
    
//    cout<< p << q << r << endl;
    q = 300;
//    cout<< p << q << r << endl;
    
    int s = 34;
    int y = 56;
    /*
    swapByAddress(&s, &y);
    cout<< s << y << endl;
    swapByReference(s, y);
    cout<< s << y << endl;
    
    thisPointer thisP;
    thisP.get();
    
    returnObjType rtn1, rtn2, rtn3;
    rtn1.inputData();
    rtn2.inputData();
    rtn3 = rtn1.sum(rtn2);
    rtn3.showData();
    */
    
    /*int n;
    cout<< "Enter no.of students : \n";
    cin>> n;
     
    arrayOfObjects arr[n];
    
    for(int k = 0; k<n; k++){
        arr[k].inputStudent();
    }
    
    cout<< "ID \t NAME \t\t MARKS \n";
    cout<< "-------------------------\n";
    
    for(int k = 0; k<n; k++){
        arr[k].getStudentData();
    }*/
    
    /*int j = 56;
    int h = 67;
    construct cst(j, h);
    //construct cst;
    cst.get();
    cst.update(54, 90);
    cst.get();*/
    
    int r_ = 46;
    int h = 90;
    destruct dst(r_, h);
    

    
    
    
}


