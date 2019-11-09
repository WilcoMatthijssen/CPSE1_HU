#ifndef SET_HPP
#define SET_HPP
#include <array>

template< typename T, int maxSize> 
class set{
public:

   int size=0;
   std::array<T, maxSize> setArray;
   set(){  }


   void add(T n){
      if( !contains(n) || size<maxSize){
            setArray[size]=n;
            size++;
      }
   }
   void remove(T n){
      for(int i=0; i<size; i++){
         if(setArray[i]==n){
            setArray[i]=setArray[size];
            size--;
            break;
         }
      }
   }
   bool contains(T n){
      for( int i=0; i<size; i++){
            if(setArray[i]==n){
               return true;
            }
      }
      return false;
   }

   T max(){
      T max=setArray[0];
      for(int i=1; i<size; i++){
         if(max < setArray[i]){
            max=setArray[i];
         }

      }
      return max;
   }
   
   
  
};

template<typename T, int maxSize>
std::ostream & operator<<(std::ostream & out, const set<T, maxSize> & setObject){
   for(int i=0 ; i<setObject.size;i++){
      out<<setObject.setArray[i];
   }
   return out;
}
#endif