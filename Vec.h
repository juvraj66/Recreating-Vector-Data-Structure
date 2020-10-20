#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
template <typename T> class Vec{
public:
   Vec(){//Basic constructor setting all values to zero.
     _capacity=0;
     _size=0;
     _vec=0;
 }
   Vec(int n){// Initializing vector with capacity and size. aka constructor
     if(n<=0) _capacity=0, _size=0, _vec=NULL;
     else{
       _capacity=n, _size=n;
       allocate();
     }
   }
   Vec(int n, const T &a){//Initializing vector with capacity,size and values. aka constructor
     if(n<=0) _capacity=0, _size=0, _vec=NULL;
     else{
       _capacity=n, _size=n;
       allocate();
       for(int i=0;i<_capacity;i++){
         _vec[i]=a;
              }
        }
   }
   int capacity()const{return _capacity;}
   int size()const{return _size;}
   T front()const{// returns 1st element in vector
      if(_size<=0) return 0;
      else return _vec[0];
   }
   T back()const{// returns last element in vector
      if(_size<=0) return 0;
      else return _vec[_size-1];
   }
   void clear(){ _size=0;}//{// clears vector.
   void pop_back(){_size=_size-1;}// pops last element from vector
   void push_back(const T &a){// Add element to vec if vec of size is<capacity add element to vec else increase capacity by 2.
     if(_size<_capacity){
       _vec[_size]=a;
       _size=_size+1;
       return;
     }
     if (_size == _capacity){
       if(_capacity==0) _capacity=1;
       else if(_capacity) _capacity *=2;
       T *oldvec=_vec;
       allocate();
       if(oldvec!=NULL|| oldvec==NULL){
         for(int i=0;i<_size;i++){
           _vec[i]=oldvec[i];
         }
         delete [] oldvec;}
         _vec[_size]=a;
         _size=_size+1;
        }
   }
   T & at(int n){// Returns the element which the user requested.
     if(n>=0 && n<_size) return _vec[n];
     if(n<0||n>=_size){
        T *pnull=NULL;
        return *pnull;
     }
   }
   void erase(int n){// Erases data up to the nth element.
     if(n>=0 && n<_size){
        for(int i=0;i<_size;i++){
           _vec[n+i]=_vec[n+i+1];
     }
     _size=_size-1;
     return;
     }
     else return;
   }
   T& operator[](int n);
   const T& operator[](int n) const;
   Vec(const Vec &orig);
   Vec& operator= (const Vec &rhs);
   ~Vec();
private:
   int _capacity;
   int _size;
   T * _vec;// vec is a pointer to int and is a dynamically allocated array.
   void allocate(){// dynamically allocate array _vec.
      if(_capacity<=0) _vec=NULL;
      if(_capacity>0) _vec=new T[_capacity];
   }
   void release(){//releasing dynamically allocated memory.
      if(_vec==NULL) return ;
      else{
        delete[] _vec;
        _vec=NULL;
      }
   }
};
//Non-Inline functions
template<typename T>
Vec<T>::~Vec(){ release();}//Deconstructor
template<typename T>
Vec<T>::Vec(const Vec &orig){// Copy constructor
   _capacity=orig._size;
   _size=orig._size;
   allocate();
   for(int i=0;i<_size;i++){
      _vec[i]=orig._vec[i];
   }
}
template<typename T>//Overloading assignment operator.
Vec<T>& Vec<T>::operator= (const Vec<T> &rhs){
   if(this==&rhs) return *this;
   _capacity=rhs._size;
   _size=rhs._size;
   release();
   allocate();
   for(int i=0;i<_size;i++){
      _vec[i]=rhs._vec[i];
   }
   return *this;
}
template<typename T>
//Overloading [] operator.
T& Vec<T>::operator[](int n){ return at(n);}
template<typename T>
const T& Vec<T>::operator[](int n) const{
   if(n>=0 && n<_size) return _vec[n];
   if(n<0||n>=_size){
      T *pnull=NULL;
       return *pnull;}
     }
